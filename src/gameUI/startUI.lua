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
    --self.UI.gameName:setPosition(cc.p(display.cx,display.cy + 200))
    --self.UI.gameName:setScale(0.7)
    --self:addChild(self.UI.gameName)
    --获取标题图片大小
    local titleSize = self.UI.gameName:getContentSize()
    
    --创建发光底板
    --self.UI.spark = cc.Sprite:create("UI/denglu/spark.png")
    --self.UI.spark:setPosition(cc.p(-titleSize.width/2, 0))

    --创建裁剪节点
    --[[
    self.UI.clipplingNode = cc.ClippingNode:create()
    self.UI.clipplingNode:setPosition(cc.p(display.cx,display.cy + 200))
    self.UI.clipplingNode:setAlphaThreshold(0.05)
    self.UI.clipplingNode:setContentSize(titleSize.width,titleSize.height)
    self.UI.clipplingNode:setStencil(self.UI.gameName)
    self.UI.clipplingNode:addChild(self.UI.gameName,1)
    self.UI.clipplingNode:addChild(self.UI.spark,2)
    self:addChild(self.UI.clipplingNode)

    local sparkMove = cc.MoveBy:create(2,cc.p(titleSize.width, 0))
    self.UI.spark:runAction(cc.RepeatForever:create(cc.Sequence:create(sparkMove,sparkMove:reverse())))]]

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

    --添加设置按钮
    self.UI.settingBtn = ccui.Button:create("UI/denglu/aboutBtn.png")
    self.UI.settingBtn:setAnchorPoint(cc.p(1, 1))
    self.UI.settingBtn:setPosition(cc.p(display.width, display.height))
    self.UI.settingBtn:setTitleText("设置")
    self.UI.settingBtn:setTitleFontSize(45)
    self:addChild(self.UI.settingBtn)

    --添加版本号标签
    self.UI.versionLabel = cc.LabelTTF:create("版本号 ", "Arial", 50)
    self.UI.versionLabel:setPosition(cc.p(display.width - 200,100))
    self:addChild(self.UI.versionLabel)

    cs.logger.i("gameName************2")
    singleManagerUI:getInstance():bindListener(self.UI.bgSp,self,"bgSp")

    --绑定事件
	singleManagerUI:getInstance():bindListener(self.UI.startBtn,self,"startBtn")
	singleManagerUI:getInstance():bindListener(self.UI.clearBtn,self,"clearBtn")
	singleManagerUI:getInstance():bindListener(self.UI.settingBtn,self,"settingBtn")

    --载入shader
    self.ShaderManager = require("gameUI.gameUIBase.ShaderManager")
    self.ShaderManager:load()


    for i=1,10 do
        local uuu = cs.conf.a("uiMapPos",i)
        if uuu == nil then
            return
        end
        local xxx = uuu["number"]

        print("number is = "..xxx)
    end
end

