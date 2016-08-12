--战斗时间管理单键类
if cc.exports.singleTimeManager == nil then
    cc.exports.singleTimeManager = {} 
end

function singleTimeManager:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleTimeManager:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
        self.instance:_init()
    end  
    return self.instance  
end 

function singleTimeManager:_init() 
    self.allTimer = {}
    self.nextRemoveTimer = {}
    self.nextAddTimer = {}
    self.isNextFrameRemoveAll = false
end

--设定主要的时间调度层，来为整个时间调度
function singleTimeManager:setMainLayerForTime(MainLayer)
	self.m_MainLayer = MainLayer

	self.m_MainLayer:scheduleUpdateWithPriorityLua(
		function(dt)
            --开始调度每个时间
			for i,v in pairs(self.allTimer) do
				v:UpData(dt)
			end
    		
    		--清理所有的时间调度者
    		if self.isNextFrameRemoveAll == true then
    			self.isNextFrameRemoveAll = false
    			self.allTimer = {}
    		end
    		
    		--清理部分时间调度者
    		for i,v in pairs(self.nextRemoveTimer) do
    			self:_removeTimer(v)
    		end

    		--加入部分时间调度者
    		for i,v in pairs(self.nextAddTimer) do
    			table.insert(self.allTimer, v)
    		end

    		self.nextRemoveTimer = {}
    		self.nextAddTimer = {}
    	end,
    0)
end

--加入一个需要时间调度的成员
function singleTimeManager:addTimer( Timer )
	table.insert(self.nextAddTimer, Timer)
end

--下一帧，删除某一个需要时间调度的成员
function singleTimeManager:nextRemoveTimerNextFrame( Timer )
	table.insert(self.nextRemoveTimer, Timer)
end

--下一帧，删除所有需要时间调度的成员
function singleTimeManager:removeAllTimerNextFrame()
	self.isNextFrameRemoveAll = true
end

--暂停游戏中的时间调度
function singleTimeManager:Pause( ... )
	-- body
end

--继续游戏中的时间调度
function singleTimeManager:Continue( ... )
	-- body
end

--内部调用函数，不对外开放
function singleTimeManager:_removeTimer( Timer )
	cs.logger.i("_removeTimer")
	for i,v in pairs(self.allTimer) do
		if v == Timer then
			cs.logger.i("_removeTimer  OK")
			table.remove( self.allTimer, i )
		end
	end
end
