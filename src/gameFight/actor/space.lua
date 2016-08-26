local space = class("space",require("gameFight.actor.actor"))

function space:ctor()
    --self:setData()
    space.super.ctor(self)
    self:setActorCamp( CC_CAMP.Camp_Non)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个空地标
    self.spaceImage = ccui.ImageView:create("map/space.png")          --生命节点，用于怪物的翻转已经特效等
    self.spaceImage:setTouchEnabled(true)
    self.spaceImage:setAnchorPoint(cc.p(0.5,0.5))    --设定节点的锚点
    self:addChild(self.spaceImage,10)            --加入根节点

    -- 添加触控事件侦听器
   -- self.spaceSp:addTouchEventListener(listener)
	singleManagerUI:getInstance():bindListener(self.spaceImage,self,"spaceSp")
end

function space:enter()
	cs.logger.i("space:enter()")
end

function space:spaceSpTouchEnded()
---创建一个出现动画
	local buildTower = require("gameFight.fightUI.buildTowerUI"):create()
	buildTower:createUI(self)
end

return space