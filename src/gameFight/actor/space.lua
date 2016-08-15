local space = class("space",require("gameFight.actor.actor"))

function space:ctor()
    --self:setData()
    life.super.ctor(self)
    self:setActorCamp( CC_CAMP.Camp_Non)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个空地标
    self.spaceSp = cc.Sprite:create("")          --生命节点，用于怪物的翻转已经特效等
    self.lifeLayer:setAnchorPoint(cc.p(0.5,0.5))    --设定节点的锚点
    self:addChild(self.lifeLayer,10)            --加入根节点

end

return space