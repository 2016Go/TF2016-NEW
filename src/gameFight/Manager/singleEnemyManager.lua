--战斗时间管理单键类
if cc.exports.singleEnemyManager == nil then
    cc.exports.singleEnemyManager = {} 
end

function singleEnemyManager:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleEnemyManager:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()
        self.instance:_init()
    end  
    return self.instance  
end 

--设定波次数据,每次设定数据的时候，可以附带一个重置ID
function singleEnemyManager:setWaveData(waveData , nowEnemyID)
    self.waveData = waveData
    self.nowEnemyID = nowEnemyID or self.nowEnemyID
end

--开始每帧更新敌人管理器
function singleEnemyManager:UpData(dt)
    self.timeGo = self.timeGo + dt
    
    --检测是否还可以刷出怪物，如果可以刷怪，如果不可以，等待，如果没怪了，请求下一波
    if self:_checkAddEnemt() == false then
        return
    end

    for i,v in pairs(self.allEnemy) do
        v:UpData(dt)
    end
end

--加入一个敌人
function singleEnemyManager:addEnemy(myEnemy)
    table.insert(self.allEnemy, myEnemy)
end

--删除一个敌人，下一帧
function singleEnemyManager:removeEnemyNextFrame(myEnemy)
    table.insert(self.nextFrameRemoveEnemy, myEnemy)
end

--删除一个敌人，内部调用
function singleEnemyManager:removeEnemy(myEnemy)
    cs.logger.i("removeEnemy---no ok")
    for i,v in pairs(self.allEnemy) do
        if v == myEnemy then
            cs.logger.i("remove---ok")
            table.remove( self.allEnemy, i )
            return
        end
    end
end

--监听事件
function singleEnemyManager:eventResponse(gameEventID, eventSender, parameter)
    --有敌方单位到达了终点位置
    if gameEventID == CC_GAME_EVENT.GameEvent_EnemyGoOver then
        cs.logger.i("eventSender:clear()")
        self:removeEnemy(eventSender)
        eventSender:clear()

    --更新最新的波次信息
    elseif gameEventID == CC_GAME_EVENT.GameEvent_WaveDataReady then
        cs.logger.i("setWaveData:parameter()")
        if parameter == nil then
            cs.logger.i("parameter:parameter() == nil")
            return
        end
        singleTimeManager:getInstance():addTimer(self)
        self:setWaveData(parameter,1)
    else
        cs.logger.i("this is a meng B msg")
    end

    cs.logger.i("eventResponse end")
end


--内部调用初始化函数
function singleEnemyManager:_init()
    self.allEnemy = {}
    self.nextFrameRemoveEnemy = {}
    self.timeGo = 0
    self.waveData = {}
    self.nowEnemyID = 1

    --加入一个监听事件
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_WaveDataReady, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_EnemyGoOver, self)
end

function singleEnemyManager:_checkAddEnemt()
    --如果波次信息为空（已经刷完了）
    if next(self.waveData) == nil then
        
        --如果场上还有怪物(继续行动)
        if next(self.allEnemy) ~= nil then
            cs.logger.i("self.allEnemy is not null")
            return true 

        --否者，停止更新，发送请求波次 
        else
            cs.logger.i("self.allEnemy is null")
            singleTimeManager:getInstance():nextRemoveTimerNextFrame(self)
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_NextWaveNeed, self)
            return false
        end
    end

    local nowItem = self.waveData["e"][self.nowEnemyID]
    if nowItem == nil then
        --处理一波完成事件(继续行动)
        self.waveData = {}
        return true
    end    

    --如果已经到达出场时间
    local dTime = tonumber(nowItem["-d"])/1000
    print("nowItem"..self.nowEnemyID.." = "..nowItem["-d"].." to num = "..dTime)
    if dTime <= self.timeGo then
        self.nowEnemyID = self.nowEnemyID + 1
        self.timeGo = 0 

        local actorData = {}
        actorData.name         = "飞翔的小鸟"           -- 怪物名字
        actorData.life         = 100                   -- 生命值
        actorData.speed        = 260                    -- 速度值
        actorData.mainRes      = "babyspirit/walk/"          -- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
        actorData.standName    = "stand"               -- 站立动作名字
        actorData.walk         = "walk"                -- 站立动作名字
        actorData.road         = 1                     -- 站立动作名字

        local Enemy1 = require("gameFight.actor.enemy"):create()
        Enemy1:setData(actorData)
        Enemy1.nowState = CC_ENEMY_STATE.State_Born
        self:addEnemy(Enemy1)
        singleGameData:getInstance():getMainLayer():addChild(Enemy1,99)
    end

    return true
end

