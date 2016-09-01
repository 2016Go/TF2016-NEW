local mapUI = class("mapUI" , function() return cc.Layer:create() end)

--初始化函数
function mapUI:ctor()
	--初始化监听器，初始化数据
	cs.logger.i("mapUI:ctor()")

	self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))

	self.UI = {}

	--用于存放所有的称号
	self.UI.LabelBtn = {}

    --成就层、战斗层、升级层
    self.UI.battleLayer = require("gameUI.battleUI"):create()

    --添加翻页容器
    self.UI.pageView = ccui.PageView:create()
    self.UI.pageView:setTouchEnabled(true)
    self.UI.pageView:setContentSize(cc.size(display.width,display.height))
    self.UI.pageView:setAnchorPoint(cc.p(0.5,0.5))
    self.UI.pageView:setPosition(cc.p(display.cx,display.cy))
    self:addChild(self.UI.pageView)
    
    --成就页
    self.UI.achievementLayout = ccui.Layout:create()
    self.UI.achievementLayout:setBackGroundColorType(ccui.LayoutBackGroundColorType.solid)
    self.UI.achievementLayout:setBackGroundColor(cc.c3b(255,255,0))
    self.UI.achievementLayout:setContentSize(self.UI.pageView:getContentSize())
    self.UI.pageView:addPage(self.UI.achievementLayout)
    --战斗地图页
    self.UI.battleLayout = ccui.Layout:create()
    self.UI.battleLayout:setContentSize(cc.size(self.UI.pageView:getContentSize().width,self.UI.battleLayer.UI.bgSp:getContentSize().height))
    self.UI.battleLayout:addChild(self.UI.battleLayer)
    self.UI.pageView:addPage(self.UI.battleLayout)
    --升级页
    self.UI.upgradeLayout = ccui.Layout:create()
    self.UI.upgradeLayout:setBackGroundColorType(ccui.LayoutBackGroundColorType.solid)
    self.UI.upgradeLayout:setBackGroundColor(cc.c3b(0,255,255))
    self.UI.upgradeLayout:setContentSize(self.UI.pageView:getContentSize())
    self.UI.pageView:addPage(self.UI.upgradeLayout)

    --添加按钮层
    self.UI.btnLayer = cc.Layer:create()
    self:addChild(self.UI.btnLayer)

	--添加返回按钮
	self.UI.backBtn = ccui.Button:create("UI/homePage/back.png")
    self.UI.backBtn:setPosition(cc.p(50, display.height - 50))
    self.UI.btnLayer:addChild(self.UI.backBtn)

    --添加金币文本 
    self.UI.goldText = ccui.Button:create("UI/homePage/progressbar_bg.png","UI/homePage/progressbar_bg.png")
    self.UI.goldText:setPosition(cc.p(540, display.height - 50))
    self.UI.goldText:setColor(cc.c3b(255, 255, 255))
    self.UI.goldText:setTitleFontSize(25)
    self.UI.goldText:setTitleText(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_Wallet])
    self.UI.btnLayer:addChild(self.UI.goldText)
    --添加金币图标
    self.UI.goldPic = cc.Sprite:create("UI/homePage/gold.png")
    self.UI.goldPic:setPosition(cc.p(610, display.height - 50))
    self.UI.btnLayer:addChild(self.UI.goldPic)
    --添加商城按钮
    self.UI.shopBtn = ccui.Button:create("UI/homePage/buy.png")
    self.UI.shopBtn:setPosition(cc.p(460, display.height - 50))
    self.UI.btnLayer:addChild(self.UI.shopBtn)

    --添加称号文本
    self.UI.titleText = ccui.Button:create("UI/homePage/progressbar_bg.png","UI/homePage/progressbar_bg.png")
    self.UI.titleText:setPosition(cc.p(display.cx ,display.height - 50))
    self.UI.titleText:setTitleColor(cc.c3b(255, 255, 255))
    self.UI.titleText:setTitleFontSize(25)
    self.UI.titleText:setTitleText(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_Title])
    self.UI.btnLayer:addChild(self.UI.titleText)

    --添加称号图标
    self.UI.titlePic = ccui.ImageView:create("UI/homePage/honor.png")
    self.UI.titlePic:setPosition(cc.p(display.cx - 100, display.height - 50))
    self.UI.btnLayer:addChild(self.UI.titlePic)

    --绘制下方按钮底色
    self.UI.drawNode = cc.DrawNode:create()
    self.UI.drawNode:setPosition(cc.p(display.cx,0))
    self.UI.drawNode:drawSolidRect(cc.p(-100 ,0), cc.p(100 ,100), cc.c4f(0,0.4,0.6,1))
    self.UI.btnLayer:addChild(self.UI.drawNode)
    --按钮底色背景
    self.UI.btnBackBg = ccui.ImageView:create("UI/homePage/function_bg.png")
    self.UI.btnBackBg:setAnchorPoint(cc.p(0,0))
    self.UI.btnBackBg:setPosition(cc.p(0,0))
    self.UI.btnLayer:addChild(self.UI.btnBackBg)
    --模板
    self.UI.btnBackIn = cc.Sprite:create("UI/homePage/function_extrude_inside.png")
    local btnBackSize = self.UI.btnBackIn:getContentSize()
    --底板滑块
    self.UI.btnSlider = cc.Sprite:create("UI/homePage/function_extrude.png")
    --遮罩结点
    self.UI.clippingNode = cc.ClippingNode:create()
    self.UI.clippingNode:setPosition(cc.p(display.cx, 50))
    self.UI.clippingNode:setAlphaThreshold(0.05)
    self.UI.clippingNode:setStencil(self.UI.btnBackIn)
    self.UI.clippingNode:addChild(self.UI.btnSlider)
    self.UI.btnLayer:addChild(self.UI.clippingNode)

    --成就按钮
	self.UI.achievementBtn = ccui.Button:create("UI/homePage/achievement.png")
	self.UI.achievementBtn:setPosition(cc.p(display.left + 100,display.bottom + 58))
    self.UI.achievementBtn:setScale(0.7)
	self.UI.achievementBtn:setTitleFontSize(30)
    self.UI.achievementBtn:setTitleText("成就")
	self.UI.achievementBtn:setTitleColor(cc.c3b(255, 255, 255))
	self.UI.btnLayer:addChild(self.UI.achievementBtn)

    self.UI.achievementRender = self.UI.achievementBtn:getTitleRenderer()
    self.UI.achievementRender:setPositionY(-20)
    self.UI.achievementRender:setVisible(false)
    --战斗按钮
	self.UI.battleBtn = ccui.Button:create("UI/homePage/battle.png")
	self.UI.battleBtn:setPosition(cc.p(display.cx,display.bottom + 58))
    self.UI.battleBtn:setScale(0.7)
    self.UI.battleBtn:setTitleFontSize(30)
    self.UI.battleBtn:setTitleText("战斗")
    self.UI.battleBtn:setTitleColor(cc.c3b(255, 255, 255))
    self.UI.btnLayer:addChild(self.UI.battleBtn)

    self.UI.battleRender = self.UI.battleBtn:getTitleRenderer()
    self.UI.battleRender:setPositionY(-20)
    self.UI.battleRender:setVisible(false)
    --升级按钮
    self.UI.upgradeBtn = ccui.Button:create("UI/homePage/upgrade.png")
    self.UI.upgradeBtn:setPosition(cc.p(display.right - 100,display.bottom + 58))
    self.UI.upgradeBtn:setScale(0.7)
    self.UI.upgradeBtn:setTitleFontSize(30)
    self.UI.upgradeBtn:setTitleText("升级")
    self.UI.upgradeBtn:setTitleColor(cc.c3b(255, 255, 255))
    self.UI.btnLayer:addChild(self.UI.upgradeBtn)

    self.UI.upgradeRender = self.UI.upgradeBtn:getTitleRenderer()
    self.UI.upgradeRender:setPositionY(-20)
    self.UI.upgradeRender:setVisible(false)
    --添加按钮标志(小三角形)
    self.UI.leftTriangle = cc.Sprite:create("UI/homePage/function_triangle.png")
    self.UI.rightTriangle = cc.Sprite:create("UI/homePage/function_triangle.png")
    self.UI.triangleNode = cc.Node:create()
    self.UI.triangleNode:setPosition(self.UI.battleBtn:getPosition())
    self.UI.leftTriangle:setPosition(cc.p(-110 , 0))
    self.UI.rightTriangle:setPosition(cc.p(110 , 0))
    self.UI.triangleNode:addChild(self.UI.leftTriangle)
    self.UI.triangleNode:addChild(self.UI.rightTriangle)
    self.UI.rightTriangle:setScaleX(-1)
    self.UI.btnLayer:addChild(self.UI.triangleNode)
    
    --添加虚线标志
    self.UI.leftDashed = cc.Sprite:create("UI/homePage/function_line.png")
    self.UI.rightDashed = cc.Sprite:create("UI/homePage/function_line.png")
    self.UI.leftDashed:setPosition(cc.p(-128, -5))
    self.UI.rightDashed:setPosition(cc.p(128, -5))
    self.UI.triangleNode:addChild(self.UI.leftDashed)
    self.UI.triangleNode:addChild(self.UI.rightDashed)

    --初始化页面
    self:runAction(cc.CallFunc:create(function () self:battleBtnTouchEnded() end))
    --绑定事件
    singleManagerUI:getInstance():bindListener(self.UI.backBtn,self,"backBtn")
    singleManagerUI:getInstance():bindListener(self.UI.battleBtn,self,"battleBtn")
    singleManagerUI:getInstance():bindListener(self.UI.achievementBtn, self, "achievementBtn")
    singleManagerUI:getInstance():bindListener(self.UI.upgradeBtn, self, "upgradeBtn")
    singleManagerUI:getInstance():bindListener(self.UI.titleText,self,"titleText")
    singleManagerUI:getInstance():bindListener(self.UI.shopBtn, self, "shopBtn")
