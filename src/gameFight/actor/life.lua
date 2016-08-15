local life = class("life",require("gameFight.actor.actor"))

function life:ctor()
    --self:setData()
    life.super.ctor(self)

    --自身根节点，用于怪物移动
    self:setAnchorPoint(cc.p(0.5,0.5))	--设定根节点的锚点

    self.lifeLayer = cc.Layer:create() 			--生命节点，用于怪物的翻转已经特效等
    self.lifeLayer:setAnchorPoint(cc.p(0.5,0.5))	--设定节点的锚点
    self:addChild(self.lifeLayer,10)            --加入根节点
end

function life:setData(actorData)
    self.actorData = {}
	self.actorData.name  		= actorData.name			-- 怪物名字
	self.actorData.life  		= actorData.life  			-- 生命值
	self.actorData.speed 		= actorData.speed 			-- 速度值
	self.actorData.mainRes 		= actorData.mainRes			-- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
    self.actorData.direction    = actorData.direction or CC_LIFT_WALK_DIR.Walk_All --移动方向初始化
end

return life