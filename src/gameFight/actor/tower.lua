local tower = class("tower",require("gameFight.actor.life"))

function tower:ctor()
    --self:setData()
    tower.super.ctor(self)
    self:setActorCamp( CC_CAMP.Camp_Own)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个塔的造型空图片
    self.mainSprite = cc.Sprite:create()
    self.mainSprite:setAnchorPoint(cc.p(0.5,0.3))
    self.mainSprite:setPosition(cc.p(0,0))

	--singleManagerUI:getInstance():bindListener(self.lifeLayer,self,"towerImage")
end

--存储数据
function tower:setTowerData(data)
    self.towerData = data

    --初始化CD为0 
    self.fireCD = 0 

    --目标敌人,特殊的初始化，如此来标记没有敌人
    self.targetEnemy = nil

    --根据子弹的数据设定一次塔的攻击优先级
    local bulletData = cs.conf.a("bullet" , self.towerData["bulletID"])
    self.attType = bulletData['attType']
    self.isWaitBullet = false

    --该值，只对等待子弹有效果
    self.isCanFire = true
    if self.towerData["pInterval"] == -1 then
        self.isWaitBullet = true
    end
end

function tower:createTowerWithData()
    local fristFrame , animation = singleUtil:getInstance():createFrameCache(self.towerData['png'] ,"/standby/", 0.25, 9, 20, "%02d.png")
    
    if fristFrame == nil then
        return
    end

    if animation == nil then
        return
    end

    self.mainSprite:setSpriteFrame(fristFrame)
    self.mainSprite:runAction(cc.RepeatForever:create(cc.Animate:create(animation)))
    self.lifeLayer:addChild(self.mainSprite , 10)
    self:ShowTheDebug()
end

function tower:UpData(dt)
    --检查CD是否OK
    if self.isWaitBullet == false then
        if self.fireCD > 0 then
            self.fireCD = self.fireCD - dt
            return
        end
    else
        if self.isCanFire == false then
            return
        end        
    end 
    
    local  myPos = cc.p( self:getPosition() )
    
    --检查是否存在瞄准目标
    if self:targetEnemyCheck() == true then
        return
    end

    --检查范围内是否有怪物存在
    --获取所有怪物
    local  allEnemy = singleEnemyManager:getInstance():getAllEnemy()
    
    --计算怪物距离塔的直线距离
    for i,v in pairs(allEnemy) do
        --根据有限级判断能否被攻击
        if self:isCanAtt(v) then
            local d = cc.pGetDistance( myPos, cc.p(v:getPosition()) )
            --范围内怪物
            if d < self.towerData['pRange'] then
                --发送创建子弹消息
                self:sendBulletEvent(v,myPos)
                return
            end
        end
    end
end

function tower:isCanAtt(v)
    --如果怪物免疫等级高于塔的攻击属性等级，则无法瞄准
    if v.actorData == nil then
        return false
    end
    if v.actorData.immine > self.attType then
        return false
    end
    return true
end

--已有目标的检测
function tower:targetEnemyCheck()
    local  myPos    = cc.p( self:getPosition() )

    --判断是否已有目标
    if self.targetEnemy == nil then
        return false
    end

    if self:isCanAtt(self.targetEnemy) == false then
        return false
    end  
    
    --判断目标是否依旧在管理器中
    if singleEnemyManager:getInstance():checkEnemyIsInManager( self.targetEnemy ) == false then
        self.targetEnemy = nil
        return false
    end

    --判断敌人是否存活
    if self.targetEnemy.actorData.life <= 0 then
        self.targetEnemy = nil
        return false
    end

    --判断敌人是否依旧还在范围圈内
    local d = cc.pGetDistance( myPos, cc.p(self.targetEnemy:getPosition()) )
    if d > self.towerData['pRange'] then
        self.targetEnemy = nil
        return false
    end

    self:sendBulletEvent(self.targetEnemy, myPos)
    return true  
end

function tower:sendBulletEvent(targetEnemy,myPos)
    --发送创建子弹消息
    local sendData = {}
    sendData.bulletID = self.towerData["bulletID"]
    sendData.bulletPos = myPos
    sendData.targetEnemy = targetEnemy
    self.targetEnemy = targetEnemy
    sendData.bulletTargetPos = cc.p(targetEnemy:getPosition())
    singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BuildBullet, self, sendData)
    
    --该值，只对等待子弹有效果
    self.isCanFire = false

    --自身的CD等变化
    self.fireCD = self.towerData['pInterval'] / 1000
    self.targetEnemy = targetEnemy
end

function tower:ShowTheDebug(stageData)
    if CC_IS_SHOW_DEBUG == false then
        return
    end

    local m_pDrawNode = cc.DrawNode:create(1)
    m_pDrawNode:setAnchorPoint(cc.p(0,0))
    m_pDrawNode:setPosition(cc.p(0,0))
    self:addChild(m_pDrawNode, 99)
    m_pDrawNode:drawCircle(cc.p(0,0), self.towerData['pRange'], 0, 18, false, 1, 1, cc.c4b(1,0,1,1))
end

return tower