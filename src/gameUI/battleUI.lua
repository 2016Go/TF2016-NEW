local battleUI = class("battleUI", function() return cc.Layer:create() end)

--初始化函数
function battleUI:ctor()
	--初始化监听、数据
	cs.logger.i("battleUI:ctor()")

	self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))
    self.UI = {}

    --用于存放地图触摸位置
    self.touchPlace = {["lastTouch"] = -1,["currentTouch"] = -1} 
	--加载一张背景图片
    self.UI.bgSp = ccui.ImageView:create("UI/denglu/map.jpg")
    self.UI.bgSp:setTouchEnabled(true)
	self.UI.bgSp:setAnchorPoint(cc.p(0,0))
    self:addChild(self.UI.bgSp)
  
    --测试
    self.UI.sprite1 = cc.Sprite:create("UI/denglu/cannon.png")
    self.UI.bgSp:addChild(self.UI.sprite1)
    self.UI.sprite1:setPosition(cc.p(300,800))
    self.UI.sprite1:runAction(cc.TintTo:create(0, 150, 150, 150))

    self.UI.sprite2 = cc.Sprite:create("UI/denglu/cannon.png")
    self.UI.bgSp:addChild(self.UI.sprite2)
    self.UI.sprite2:setPosition(cc.p(400,800))

    self.UI.sprite3 = cc.Sprite:create("UI/denglu/cannon.png")
    self.UI.bgSp:addChild(self.UI.sprite3)
    self.UI.sprite3:setPosition(cc.p(500,800))
    self.UI.sprite3:setOpacity(200)

    --获取最大关卡数
    self.UI.missionMaxNum = 0
    for i = 1 , 30 do
        local uiMapPos = cs.conf.a("uiMapPos",i)
        if uiMapPos == nil then
            break
        end
        self.UI.missionMaxNum = self.UI.missionMaxNum + 1
    end

     --添加关卡按钮
    self.UI.missionBtn = {}
    
    for i = 1 , self.UI.missionMaxNum do
        --读取conf文件
        local uiMapPos = cs.conf.a("uiMapPos",i)
        if uiMapPos == nil then
            break
        end
        --获取按钮信息
        local unClearPng = uiMapPos["unClearPng"]
        local clearPng = uiMapPos["clearPng"]
        local missionNum = uiMapPos["number"]
        local placeX = uiMapPos["pos"].x
        local placeY = uiMapPos["pos"].y

        self.UI.missionBtn[i] = ccui.Button:create(unClearPng)
        self.UI.missionBtn[i]:setPosition(cc.p(placeX,placeY))
        self.UI.missionBtn[i]:setTitleText(missionNum)
        self.UI.missionBtn[i]:setTitleFontSize(30)

        self.UI.bgSp:addChild(self.UI.missionBtn[i])
        
        --初始化按钮纹理
        if tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum]) == self.UI.missionMaxNum then
            self.UI.missionBtn[i]:loadTextureNormal(unClearPng)
        elseif i > tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum]) + 1 then
            self.UI.missionBtn[i]:setVisible(false)
        elseif i == tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum]) + 1 then
            self.UI.missionBtn[i]:loadTextureNormal(clearPng)
        end

        --事件监听
        self["missionBtn" ..i .."TouchBegan"] = function ()
            cs.logger.i("missionBtn" ..i .."TouchBegan")
            self.UI.missionBtn[i]:setOpacity(200)
        end

        self["missionBtn" ..i .."TouchEnded"] = function ()
            cs.logger.i("missionBtn"..i.."TouchEnded")
            --进入战斗界面
            self.UI.missionBtn[i]:setOpacity(255)
            local fightMainScene = require("gameFight.fightMainScene"):create()
            singleManagerUI:getInstance():changeUI({} , fightMainScene , CC_UI_GOTO_TPYE.UI_Rep_Scene)
        end

        self["missionBtn" ..i .."TouchCanceled"] = function ()
            cs.logger.i("missionBtn" ..i .."TouchCanceled")
            self.UI.missionBtn[i]:setOpacity(255)
        end

        singleManagerUI:getInstance():bindListener(self.UI.missionBtn[i],self,"missionBtn"..i)
    end
    
    self:mapInitPosition()
    --添加调试按钮
    self.UI.testButton = ccui.Button:create("UI/denglu/laser.png")
    self.UI.testButton:setPosition(cc.p(display.cx,display.bottom + 200))
    self:addChild(self.UI.testButton)
    singleManagerUI:getInstance():bindListener(self.UI.testButton, self, "testButton")

    --为地图添加监听
    singleManagerUI:getInstance():bindListener(self.UI.bgSp, self, "bgSp")
