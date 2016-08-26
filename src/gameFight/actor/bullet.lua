local bullet = class("bullet",require("gameFight.actor.actor"))

function bullet:ctor()
    --self:setData()
    bullet.super.ctor(self)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个子弹的造型空图片
    self.mainSprite = cc.Sprite:create()
    self.mainSprite:setAnchorPoint(cc.p(0.5,0.5))
    self.mainSprite:setPosition(cc.p(0,0))

    --用于判断子弹是否已经造成过伤害
    self.isAtt = false
end

--子弹出生
--给出子弹的ID和子弹将要过去的点
function bullet:born(bulletData)

    self.bulletData = cs.util.tablecpy(cs.conf.a("bullet",bulletData.bulletID))
    local fristFrame , animation = singleUtil:getInstance():createFrameCache(self.bulletData['png'] ,"/walk/", 0.25, 2, 10, "%02d.png")

    if fristFrame == nil then
        print(" fristFrame == nil "..self.bulletData['png'])
    end

    if animation == nil then
        print(" animation == nil "..self.bulletData['png'])
    end

    self.mainSprite:setSpriteFrame(fristFrame)
    self.mainSprite:runAction(cc.RepeatForever:create(cc.Animate:create(animation)))
    self:addChild(self.mainSprite , 10)
    self:setPosition(bulletData.bulletPos)

    --上一个计算点的初始化，这个值特殊用于路径攻击的一个计算量
    self.PreviousPos  = bulletData.bulletPos

    --保存目标信息
    self:_setTargetData(bulletData)
end

--保存一个发射者
function bullet:setFirer(firer)
    self.firer = firer
end

--重载清理函数
function bullet:clear()
    if self.firer.isWaitBullet ~= nil then
        if self.firer.isWaitBullet == true then
            self.firer.isCanFire = true
        end
    end
    
    self:removeFromParent()
end

function bullet:UpData(dt)
    --自身的移动
    local willMoveX = self.bulletData.speedX * dt
    local willMoveY = self.bulletData.speedY * dt
    local myPos = cc.p(self:getPosition())
    local newPos = cc.p(myPos.x + willMoveX , myPos.y + willMoveY)
    self:setPosition(newPos)

    --是否自身应该造成伤害
    self:_cheakSendBullt(willMoveX, willMoveY,newPos) 

    --是否自身应该销往
    self:cheakDie(newPos)  
end

function bullet:_cheakSendBullt(willMoveX, willMoveY,newPos)
    --如果是目标攻击模式，在到达目标后发送目标到达消息，并进行攻击
    if self.bulletData['damageType']["mode"] == "targetAtt" then
        --如果该子弹已经造成过一次伤害，说子弹是不消失类型，但也不会再次造成伤害
        if self.isAtt == true then
            return
        end
        
        if willMoveX < 0 then
            if newPos.x <= self.bulletTargetPos.x then            
                local targetEnemyVec = {}
                table.insert( targetEnemyVec, self.targetEnemy )
                self:sendBullt(targetEnemyVec)
                return
            end  
        else
            if newPos.x >= self.bulletTargetPos.x then
                local targetEnemyVec = {}
                table.insert( targetEnemyVec, self.targetEnemy )
                self:sendBullt(targetEnemyVec)
                return
            end
        end   
    end

    --是否判断攻击
    if self.bulletData['damageType']["mode"] == "roadAtt" then
        --self.PreviousPos

        --获得两点之间的距离
   
        local d = cc.pGetDistance( self.PreviousPos, newPos)
        local diameterMax = self.bulletData['pRange'] * 2
        local diameterMin = self.bulletData['pRange']

        --如此范围的移动。运行给一次判定机会
        if (d < diameterMax)  and  (d > diameterMin ) then
            self.PreviousPos = newPos
            self:_cheakEnemy(newPos)
            return
        end

        if d > diameterMax then
            --排除错误情况，避免死循环
            if self.bulletData.speedX > 0 then
                if self.PreviousPos.x > newPos.x then
                    return
                end
            elseif self.bulletData.speedX < 0 then
                if self.PreviousPos.x < newPos.x then
                    return
                end
            end

            --排除错误情况，避免死循环
            if self.bulletData.speedY > 0 then
                if self.PreviousPos.y > newPos.y then
                    return
                end
            elseif self.bulletData.speedY < 0 then
                if self.PreviousPos.y < newPos.y then
                    return
                end
            end

            local allSpeed = (math.abs(self.bulletData.speedX) + math.abs(self.bulletData.speedY))
            local xMove = diameterMax * (self.bulletData.speedX / allSpeed)
            local yMove = diameterMax * (self.bulletData.speedY / allSpeed)
            self.PreviousPos.x = self.PreviousPos.x + xMove
            self.PreviousPos.y = self.PreviousPos.y + yMove

            self:_cheakEnemy(self.PreviousPos)
        end
    end