end

--添加一个灰色层
function mapUI:addColorLayer()
    cs.logger.i("addColorLayer*************************")
    --添加一个半透明的层并吞噬触摸
    self.UI.colorLayer = cc.LayerColor:create(cc.c4b(100,100,100,100))  
    self:addChild(self.UI.colorLayer)

    --添加返回地图层的返回按钮
    self.UI.backToMapBtn = ccui.Button:create("UI/homePage/back.png")  
    self.UI.backToMapBtn:setPosition(cc.p(50, display.height - 50))
    self.UI.colorLayer:addChild(self.UI.backToMapBtn)

    --显示选中的称号
    self.UI.titleShowLabel = ccui.Button:create("UI/denglu/aboutBtn.png")   
    self.UI.titleShowLabel:setTitleText("称号:"..self.UI.titleText:getTitleText())
    self.UI.titleShowLabel:setTitleColor(cc.c3b(0,0,0))
    self.UI.titleShowLabel:setTitleFontSize(40)
    self.UI.titleShowLabel:setPosition(cc.p(display.cx,display.top - 100))
    self.UI.colorLayer:addChild(self.UI.titleShowLabel)

    --绑定监听，颜色层绑定监听是防止监听向下传递
    singleManagerUI:getInstance():bindListener(self.UI.colorLayer, self, "colorLayer")
    singleManagerUI:getInstance():bindListener(self.UI.backToMapBtn, self, "backToMapBtn")

    --添加不同的称号按钮并添加监听
    for i = 1, 20 do  
        local title = cs.conf.a("title",i)
        if title == nil then
            return
        end

        self.UI.LabelBtn[i] = ccui.Button:create("UI/denglu/aboutBtn.png","UI/denglu/aboutBtn.png")
        self.UI.LabelBtn[i]:setTitleText(title["name"])
        self.UI.LabelBtn[i]:setTitleColor(cc.c3b(0,0,0))
        self.UI.LabelBtn[i]:setTitleFontSize(40)
        self.UI.LabelBtn[i]:setBright(true)
        self.UI.LabelBtn[i]:setPosition(cc.p(180 + (i + 1) % 2 * 300,1000 - math.floor((i + 1) / 2) *100))
        self.UI.colorLayer:addChild(self.UI.LabelBtn[i])
        
        self["LabelBtn"..i.."TouchEnded"] = function ()
            cs.logger.i("LabelBtn"..i.."TouchEnded")
            self.UI.titleShowLabel:setTitleText("称号:"..self.UI.LabelBtn[i]:getTitleText())
            self:showRect(self.UI.LabelBtn[i])
        end
        singleManagerUI:getInstance():bindListener(self.UI.LabelBtn[i], self, "LabelBtn"..i)
    end
