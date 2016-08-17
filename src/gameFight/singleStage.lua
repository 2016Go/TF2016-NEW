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

    --获取图片原本大小
    local bgSize = pSprit:getContentSize();

    --保存一份以防万一
    self.target = target

    --将图片扩大成背景大小
    pSprit:setScaleX(display.width/bgSize.width)
    pSprit:setScaleY(display.height/bgSize.height)

    
    pSprit:setAnchorPoint(cc.p(0,0))
    pSprit:setPosition(cc.p(0,0))
    target:addChild(pSprit , CC_GAME_LAYER_LEVEL.Layer_scene)

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
        --m_pDrawNode:drawCircle(cc.p(b[1],b[2]), 5, 0, 4, false, 1, 1, cc.c4b(1,1,0,0.9))
    end

end

function singleStage:ShowTheDebug(target, stageData)
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
        tower:setPosition(cc.p(x,y))
        pParent:addChild(tower, CC_GAME_LAYER_LEVEL.Layer_scene_space)
    end
end

function singleStage:_init()
    -- body
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_BuildTower, self)
end