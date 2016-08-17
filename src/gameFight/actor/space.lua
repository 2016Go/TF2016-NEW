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

--[[	
	local listener = function(sender,type)
		if type == ccui.TouchEventType.ended then
   			self:spaceSpTouchEnd()
   		end
    end
]]
    -- 添加触控事件侦听器
   -- self.spaceSp:addTouchEventListener(listener)

	singleManagerUI:getInstance():bindListener(self.spaceImage,self,"spaceSp")
end

function space:enter()
	cs.logger.i("space:enter()")
end

function space:spaceSpTouchEnded()
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

    --创建生命图片
    --local stageData = 
    --self.UI.lifeLabel:setString(""..stageData.life)
    --self.UI.goldLabel:setString(""..stageData)
    --self.UI.waveLabel:setString(""..stageData.wave.."/"..stageData.waveLimit)

	--销毁自己
	--发送建造塔的消息。
	singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BuildTower, self , towerData)

end

return space