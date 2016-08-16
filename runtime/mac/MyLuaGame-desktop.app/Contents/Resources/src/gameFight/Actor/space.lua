local space = class("space",require("gameFight.actor.actor"))

function space:ctor()
    --self:setData()
    space.super.ctor(self)
    self:setActorCamp( CC_CAMP.Camp_Non)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个空地标
    self.spaceSp = cc.Sprite:create("super/space.png")          --生命节点，用于怪物的翻转已经特效等
    self.spaceSp:setAnchorPoint(cc.p(0.5,0.5))    --设定节点的锚点
    self:addChild(self.spaceSp,10)            --加入根节点
end

return space