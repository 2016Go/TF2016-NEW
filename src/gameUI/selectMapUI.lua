local selectMapUI = class("selectMapUI", function() return cc.Layer:create() end)

--初始化函数
function selectMapUI:ctor()
	--初始化监听数据，初始化数据
	cs.logger.i("selectMapUI:ctor()")

	self:setAnchorPoint(cc.p(0,0))
	self:setPosition(cc.p(0,0))

	self.UI = {}
    
    --加载背景图片
    self.UI.bgSp = cc.Sprite:create("UI/denglu/bgPic.jpg")
    self.UI.bgSp:setAnchorPoint(cc.p(0,0))
    self.UI.bgSp:setPosition(cc.p(0,0))

    --获取背景图的大小
    local bgSize = self.UI.bgSp:getContentSize()

    --扩展图片到屏幕大小 
    self.UI.bgSp:setScaleX(display.width/bgSize.width)
    self.UI.bgSp:setScaleY(display.height/bgSize.height)
    self:add(self.UI.bgSp)
    
    --添加关卡按钮及标签
    self.UI.missionBtn = {}
    self.UI.missionLabel = {}


    for i=1,3 do
    	--关卡按钮
    	self.UI.missionBtn[i] = ccui.Button:create("UI/denglu/cloud.png")
    	self.UI.missionBtn[i]:setPosition(cc.p(180 * i - 40,1000 - 200 * i))
        self.UI.missionBtn[i]:setScale(0.5)
    	self:add(self.UI.missionBtn[i])
    	--关卡文本
    	self.UI.missionLabel[i] = cc.LabelTTF:create("第" ..i .."关", "Arial", 40)
    	self.UI.missionLabel[i]:setPositionX(self.UI.missionBtn[i]:getPositionX())
    	self.UI.missionLabel[i]:setPositionY(self.UI.missionBtn[i]:getPositionY() + 100)
        self.UI.missionLabel[i]:setColor(cc.c3b(100,100,100))
        self:add(self.UI.missionLabel[i])

        --关卡按钮绑定函数
        self["missionBtn"..i.."TouchEnded"] = function ()
            cs.logger.i("missionBtn" ..i .."TouchEnded")

            --进入战斗界面
            local fightMainScene = require("gameFight.fightMainScene"):create()
            singleManagerUI:getInstance():changeUI({} , fightMainScene , CC_UI_GOTO_TPYE.UI_Rep_Scene)
        end
        --绑定事件
        singleManagerUI:getInstance():bindListener(self.UI.missionBtn[i],self,"missionBtn"..i)
      
    end  
end

function selectMapUI:enter()
    cs.logger.i("enter****************")
end

function selectMapUI:enterTransitionFinish()
    cs.logger.i("enterTransitionFinish****************")
end

function selectMapUI:exit()
    cs.logger.i("exit*****************************")
end

function selectMapUI:exitTransitionStart()
    cs.logger.i("exitTransitionStart*****************************")
end

function selectMapUI:cleanup()
    cs.logger.i("cleanup*****************************")
end

return selectMapUI