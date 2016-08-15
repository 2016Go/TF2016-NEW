--战斗场景单键类
if cc.exports.singleGameData == nil then
    cc.exports.singleGameData = {} 
end

function singleGameData:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleGameData:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
    	self:_init()
    end  
    return self.instance  
end 

function singleGameData:setStageData(data)
	self.mainUIData.life = data.life
	self.mainUIData.gold = data.gold
	self.mainUIData.wave = data.wave
	self.mainUIData.bgm = data.bgm
	self.mainUIData.towersindex = data.towersindex
	self.mainUIData.waveLimit = data.waveLimit    --波次上限
end

function singleGameData:getStageData()
	return self.mainUIData
end

function singleGameData:setMainLayer(mainLayer)
	self.mainLayer = mainLayer
end

function singleGameData:getMainLayer()
	return self.mainLayer
end

function singleGameData:_init()
	self.mainUIData = {}
	self.mainUIData.life = 10
	self.mainUIData.gold = 100
	self.mainUIData.wave = 0
	self.mainUIData.waveLimit = 10    --波次上限

	singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_NextWaveNeed, self)
	singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_EnemyGoOver, self)
end

function singleGameData:eventResponse(gameEventID, eventSender, parameter)
    --请求波次
    if gameEventID == CC_GAME_EVENT.GameEvent_NextWaveNeed then
        if self.mainUIData.wave  >= self.mainUIData.waveLimit then
        	--完成波次逻辑
        	return
        end
        self.mainUIData.wave  = self.mainUIData.wave + 1
 		singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_MainUIDataChange, self)
    
    elseif gameEventID == CC_GAME_EVENT.GameEvent_EnemyGoOver then
    	if self.mainUIData.life  <= 0 then
    		--死亡逻辑
    		return
    	end
    	self.mainUIData.life  = self.mainUIData.life - parameter
    	singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_MainUIDataChange, self)
    else
        cs.logger.i("this is a meng B msg")
    end
end
