--战斗场景单键类
if cc.exports.singleStage == nil then
    cc.exports.singleStage = {} 
end

function singleStage:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleStage:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()
        self.instance:_init()  
    end  
    return self.instance  
end  

--设定场景的数据，并显示场景
function singleStage:runStageForData(target, stageData, isDebugShow)
    --创建一个地形
    local pSprit = cc.Sprite:create(stageData["map"]["bgimage"])
    local pTopSprit = cc.Sprite:create(stageData["map"]["bgtopimage"])

    local pSkySprit = cc.Sprite:create("map/cloudshadow.png")

    --获取图片原本大小
    local bgSize = pSprit:getContentSize();

    --保存一份以防万一
    self.target = target

    --将图片扩大成背景大小
    pSprit:setScaleX(display.width/bgSize.width)
    pSprit:setScaleY(display.height/bgSize.height)
    pTopSprit:setScaleX(display.width/bgSize.width)
    pTopSprit:setScaleY(display.height/bgSize.height)

    
    pSprit:setAnchorPoint(cc.p(0,0))
    pSprit:setPosition(cc.p(0,0))
    target:addChild(pSprit , CC_GAME_LAYER_LEVEL.Layer_scene)

    pTopSprit:setAnchorPoint(cc.p(0,0))
    pTopSprit:setPosition(cc.p(0,0))
    target:addChild(pTopSprit , CC_GAME_LAYER_LEVEL.Layer_scene_top)

    pSkySprit:setAnchorPoint(cc.p(0,0))
    pSkySprit:setPosition(cc.p(0,300))
    pSkySprit:runAction(cc.MoveBy:create(300, cc.p(500, 500)))
    target:addChild(pSkySprit , CC_GAME_LAYER_LEVEL.Layer_scene_sky)

    self.instance:showSpace(target, stageData["map"]["towers"]["tower"])


    if isDebugShow == true then
        self.instance:ShowTheDebug(target, stageData["map"]["roads"]["road"])
    end
end

function singleStage:showSpace(target, stageData)
        --获得单个坐标

    local m_pDrawNode = cc.DrawNode:create(1)
    m_pDrawNode:setAnchorPoint(cc.p(0,0))
    m_pDrawNode:setPosition(cc.p(0,0))
    target:addChild(m_pDrawNode, CC_GAME_LAYER_LEVEL.Layer_scene_debug)

    for pCount, pData in pairs(stageData) do
        local b = loadstring("return "..pData["-tpos"])();
        local space = require("gameFight.actor.space"):create()
        space:setPosition(cc.p(b[1],b[2]))
        target:addChild(space, CC_GAME_LAYER_LEVEL.Layer_scene_space)
    end

end

function singleStage:ShowTheDebug(target, stageData)
    if CC_IS_SHOW_DEBUG == false then
        return
    end
    
    local m_pDrawNode = cc.DrawNode:create(1)
    m_pDrawNode:setAnchorPoint(cc.p(0,0))
    m_pDrawNode:setPosition(cc.p(0,0))
    target:addChild(m_pDrawNode, CC_GAME_LAYER_LEVEL.Layer_scene_debug)

    --获得单个坐标
    for pCount, pData in ipairs(stageData) do
        for i, v in pairs(pData["p"]) do
            local b = loadstring("return "..v)();
            m_pDrawNode:drawCircle(cc.p(b[1],b[2]), 5, 0, 4, false, 1, 1, cc.c4b(1,0,0,0.9))
        end
    end
end

function singleStage:eventResponse(gameEventID, eventSender, parameter)
    if gameEventID == CC_GAME_EVENT.GameEvent_BuildTower then
        local pParent = eventSender:getParent() 
        local x,y = eventSender:getPosition()
        eventSender:removeFromParent()

        local tower = require("gameFight.actor.tower"):create()
        tower:setPosition(cc.p(x,y - 12))
        tower:setTowerData(parameter)
        tower:createTowerWithData()
        singleTowerManager:getInstance():addTower(tower)
        
        --动态计算塔的坐标位置
        local  zoder = 120 - math.floor((tower:getPositionY()/10) + 0.5)
        pParent:addChild(tower, CC_GAME_LAYER_LEVEL.Layer_scene_enemy + zoder)

    elseif gameEventID == CC_GAME_EVENT.GameEvent_GoldPoor then
        local goldLabel = cc.LabelTTF:create("", "ttf/fangzhenglier.ttf", 50)  
        goldLabel:setAnchorPoint(cc.p(0.5,0.5))
        goldLabel:setPosition(cc.p(display.width/2 , display.height/2 ))
        goldLabel:setColor(cc.c3b(1,1,1))
        goldLabel:setString("show me the money??")
        local mainLayer = singleGameData:getInstance():getMainLayer()
        mainLayer:addChild(goldLabel,CC_GAME_LAYER_LEVEL.Layer_fight_main_ui)

        local callBack = cc.CallFunc:create(function ( ... )
            goldLabel:removeFromParent()
        end)
        local bAction1 = cc.Spawn:create(cc.MoveBy:create(1.5,cc.p(0,100)),cc.FadeOut:create(1.5)) 
        local bAction2 = cc.Sequence:create(bAction1,callBack) 
        goldLabel:runAction(bAction2)
    end
end

function singleStage:_init()
    -- body
    
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_GoldPoor, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_BuildTower, self)
end