--添加一个灰色层
function startUI:addColorLayer()
    cs.logger.i("addColorLayer*************************")
    --添加一个半透明的层并吞噬触摸
    self.UI.colorLayer = cc.LayerColor:create(cc.c4b(100,100,100,100))  
    self:addChild(self.UI.colorLayer)
    
    --添加背景框
    self.UI.settingBg = cc.Sprite:create("UI/denglu/setBg.jpg")
    self.UI.settingBg:setPosition(cc.p(display.cx, display.cy))
    self.UI.colorLayer:addChild(self.UI.settingBg)
    local setBgSize = self.UI.settingBg:getContentSize()

    --添加标签
    self.UI.setLabel = cc.LabelTTF:create("设置","ttf/fangzhenglier.ttf",30)
    self.UI.musicLabel = cc.LabelTTF:create("音乐","ttf/fangzhenglier.ttf",40)
    self.UI.effectLabel = cc.LabelTTF:create("音效","ttf/fangzhenglier.ttf",40)
    self.UI.setLabel:setPosition(cc.p(setBgSize.width/2, 350))
    self.UI.musicLabel:setPosition(cc.p(100, 200))
    self.UI.effectLabel:setPosition(cc.p(100, 100))
    self.UI.settingBg:addChild(self.UI.setLabel)
    self.UI.settingBg:addChild(self.UI.musicLabel)
    self.UI.settingBg:addChild(self.UI.effectLabel)

    --勾选框
    self.UI.musicCheckBox = ccui.CheckBox:create("UI/denglu/cannon.png", "UI/denglu/cannon.png","UI/denglu/gold.png","","")                                 
    self.UI.effectCheckBox = ccui.CheckBox:create("UI/denglu/cannon.png", "UI/denglu/cannon.png","UI/denglu/gold.png","","")
    self.UI.musicCheckBox:setPosition(cc.p(setBgSize.width - 100, 200))
    self.UI.effectCheckBox:setPosition(cc.p(setBgSize.width - 100, 100))
    self.UI.settingBg:addChild(self.UI.musicCheckBox)
    self.UI.settingBg:addChild(self.UI.effectCheckBox)

    --语言选择按钮
    self.UI.languageBtn = ccui.Button:create("UI/denglu/clearBtn.png")
    self.UI.languageBtn:setTitleText("语言")
    self.UI.languageBtn:setTitleFontSize(40)
    self.UI.languageBtn:setPosition(cc.p(setBgSize.width/2, 50))
    self.UI.settingBg:addChild(self.UI.languageBtn)

    --返回按钮
    self.UI.backBtn = ccui.Button:create("UI/denglu/gold.png")
    self.UI.backBtn:setAnchorPoint(cc.p(1,1))
    self.UI.backBtn:setPosition(cc.p(setBgSize.width,setBgSize.height))
    self.UI.settingBg:addChild(self.UI.backBtn)

    --绑定监听
    singleManagerUI:getInstance():bindListener(self.UI.colorLayer, self, "colorLayer")
    singleManagerUI:getInstance():bindListener(self.UI.backBtn, self, "backBtn")
    singleManagerUI:getInstance():bindListener(self.UI.musicCheckBox, self, "musicCheckBox")
    singleManagerUI:getInstance():bindListener(self.UI.effectCheckBox, self, "effectCheckBox")
    singleManagerUI:getInstance():bindListener(self.UI.languageBtn, self, "languageBtn")
end

function startUI:musicCheckBoxTouchEnded()
    print("*****************")
    print(self.UI.musicCheckBox:isSelected())
end

--删除灰色层
function startUI:removeColorLayer()
    cs.logger.i("removeColorLayer")
    if self.UI.colorLayer ~= nil then
        self.UI.colorLayer:removeFromParent()
        self.UI.drawNode = nil
    end
end

--按钮监听事件函数
function startUI:bgSpTouchBegan()
    print("bgSpTouchBegan")
    --self.UI.bgSp:setGLProgram(self.ShaderManager:getShader(self.ShaderManager.ShaderType.HIGHTLIGHT))
    --self.UI.bgSp:setGLProgram(self.ShaderManager:getShader(self.ShaderManager.ShaderType.COFFEE))
    self.UI.bgSp:setGLProgram(self.ShaderManager:getShader(self.ShaderManager.ShaderType.GRAY))
end

function startUI:bgSpTouchEnd()

end

function startUI:startBtnTouchEnded()
	cs.logger.i("startBtnTouchEnded")
	--进入选关界面
    local mapUI = require("gameUI.mapUI"):create()
    singleManagerUI:getInstance():changeUI({} , mapUI , CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

function startUI:clearBtnTouchEnded()
    singleUIData:getInstance():_setNewPlayerData()
end

function startUI:settingBtnTouchEnded()
    cs.logger.i("settingBtnTouchEnded") 
    self:addColorLayer()
end

function startUI:backBtnTouchEnded()
    cs.logger.i("backBtnTouchEnded")
    self:removeColorLayer()
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