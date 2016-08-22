local battleUI = class("battleUI", function() return cc.Layer:create() end)

--初始化函数
function battleUI:ctor()
	--初始化监听、数据
	cs.logger.i("battleUI:ctor()")

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

    --添加关卡按钮
    self.UI.missionBtn = {}
    self.UI.missionPic = {"UI/denglu/ui_selectflag_1.png", "UI/denglu/ui_selectflag.png"}
    self.UI.missionBtnState = {1, 2}  --1表示未成功挑战过，2表示成功挑战过
    self.UI.missionBtnPlace = { {300, 800},
                                {200, 600}
                              }
    for i=1,2 do
        self.UI.missionBtn[i] = ccui.Button:create(self.UI.missionPic[self.UI.missionBtnState[i]])
        self.UI.missionBtn[i]:setPosition(cc.p(self.UI.missionBtnPlace[i][1],self.UI.missionBtnPlace[i][2]))
        self:addChild(self.UI.missionBtn[i])

        self["missionBtn" ..i .."TouchEnded"] = function ()
            cs.logger.i("missionBtn"..i.."TouchEnded")
            --进入战斗界面
            local fightMainScene = require("gameFight.fightMainScene"):create()
            singleManagerUI:getInstance():changeUI({} , fightMainScene , CC_UI_GOTO_TPYE.UI_Rep_Scene)
        end

        singleManagerUI:getInstance():bindListener(self.UI.missionBtn[i],self,"missionBtn"..i)
    end
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