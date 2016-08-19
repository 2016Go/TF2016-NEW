local bullet = class("bullet",require("gameFight.actor.actor"))

function bullet:ctor()
    --self:setData()
    bullet.super.ctor(self)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个子弹的造型空图片
    self.mainSprite = cc.Sprite:create()
    self.mainSprite:setAnchorPoint(cc.p(0.5,0.5))
    self.mainSprite:setPosition(cc.p(0,0))
end

--子弹出生
--给出子弹的ID和子弹将要过去的点
function bullet:born(bulletData)
    self.bulletData = cs.conf.a("bullet",bulletData.bulletID)
    print("createbullet = "..self.bulletData['png'])
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

    --保存目标信息
    self.bulletTargetPos = bulletData.bulletTargetPos
    self.targetEnemy = bulletData.targetEnemy

    local subX = bulletData.bulletTargetPos.x - bulletData.bulletPos.x
    local subY = bulletData.bulletTargetPos.y - bulletData.bulletPos.y
    self.bulletData.speedX = self.bulletData.speed * (subX  / (math.abs(subX) + math.abs(subY)))
    self.bulletData.speedY = self.bulletData.speed * (subY  / (math.abs(subX) + math.abs(subY)))

    --旋转
    local t2 = math.atan2( (self.bulletData.speedY),math.abs(self.bulletData.speedX)) * 180/3.14159;
    self.mainSprite:setRotation(t2) 
end



function bullet:UpData(dt)
    local willMoveX = self.bulletData.speedX * dt
    local willMoveY = self.bulletData.speedY * dt

    local myPos = cc.p(self:getPosition())
    local newPos = cc.p(myPos.x + willMoveX , myPos.y + willMoveY)

    if willMoveX < 0 then
        if newPos.x <= self.bulletTargetPos.x then
            newPos = self.bulletTargetPos
            self:setPosition(newPos)

            --发送子弹到达目的地时间
            local sendData = {}
            sendData.targetEnemy = self.targetEnemy
            sendData.aoe = self.bulletData["aoe"]
            sendData.att = 100
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletCollision, self, sendData)
        else
            self:setPosition(newPos)
        end  
    else
        if newPos.x >= self.bulletTargetPos.x then
            newPos = self.bulletTargetPos
            self:setPosition(newPos)

            --发送子弹到达目的地时间
            local sendData = {}
            sendData.targetEnemy = self.targetEnemy
            sendData.aoe = self.bulletData["aoe"]
            sendData.att = 10
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BulletCollision, self, sendData)
        else
            self:setPosition(newPos)
        end
    end   
end

return bullet