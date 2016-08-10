--载入所有单键类
require("gameFight.singleStage")
require("gameFight.singleLoadMap")
require("gameFight.Data.singleGameData")
require("gameFight.singleUtil")
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

    --创建一套测试数据
    singleGameData:getInstance():createTestData()

    --载入场景，并且选择是否开启debug模式
    singleStage:getInstance():runStageForData(self.m_MainLayer, stageData, true)

    --载入一个角色
    --测试Actor
    local Enemy = require("gameFight.Actor.Enemy"):create()
    Enemy:setData(singleGameData:getInstance().ActorData)
    Enemy:walk()
    Enemy:bigen()

    self.m_MainLayer:addChild(Enemy.RootLayer,99)

    --运行
    cc.Director:getInstance():runWithScene(self.m_MainScene)
end

return fightMainScene