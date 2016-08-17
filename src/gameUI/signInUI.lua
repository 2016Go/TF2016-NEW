local signInUI = class("signInUI", function() return cc.Layer:create() end)

--初始化界面函数
function signInUI:ctor()
	--初始化监听数据，初始化数据
	cs.logger.i("signInUI:ctor()")

	local a = cs.conf.a('tower', 1)
	cs.util.printTable(a)

	self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))

	self.UI = {}
	
	--加载一张背景图片
	self.UI.bgSp = cc.Sprite:create("UI/denglu/bg.png")
    self.UI.bgSp:setAnchorPoint(cc.p(0,0))
	self.UI.bgSp:setPosition(cc.p(0,0))

	--获取图片原本大小
	local bgSize = self.UI.bgSp:getContentSize();

	--将图片扩大成背景大小
	self.UI.bgSp:setScaleX(display.width/bgSize.width)
	self.UI.bgSp:setScaleY(display.height/bgSize.height)

	self:addChild(self.UI.bgSp )

	--加载账号密码输入框
	self.UI.accountLabel = cc.LabelTTF:create("账号", "ttf/fangzhenglier.ttf", 30)  
    self.UI.accountLabel:setAnchorPoint(cc.p(1,0.5))
    self.UI.accountLabel:setPosition(cc.p(display.width/2 - 125,display.height/2))
    self:addChild(self.UI.accountLabel )

	self.UI.account = ccui.EditBox:create(cc.size(200,50), "UI/gonggongziyuan/Elm_94.png")
	self.UI.account:setAnchorPoint(cc.p(0,0.5))
	self.UI.account:setPosition(cc.p(display.width/2 - 100,display.height/2))
    self.UI.account:setFontColor(cc.c3b(216, 216, 216))
    self.UI.account:setMaxLength(12)
	self:addChild(self.UI.account )

	self.UI.passwoldLabel = cc.LabelTTF:create("密码", "ttf/fangzhenglier.ttf", 30)  
    self.UI.passwoldLabel:setAnchorPoint(cc.p(1,0.5))
    self.UI.passwoldLabel:setPosition(cc.p(display.width/2 - 125,display.height/2 - 100))
    self:addChild(self.UI.passwoldLabel )

	self.UI.passwold = ccui.EditBox:create(cc.size(200,50), "UI/gonggongziyuan/Elm_94.png")
	self.UI.passwold:setAnchorPoint(cc.p(0,0.5))
	self.UI.passwold:setPosition(cc.p(display.width/2 - 100 ,display.height/2 -100))
    self.UI.passwold:setFontColor(cc.c3b(216, 216, 216))
    self.UI.passwold:setMaxLength(12)
    self.UI.passwold:setInputFlag(cc.EDITBOX_INPUT_FLAG_PASSWORD)
	self:addChild(self.UI.passwold )

	--加载游客登录
	self.UI.touristBtn = ccui.Button:create("UI/denglu/Button_59_01.png")
	self.UI.touristBtn:setAnchorPoint(cc.p(0.5,0.5))
	self.UI.touristBtn:setPosition(cc.p(display.width/2 - 150,display.height/2 -200))
	self.UI.touristBtn:setTitleText("游客登录")
	self.UI.touristBtn:setTitleFontSize(25)

	--绑定事件
	singleManagerUI:getInstance():bindListener(self.UI.touristBtn,self,"touristBtn")
	self:addChild(self.UI.touristBtn )

	--加载注册按钮
	self.UI.registerBtn = ccui.Button:create("UI/denglu/Button_59_03.png")
	self.UI.registerBtn:setAnchorPoint(cc.p(0.5,0.5))
	self.UI.registerBtn:setPosition(cc.p(display.width/2 + 100,display.height/2 -200))
	self.UI.registerBtn:setTitleText("注册游戏")
	self.UI.registerBtn:setTitleFontSize(25)
	self:addChild(self.UI.registerBtn )

	self.UI.testLabel = cc.LabelTTF:create("测试金币", "ttf/fangzhenglier.ttf", 50)  
    self.UI.testLabel:setAnchorPoint(cc.p(1,0.5))
    self.UI.testLabel:setPosition(cc.p(display.width/2 + 125,display.height/2 + 300))
    self:addChild(self.UI.testLabel )

	--绑定事件
	singleManagerUI:getInstance():bindListener(self.UI.registerBtn,self,"registerBtn")
end
function signInUI:registerBtnTouchEnded()
	cs.logger.i("registerBtnTouchEnded")


	singleUIData:getInstance():setData(CC_UI_DATA_TPYE.UI_Wallet, singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_Wallet] + 1 )
end

function signInUI:touristBtnTouchEnded()
	cs.logger.i("touristBtnTouchEnded")

	--进入游戏
    local fightMainScene = require("gameFight.fightMainScene"):create()
    singleManagerUI:getInstance():changeUI({} , fightMainScene , CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

function signInUI:refreshUI(event,eventSender,data)
	cs.logger.i("refreshUI ")
	self.UI.testLabel:setString("测试金币 = "..data)
end

function signInUI:enter()
	cs.logger.i("enter****************")
	singleUIEvent:getInstance():addEventListenerInPool(CC_UI_DATA_TPYE.UI_PlayName, self)
    singleUIEvent:getInstance():addEventListenerInPool(CC_UI_DATA_TPYE.UI_Wallet, self)

end

function signInUI:enterTransitionFinish()
	cs.logger.i("enterTransitionFinish****************")
end

function signInUI:exit()
	cs.logger.i("exit*****************************")
	singleUIEvent:getInstance():removeEventListenerInPool(CC_UI_DATA_TPYE.UI_PlayName, self)
    singleUIEvent:getInstance():removeEventListenerInPool(CC_UI_DATA_TPYE.UI_Wallet, self)
end

function signInUI:exitTransitionStart()
	cs.logger.i("exitTransitionStart*****************************")
end

function signInUI:cleanup()
	cs.logger.i("cleanup*****************************")
end
return signInUI