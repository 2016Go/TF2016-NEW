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
    end  
    return self.instance  
end  

--设定场景的数据，并显示场景
function singleStage:runStageForData(target, stageData, isDebugShow)
    --创建一个地形
    local pSprit = cc.Sprite:create(stageData["map"]["bgimage"])
    pSprit:setAnchorPoint(cc.p(0,0))
    pSprit:setPosition(cc.p(0,0))
    target:addChild(pSprit , CC_GAME_LAYER_LEVEL.Layer_scene)

    if isDebugShow == true then
        self.instance:ShowTheDebug(target, stageData["map"]["roads"]["road"])
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