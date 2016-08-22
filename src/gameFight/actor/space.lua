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
--[[
	local sp = cc.Sprite:create("fightUI/sele_tower.png")
	sp:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点
	sp:setScale(0.5)
	sp:setOpacity(0)
	--sp:setTouchEnabled(false)

	

	--cc.Sequence:create(action) 
	local bAction1 = cc.Spawn:create(cc.ScaleTo:create(0.25,1.3),cc.FadeIn:create(0.2)) 
	local bAction2 = cc.Sequence:create(bAction1,cc.ScaleTo:create(0.08,0.9),cc.ScaleTo:create(0.04,1)) 


	sp:runAction(bAction2)
	self:addChild(sp)
]]
	

---
--[[
	local canBuildID = singleGameData:getInstance():towerData.canBuild

	for k,v in pairs(canBuildID) do
		print(k,v)
	end
	--获得塔ID
	local towerID = 1

	--判定金币是否足够
	local towerData = cs.conf.a("tower" , towerID)
	local nowGold = singleGameData:getInstance():getStageData().gold
	if nowGold < towerData['gunbuildGold'] then
		--没钱造个JB
		return
	end

	singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_GoldChange, self , -towerData['gunbuildGold'])

	--销毁自己
	--发送建造塔的消息。
	singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BuildTower, self , towerData)
	]]
end

return space