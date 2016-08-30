local tower = class("tower",require("gameFight.actor.life"))

function tower:ctor()
    --self:setData()
    tower.super.ctor(self)
    self:setActorCamp( CC_CAMP.Camp_Own)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点
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
    --local fristFrame , animation = singleUtil:getInstance():createFrameCache(self.towerData['png'] ,"/standby/", 0.25, 9, 20, "%02d.png")
    
    --if fristFrame == nil then
    --    return
    --end

    --if animation == nil then
    --    return
    --end

    --self.mainSprite:setSpriteFrame(fristFrame)
    --self.mainSprite:runAction(cc.RepeatForever:create(cc.Animate:create(animation)))
    --self.lifeLayer:addChild(self.mainSprite , 10)
    
    self.mainSprite = DHSkeletonAnimation:createWithFile(self.towerData['png']);
    self.mainSprite:setAnchorPoint(cc.p(0.5,0.5))

    self.lifeLayer:addChild(self.mainSprite , 10)
    self.mainSprite:setScale(0.5)
    self.mainSprite:scheduleUpdateLua()

    local aa = function ( eventName,test2 )
        if eventName == "attEvent" then
            self:_sendBulletEvent()
        end
    end

    self.mainSprite:registerLuaHandler( aa )
    self.mainSprite:playAnimation("stand",-1)

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
    print("sendBulletEvent**************")
    --存储必要数据
    self.__sendBulletEventTargetEnemy = targetEnemy
    self.__sendBulletEventTargetEnemyPos = cc.p(targetEnemy:getPosition())
    self.__sendBulletEventmyPos = myPos

    --播放事件，由事件去处理
    self.mainSprite:playAnimation("att")

    --该值，只对等待子弹有效果
    self.isCanFire = false

    --自身的CD等变化
    self.fireCD = self.towerData['pInterval'] / 1000
    self.targetEnemy = targetEnemy
end

--真正的发送事件
function tower:_sendBulletEvent()
    local targetEnemy = self.__sendBulletEventTargetEnemy
    local targetPos = self.__sendBulletEventTargetEnemyPos
    local myPos = self.__sendBulletEventmyPos

    local sendData = {}
    sendData.bulletID = self.towerData["bulletID"]
    sendData.bulletPos = myPos
    sendData.targetEnemy = targetEnemy
    sendData.bulletTargetPos = targetPos

    singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BuildBullet, self, sendData)

    if self.towerData['bulletNum'] > 1 then 
        local iNum = self.towerData['bulletNum'] -1
        local  symbol = -1

        for i = 1 , iNum do
            --确定符号
            symbol = symbol * -1
            --确定偏移值
            local ag = 10 * math.ceil(i/2) * symbol
            local sendDataBan = {}
            sendDataBan.bulletID = self.towerData["bulletID"]
            sendDataBan.bulletPos = myPos
            sendDataBan.bulletTargetPos = self:getOffsetbulletPos(myPos,targetPos,ag)

            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BuildBullet, self, sendDataBan)
        end
    end

end

--获取偏移子弹的目标位置
function tower:getOffsetbulletPos(myPos, targetPos, angle)
    local subX = targetPos.x - myPos.x
    local subY = targetPos.y - myPos.y

    local x = math.abs(subX)
    local y = math.abs(subY)
    local ag = self:getAngleByPos(cc.p(0,0) , cc.p(x, y))

    --30度的偏移计算
    local tanData = math.tan(math.rad(ag + angle))

    --print("subY = "..subY)
    local y = math.abs(subX) * tanData
    if subX < 0 then
        x = - x
    end
    if subY < 0 then
        y = - y
    end
    return cc.p(x + myPos.x ,y + myPos.y)
end

--求两点之间的夹角
function tower:getAngleByPos(p1,p2)  
    local p = {}  
    p.x = p2.x - p1.x  
    p.y = p2.y - p1.y  
             
    local r = math.atan2(p.y,p.x)*180/math.pi  
    return r  
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