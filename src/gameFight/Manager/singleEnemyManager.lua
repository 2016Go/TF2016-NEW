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
function singleEnemyManager:UpData(dt , iCountTime)
    --如果单数计时，不执行，如此来提高游戏效率
    self.dt = self.dt + dt
    if iCountTime == 1 then
        return
    end
    self.timeGo = self.timeGo + self.dt



    --检测是否还可以刷出怪物，如果可以刷怪，如果不可以，等待，如果没怪了，请求下一波
    if self:_checkAddEnemt() == false then
        return
    end

    --运行更新
    for i,v in pairs(self.allEnemy) do
        v:UpData(self.dt)
    end

            --先删除
    for i,v in pairs(self.nextFrameRemoveEnemy) do
        self:_removeEnemy(v)
    end 

    --再添加
    for i,v in pairs(self.nextFrameAddEnemy) do
        table.insert(self.allEnemy, v)
    end 

    self.nextFrameRemoveEnemy = {}
    self.nextFrameAddEnemy = {}
    self.dt = 0
end

--加入一个敌人
function singleEnemyManager:addEnemy(myEnemy)
    table.insert(self.nextFrameAddEnemy, myEnemy)
end

--删除一个敌人，下一帧
function singleEnemyManager:removeEnemyNextFrame(myEnemy)
    table.insert(self.nextFrameRemoveEnemy, myEnemy)
end

--删除一个敌人，内部调用,危险操作，可能导致崩溃，不建议随便使用
function singleEnemyManager:_removeEnemy(myEnemy)
    for i,v in pairs(self.allEnemy) do
        if v == myEnemy then
            table.remove( self.allEnemy, i )
            v:clear()
            return
        end
    end
end

--监听事件
function singleEnemyManager:eventResponse(gameEventID, eventSender, parameter)
    --有敌方单位到达了终点位置
    if gameEventID == CC_GAME_EVENT.GameEvent_EnemyGoOver then
        self:removeEnemyNextFrame(eventSender)

    --更新最新的波次信息
    elseif gameEventID == CC_GAME_EVENT.GameEvent_WaveDataReady then
        if parameter == nil then
            cs.logger.i("parameter:parameter() == nil")
            return
        end
        singleTimeManager:getInstance():addTimer(self)
        self:setWaveData(parameter,1)
    elseif gameEventID ==  CC_GAME_EVENT.GameEvent_LifeDie then
        --if self:checkEnemyIsInManager(eventSender) == true then
        self:removeEnemyNextFrame(eventSender)
        --end
    else
        cs.logger.i("this is a meng B msg")
    end

end

--获取所有怪物
function singleEnemyManager:getAllEnemy()
    return self.allEnemy
end

--检测参数中的怪物是否依旧存在于管理器中
function singleEnemyManager:checkEnemyIsInManager(myEnemy)
    for i,v in pairs(self.allEnemy) do
        if v == myEnemy then
            return true
        end
    end

    return false
end

--内部调用初始化函数
function singleEnemyManager:_init()
    self.dt = 0
    self.allEnemy = {}
    self.nextFrameRemoveEnemy = {}
    self.nextFrameAddEnemy = {}
    self.timeGo = 0
    self.waveData = {}
    self.nowEnemyID = 1

    --加入一个监听事件
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_WaveDataReady, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_EnemyGoOver, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_LifeDie, self)
end

function singleEnemyManager:_checkAddEnemt()
    --如果波次信息为空（已经刷完了）
    if next(self.waveData) == nil then
        
        --如果场上还有怪物(继续行动)
        if next(self.allEnemy) ~= nil then
            --cs.logger.i("self.allEnemy is not null")
            return true 

        --否者，停止更新，发送请求波次 
        else
            cs.logger.i("self.allEnemy is null")
            singleTimeManager:getInstance():nextRemoveTimerNextFrame(self)
            singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_NextWaveNeed, self)
            return false
        end
    end

    --获取当前正要加入的单个敌人数据
    local nowItem = singleLoadData:getInstance():getEnemyItemBornData(self.waveData , self.nowEnemyID)
    if nowItem == nil then
        --处理一波完成事件(继续行动)
        self.waveData = {}
        return true
    end    

    --获取出场延时，并判断是否已经到达出场时间
    local dTime = singleLoadData:getInstance():getEnemyItemBornTime(self.waveData , self.nowEnemyID)
    if dTime <= self.timeGo then
        --获取当前的小怪数据    
        local enemyItemData =singleLoadData:getInstance():getEnemyItem(self.waveData , self.nowEnemyID)
        if enemyItemData == nil then 
            --当下一个怪物不存在的时候。返回
            self.waveData = {}
            return true
        end

        --用数据创建敌人
        self:_AddEnemt(enemyItemData,nowItem)

        --更新数据
        self.nowEnemyID = self.nowEnemyID + 1
        self.timeGo = 0 
    end

    return true
end

function singleEnemyManager:_AddEnemt(enemyItemData,nowItem)
        local actorData = {}
        actorData.name         = enemyItemData["-name"]                   -- 怪物名字
        actorData.life         = tonumber(enemyItemData["-baseHP"]) or 20 -- 生命值
        actorData.speed        = tonumber(enemyItemData["-speed"]) or 30  -- 速度值
        actorData.sclase       = tonumber(enemyItemData["-sclase"]) or 1 -- 放大缩小
        actorData.mainRes      = enemyItemData["-anim"]                   -- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
        actorData.gold         = tonumber(enemyItemData["-gold"]) or 1    -- 获得资源
        actorData.punishHP     = tonumber(enemyItemData["-punishHP"]) or 1 -- 进入通道造成的伤害
        actorData.road         = tonumber(nowItem["-r"]) or 1             -- 道路
        --兼容老版本配置
        if actorData.road == 0 then
            actorData.road = 1
        end

        local enemy = require("gameFight.actor.enemy"):create()
        enemy:setData(actorData)
        enemy.nowState = CC_ENEMY_STATE.State_Born
        self:addEnemy(enemy)
        singleGameData:getInstance():getMainLayer():addChild(enemy,CC_GAME_LAYER_LEVEL.Layer_scene_enemy)
end