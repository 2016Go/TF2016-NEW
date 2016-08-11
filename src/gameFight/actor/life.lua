local Life = class("Life")
cs.class.setFather(Life,"gameFight.Actor.Actor")

function Life:create()
    print("Life:create()")
    Life.rootLayer = cc.Layer:create() 			--根节点，用于怪物移动
    Life.rootLayer:setAnchorPoint(cc.p(0,0))	--设定根节点的锚点

    Life.lifeLayer = cc.Layer:create() 			--生命节点，用于怪物的翻转已经特效等
    Life.lifeLayer:setAnchorPoint(cc.p(0,0))	--设定节点的锚点
    Life.rootLayer:addChild(Life.lifeLayer,10)	--加入根节点
end

function Life:setData(actorData)
    print("Life:setLifeData()")
    
    self.actorData = {}
	self.actorData.name  		= actorData.name			-- 怪物名字
	self.actorData.life  		= actorData.life  			-- 生命值
	self.actorData.speed 		= actorData.speed 			-- 速度值
	self.actorData.mainRes 		= actorData.mainRes			-- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
end

return Life