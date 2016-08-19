local life = class("life",require("gameFight.actor.actor"))

function life:ctor()
    --self:setData()
    life.super.ctor(self)

    --自身根节点，用于怪物移动
    self:setAnchorPoint(cc.p(0.5,0.5))	--设定根节点的锚点

    --生命值的数据结构，用于后面子类使用
    self.actorData = {}
    self.actorData.life         = 10            -- 生命值
    self.actorData.direction    = CC_LIFT_WALK_DIR.Walk_All --移动方向初始化
    
    self.lifeLayer = cc.Layer:create() 			--生命节点，用于怪物的翻转已经特效等
    self.lifeLayer:setAnchorPoint(cc.p(0.5,0.5))	--设定节点的锚点
    self:addChild(self.lifeLayer,10)            --加入根节点
end

function life:_checklief()
    if self.actorData.life  <= 0 then      
        singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_LifeDie, self, self.actorData)
        return false
    end
    return true
end

return life