end

--删除灰色层
function mapUI:removeColorLayer()
    cs.logger.i("removeColorLayer")
    if self.UI.colorLayer ~= nil then
        singleUIData:getInstance():setData(CC_UI_DATA_TPYE.UI_Title, string.sub(self.UI.titleShowLabel:getTitleText(),8))
        self.UI.colorLayer:removeFromParent()
        self.UI.drawNode = nil
    end
end

--更新下方按钮状态
function mapUI:refreshBtn(type)
    --初始化状态
    self.UI.achievementBtn:setScale(0.7)
    self.UI.battleBtn:setScale(0.7)
    self.UI.upgradeBtn:setScale(0.7)
    self.UI.achievementRender:setVisible(false)
    self.UI.battleRender:setVisible(false)
    self.UI.upgradeRender:setVisible(false)
    self.UI.achievementBtn:setPositionY(display.bottom + 58)
    self.UI.battleBtn:setPositionY(display.bottom + 58)
    self.UI.upgradeBtn:setPositionY(display.bottom + 58)
    --更新三角形位置以及按钮状态
    if type == 1 then
        self.UI.achievementBtn:setPositionY(display.bottom + 100)
        self.UI.achievementBtn:setScale(1)
        self.UI.achievementRender:setVisible(true)
        self.UI.leftTriangle:setVisible(false)
        self.UI.rightTriangle:setVisible(true)
        self.UI.leftDashed:setVisible(false)
        self.UI.rightDashed:setVisible(true)
        self.UI.triangleNode:setPositionX(self.UI.achievementBtn:getPositionX())
    elseif type == 2 then
        self.UI.battleBtn:setPositionY(display.bottom + 100)
        self.UI.battleBtn:setScale(1)
        self.UI.battleRender:setVisible(true)
        self.UI.leftTriangle:setVisible(true)
        self.UI.rightTriangle:setVisible(true)
        self.UI.leftDashed:setVisible(true)
        self.UI.rightDashed:setVisible(true)
        self.UI.triangleNode:setPositionX(self.UI.battleBtn:getPositionX())
    elseif type == 3 then
        self.UI.upgradeBtn:setPositionY(display.bottom + 100)
        self.UI.upgradeBtn:setScale(1)
        self.UI.upgradeRender:setVisible(true)
        self.UI.leftTriangle:setVisible(true)
        self.UI.rightTriangle:setVisible(false)
        self.UI.leftDashed:setVisible(true)
        self.UI.rightDashed:setVisible(false)
        self.UI.triangleNode:setPositionX(self.UI.upgradeBtn:getPositionX())
    end
    --三角形动作
    local move = cc.MoveBy:create(0.12,cc.p(6,0))
    local moveClone = move:clone()
    local leftSequence = cc.Sequence:create(move:reverse(),move,move:reverse(),move)
    local rightSequence = cc.Sequence:create(moveClone,moveClone:reverse(),moveClone,moveClone:reverse())
    self.UI.leftTriangle:runAction(leftSequence)
    self.UI.rightTriangle:runAction(rightSequence)
    --更新下方滑块状态
    local placeX = self.UI.triangleNode:getPositionX()
    local newPlace = self.UI.clippingNode:convertToNodeSpace(cc.p(placeX, 0))
    self.UI.btnSlider:runAction(cc.MoveTo:create(0.2,cc.p(newPlace.x, 0)))

