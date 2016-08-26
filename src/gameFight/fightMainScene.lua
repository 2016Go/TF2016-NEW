--载入所有单键类
require("gameFight.singleUtil")
require("gameFight.singleStage")
require("gameFight.singleLoadData")
require("gameFight.data.singleGameData")
require("gameFight.manager.singleTimeManager")
require("gameFight.manager.singleWaveManager")
require("gameFight.manager.singleTrickManager")
require("gameFight.manager.singleEnemyManager")
require("gameFight.manager.singleTowerManager")
require("gameFight.manager.singleBulletManager")
require("gameFight.gameEvent.singleGameEventPool")
--结束单键类载入

local fightMainScene = class("fightMainScene", function() return cc.Layer:create() end)

function fightMainScene:ctor()

    --创建一个主层
    self.m_LoadingLayer = cc.Layer:create()
    self.m_LoadingLayer:setAnchorPoint(cc.p(0,0))
    self.m_LoadingLayer:setPosition(cc.p(0,0))
    self:addChild(self.m_LoadingLayer,20)

    --背景图片
    self.loadingSp = cc.Sprite:create("UI/loading/loading.png")
    self.loadingSp:setAnchorPoint(cc.p(0,0))
    self.loadingSp:setPosition(cc.p(0,0))
    self.m_LoadingLayer:addChild(self.loadingSp,10)

    --说明文字
    self.titleLabel = cc.Label:createWithSystemFont("Loding…………", "Arial", 50)
    self.titleLabel:setAnchorPoint(cc.p(0.5,1))
    self.titleLabel:setPosition(cc.p(display.width/2 , display.height - 50))
    self.titleLabel:setTextColor(cc.c4b(255, 255, 255 ,255))
    self.m_LoadingLayer:addChild(self.titleLabel,20)

    --小技巧
    self.titleLabel = cc.Label:createWithSystemFont("defense towers can be combined with each other", "Arial", 23)
    self.titleLabel:setAnchorPoint(cc.p(0.5,0))
    self.titleLabel:setPosition(cc.p(display.width/2 , 75))
    self.titleLabel:setTextColor(cc.c4b(255, 255, 255 ,255))
    self.m_LoadingLayer:addChild(self.titleLabel,20)

    --进度条背景
    self.progressbarbg = cc.Sprite:create("UI/loading/progressbar_bg.png")
    self.progressbarbg:setPosition(cc.p(display.width/2 , 130)) 
    self.progressbarbg:setAnchorPoint(cc.p(0.5,0.5)) 
    self.m_LoadingLayer:addChild(self.progressbarbg,30)
    --
    self.progressbarLeft = cc.ProgressTimer:create(cc.Sprite:create("UI/loading/progressbar.png"))  
    self.progressbarLeft:setType(cc.PROGRESS_TIMER_TYPE_BAR)
    self.progressbarLeft:setMidpoint(cc.p(0, 0)) 
    -- 设置横向进度条变化率，y=0意味着没有竖向的变化   
    self.progressbarLeft:setBarChangeRate(cc.p(1, 0))  
    self.progressbarLeft:setPosition(cc.p(display.width/2 , 130))  
    self.m_LoadingLayer:addChild(self.progressbarLeft,31)


    --载入所有的战斗plist
    local myUtil = singleUtil:getInstance()
    myUtil:addAllPlist()

    --加入一个角色移动
    self.manGo = cc.Sprite:create()
    local fristFrame , animation = singleUtil:getInstance():createFrameCache("goblin" ,"/walk/walk", 0.1,7)
    self.manGo:setSpriteFrame(fristFrame)
    self.manGo:runAction(cc.RepeatForever:create(cc.Animate:create(animation)))
    self.manGo:setAnchorPoint(cc.p(0,0))
    self.manGo:setPosition(cc.p(display.width/2 - self.progressbarLeft:getContentSize().width/2 - 35,140))
    self.m_LoadingLayer:addChild(self.manGo,20)

    self:initData(1)
end

