--载入所有单键类
require("gameFight.singleUtil")
require("gameFight.singleStage")
require("gameFight.singleLoadData")
require("gameFight.data.singleGameData")
require("gameFight.manager.singleTimeManager")
require("gameFight.manager.singleEnemyManager")
require("gameFight.manager.singleWaveManager")
require("gameFight.gameEvent.singleGameEventPool")
--结束单键类载入

local fightMainScene = class("fightMainScene", function() return cc.Layer:create() end)

function fightMainScene:ctor()
    --创建一个主层
    cs.logger.i("fightMainScene:ctor **********************")
    self.m_MainLayer = cc.Layer:create()
    self.m_MainLayer:setAnchorPoint(cc.p(0,0))
    self.m_MainLayer:setPosition(cc.p(0,0))
    self:addChild(self.m_MainLayer,10)

    --创建一套测试数据
    local gameData = singleGameData:getInstance()
    gameData:setMainLayer(self.m_MainLayer)

    --载入所有的战斗plist
    local myUtil = singleUtil:getInstance()
    myUtil:addAllPlist()

    --读取Map配置文件
    local loadData = singleLoadData:getInstance()
    local stageData = loadData:loadMap("json/map1.json")
    loadData:loadEnemy("json/enemy.json")
    loadData:loadLevelEnemy("json/level1.json")
    gameData:setStageData(loadData:getStageData())

    --加入一个时间管理器管理游戏中的时间
    local timeManager = singleTimeManager:getInstance()
    timeManager:setMainLayerForTime(self.m_MainLayer)

    --加入一个怪物管理器管理游戏中的怪物
    local enemyManager = singleEnemyManager:getInstance()

    --加入一个波次管理器管理游戏中的波次
    local waveManager = singleWaveManager:getInstance()

    --创建一个事件池
    local singEventPool = singleGameEventPool:getInstance()

    --创建一个战斗UI的主要界面UI
    local fightUI = require("gameFight.fightUI.fightMainUI"):create()
    self.m_MainLayer:addChild(fightUI,CC_GAME_LAYER_LEVEL.Layer_fight_main_ui) 
    fightUI:refreshUI()

    --载入场景，并且选择是否开启debug模式
    singleStage:getInstance():runStageForData(self.m_MainLayer, stageData, true)

--------------------------------------------------------------------------------
    --开始下一波（第一波）gameUI
    cs.logger.i("SendEventForListener GameEvent_NextWaveNeed")
    singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_NextWaveNeed)

    --运行
end

return fightMainScene