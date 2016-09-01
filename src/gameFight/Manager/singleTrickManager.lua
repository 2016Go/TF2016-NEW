--机关管理单键类
if cc.exports.singleTrickManager == nil then
    cc.exports.singleTrickManager = {} 
end

function singleTrickManager:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleTrickManager:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
        self.instance:_init()
    end  
    return self.instance  
end 

--监听事件
function singleTrickManager:eventResponse(gameEventID, eventSender, parameter)
    if gameEventID == CC_GAME_EVENT.GameEvent_Trick_Dele then
        self:removeTrickNextFrame(eventSender)
    end 
end

--设定一个加载层级方便add
function singleTrickManager:setLayer( mainLayer )
    self.mainLayer = mainLayer
end

--开始每帧更新敌人管理器
function singleTrickManager:UpData(dt , iCountTime)
    --如果双数计时，不执行，如此来提高游戏效率
    self.dt = self.dt + dt
    if iCountTime == 0 then
        return
    end    

    --更新每一个塔的数据
    for k,v in pairs(self.allTrick) do
       v:UpData(self.dt)
    end

    --先删除
    for i,v in pairs(self.nextFrameRemoveTrick) do
        self:_removeTrick(v)
    end 

    self.nextFrameRemoveTrick = {}
    self.dt = 0
end

--删除一个机关，下一帧
function singleTrickManager:removeTrickNextFrame(myTrick)
    table.insert(self.nextFrameRemoveTrick, myTrick)
end

function singleTrickManager:_removeTrick(myTrick)
    for i,v in pairs(self.allTrick) do
        if v == myTrick then
            table.remove( self.allTrick, i )
            v:clear()
            return
        end
    end
end

--设定并创建机关
function singleTrickManager:setTrickAndCreate(trickData)
    cs.util.printTable(trickData)
    for k,v in pairs(trickData) do
        self:_createTrick(k,v)
    end

end

function singleTrickManager:_createTrick(key , posVec)
    local data = cs.conf.a("trick" , key)
    if data == nil then
        cs.logger.w("trick id is bad ="..key)
        return
    end

    if type(posVec) ~= "table" then
        self:_createTrickItem(data , posVec)
    else
        for k,v in ipairs(posVec) do
            self:_createTrickItem(data , v)
        end
    end
    
end

function singleTrickManager:_createTrickItem(data , pos)
    local trick = require("gameFight.actor.trick"):create()
    trick:setData(data , self.tirckTag)
    self.tirckTag = self.tirckTag + 1

    local b = loadstring("return "..pos)()
    trick:setPosition(cc.p(b[1],b[2]))

    self.mainLayer:addChild( trick , CC_GAME_LAYER_LEVEL.Layer_scene_debug )
    table.insert(self.allTrick , trick)
end

function singleTrickManager:_init()  
    self.allTrick = {}
    self.nextFrameRemoveTrick = {}
    self.dt = 0

    --用于标记
    self.tirckTag = 0
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_Trick_Dele, self)
end