end

--按钮选中显示边框
function mapUI:showRect(node)
    if self.UI.drawNode == nil then
        self.UI.drawNode = cc.DrawNode:create(2)
        self.UI.drawNode:setPosition(cc.p(0, 0))
        self.UI.colorLayer:addChild(self.UI.drawNode)
        cs.logger.i("drawnode is nil")
    end
    self.UI.drawNode:clear()

    local startPoint = cc.p(node:getBoundingBox().x,node:getBoundingBox().y)
    local endPoint = cc.p(node:getBoundingBox().x + node:getBoundingBox().width,node:getBoundingBox().y + node:getBoundingBox().height)
    local rectColor = cc.c4f(1, 0, 0, 1)
    self.UI.drawNode:drawRect(startPoint, endPoint, rectColor)
end

--按钮监听事件函数
function mapUI:refreshUI(event,eventSender,data)
    cs.logger.i("refreshUI")
    if event == CC_UI_DATA_TPYE.UI_Wallet then
        self.UI.goldText:setTitleText(data) 
    end
    if event == CC_UI_DATA_TPYE.UI_Title then
        self.UI.titleText:setTitleText(data)    
    end
end

function mapUI:shopBtnTouchEnded()
    cs.logger.i("shopBtnTouchEnded")
    singleUIData:getInstance():setData(CC_UI_DATA_TPYE.UI_Wallet, singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_Wallet] + 1 )
