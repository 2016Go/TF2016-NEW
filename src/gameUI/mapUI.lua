local mapUI = class("mapUI" , function() return cc.Layer:create() end)

--初始化函数
function mapUI:ctor()
	--初始化监听器，初始化数据
	cs.logger.i("mapUI:ctor()")

	self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))

	self.UI = {}

	--加载一张背景图片
	self.UI.bgSp = cc.Sprite:create("UI/denglu/ui_map.jpg")
	self.UI.bgSp:setAnchorPoint(cc.p(0,0))
	self.UI.bgSp:setPosition(cc.p(0,0))

	--获取背景图片的大小
	local bgSize = self.UI.bgSp:getContentSize()

	--将图片扩展成背景大小
	self.UI.bgSp:setScaleX(display.width/bgSize.width)
	self.UI.bgSp:setScaleY(display.height/bgSize.height)
	self:addChild(self.UI.bgSp)

	--添加返回按钮
	self.UI.backBtn = ccui.Button:create("UI/denglu/btn_back.png")
	self.UI.backBtn:setAnchorPoint(cc.p(0,1))
    self.UI.backBtn:setPosition(cc.p(0,display.height))
    self:add(self.UI.backBtn)

    --添加金币图标
    self.UI.goldPic = cc.Sprite:create("UI/denglu/gold.png")
    self.UI.goldPic:setAnchorPoint(cc.p(1,1))
    self.UI.goldPic:setPosition(cc.p(display.width,display.height - 40))
    self:addChild(self.UI.goldPic)
    --添加金币文本
    self.UI.goldLabel = cc.LabelTTF:create("12345", "Arial", 30)
    self.UI.goldLabel:setAnchorPoint(cc.p(0,1))
    self.UI.goldLabel:setPosition(cc.p(display.width - 120,display.height - 40))
    self.UI.goldLabel:setColor(cc.c3b(0,0,0))
    self:addChild(self.UI.goldLabel)
    --添加商城按钮
    self.UI.shopBtn = ccui.Button:create("UI/denglu/btn_shop.png")
    self.UI.shopBtn:setAnchorPoint(cc.p(0,1))
    self.UI.shopBtn:setScale(0.4)
    self.UI.shopBtn:setPosition(cc.p(display.width - 160,display.height - 35))
    self:addChild(self.UI.shopBtn)
    --添加称号文本
    self.UI.titleLabel = cc.LabelTTF:create("称号:音速小子", "Arial", 40)
    self.UI.titleLabel:setPosition(cc.p(display.cx ,display.height - 55))
    self.UI.titleLabel:setColor(cc.c3b(0, 0, 0))
    self.UI.titleLabel:setTag(1)
    self:addChild(self.UI.titleLabel)
    
    --成就按钮
	self.UI.achievementBtn = ccui.Button:create("UI/denglu/selectBtn.png")
	self.UI.achievementBtn:setPosition(cc.p(display.left + 100,display.bottom + 50))
	self.UI.achievementBtn:setTitleText("成就")
	self.UI.achievementBtn:setTitleFontSize(45)
	self.UI.achievementBtn:setTitleColor(cc.c3b(0, 0, 0))
	self:addChild(self.UI.achievementBtn)
    --战斗按钮
	self.UI.battleBtn = ccui.Button:create("UI/denglu/selectBtn.png")
	self.UI.battleBtn:setPosition(cc.p(display.cx,display.bottom + 50))
    self.UI.battleBtn:setTitleText("战斗")
    self.UI.battleBtn:setTitleFontSize(45)
    self.UI.battleBtn:setTitleColor(cc.c3b(0, 0, 0))
    self:addChild(self.UI.battleBtn)
    --升级按钮
    self.UI.upgradeBtn = ccui.Button:create("UI/denglu/selectBtn.png")
    self.UI.upgradeBtn:setPosition(cc.p(display.right - 100,display.bottom + 50))
    self.UI.upgradeBtn:setTitleText("升级")
    self.UI.upgradeBtn:setTitleFontSize(45)
    self.UI.upgradeBtn:setTitleColor(cc.c3b(0, 0, 0))
    self:addChild(self.UI.upgradeBtn)

    --绑定事件
    singleManagerUI:getInstance():bindListener(self.UI.backBtn,self,"backBtn")
    singleManagerUI:getInstance():bindListener(self.UI.battleBtn,self,"battleBtn")
    
    self:bindLabelListener(self.UI.titleLabel)
end

--标签绑定监听

function mapUI:bindLabelListener(node)
	local labelListener = cc.EventListenerTouchOneByOne:create()

    local touchBegan = function (touch,event)
        local locationInNode = node:convertToNodeSpace(touch:getLocation())
	    local nodeContent = node:getContentSize()
	    local rect = cc.rect(0,0,nodeContent.width,nodeContent.height)

		if cc.rectContainsPoint(rect,locationInNode)  then
			return true
		end
		return false
    end

	local touchEnded = function(touch,event)
       	local locationInNode = node:convertToNodeSpace(touch:getLocation())s
	    local nodeContent = node:getContentSize()
	    local rect = cc.rect(0,0,nodeContent.width,nodeContent.height)

		if cc.rectContainsPoint(rect,locationInNode)  then
			cs.logger.i("labelTouchEnded")
			if node:getTag() == 1 then   --点击标签为地图层称号标签时
				local colorLayer = cc.LayerColor:create(cc.c4b(100,100,100,100))
				self:getParent():add(colorLayer, 100)
                local layerListener = cc.cc.EventListenerTouchOneByOne:create()
                LayerListener:setSwallowTouches(true)
                labelListener:registerScriptHandler(function (touch,event) return false end,cc.Handler.EVENT_TOUCH_BEGAN)
  	            cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(layerListener, colorLayer)
			else
				----
			end
		end
	end
	labelListener:registerScriptHandler(touchBegan,cc.Handler.EVENT_TOUCH_BEGAN)
	labelListener:registerScriptHandler(touchEnded,cc.Handler.EVENT_TOUCH_ENDED)
	cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(labelListener, node)
end


--按钮监听事件函数
function mapUI:backBtnTouchEnded()
	cs.logger.i("backBtnTouchEnded")
	--返回开始界面
    local startUI = require("gameUI.startUI"):create()
    singleManagerUI:getInstance():changeUI({} , startUI , CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

function mapUI:achievementBtnTouchEnded()
	cs.logger.i("achievementBtnTouchEnded")

end

function mapUI:battleBtnTouchEnded()
	cs.logger.i("battleBtnTouchEnded")
    --进入战斗界面
    local fightMainScene = require("gameFight.fightMainScene"):create()
    singleManagerUI:getInstance():changeUI({} , fightMainScene , CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

function mapUI:upgradeBtnTouchEnded()
	cs.logger.i("upgradeBtnTouchEnded")
	
end

function mapUI:enter()
    cs.logger.i("enter****************")
end

function mapUI:enterTransitionFinish()
    cs.logger.i("enterTransitionFinish****************")
end

function mapUI:exit()
    cs.logger.i("exit*****************************")
end

function mapUI:exitTransitionStart()
    cs.logger.i("exitTransitionStart*****************************")
end

function mapUI:cleanup()
    cs.logger.i("cleanup*****************************")
end

return mapUI