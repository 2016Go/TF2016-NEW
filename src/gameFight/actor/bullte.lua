local tower = class("tower",require("gameFight.actor.actor"))

function tower:ctor()
    --self:setData()
    tower.super.ctor(self)
    self:setActorCamp( CC_CAMP.Camp_Own)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个空地标
    self.towerImage = ccui.ImageView:create("Fight/tower/1.png")          --生命节点，用于怪物的翻转已经特效等
    self.towerImage:setTouchEnabled(true)
    self.towerImage:setAnchorPoint(cc.p(0.5,0.5))    --设定节点的锚点
    self:addChild(self.towerImage,10)            --加入根节点

	singleManagerUI:getInstance():bindListener(self.towerImage,self,"towerImage")
end

function tower:towerImageTouchEnded()


end

return tower