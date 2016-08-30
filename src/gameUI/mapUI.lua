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

    --添加底部层
    self.UI.bottomLayer = cc.Layer:create()
    self:addChild(self.UI.bottomLayer)
    self.UI.bottomLayer:addChild(require("gameUI.battleUI"):create())

    --添加按钮层
    self.UI.btnLayer = cc.Layer:create()
    self:addChild(self.UI.btnLayer)

	--添加返回按钮
	self.UI.backBtn = ccui.Button:create("UI/denglu/btn_back.png")
	self.UI.backBtn:setAnchorPoint(cc.p(0,1))
    self.UI.backBtn:setPosition(cc.p(0,display.height))
    self.UI.btnLayer:addChild(self.UI.backBtn)

    --添加金币图标
    self.UI.goldPic = cc.Sprite:create("UI/denglu/gold.png")
    self.UI.goldPic:setAnchorPoint(cc.p(1,1))
    self.UI.goldPic:setPosition(cc.p(display.width,display.height - 40))
    self.UI.btnLayer:addChild(self.UI.goldPic)
    --添加金币文本
    self.UI.goldLabel = cc.LabelTTF:create("12345", "Arial", 30)
    self.UI.goldLabel:setAnchorPoint(cc.p(0,1))
    self.UI.goldLabel:setPosition(cc.p(display.width - 120,display.height - 40))
    self.UI.goldLabel:setColor(cc.c3b(0,0,0))
    self.UI.goldLabel:setString(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_Wallet])
    self.UI.btnLayer:addChild(self.UI.goldLabel)
    --添加商城按钮
    self.UI.shopBtn = ccui.Button:create("UI/denglu/btn_shop.png")
    self.UI.shopBtn:setAnchorPoint(cc.p(0,1))
    self.UI.shopBtn:setScale(0.4)
    self.UI.shopBtn:setPosition(cc.p(display.width - 160,display.height - 35))
    self.UI.btnLayer:addChild(self.UI.shopBtn)
    --添加称号文本
    self.UI.titleLabel = cc.Label:createWithSystemFont("称号:音速小子", "Arial", 40)
    self.UI.titleLabel:setPosition(cc.p(display.cx ,display.height - 55))
    self.UI.titleLabel:setColor(cc.c3b(0, 0, 0))
    self.UI.titleLabel:setString("称号:"..singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_Title])
    self.UI.btnLayer:addChild(self.UI.titleLabel)
    
    --成就按钮
	self.UI.achievementBtn = ccui.Button:create("UI/denglu/selectBtn.png")
	self.UI.achievementBtn:setPosition(cc.p(display.left + 100,display.bottom + 50))
	self.UI.achievementBtn:setTitleText("成就")
	self.UI.achievementBtn:setTitleFontSize(45)
	self.UI.achievementBtn:setTitleColor(cc.c3b(0, 0, 0))
	self.UI.btnLayer:addChild(self.UI.achievementBtn)
    --战斗按钮
	self.UI.battleBtn = ccui.Button:create("UI/denglu/selectBtn.png")
	self.UI.battleBtn:setPosition(cc.p(display.cx,display.bottom + 50))
    self.UI.battleBtn:setTitleText("战斗")
    self.UI.battleBtn:setTitleFontSize(45)
    self.UI.battleBtn:setTitleColor(cc.c3b(0, 0, 0))
    self.UI.btnLayer:addChild(self.UI.battleBtn)
    --升级按钮
    self.UI.upgradeBtn = ccui.Button:create("UI/denglu/selectBtn.png")
    self.UI.upgradeBtn:setPosition(cc.p(display.right - 100,display.bottom + 50))
    self.UI.upgradeBtn:setTitleText("升级")
    self.UI.upgradeBtn:setTitleFontSize(45)
    self.UI.upgradeBtn:setTitleColor(cc.c3b(0, 0, 0))
    self.UI.btnLayer:addChild(self.UI.upgradeBtn)

    --添加按钮标志(小三角形)
    self.UI.leftTriangle = cc.Sprite:create("UI/denglu/triangle.png")
    self.UI.rightTriangle = cc.Sprite:create("UI/denglu/triangle.png")
    self.UI.triangleNode = cc.Node:create()
    self.UI.triangleNode:setPosition(self.UI.battleBtn:getPosition())
    self.UI.leftTriangle:setPosition(cc.p(-50 , 0))
    self.UI.rightTriangle:setPosition(cc.p(50 , 0))
    self.UI.triangleNode:addChild(self.UI.leftTriangle)
    self.UI.triangleNode:addChild(self.UI.rightTriangle)
    self.UI.leftTriangle:setRotation(90)
    self.UI.rightTriangle:setRotation(-90)
    self.UI.btnLayer:addChild(self.UI.triangleNode)

    --绑定事件
    singleManagerUI:getInstance():bindListener(self.UI.backBtn,self,"backBtn")
    singleManagerUI:getInstance():bindListener(self.UI.battleBtn,self,"battleBtn")
    singleManagerUI:getInstance():bindListener(self.UI.achievementBtn, self, "achievementBtn")
    singleManagerUI:getInstance():bindListener(self.UI.upgradeBtn, self, "upgradeBtn")
    singleManagerUI:getInstance():bindListener(self.UI.titleLabel, self, "titleLabel")
    singleManagerUI:getInstance():bindListener(self.UI.shopBtn, self, "shopBtn")