end

--发送子弹攻击事件
function bullet:sendBullt(targetEnemy)
    if next(targetEnemy) == nil then
        return
    end
    --发送子弹到达目的地时间
    local sendData = {}
    sendData.targetEnemy = targetEnemy
    sendData.aoe = self.bulletData["aoe"]
    sendData.att = self.bulletData['att']
    sendData.attType = self.bulletData['attType']
    sendData.buffId = self.bulletData['buffId']
    singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletCollision, self, sendData)
    self.isAtt = true
end

--子弹自身的范围检测伤害怪物函数
function bullet:_cheakEnemy(Pos)
    --获取所有怪物
    local allEnemy = singleEnemyManager:getInstance():getAllEnemy()
    local targetEnemyVec = {}
    --计算怪物距离塔的直线距离
    for i,v in pairs(allEnemy) do
        --根据有限级判断能否被攻击
        if self:_isCanAtt(v) then
            local d = cc.pGetDistance( Pos, cc.p(v:getPosition()) )
            --范围内怪物
            if d < self.bulletData["pRange"] then
                --发送创建子弹消息
                table.insert( targetEnemyVec,v)
            end
        end
    end

    self:sendBullt(targetEnemyVec)
end

--检测自身是否应该死亡
function bullet:cheakDie(newPos)
    --如果是目标攻击，且已经击中过目标，为最常规的子弹消失
    if self.bulletData['disappear'] == "att" then
        if self.bulletData['fireMode']["mode"] == 1 then
            if self.isAtt == true then
                singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletDie, self, nil)
                return
            end
        
        --如果子弹可以弹射的话，那么要计算子弹的弹射数值
        elseif fireMode["mode"] == 3 then
            self.bulletData['fireMode']["iTime"] = self.bulletData['fireMode']["iTime"] -1
            
            --如果已经弹射完毕
            if fireMode["iTime"] < 0 then
                singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletDie, self, nil)
                return
            end

            --如果找不到合适的弹射目标
            if self:_catapultFindTarget() ~= true then
                singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletDie, self, nil)
                return
            end
        end
    end

    --如果是出屏幕消失模式,在其他地方检测子弹是否应该消失
    if self.bulletData['disappear'] == "out" then
        if newPos.x < -10 then 
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletDie, self, nil)
            return
        end

        if newPos.y < -10 then 
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletDie, self, nil)
            return
        end

        if newPos.x > display.width + 10 then 
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletDie, self, nil)
            return
        end

        if newPos.y > display.height + 10 then
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletDie, self, nil)
            return
        end
    end
end

--弹射子弹寻找另外的射击膜表
function bullet:_catapultFindTarget()
    --获取所有怪物
    local allEnemy = singleEnemyManager:getInstance():getAllEnemy()
    local myPos = cc.p(self:getPosition())

    --计算怪物距离塔的直线距离
    for i,v in pairs(allEnemy) do
        --根据有限级判断能否被攻击
        if self:_isCanAtt(v) then

            if v ~= self.targetEnemy  then
                local d = cc.pGetDistance( myPos, cc.p(v:getPosition()) )
                --范围内怪物
                if d < self.bulletData["pRange"] then
                    --发送创建子弹消息
                    local sendData = {}

                    sendData.bulletPos = myPos
                    sendData.targetEnemy = v
                    sendData.bulletTargetPos = cc.p(v:getPosition())

                    --自身的等变化
                    self:_setTargetData(sendData)
                    return true
                end
            end
        end
    end
    return false
end

--判断是否能够被攻击
function bullet:_isCanAtt(enemy)
    if enemy.actorData == nil then
        return false
    end
    
    if enemy.actorData.immine > self.bulletData.attType then
        return false
    end

    return true
end

--设定目标数据
function bullet:_setTargetData(bulletData)
    self.bulletTargetPos = bulletData.bulletTargetPos
    self.targetEnemy = bulletData.targetEnemy

    local subX = bulletData.bulletTargetPos.x - bulletData.bulletPos.x
    local subY = bulletData.bulletTargetPos.y - bulletData.bulletPos.y

    self.bulletData.speedX = self.bulletData.speed * (subX  / (math.abs(subX) + math.abs(subY)))
    self.bulletData.speedY = self.bulletData.speed * (subY  / (math.abs(subX) + math.abs(subY)))

    --旋转
    local t2 = math.atan2( (self.bulletData.speedY),(self.bulletData.speedX)) * 180/3.14159
    self.mainSprite:setRotation(-t2 ) 
end

return bullet