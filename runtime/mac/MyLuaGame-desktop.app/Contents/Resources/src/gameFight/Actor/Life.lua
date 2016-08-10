local Life = class("Life")
cs.class.setFather(Life,"gameFight.Actor.Actor")

function Life:create()
    print("Life:create()")
    Life.RootLayer = cc.Layer:create() 			--根节点，用于怪物移动
    Life.RootLayer:setAnchorPoint(cc.p(0,0))	--设定根节点的锚点

    Life.LifeLayer = cc.Layer:create() 			--生命节点，用于怪物的翻转已经特效等
    Life.LifeLayer:setAnchorPoint(cc.p(0,0))	--设定节点的锚点
    Life.RootLayer:addChild(Life.LifeLayer,10)	--加入根节点
end

function Life:setData(ActorData)
    print("Life:setLifeData()")
    
    self.ActorData = {}
	self.ActorData.name  		= ActorData.name			-- 怪物名字
	self.ActorData.life  		= ActorData.life  			-- 生命值
	self.ActorData.speed 		= ActorData.speed 			-- 速度值
	self.ActorData.mainRes 		= ActorData.mainRes			-- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
end

return Life