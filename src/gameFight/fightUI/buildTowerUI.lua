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

	--保存一份数据
	self.target = target

	--用笛卡尔坐标系转换获得应该绘制的坐标位置
    local widgetPoint   = target:getAnchorPointInPoints()
    local wordPoint     = target:convertToWorldSpace( widgetPoint )
    local localPoint    = mainLayer:convertToNodeSpace(wordPoint)

    localPoint.x = localPoint.x - display.width/2 
    localPoint.y = localPoint.y - display.height/2

	self.seleTower = cc.Sprite:create("fightUI/sele_tower.png")
	self.seleTower:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点
	self.seleTower:setScale(0.5)
	self.seleTower:setOpacity(0)
	self.seleTower:setPosition(localPoint)

	--创建一个背景用于点击消失的图片
	self.bgSp = cc.Sprite:create()
	self.bgSp:setContentSize(display)
	self.bgSp:setAnchorPoint(cc.p(0,0))  --设定根节点的锚点
	
	local bAction1 = cc.Spawn:create(cc.ScaleTo:create(0.25,1.3),cc.FadeIn:create(0.2)) 
	local bAction2 = cc.Sequence:create(bAction1,cc.ScaleTo:create(0.08,0.9),cc.ScaleTo:create(0.04,1)) 

	self:createTowerIcon(self.seleTower)
	self.seleTower:runAction(bAction2)
	
	self:addChild(self.seleTower,10)
	self:addChild(self.bgSp,9)

	mainLayer:addChild(self,CC_GAME_LAYER_LEVEL.Layer_fight_main_ui)

	singleManagerUI:getInstance():bindListener(self.bgSp,self,"bgSp")
end

function buildTowerUI:createTowerIcon(sp)
	local towerData = singleGameData:getInstance().towerData.canBuild
	for k,v in pairs(towerData) do
		--判定金币是否足够
		local towerData = cs.conf.a("tower" , v)

		--加入塔的图片
		print(towerData["png"].."/".."icon.png")
		local pngFrame = cc.SpriteFrameCache:getInstance():getSpriteFrame(towerData["png"].."/".."icon.png")
		local towerSp = cc.Sprite:createWithSpriteFrame(pngFrame)
		towerSp:setPosition(self.iconPos[""..k])
		sp:addChild(towerSp)
		
		--加入塔的价格
		local goldLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 25)  
    	goldLabel:setAnchorPoint(cc.p(0,0.5))
    	goldLabel:setPosition(cc.p( 15,40))
    	goldLabel:setString(""..towerData['gunbuildGold'] )
    	towerSp:addChild(goldLabel )

    	local anchorPoint = towerSp:getAnchorPoint()
    	local rect = towerSp:getBoundingBox()
    	local worldPoint = towerSp:convertToWorldSpace(cc.p(rect.x, rect.y))
		self["towerSp"..k] = towerSp
		singleManagerUI:getInstance():bindListener(towerSp,self,"towerSp", k)
	end
end

function buildTowerUI:towerSpTouchBegan(towerID)
	print("towerSpTouchBegan1")
	--self:removeFromParent()

	--读取当前塔的数据
	local towerData = cs.conf.a("tower" , towerID)

	--创建一个演示塔在地址上
	local pngFrame = cc.SpriteFrameCache:getInstance():getSpriteFrame(towerData["png"].."/".."icon.png")
	local towerSp  = cc.Sprite:createWithSpriteFrame(pngFrame)
	towerSp:setAnchorPoint(cc.p(0.5,0.3))
	towerSp:setOpacity(150)
	local seleTowerSize = cc.p( self.seleTower:getContentSize().width, self.seleTower:getContentSize().height)
	towerSp:setPosition( cc.pMul(seleTowerSize,0.5) )
	self.seleTower:addChild(towerSp)

	--创建一个演示攻击圈
	local pDrawNode = cc.DrawNode:create(1)
    pDrawNode:setAnchorPoint(cc.p(0.5,0.3))
    pDrawNode:drawCircle(cc.p(0,0), towerData['pRange'], 0, 18, false, 1, 1, cc.c4b(1,0,1,1))
    pDrawNode:setPosition( cc.pMul(seleTowerSize,0.5) )
	self.seleTower:addChild(pDrawNode)

	--隐藏以前的地标
	self.target.spaceImage:setVisible(false)
	
	--循环隐藏以前的塔
	for i=1,4 do
		self["towerSp"..i]:setVisible(false)
	end

	--加入一个确认按钮
	local towerSp  = cc.Sprite:create("fightUI/tower_ok.png")
	towerSp:setPosition(cc.p(self["towerSp"..towerID]:getPosition()))
	self["towerSp"..towerID]:getParent():addChild(towerSp)
	singleManagerUI:getInstance():bindListener(towerSp,self,"towerOk", towerID)
end

function buildTowerUI:towerOkTouchEnded(towerID)
	--读取当前塔的数据
	local towerData = cs.conf.a("tower" , towerID)
	local nowGold = singleGameData:getInstance():getStageData().gold
	if nowGold < towerData['gunbuildGold'] then
		--没钱造个JB
		singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_GoldPoor, self , towerData)
		return
	end

	singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_GoldChange, self , -towerData['gunbuildGold'])

	--销毁自己
	--发送建造塔的消息。
	singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_BuildTower, self.target , towerData)
	self:removeFromParent()
end

function buildTowerUI:bgSpTouchBegan()
	print("bgSpTouchBegan**************")
	self.target.spaceImage:setVisible(true)

	if(self.target.towerSp ~= nil ) then
		self.target.towerSp:removeFromParent()
		self.target.pDrawNode:removeFromParent()
		self.target.towerSp = nil
		self.target.pDrawNode = nil
	end

	self:removeFromParent()
end

return buildTowerUI