local fightMainUI = class("fightMainUI", function() return cc.Layer:create() end)

function fightMainUI:ctor()
    --初始化监听数据，初始化数据
    self.UI = {}
    self:createUI()
 
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_MainUIDataChange, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_LifeDie, self)  
end

function fightMainUI:createUI()
    --加入生命
    self.UI.lifeSp = cc.Sprite:create("UI/battle/img/life_bar.png")
    self.UI.lifeSp:setAnchorPoint(cc.p(1,1))
    self.UI.lifeSp:setPosition(cc.p( display.size.width * 0.86 ,display.size.height* 0.99))
    self:addChild(self.UI.lifeSp )

    self.UI.lifeHeard = cc.Sprite:create("UI/battle/img/life.png")
    self.UI.lifeHeard:setAnchorPoint(cc.p(0.5,0.15))
    self.UI.lifeHeard:setPosition(cc.p(0,0))
    self.UI.lifeSp:addChild(self.UI.lifeHeard )

    self.UI.lifeLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 25)  
    self.UI.lifeLabel:setAnchorPoint(cc.p(0.5,0.5))
    local lifeSpSize = self.UI.lifeSp:getContentSize()
    self.UI.lifeLabel:setPosition(cc.p( lifeSpSize.width/2 + 10,lifeSpSize.height/2))
    self.UI.lifeSp:addChild(self.UI.lifeLabel )

    --创建金币图片
    self.UI.goldSp = cc.Sprite:create("UI/battle/img/gold_bar.png")
    self.UI.goldSp:setAnchorPoint(cc.p(0.5,1))
    self.UI.goldSp:setPosition(cc.p( display.size.width * 0.57 ,display.size.height* 0.99))
    self:addChild(self.UI.goldSp )

    self.UI.goldMo = cc.Sprite:create("UI/battle/img/gold.png")
    self.UI.goldMo:setAnchorPoint(cc.p(0.5,0.15))
    self.UI.goldMo:setPosition(cc.p(0,0))
    self.UI.goldSp:addChild(self.UI.goldMo )

    self.UI.goldLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 25)  
    self.UI.goldLabel:setAnchorPoint(cc.p(0.5,0.5))
    local goldSpSize = self.UI.goldSp:getContentSize()
    self.UI.goldLabel:setPosition(cc.p( goldSpSize.width/2 + 10,goldSpSize.height/2))
    self.UI.goldSp:addChild(self.UI.goldLabel )

    --创建过关条件进度条
    self.UI.progressbarbg = cc.Sprite:create("UI/battle/img/progressbar_bg.png")
    self.UI.progressbarbg:setPosition(cc.p(display.size.width * 0.02, display.size.height*0.99)) 
    self.UI.progressbarbg:setAnchorPoint(cc.p(0,1)) 
    self:addChild(self.UI.progressbarbg,30)
    --
    self.UI.progressbarLeft = cc.ProgressTimer:create(cc.Sprite:create("UI/battle/img/progressbar.png"))  
    self.UI.progressbarLeft:setAnchorPoint(cc.p(0.5,0.5)) 
    self.UI.progressbarLeft:setType(cc.PROGRESS_TIMER_TYPE_BAR)
    self.UI.progressbarLeft:setMidpoint(cc.p(0, 0)) 
    -- 设置横向进度条变化率，y=0意味着没有竖向的变化   
    self.UI.progressbarLeft:setBarChangeRate(cc.p(1, 0))
    local progressbarSpSize = self.UI.progressbarbg:getContentSize()  
    self.UI.progressbarLeft:setPosition(cc.p(progressbarSpSize.width/2, progressbarSpSize.height/2)) 
    self.UI.progressbarbg:addChild(self.UI.progressbarLeft,31)

    self.UI.progressbarHead = cc.Sprite:create("UI/battle/img/head.png")
    self.UI.progressbarHead:setAnchorPoint(cc.p(0.2,0.15))
    self.UI.progressbarHead:setPosition(cc.p(0,0))
    self.UI.progressbarbg:addChild(self.UI.progressbarHead, 32)

    self.UI.progressbarText = cc.LabelTTF:create("0%", "ttf/fangzhenglier.ttf", 25)  
    self.UI.progressbarText:setAnchorPoint(cc.p(1,0.5))
    self.UI.progressbarText:setPosition(cc.p( progressbarSpSize.width - 15,progressbarSpSize.height/2))
    self.UI.progressbarbg:addChild(self.UI.progressbarText,33)

    --self.m_LoadingLayer:addChild(self.progressbarLeft,31)

    --[[self.UI.waveSp = cc.Sprite:create("plist/fight/wave.png")
    self.UI.waveSp:setAnchorPoint(cc.p(0,1))
    self.UI.waveSp:setScale(0.5)
    self.UI.waveSp:setPosition(cc.p(display.size.width * 0.55,display.size.height))
    self:addChild(self.UI.waveSp )

    self.UI.waveLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 50)  
    self.UI.waveLabel:setAnchorPoint(cc.p(0,0))
    self.UI.waveLabel:setPosition(cc.p( 130,15))
    self.UI.waveSp:addChild(self.UI.waveLabel)
]]

    --加入连击字体
    self.UI.labelBmFont = cc.LabelBMFont:create(" ", "ttf/TxtNumber_20.fnt")
    self.UI.labelBmFont:setScale(1.8)
    self.UI.labelBmFont:setAnchorPoint(cc.p(0.5,1))
    self.UI.labelBmFont:setPosition(ccp(display.size.width/2 , display.size.height*0.96))
    self.doubleHitNum = 0
    self:addChild(self.UI.labelBmFont)

    --加入技能按钮
    self.UI.skillBtn = ccui.Button:create("UI/battle/img/button_bg.png")
    self.UI.skillBtn:setAnchorPoint(cc.p(0.5,0))
    self.UI.skillBtn:setPosition(cc.p(display.size.width/2,0))
    self:addChild(self.UI.skillBtn)

    local skillBtnSize = self.UI.skillBtn:getContentSize()  
    self.UI.skillSp = cc.Sprite:create("UI/battle/img/bomb_button.png")
    self.UI.skillSp:setAnchorPoint(cc.p(0.5,0.5))
    self.UI.skillSp:setPosition(cc.p(display.size.width/2,skillBtnSize.height/2-5))
    self:addChild(self.UI.skillSp)

    local skillSpSize = self.UI.skillSp:getContentSize() 
    self.UI.skillIcon = cc.Sprite:create("UI/battle/img/bomb.png")
    self.UI.skillIcon:setAnchorPoint(cc.p(0.5,0.5))
    self.UI.skillIcon:setPosition(cc.p(skillSpSize.width/4,skillSpSize.height/2))
    self.UI.skillSp:addChild(self.UI.skillIcon)

    self.UI.skillFont = cc.LabelBMFont:create("5", "ttf/TxtNumber_20.fnt")
    self.UI.skillFont:setScale(1.5)
    self.UI.skillFont:setAnchorPoint(cc.p(0,0.5))
    self.UI.skillFont:setPosition(cc.p(skillSpSize.width/2 + 5,skillSpSize.height/2))
    self.UI.skillSp:addChild(self.UI.skillFont)

    --加入暂停按钮
    self.UI.pauseBtn = ccui.Button:create("UI/battle/img/Pause_bg.png")
    self.UI.pauseBtn:setAnchorPoint(cc.p(1,1))
    self.UI.pauseBtn:setPosition(cc.p(display.size.width*0.99,display.size.height))
    self:addChild(self.UI.pauseBtn)

    self.UI.pauseSp = cc.Sprite:create("UI/battle/img/Pause.png")
    self.UI.pauseSp:setAnchorPoint(cc.p(0.5,0.5))
    local pauseBtnSize = self.UI.pauseBtn:getContentSize()  
    self.UI.pauseSp:setPosition(cc.p(display.size.width*0.99 - pauseBtnSize.width/2,display.size.height-pauseBtnSize.height/2))
    self:addChild(self.UI.pauseSp)