end

function mapUI:titleTextTouchEnded()
    cs.logger.i("titleTextTouchEnded")
    --显示所有称号
    self:addColorLayer()
end

function mapUI:backToMapBtnTouchEnded()
    cs.logger.i("backToMapBtnEnded")
    --返回地图层
    self:removeColorLayer()
end

function mapUI:backBtnTouchEnded()
	cs.logger.i("backBtnTouchEnded")
	--返回开始界面
    local startUI = require("gameUI.startUI"):create()
    singleManagerUI:getInstance():changeUI({} , startUI , CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

function mapUI:achievementBtnTouchEnded()
	cs.logger.i("achievementBtnTouchEnded")
    self.UI.triangleNode:setPosition(self.UI.achievementBtn:getPosition())
    self:refreshBtn(1)
    self.UI.pageView:scrollToPage(0)
end

function mapUI:battleBtnTouchEnded()
	cs.logger.i("battleBtnTouchEnded")
    self:refreshBtn(2)
    self.UI.pageView:scrollToPage(1)
end

function mapUI:upgradeBtnTouchEnded()
	cs.logger.i("upgradeBtnTouchEnded")
    self:refreshBtn(3)	
    self.UI.pageView:scrollToPage(2)
end

function mapUI:balanceLayerTouchEnded()
    cs.logger.i("balanceLayerTouchEnded")
    --返回地图界面
    local mapUI = require("gameUI.mapUI"):create()
    singleManagerUI:getInstance():changeUI({}, mapUI, CC_UI_GOTO_TPYE.UI_Rep_Scene) 
end

function mapUI:enter()
    cs.logger.i("enter****************")
    singleUIEvent:getInstance():addEventListenerInPool(CC_UI_DATA_TPYE.UI_Wallet, self)
    singleUIEvent:getInstance():addEventListenerInPool(CC_UI_DATA_TPYE.UI_Title, self)
end

function mapUI:enterTransitionFinish()
    cs.logger.i("enterTransitionFinish****************")
end

function mapUI:exit()
    cs.logger.i("exit*****************************")
    singleUIEvent:getInstance():removeEventListenerInPool(CC_UI_DATA_TPYE.UI_Wallet, self)
    singleUIEvent:getInstance():removeEventListenerInPool(CC_UI_DATA_TPYE.UI_Title, self)
end

function mapUI:exitTransitionStart()
    cs.logger.i("exitTransitionStart*****************************")
end

function mapUI:cleanup()
    cs.logger.i("cleanup*****************************")
end

return mapUI