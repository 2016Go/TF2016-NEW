local buildTowerUI = class("buildTowerUI", function() return cc.Layer:create() end)

function buildTowerUI:ctor()
    --初始化监听数据，初始化数据
    self.UI = {}
    --self:createUI()
    self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))

	self.iconPos = 
	{
		["1"] = cc.p(65,10),
		["2"] = cc.p(130,65),
		["3"] = cc.p(65,130),
		["4"] = cc.p(10,65)
	}
end

--特殊的UI创建，需要参数
function buildTowerUI:createUI(target)
	--获得mainLayer
	local mainLayer = singleGameData:getInstance():getMainLayer()

	--用笛卡尔坐标系转换获得应该绘制的坐标位置
    local widgetPoint   = target:getAnchorPointInPoints()
    local wordPoint     = target:convertToWorldSpace( widgetPoint )
    local localPoint    = mainLayer:convertToNodeSpace(wordPoint)

    localPoint.x = localPoint.x - display.width/2 
    localPoint.y = localPoint.y - display.height/2

	local sp = cc.Sprite:create("fightUI/sele_towe.png")
	sp:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点
	sp:setScale(0.5)
	sp:setOpacity(0)
	sp:setPosition(localPoint)

	--创建一个背景用于点击消失的图片
	self.bgSp = cc.Sprite:create()
	self.bgSp:setContentSize(display)
	self.bgSp:setAnchorPoint(cc.p(0,0))  --设定根节点的锚点
	
	local bAction1 = cc.Spawn:create(cc.ScaleTo:create(0.25,1.3),cc.FadeIn:create(0.2)) 
	local bAction2 = cc.Sequence:create(bAction1,cc.ScaleTo:create(0.08,0.9),cc.ScaleTo:create(0.04,1)) 

	self:createTowerIcon(sp)
	sp:runAction(bAction2)
	
	self:addChild(sp,10)
	self:addChild(self.bgSp,9)

	mainLayer:addChild(self,CC_GAME_LAYER_LEVEL.Layer_fight_main_ui)

	singleManagerUI:getInstance():bindListener(self.bgSp,self,"bgSp")
end

function buildTowerUI:createTowerIcon(sp)
	local towerData = singleGameData:getInstance().towerData.canBuild
	for k,v in pairs(towerData) do
		--判定金币是否足够
		local towerData = cs.conf.a("tower" , v)

		print(towerData["png"].."/".."icon.png")
		local pngFrame = cc.SpriteFrameCache:getInstance():getSpriteFrame(towerData["png"].."/".."icon.png")
		local towerSp = cc.Sprite:createWithSpriteFrame(pngFrame)
		towerSp:setPosition(self.iconPos[""..k])
		sp:addChild(towerSp)


		singleManagerUI:getInstance():bindListener(towerSp,self,"bgSp"..k)

	end
end

function buildTowerUI:bgSp1()

	local towerData = cs.conf.a("tower" , 1)
	local nowGold = singleGameData:getInstance():getStageData().gold
	if nowGold < towerData['gunbuildGold'] then
			--没钱造个JB
		return
	end

	print("1111111")
	--singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_GoldChange, self , -towerData['gunbuildGold'])

		--销毁自己
		--发送建造塔的消息。
	self:removeFromParent()
	--singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BuildTower, self , towerData)

end

function buildTowerUI:bgSpTouchBegan()
	self:removeFromParent()
end

return buildTowerUI