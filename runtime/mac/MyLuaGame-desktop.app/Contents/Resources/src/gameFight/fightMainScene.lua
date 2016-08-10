--载入所有单键类
require("gameFight.singleStage")
require("gameFight.singleLoadMap")
require("gameFight.singleUtil")

local fightMainScene = class("fightMainScene")

--成员函数
local m_MainScene = nil

function fightMainScene:create(configs)

    --创建一个场景
    m_MainScene = cc.Scene:create()
    m_MainScene:setAnchorPoint(cc.p(0,0))
    m_MainScene:setPosition(cc.p(0,0))

    --读取Map配置文件
    local stageData = singleLoadMap:getInstance():loadMap("map1.json")

    --载入场景，并且选择是否开启debug模式
    singleStage:getInstance():runStageForData(m_MainScene, stageData, true)

    --载入一个角色
    local animation = singleUtil:getInstance():createFrameCache("enemy/babyspirit/walk","walk",7)
    local action = cc.Sequence:create(cc.Animate:create(animation),cc.CallFunc:create(function()  end))


    local testPs = cc.Sprite:create("enemy/babyspirit/walk/walk0000.png") 
    testPs:setScale(2.0)
    testPs:runAction(cc.RepeatForever:create(action))

    testPs:setPosition(cc.p(200,200))

    m_MainScene:addChild(testPs,99)

    --运行
    cc.Director:getInstance():runWithScene(m_MainScene)
end

return fightMainScene