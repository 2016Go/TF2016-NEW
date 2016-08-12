
local enemy = class("enemy",require("gameFight.actor.life"))

function enemy:ctor()
    enemy.super.ctor(self)

    --设定怪物类型
    self:setActorCamp( CC_CAMP.Camp_Enemy)
    self.nowPosID = 1 --当前行动节点ID
    self.nowState = CC_ENEMY_STATE.State_Ready --设定为准备
    self.actorTime = 0 -- 当前行为时间
    --创建怪物蹄片
    self.mainSprite = cc.Sprite:create()
    self.mainSprite:setAnchorPoint(cc.p(0,0))
    self.lifeLayer:addChild(self.mainSprite , 10)
end

--当怪物死亡，或消失的时候调用
function enemy:clear()
    self:removeFromParent()
end

function enemy:setData(actorData)
    self.actorData = {}
    self.actorData.name         = actorData.name            -- 怪物名字
    self.actorData.life         = actorData.life            -- 生命值
    self.actorData.speed        = actorData.speed           -- 速度值
    self.actorData.mainRes      = actorData.mainRes         -- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
    self.actorData.stand        = actorData.stand           -- 站立动作名字
    self.actorData.walk         = actorData.walk            -- 位移动作名字
    self.actorData.road         = actorData.road            -- 行走道路ID
    self.actorData.roadData     = singleLoadMap:getInstance().mapData["map"]["roads"]["road"][self.actorData.road]            -- 行走道路的数据
end

function enemy:born()
    self.nowPosID = 1 --当前行动节点ID
    local bornPos = self:_getLoadPos(self.nowPosID )

    --设置到出生位置
    self:setPosition(bornPos)

    --可能存在的出生动画播放预留
    --开始进入行走状态
    self.nowState = CC_ENEMY_STATE.State_Walk

    --动作行为切换为行走
    local fristFrame , animation = singleUtil:getInstance():createFrameCache(self.actorData.mainRes ,self.actorData.walk, 0.25,7)
    self.mainSprite:setSpriteFrame(fristFrame)
    self.mainSprite:runAction(cc.RepeatForever:create(cc.Animate:create(animation)))

    self:_setActorTime(-1)
end

function enemy:walkUpData(dt)
    --将要行走路长
    local willGo = self.actorData.speed * dt
    --活动当前怪物所在点
    local nowPos = cc.p(self:getPosition())

    --计算走过下一个节点位置后剩余的路长
    local surplus = willGo
    local nextPosID = self.nowPosID

    --循环查找可以到达的最后一个点
    while(true) 
    do
        nextPosID = nextPosID + 1

        --如果为空说明已经到达终点。发送消息说明已经到达终点
        if self:_getLoadPos(nextPosID ) == nil then
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_EnemyGoOver, self)
            return
        end

        local willSurplus = self:_checkSurplus(surplus, nowPos, nextPosID)
        if willSurplus <= 0 then
            break
        end

        --修正最新的nowPos，surplus, 以及nowPosID
        surplus = willSurplus
        nowPos = self:_getLoadPos(nextPosID )
        self.nowPosID  = nextPosID
    end

    --获取下一个节点位置

    local nextPos = self:_getLoadPos(nextPosID)
    
    --两点总边长
    local addMath = math.abs(nextPos.y-nowPos.y) + math.abs(nextPos.x-nowPos.x)
    local x = surplus*( (nextPos.x-nowPos.x)/ addMath )
    local y = surplus*( (nextPos.y-nowPos.y)/ addMath )

    self:setPosition(cc.p(nowPos.x+x,nowPos.y+y))

end

function enemy:UpData(dt)

    --更新时间
    if self.actorTime > 0 then
        self.actorTime = self.actorTime - dt
        return
    end

    --只有行走状态才开始更新自己的位置
    if self.nowState == CC_ENEMY_STATE.State_Walk then
        self:walkUpData(dt)
        return
    end

    --出生
    if self.nowState == CC_ENEMY_STATE.State_Born then
        self:born()
    end

end


function enemy:_checkSurplus(surplus, nowPos , nextPosID)
    local nextPos = self:_getLoadPos(nextPosID )
    local allDistance = math.sqrt(math.pow((nextPos.y-nowPos.y),2)+math.pow((nextPos.x-nowPos.x),2))

    --取4位小数
    allDistance = math.ceil(allDistance*1000)/1000
    surplus = math.ceil(surplus*1000)/1000

    return surplus - allDistance
end

function enemy:_getLoadPos(nowPosID)
    if self.actorData.roadData["p"][nowPosID] == nil then
        return nil
    end
    local pos = loadstring("return "..self.actorData.roadData["p"][nowPosID])();
    return cc.p(pos[1],pos[2])
end

--特殊情况设定actorTime时间的通用接口
function enemy:_setActorTime(actorTime)
    self.actorTime = actorTime
    cs.logger.i("Enemy:_setActorTime is do")
end

return enemy
