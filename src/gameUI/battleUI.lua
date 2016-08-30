local battleUI = class("battleUI", function() return cc.Layer:create() end)

--初始化函数
function battleUI:ctor()
	--初始化监听、数据
	cs.logger.i("battleUI:ctor()")

	self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))
    self.UI = {}
     
    --载入shader
    self.ShaderManager = require("gameUI.gameUIBase.ShaderManager")
    self.ShaderManager:load()

    --用于存放地图触摸位置
    self.touchPlace = {["lastTouch"] = -1,["currentTouch"] = -1} 
	--加载一张背景图片
    self.UI.bgSp = ccui.ImageView:create("UI/denglu/map.jpg")
    self.UI.bgSp:setTouchEnabled(true)
	self.UI.bgSp:setAnchorPoint(cc.p(0,0))
    self:addChild(self.UI.bgSp)

    --获取最大关卡数
    self.UI.missionMaxNum = 0
    for i = 1 , 30 do
        local uiMapPos = cs.conf.a("uiMapPos",i)
        if uiMapPos == nil then
            break
        end
        self.UI.missionMaxNum = self.UI.missionMaxNum + 1
    end
    print(self.UI.missionNaxNum)

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

        self.UI.missionBtn[i] = ccui.Button:create(clearPng,clearPng)
        self.UI.missionBtn[i]:setPosition(cc.p(placeX,placeY))

        self.UI.bgSp:addChild(self.UI.missionBtn[i])

        --初始化按钮纹理
        if i > tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum]) + 1 then
            self.UI.missionBtn[i]:setVisible(false)
        elseif i == tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum]) + 1 then
            self.UI.missionBtn[i]:loadTextureNormal(unClearPng)
            self.UI.missionBtn[i]:loadTexturePressed(unClearPng)
        else
            local width = self.UI.missionBtn[i]:getContentSize().width
            local height = self.UI.missionBtn[i]:getContentSize().height
            local missionLabel = cc.Label:createWithSystemFont(missionNum,"Arial",30)
            missionLabel:setPosition(cc.p(width/2, height/2 + 30))
            self.UI.missionBtn[i]:loadTextureNormal(clearPng)
            self.UI.missionBtn[i]:loadTexturePressed(clearPng)
            self.UI.missionBtn[i]:addChild(missionLabel)
        end

        --事件监听
        self["missionBtn" ..i .."TouchBegan"] = function ()
            cs.logger.i("missionBtn" ..i .."TouchBegan")
            self.UI.missionBtn[i]:setColor(cc.c3b(255, 240, 240))
            if i <= tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum]) then
                self.UI.highLightSp = cc.Sprite:create(clearPng)
                self.UI.highLabel = cc.Label:createWithSystemFont(missionNum,"Arial",30)
                local width = self.UI.highLightSp:getContentSize().width
                local height = self.UI.highLightSp:getContentSize().height
                self.UI.highLabel:setPosition(cc.p(width/2, height/2 + 30))
                self.UI.highLightSp:addChild(self.UI.highLabel)
            else
                self.UI.highLightSp = cc.Sprite:create(unClearPng)
            end
            self.UI.bgSp:addChild(self.UI.highLightSp)
            self.UI.highLightSp:setPosition(self.UI.missionBtn[i]:getPosition())
            self.UI.highLightSp:setGLProgram(self.ShaderManager:getShader(self.ShaderManager.ShaderType.HIGHTLIGHT))
        end

        self["missionBtn" ..i .."TouchMoved"] = function ()
            cs.logger.i("missionBtn" ..i .."TouchMoved")
            
            local movePos = self.UI.missionBtn[i]:convertToNodeSpace(self.UI.missionBtn[i]:getTouchMovePosition())
            local btnSize = self.UI.missionBtn[i]:getContentSize()
            local rect = cc.rect(0,0,btnSize.width,btnSize.height)
            if not cc.rectContainsPoint(rect,movePos) then
                if self.UI.highLightSp ~= nil then
                    self.UI.highLightSp:removeFromParent()
                    self.UI.highLightSp = nil
                end
            end
        end

        self["missionBtn" ..i .."TouchEnded"] = function ()
            cs.logger.i("missionBtn"..i.."TouchEnded")
           
            if self.UI.highLightSp ~= nil then
                self.UI.highLightSp:removeFromParent()
                self.UI.highLightSp = nil
            end
            --进入战斗界面
            --self.UI.missionBtn[i]:setOpacity(255)
            local fightMainScene = require("gameFight.fightMainScene"):create()
            singleManagerUI:getInstance():changeUI({} , fightMainScene , CC_UI_GOTO_TPYE.UI_Rep_Scene)
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

