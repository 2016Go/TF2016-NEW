local fightMainUI = class("fightMainUI", function() return cc.Layer:create() end)

function fightMainUI:ctor()
    --初始化监听数据，初始化数据
    self.UI = {}
    self:createUI()

    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_MainUIDataChange, self)
end

function fightMainUI:createUI()
    self.UI.lifeSp = cc.Sprite:create("plist/fight/life.png")
    self.UI.lifeSp:setAnchorPoint(cc.p(0,1))
    self.UI.lifeSp:setScale(0.5)
    self.UI.lifeSp:setPosition(cc.p( display.size.width * 0.05 ,display.size.height))
    self:addChild(self.UI.lifeSp )

    self.UI.lifeLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 50)  
    self.UI.lifeLabel:setAnchorPoint(cc.p(0,0))
    self.UI.lifeLabel:setPosition(cc.p( 130,15))
    self.UI.lifeSp:addChild(self.UI.lifeLabel )

    --创建金币图片
    self.UI.goldSp = cc.Sprite:create("plist/fight/gold.png")
    self.UI.goldSp:setAnchorPoint(cc.p(0,1))
    self.UI.goldSp:setPosition(cc.p(display.size.width * 0.30,display.size.height))
    self.UI.goldSp:setScale(0.5)
    self:addChild(self.UI.goldSp )

    self.UI.goldLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 50)  
    self.UI.goldLabel:setAnchorPoint(cc.p(0,0))
    self.UI.goldLabel:setPosition(cc.p( 130,15))
    self.UI.goldSp:addChild(self.UI.goldLabel )

    --创建波次
    self.UI.waveSp = cc.Sprite:create("plist/fight/wave.png")
    self.UI.waveSp:setAnchorPoint(cc.p(0,1))
    self.UI.waveSp:setScale(0.5)
    self.UI.waveSp:setPosition(cc.p(display.size.width * 0.55,display.size.height))
    self:addChild(self.UI.waveSp )

    self.UI.waveLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 50)  
    self.UI.waveLabel:setAnchorPoint(cc.p(0,0))
    self.UI.waveLabel:setPosition(cc.p( 130,15))
    self.UI.waveSp:addChild(self.UI.waveLabel)
end

--该函数需要在setData完成后调用，生成界面
function fightMainUI:refreshUI()
    --创建生命图片
    local stageData = singleGameData:getInstance():getStageData()
    self.UI.lifeLabel:setString(""..stageData.life)
    self.UI.goldLabel:setString(""..stageData.gold)
    self.UI.waveLabel:setString(""..stageData.wave.."/"..stageData.waveLimit)
end

function fightMainUI:eventResponse(gameEventID, eventSender, parameter)
    --请求波次
    if gameEventID == CC_GAME_EVENT.GameEvent_MainUIDataChange then
        --开始进行波次的等待时间
        self:refreshUI()
    else
        cs.logger.i("this is a meng B msg")
    end
end

return fightMainUI