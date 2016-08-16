--战斗场景单键类
if cc.exports.singleUIEvent == nil then
    cc.exports.singleUIEvent = {} 
end

function singleUIEvent:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleUIEvent:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  

        self:_init()
    end  
    return self.instance  
end

--加入一个事件监听者到事件池中
function singleUIEvent:addEventListenerInPool(gameEventID, eventListener)
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

--加入一个事件监听者到事件池中
function singleUIEvent:removeEventListenerInPool(gameEventID)
    --获取所有监听者
    local listenerVec = self.eventDataVec[gameEventID]
    --懒得去用find啦，自己写
    for i,v in ipairs(listenerVec) do
        if v == eventListener then
            cs.logger.i("remove UI event",i)
            table.remove( listenerVec, i )
            return
        end
    end

    table.insert(self.eventDataVec[gameEventID],eventListener)
end

function singleUIEvent:SendEventForListener(gameEventID, eventSender, parameter)
    --获取所有监听者
    local listenerVec = self.eventDataVec[gameEventID]
    for k,v in pairs(listenerVec) do
        if v.refreshUI ~= nil then
            v:refreshUI(gameEventID, eventSender, singleUIData:getInstance()[gameEventID])
        end
    end
end

--内部初始化函数
function singleUIEvent:_init()
    self.eventDataVec = {}
    for i,v in pairs(CC_GAME_EVENT) do
       --创建足够量的事件池table
       self.eventDataVec[v] = {}
    end
end