--旗帜动画
function battleUI:flagAnimate() 
    --获取最大通关数
    local currentMission = tonumber(singleUIData:getInstance()[CC_UI_DATA_TPYE.UI_MissionNum])
    --如果为当前最大通关数，先缩小按钮
    if currentMission < self.UI.missionMaxNum then
        self.UI.missionBtn[currentMission + 1]:setScale(0)
    end
    --地图动作
    local placeX,placeY = 0,0

    if currentMission > 0 and currentMission < self.UI.missionMaxNum then
       placeX = display.width/2 - self.UI.missionBtn[currentMission + 1]:getPositionX()
       placeY = display.height/2 - self.UI.missionBtn[currentMission + 1]:getPositionY()
    end
    --防止地图越界
    
    local width = self.UI.bgSp:getContentSize().width
    local height = self.UI.bgSp:getContentSize().height

    if placeX > 0 then
        placeX = 0
    elseif placeX + width < display.width then
        placeX = display.width - width
    end
    if placeY > 0 then
       placeY = 0
    elseif placeY + height < display.height then
       placeY = display.height - height
    end
    
    local mapMove = cc.MoveTo:create(1,cc.p(placeX,placeY))
    --按钮动作
    local mapCallfunc = cc.CallFunc:create(function ()
        local flagScaleBig = cc.ScaleTo:create(0.4, 1.2)
        local flagScaleSmall = cc.ScaleTo:create(0.2, 1)
        local flagSequence = cc.Sequence:create(flagScaleBig,flagScaleSmall)
        self.UI.missionBtn[currentMission + 1]:runAction(flagSequence)
    end)
    --判断是否执行地图动作
    if currentMission == 0 then
        self.UI.bgSp:runAction(mapCallfunc)
    elseif currentMission > 0 and currentMission < self.UI.missionMaxNum then
        self.UI.bgSp:runAction(cc.Sequence:create(mapMove,mapCallfunc))
    end
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
    
    --地图更新起始位置
    if currentMission == 0 then
        currentMission = 1
    elseif currentMission >= self.UI.missionMaxNum then
        currentMission = self.UI.missionMaxNum
    end
    local newPlaceX = display.width/2 - self.UI.missionBtn[currentMission]:getPositionX()
    local newPlaceY = display.height/2 - self.UI.missionBtn[currentMission]:getPositionY()
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

    --地图移动动画
    self:flagAnimate()
end

--地图移动
function battleUI:mapMove(lastPoint,currentPoint)
    print('battleUI:mapMove-----------------')
    local width = self.UI.bgSp:getContentSize().width
    local height = self.UI.bgSp:getContentSize().height
    local currentPlaceX = self.UI.bgSp:getPositionX()
    local currentPlaceY = self.UI.bgSp:getPositionY()
    local vectorX = currentPoint.x - lastPoint.x
    local vectorY = currentPoint.y - lastPoint.y
    currentPlaceX = currentPlaceX + vectorX
    currentPlaceY = currentPlaceY + vectorY

    --判断地图越界
    if currentPlaceX > 0 then
        currentPlaceX = 0
    elseif currentPlaceX + width < display.width then
        currentPlaceX = display.width - width
    end
    if currentPlaceY > 0 then
        currentPlaceY = 0
    elseif currentPlaceY + height < display.height then
        currentPlaceY = display.height - height
    end    

    self.UI.bgSp:setPosition(cc.p(currentPlaceX,currentPlaceY))
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