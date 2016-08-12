--载入所有单键类
require("gameFight.singleStage")
require("gameFight.singleLoadMap")
require("gameFight.singleLoadEnemy")
require("gameFight.singleUtil")
require("gameFight.data.singleGameData")
require("gameFight.manager.singleTimeManager")
require("gameFight.manager.singleEnemyManager")
require("gameFight.manager.singleWaveManager")
require("gameFight.gameEvent.singleGameEventPool")
--结束单键类载入

local fightMainScene = class("fightMainScene")

function fightMainScene:create(configs)

    --创建一个主场景
    self.m_MainScene = cc.Scene:create()
    self.m_MainScene:setAnchorPoint(cc.p(0,0))
    self.m_MainScene:setPosition(cc.p(0,0))

    --创建一个主层
    self.m_MainLayer = cc.Layer:create()
    self.m_MainLayer:setAnchorPoint(cc.p(0,0))
    self.m_MainLayer:setPosition(cc.p(0,0))
    self.m_MainScene:addChild(self.m_MainLayer,10)

    --创建一套测试数据
    local gameData = singleGameData:getInstance()
    gameData:createTestData()
    gameData:setMainLayer(self.m_MainLayer)

    --载入所有的战斗plist
    local myUtil = singleUtil:getInstance()
    myUtil:addAllPlist()

    --读取Map配置文件
    local stageData = singleLoadMap:getInstance():loadMap("json/map1.json")

    --读取Enemy配置文件
    local enemyLoad = singleLoadEnemy:getInstance()
    enemyLoad:loadEnemy("json/enemy.json")
    enemyLoad:LoadLevelEnemy("json/level1.json")

    --读取当前关卡刷怪的Enemy配置文件
    local levelData = singleLoadEnemy:getInstance():loadEnemy("json/level1.json")

    --加入一个时间管理器管理游戏中的时间
    local timeManager = singleTimeManager:getInstance()
    timeManager:setMainLayerForTime(self.m_MainLayer)

    --加入一个怪物管理器管理游戏中的怪物
    local enemyManager = singleEnemyManager:getInstance()

    --加入一个波次管理器管理游戏中的波次
    local waveManager = singleWaveManager:getInstance()

    --创建一个事件池
    local singEventPool = singleGameEventPool:getInstance()

    --载入场景，并且选择是否开启debug模式
    singleStage:getInstance():runStageForData(self.m_MainLayer, stageData, true)

-------------------------------------------------------------------------测试代码
    --[[local Enemy1 = require("gameFight.actor.enemy"):create()
    Enemy1:setData(singleGameData:getInstance().actorData)
    Enemy1.nowState = CC_ENEMY_STATE.State_Born

    local Enemy2 = require("gameFight.actor.enemy"):create()
    singleGameData:getInstance().actorData.road = 2
    Enemy2:setData(singleGameData:getInstance().actorData)
    Enemy2.nowState = CC_ENEMY_STATE.State_Born

    local Enemy3 = require("gameFight.actor.enemy"):create()
    singleGameData:getInstance().actorData.road = 3
    singleGameData:getInstance().actorData.speed = 100
    Enemy3:setData(singleGameData:getInstance().actorData)

    Enemy3.nowState = CC_ENEMY_STATE.State_Born

    enemyManager:addEnemy(Enemy1)
    enemyManager:addEnemy(Enemy2)
    enemyManager:addEnemy(Enemy3)

    self.m_MainLayer:addChild(Enemy1,99)
    self.m_MainLayer:addChild(Enemy2,99)
    self.m_MainLayer:addChild(Enemy3,99)
    --]]
--------------------------------------------------------------------------------
    --开始下一波（第一波）
    cs.logger.i("SendEventForListener GameEvent_NextWaveNeed")
    singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_NextWaveNeed)

    --运行
    cc.Director:getInstance():runWithScene(self.m_MainScene)

end

return fightMainScene