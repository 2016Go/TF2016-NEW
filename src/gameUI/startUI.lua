local startUI = class("startUI", function() return cc.Layer:create() end)

--初始化函数
function startUI:ctor()
	--初始化监听数据，初始化数据
	cs.logger.i("startUI:ctor()")

	self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))

	self.UI = {}

	--加载一张背景图片
    self.UI.bgSp = cc.Sprite:create("UI/denglu/bgPic.jpg")
    self.UI.bgSp:setAnchorPoint(cc.p(0,0))
    self.UI.bgSp:setPosition(cc.p(0,0))

    --获取背景图片大小
    local bgSize = self.UI.bgSp:getContentSize()

	--将图片扩大成背景大小
	self.UI.bgSp:setScaleX(display.width/bgSize.width)
	self.UI.bgSp:setScaleY(display.height/bgSize.height)
	self:addChild(self.UI.bgSp)

    --添加游戏名称图片
    self.UI.gameName = cc.Sprite:create("UI/denglu/gameTitle.png")
    self.UI.gameName:setPosition(cc.p(display.cx,display.cy + 200))
    self.UI.gameName:setScale(0.7)
    self:addChild(self.UI.gameName)

    --添加开始游戏按钮
    self.UI.startBtn = ccui.Button:create("UI/denglu/startBtn.png")
    self.UI.startBtn:setPosition(cc.p(display.cx,display.cy ))
    self.UI.startBtn:setTitleText("开始游戏")
    self.UI.startBtn:setTitleFontSize(45)
    self:addChild(self.UI.startBtn)
   
    --添加清空存档按钮
    self.UI.clearBtn = ccui.Button:create("UI/denglu/clearBtn.png")
    self.UI.clearBtn:setPosition(cc.p(display.cx,display.cy - 100))
    self.UI.clearBtn:setTitleText("清空存档")
    self.UI.clearBtn:setTitleFontSize(45)
    self:addChild(self.UI.clearBtn)

    --添加关于游戏按钮
    self.UI.aboutBtn = ccui.Button:create("UI/denglu/aboutBtn.png")
    self.UI.aboutBtn:setPosition(cc.p(display.cx,display.cy - 200))
    self.UI.aboutBtn:setTitleText("关于游戏")
    self.UI.aboutBtn:setTitleFontSize(45)
    self:addChild(self.UI.aboutBtn)

    --添加版本号标签
    self.UI.versionLabel = cc.LabelTTF:create("版本号 ", "Arial", 50)
    self.UI.versionLabel:setPosition(cc.p(display.width - 200,100))
    self:addChild(self.UI.versionLabel)

    --绑定事件
	singleManagerUI:getInstance():bindListener(self.UI.startBtn,self,"startBtn")
	singleManagerUI:getInstance():bindListener(self.UI.clearBtn,self,"clearBtn")
	singleManagerUI:getInstance():bindListener(self.UI.aboutBtn,self,"aboutBtn")
end

--按钮监听事件函数
function startUI:startBtnTouchEnded()
	cs.logger.i("startBtnTouchEnded")
	--进入选关界面
    local selectMapUI = require("gameUI.selectMapUI"):create()
    singleManagerUI:getInstance():changeUI({} , selectMapUI , CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

function startUI:enter()
    cs.logger.i("enter****************")
end

function startUI:enterTransitionFinish()
    cs.logger.i("enterTransitionFinish****************")
end

function startUI:exit()
    cs.logger.i("exit*****************************")
end

function startUI:exitTransitionStart()
    cs.logger.i("exitTransitionStart*****************************")
end

function startUI:cleanup()
    cs.logger.i("cleanup*****************************")
end

return startUI