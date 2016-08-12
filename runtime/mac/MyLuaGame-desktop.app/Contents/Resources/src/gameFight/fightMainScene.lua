--载入所有单键类
require("gameFight.singleStage")
require("gameFight.singleLoadMap")
require("gameFight.singleUtil")
require("gameFight.Data.singleGameData")
require("gameFight.Manager.singleTimeManager")
require("gameFight.Manager.singleEnemyManager")
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

    --载入所有的战斗plist
    local myUtil = singleUtil:getInstance()
    myUtil:addAllPlist()

    --读取Map配置文件
    local stageData = singleLoadMap:getInstance():loadMap("map1.json")

    --加入一个时间管理器管理游戏中的时间
    local TimeManager = singleTimeManager:getInstance()
    TimeManager:setMainLayerForTime(self.m_MainLayer)

    --加入一个怪物管理器管理游戏中的怪物
    local EnemyManager = singleEnemyManager:getInstance()
    TimeManager:addTimer(EnemyManager)

    --创建一套测试数据
    singleGameData:getInstance():createTestData()

    --载入场景，并且选择是否开启debug模式
    singleStage:getInstance():runStageForData(self.m_MainLayer, stageData, true)

   

    local a = require("gameFight.actor.enemy").create()
    --local b = require("gameFight.Actor.TestSon").create()

    --a.aaa = 0
    --a:youwei()
    --b:youwei()

    --if a == b then
    --    print("1231231")
    --end
    --载入一个角色
    --测试Actor
--[[
    local Enemy1 = require("gameFight.actor.enemy"):create()
    Enemy1:setData(singleGameData:getInstance().actorData)
    Enemy1.nowState = CC_ENEMY_STATE.State_Born

    local Enemy2 = require("gameFight.actor.enemy"):create()
    singleGameData:getInstance().actorData.road = 2
    Enemy2:setData(singleGameData:getInstance().actorData)
    Enemy2.nowState = CC_ENEMY_STATE.State_Born

    local Enemy3 = require("gameFight.actor.enemy"):create()
    singleGameData:getInstance().actorData.road = 3
    singleGameData:getInstance().actorData.speed = 30
    Enemy3:setData(singleGameData:getInstance().actorData)

    Enemy3.nowState = CC_ENEMY_STATE.State_Born

    EnemyManager:addEnemy(Enemy1)
    EnemyManager:addEnemy(Enemy2)
    EnemyManager:addEnemy(Enemy3)

    --if Enemy1 == Enemy2 then
    --    print("wo lie ge qu")
    --end

    self.m_MainLayer:addChild(Enemy1,99)
    self.m_MainLayer:addChild(Enemy2,99)
    self.m_MainLayer:addChild(Enemy3,99)
]]
    --运行
    cc.Director:getInstance():runWithScene(self.m_MainScene)

end

return fightMainScene