end

--该函数需要在setData完成后调用，生成界面
function fightMainUI:refreshUI()
    --创建生命图片
    local stageData = singleGameData:getInstance():getStageData()
    self.UI.lifeLabel:setString(""..stageData.life)
    self.UI.goldLabel:setString(""..stageData.gold)
    --self.UI.waveLabel:setString(""..stageData.wave.."/"..stageData.waveLimit)

    --local toMove = cc.MoveBy:create(0.3,cc.p(self.progressbarLeft:getContentSize().width/allID,0))
    --self.manGo:runAction(toMove) 
end

--连击处理
function fightMainUI:doubleHit()
    self.doubleHitNum = self.doubleHitNum + 1
    self.UI.labelBmFont:setScale(1.8)
    self.UI.labelBmFont:setOpacity(255)
    self.UI.labelBmFont:stopAllActions()

    self.UI.labelBmFont:setString(""..self.doubleHitNum)
    --加入动画
    local doScaleMax = cc.ScaleTo:create(0.15,2.2)
    local doScaleMin = cc.ScaleTo:create(2.85,1)
    local bAction1 = cc.Spawn:create(doScaleMin,cc.FadeOut:create(2.75)) 
    local bAction2 = cc.Sequence:create(doScaleMax, bAction1, cc.CallFunc:create(function ()
                            self.doubleHitNum = 0
                        end)) 
    self.UI.labelBmFont:runAction(bAction2)
end

function fightMainUI:eventResponse(gameEventID, eventSender, parameter)
    --请求波次
    if gameEventID == CC_GAME_EVENT.GameEvent_MainUIDataChange then
        --开始进行波次的等待时间
        self:refreshUI()

        --波次临时代码，日后修改 by youwei
        if parameter ~= nil then
            local stageData = singleGameData:getInstance():getStageData()
            self.UI.progressbarLeft:runAction(cc.ProgressTo:create(0.7, stageData.wave*100/stageData.waveLimit)) 

            self.UI.progressbarText:setString(""..stageData.wave*100/stageData.waveLimit.."%")
        end
    elseif gameEventID == CC_GAME_EVENT.GameEvent_LifeDie then
        if parameter ~= nil then
            local stageData = singleGameData:getInstance():getStageData()
            stageData.gold = stageData.gold + parameter.gold
            self:refreshUI()
            self:doubleHit()
        end
    end
end

return fightMainUI