function fightMainScene:initData(iID)
    local allID = 4

    if iID == 1 then 
        --创建一个主层
        cs.logger.i("fightMainScene:ctor **********************")
        self.m_MainLayer = cc.Layer:create()
        self.m_MainLayer:setAnchorPoint(cc.p(0,0))
        self.m_MainLayer:setPosition(cc.p(0,0))
        self:addChild(self.m_MainLayer,10)

        local gameData = singleGameData:getInstance()
        gameData:setMainLayer(self.m_MainLayer)

        local todo = cc.Sequence:create(cc.ProgressTo:create(0.3, iID * 100/allID) , cc.CallFunc:create(function( )
        self:initData(iID + 1)end))
        self.progressbarLeft:runAction(todo)  

        local toMove = cc.MoveBy:create(0.3,cc.p(self.progressbarLeft:getContentSize().width/allID,0))
        self.manGo:runAction(toMove)  
    elseif iID == 2 then
        --读取Map配置文件
        local loadData = singleLoadData:getInstance()
        local stageData = loadData:loadMap("json/map1.json")
        
        local todo = cc.Sequence:create(cc.ProgressTo:create(0.3, iID * 100/allID) , cc.CallFunc:create(function( )
        self:initData(iID + 1)end))
        self.progressbarLeft:runAction(todo)   

        local toMove = cc.MoveBy:create(0.3,cc.p(self.progressbarLeft:getContentSize().width/allID,0))
        self.manGo:runAction(toMove)  
    elseif iID == 3 then
        local loadData = singleLoadData:getInstance()
        loadData:loadEnemy("json/enemy.json")
        loadData:loadLevelEnemy("json/level1.json")
        singleGameData:getInstance():setStageData(loadData:getStageData())

        --创建一个事件池
        local singEventPool = singleGameEventPool:getInstance()

        --加入一个时间管理器管理游戏中的时间
        local timeManager = singleTimeManager:getInstance()
        timeManager:setMainLayerForTime(self.m_MainLayer)

        --加入一个怪物管理器管理游戏中的怪物
        local enemyManager = singleEnemyManager:getInstance()

        --加入一个波次管理器管理游戏中的波次
        local waveManager = singleWaveManager:getInstance()

        --加入一个塔的管理器管理游戏的塔
        local towerManager = singleTowerManager:getInstance()
        towerManager:setLayer(self.m_MainLayer)
        singleTimeManager:getInstance():addTimer(towerManager)

        --加入一个子弹的管理器管理游戏的子弹
        local bulletManager = singleBulletManager:getInstance()
        bulletManager:setLayer(self.m_MainLayer)
        singleTimeManager:getInstance():addTimer(bulletManager)

        --加入一个机关的管理器管理游戏的塔
        local trickManager = singleTrickManager:getInstance()
        trickManager:setLayer(self.m_MainLayer)
        trickManager:setTrickAndCreate(singleLoadData:getInstance():getTrick())
        singleTimeManager:getInstance():addTimer(trickManager)

        --创建一个战斗UI的主要界面UI
        local fightUI = require("gameFight.fightUI.fightMainUI"):create()
        self.m_MainLayer:addChild(fightUI,CC_GAME_LAYER_LEVEL.Layer_fight_main_ui) 
        fightUI:refreshUI()

        local todo = cc.Sequence:create(cc.ProgressTo:create(0.3, iID * 100/allID) , cc.CallFunc:create(function( )
        self:initData(iID + 1)end))
        self.progressbarLeft:runAction(todo)   

        local toMove = cc.MoveBy:create(0.3,cc.p(self.progressbarLeft:getContentSize().width/allID,0))
        self.manGo:runAction(toMove)  
    elseif iID == 4 then
        local toMove = cc.MoveBy:create(0.3,cc.p(self.progressbarLeft:getContentSize().width/allID,0))
        self.manGo:runAction(toMove)  

        local todo = cc.Sequence:create(cc.ProgressTo:create(0.3, 100) , cc.CallFunc:create(function( )
            singleTimeManager:getInstance():startTime()
            singleStage:getInstance():runStageForData(self.m_MainLayer, singleLoadData:getInstance().mapData, true)
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_NextWaveNeed)

            self.m_LoadingLayer:removeFromParent()
        end))
        self.progressbarLeft:runAction(todo)   
    end
end

return fightMainScene