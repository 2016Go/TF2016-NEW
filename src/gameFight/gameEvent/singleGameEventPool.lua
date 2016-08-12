--战斗场景单键类
if cc.exports.singleGameEventPool == nil then
    cc.exports.singleGameEventPool = {} 
end

function singleGameEventPool:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleGameEventPool:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  

        self:_init()
    end  
    return self.instance  
end

--内部初始化函数
function singleGameEventPool:_init()
   cs.logger.i("singleGameEventPool")
    self.eventDataVec = {}
    for i,v in pairs(CC_GAME_EVENT) do
       --创建足够量的事件池table
       self.eventDataVec[v] = {}
    end
end

--加入一个事件监听者到事件池中
function singleGameEventPool:addEventListenerInPool(gameEventID, eventListener)
    --获取所有监听者
    local listenerVec = self.eventDataVec[gameEventID]
    --懒得去用find啦，自己写
    for k,v in pairs(listenerVec) do
        if v == eventListener then
            return
        end
    end

    table.insert(self.eventDataVec[gameEventID],eventListener)
end

function singleGameEventPool:SendEventForListener(gameEventID, eventSender, parameter)
    --获取所有监听者
    local listenerVec = self.eventDataVec[gameEventID]
    for k,v in pairs(listenerVec) do
        if v.eventResponse ~= nil then
            v:eventResponse(gameEventID, eventSender, parameter)
        end
    end
end