--战斗时间管理单键类
if cc.exports.singleWaveManager == nil then
    cc.exports.singleWaveManager = {} 
end

function singleWaveManager:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleWaveManager:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
        self.instance:_init()
    end  
    return self.instance  
end 

--监听事件
function singleWaveManager:eventResponse(gameEventID, eventSender, parameter)
    --请求波次
    cs.logger.i("singleWaveManager:eventResponse"..gameEventID)
    if gameEventID == CC_GAME_EVENT.GameEvent_NextWaveNeed then
        --开始进行波次的等待时间
        self.waveTime  = singleLoadData:getInstance():getLevelWavaDataTime(self.waveID+1)
        singleTimeManager:getInstance():addTimer(self)
    else
        cs.logger.i("this is a meng B msg")
    end
end

--开始每帧更新
function singleWaveManager:UpData(dt)

    cs.logger.i("singleWaveManager:UpData"..self.waveTime)
    self.waveTime = self.waveTime - dt
    
    --根据时间判断刷怪
    if self.waveTime <= 0 then
        singleTimeManager:getInstance():nextRemoveTimerNextFrame(self)
        self:_startNextWave()
    end
end

--设定开始下一波怪物
function singleWaveManager:_startNextWave()
    cs.logger.i("_startNextWave")
    self.waveID = self.waveID + 1
    local waveData = singleLoadData:getInstance():getLevelWavaData(self.waveID)
    singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_WaveDataReady, self, waveData)
end

function singleWaveManager:_init()  
    cs.logger.i("singleEnemyManager:_init GameEvent_NextWaveNeed")
    self.waveID = 0 --不存在0波次，用此表示游戏还没有开始
    self.waveTime = 0 --波次等待时间
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_NextWaveNeed, self)
end