end

--通关
function battleUI:missionClear()
    --最大通关数加1
    singleUIData:getInstance():setData(CC_UI_DATA_TPYE.UI_MissionNum,singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum] + 1)

    local mapUI = require("gameUI.mapUI"):create()
    singleManagerUI:getInstance():changeUI({}, mapUI, CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

--地图初始位置
function battleUI:mapInitPosition()
    local currentMission = tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum])
    local newPlaceX,newPlaceY
    --地图跟新位置，使下一个挑战关按钮居中
    if currentMission > 1 and currentMission < self.UI.missionMaxNum then
        newPlaceX = display.width/2 - self.UI.missionBtn[currentMission + 1]:getPositionX()
        newPlaceY = display.height/2 - self.UI.missionBtn[currentMission + 1]:getPositionY()
    elseif currentMission == self.UI.missionMaxNum then
        newPlaceX = display.width/2 - self.UI.missionBtn[currentMission]:getPositionX()
        newPlaceY = display.height/2 - self.UI.missionBtn[currentMission]:getPositionY()
    else
        newPlaceX = display.width/2 - self.UI.missionBtn[1]:getPositionX()
        newPlaceY = display.height/2 - self.UI.missionBtn[1]:getPositionY()
    end
    self.UI.bgSp:setPosition(cc.p(newPlaceX,newPlaceY))
    
    --调整地图位置，防止越界
    local width = self.UI.bgSp:getContentSize().width
    local height = self.UI.bgSp:getContentSize().height

    if self.UI.bgSp:getPositionX() > 0 then
        self.UI.bgSp:setPositionX(0)
    elseif self.UI.bgSp:getPositionX() + width < display.width then
        self.UI.bgSp:setPositionX(display.width - width)
    end
    if self.UI.bgSp:getPositionY() > 0 then
        self.UI.bgSp:setPositionY(0)
    elseif self.UI.bgSp:getPositionY() + height < display.height then
        self.UI.bgSp:setPositionY(display.height - height)
    end
end

--地图移动
function battleUI:mapMove(lastPoint,currentPoint)
    local width = self.UI.bgSp:getContentSize().width
    local height = self.UI.bgSp:getContentSize().height
    local currentPlaceX = self.UI.bgSp:getPositionX()
    local currentPlaceY = self.UI.bgSp:getPositionY()
    local vectorX = currentPoint.x - lastPoint.x
    local vectorY = currentPoint.y - lastPoint.y
    currentPlaceX = currentPlaceX + vectorX
    currentPlaceY = currentPlaceY + vectorY
    self.UI.bgSp:setPosition(cc.p(currentPlaceX,currentPlaceY))
    if self.UI.bgSp:getPositionX() > 0 then
        self.UI.bgSp:setPositionX(0)
    elseif self.UI.bgSp:getPositionX() + width < display.width then
        self.UI.bgSp:setPositionX(display.width - width)
    end
    if self.UI.bgSp:getPositionY() > 0 then
        self.UI.bgSp:setPositionY(0)
    elseif self.UI.bgSp:getPositionY() + height < display.height then
        self.UI.bgSp:setPositionY(display.height - height)
    end
end

--事件函数
function battleUI:testButtonTouchEnded()
    cs.logger.i("testButtonTouchEnded")
    self:missionClear()
end

function battleUI:bgSpTouchBegan()
    cs.logger.i("bgSpTouchBegan************")
    self.touchPlace.lastTouch = self.UI.bgSp:getTouchBeganPosition()
end

function battleUI:bgSpTouchMoved()
    cs.logger.i("bgSpTouchMoved************")
    self.touchPlace.currentTouch = self.UI.bgSp:getTouchMovePosition()
    self:mapMove(self.touchPlace.lastTouch, self.touchPlace.currentTouch)
    self.touchPlace.lastTouch = self.touchPlace.currentTouch
end

function battleUI:enter()
    cs.logger.i("enter****************")
end

function battleUI:enterTransitionFinish()
    cs.logger.i("enterTransitionFinish****************")
end

function battleUI:exit()
    cs.logger.i("exit*****************************")
end

function battleUI:exitTransitionStart()
    cs.logger.i("exitTransitionStart*****************************")
end

function battleUI:cleanup()
    cs.logger.i("cleanup*****************************")
end

return battleUI