end

--添加一个灰色层
function mapUI:addColorLayer()
    cs.logger.i("addColorLayer*************************")
    --添加一个半透明的层并吞噬触摸
    self.UI.colorLayer = cc.LayerColor:create(cc.c4b(100,100,100,100))  
    self:addChild(self.UI.colorLayer)

    --添加返回地图层的返回按钮
    self.UI.backToMapBtn = ccui.Button:create("UI/denglu/btn_back.png")  
    self.UI.backToMapBtn:setAnchorPoint(cc.p(0,1))
    self.UI.backToMapBtn:setPosition(cc.p(0,display.height))
    self.UI.colorLayer:addChild(self.UI.backToMapBtn)

    --显示选中的称号
    self.UI.titleShowLabel = ccui.Button:create("UI/denglu/aboutBtn.png")   
    self.UI.titleShowLabel:setTitleText(self.UI.titleLabel:getString())
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
        local aaa = string.sub(self.UI.titleShowLabel:getTitleText(),8)
        print("************"..aaa)
        singleUIData:getInstance():setData(CC_UI_DATA_TPYE.UI_Title, string.sub(self.UI.titleShowLabel:getTitleText(),8))
        self.UI.colorLayer:removeFromParent()
        self.UI.drawNode = nil
    end
end

--更新三角形图标状态
function mapUI:refreshTriangle(type)
    if type == 1 then
        self.UI.leftTriangle:setVisible(false)
        self.UI.rightTriangle:setVisible(true)
        self.UI.triangleNode:setPosition(self.UI.achievementBtn:getPosition())
    elseif type == 2 then
        self.UI.leftTriangle:setVisible(true)
        self.UI.rightTriangle:setVisible(true)
        self.UI.triangleNode:setPosition(self.UI.battleBtn:getPosition())
    elseif type == 3 then
        self.UI.leftTriangle:setVisible(true)
        self.UI.rightTriangle:setVisible(false)
        self.UI.triangleNode:setPosition(self.UI.upgradeBtn:getPosition())
    end
end

--按钮选中显示边框
function mapUI:showRect(node)
    if self.UI.drawNode == nil then
        self.UI.drawNode = cc.DrawNode:create(2)
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
        self.UI.goldLabel:setString(data) 
    end
    if event == CC_UI_DATA_TPYE.UI_Title then
        self.UI.titleLabel:setString(data) 
        self.UI.titleLabel:setString("称号:"..self.UI.titleLabel:getString())     
    end
end

function mapUI:shopBtnTouchEnded()
    cs.logger.i("shopBtnTouchEnded")
    singleUIData:getInstance():setData(CC_UI_DATA_TPYE.UI_Wallet, singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_Wallet] + 1 )
end

function mapUI:titleLabelTouchEnded()
    cs.logger.i("titleLabelTouchEnded")
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
    self:refreshTriangle(1)
end

function mapUI:battleBtnTouchEnded()
	cs.logger.i("battleBtnTouchEnded")
    self:refreshTriangle(2)
end

function mapUI:upgradeBtnTouchEnded()
	cs.logger.i("upgradeBtnTouchEnded")
    self:refreshTriangle(3)	

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