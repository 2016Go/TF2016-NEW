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
    --用于判断怪物的层级，约定每10帧执行一次
    self.zoderNum = self.zoderNum + 1

    self.timeGo = self.timeGo + self.dt

    --检测是否还可以刷出怪物，如果可以刷怪，如果不可以，等待，如果没怪了，请求下一波
    if self:_checkAddEnemy() == false then
        return
    end

    --检测机关刷怪是否需要
    self:_checkAddTrickEnemy(dt) 

    --运行更新
    for i,v in pairs(self.allEnemy) do
        v:UpData(self.dt)
    end
    
    if self.zoderNum >= 5 then
        for i,v in pairs(self.allEnemy) do
            local  zoder = 120 - math.floor((v:getPositionY()/10) + 0.5)
            v:setLocalZOrder(CC_GAME_LAYER_LEVEL.Layer_scene_enemy + zoder)
        end
        self.zoderNum = 0
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

function singleEnemyManager:_EnemyForDie(eventSender)

        local v = eventSender 
        local ani = {}
        if v.actorData.name == "slime1" then  
            ani = DHSkeletonAnimation:createWithFile("animation/slime_eff_json/slime_1_eff.json");
        else
            ani = DHSkeletonAnimation:createWithFile("animation/slime_eff_json/slime_2_eff.json"); 
        end
        ani:setPosition(cc.p(v:getPosition()))
            
        v:getParent():addChild(ani , v:getLocalZOrder()-4)
        ani:scheduleUpdateLua()
            
            --有分裂个体和没有分裂个体的不同处理方式
        if v.actorData.division == "-1" then
            ani:playAnimation("die")
            ani:setScale( v.mainSprite:getScale() )
            local bAction1 = cc.Sequence:create(cc.DelayTime:create(0.8),cc.CallFunc:create(function ()ani:removeFromParent()end))
            ani:runAction(bAction1)
        else
            local data = singleLoadData:getInstance():getEnemyFromEnemyID(v.actorData.division)
            local roadID = v.actorData.road - 1

            local pos = cc.p(v:getPosition())
            local posID = v.nowPosID
                
            ani:playAnimation("fen")
            ani:setScale(v.mainSprite:getScale() + 0.5)
            local bAction1 = cc.Sequence:create(
            cc.DelayTime:create(0.11),cc.CallFunc:create(function ()self:_AddEnemt(data,roadID,pos,posID)end),
            cc.DelayTime:create(0.19),cc.CallFunc:create(function ()self:_AddEnemt(data,roadID,pos,posID)end),
            cc.DelayTime:create(0.44),cc.CallFunc:create(function ()ani:removeFromParent()end))
            ani:runAction(bAction1)
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
            return
        end
        singleTimeManager:getInstance():addTimer(self)
        self:setWaveData(parameter,1)
    elseif gameEventID ==  CC_GAME_EVENT.GameEvent_LifeDie then
        --if self:checkEnemyIsInManager(eventSender) == true then
        self:_EnemyForDie(eventSender)
        self:removeEnemyNextFrame(eventSender)
        --end
    elseif gameEventID == CC_GAME_EVENT.GameEvent_Trick_AddEnemy then
        self.isOpenTrcikEnemy = true
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
    
    self.trickWaveData = singleLoadData:getInstance():getTrickWave()
    self.trickEnemyID  = 1
    self.trickTimeGo = 0

    self.zoderNum = 0 
    self.isOpenTrcikEnemy = false

    --加入一个监听事件
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_Trick_AddEnemy, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_WaveDataReady, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_EnemyGoOver, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_LifeDie, self)
end

function singleEnemyManager:_checkAddEnemy()
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
        local roadID = tonumber(nowItem["-r"]) or 1
        self:_AddEnemt(enemyItemData,roadID)

        --更新数据
        self.nowEnemyID = self.nowEnemyID + 1
        self.timeGo = 0 
    end

    return true
end

--检测是否需要添加机关怪物
function singleEnemyManager:_checkAddTrickEnemy(dt)
    if self.isOpenTrcikEnemy == false then
        return
    end

    if self.trickWaveData == nil then
        return
    end

    self.trickTimeGo = self.trickTimeGo + dt
    local nowItem = singleLoadData:getInstance():getEnemyItemBornData(self.trickWaveData , self.trickEnemyID)
    if nowItem == nil then
        --处理一波完成事件(继续行动)
        self.trickWaveData = {}
        self.isOpenTrcikEnemy = false
        return
    end    

    local dTime = singleLoadData:getInstance():getEnemyItemBornTime(self.trickWaveData , self.trickEnemyID)
    if dTime <= self.trickTimeGo then
        --获取当前的小怪数据    
        local enemyItemData =singleLoadData:getInstance():getEnemyItem(self.trickWaveData , self.trickEnemyID)
        if enemyItemData == nil then 
            --当下一个怪物不存在的时候。返回
            self.trickWaveData = {}
            self.isOpenTrcikEnemy = false
            return
        end

        --用数据创建敌人
        local roadID = tonumber(nowItem["-r"]) or 1
        self:_AddEnemt(enemyItemData,roadID)

        --更新数据
        self.trickEnemyID = self.trickEnemyID + 1
        self.trickTimeGo = 0 
    end
end

--加入一个怪物，最后两个参数提供给分裂的临时怪物
function singleEnemyManager:_AddEnemt(enemyItemData,roadID,NowPos,NowPosID)
        local actorData = {}
        actorData.name         = enemyItemData["-name"]                   -- 怪物名字
        actorData.life         = tonumber(enemyItemData["-baseHP"]) or 20 -- 生命值
        actorData.speed        = tonumber(enemyItemData["-speed"]) or 30  -- 速度值
        actorData.sclase       = tonumber(enemyItemData["-sclase"]) or 1 -- 放大缩小
        actorData.mainRes      = enemyItemData["-anim"]                   -- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
        actorData.gold         = tonumber(enemyItemData["-gold"]) or 1    -- 获得资源
        actorData.punishHP     = tonumber(enemyItemData["-punishHP"]) or 1 -- 进入通道造成的伤害
        actorData.road         = roadID + 1           -- 道路
        actorData.division     = enemyItemData["-division"] or "-1"
            
        local enemy = require("gameFight.actor.enemy"):create()
        enemy:setData(actorData)
        enemy.nowState = CC_ENEMY_STATE.State_Born
        self:addEnemy(enemy)

        if NowPos ~= nil then
            enemy:setPosition(NowPos)
        end

        if NowPosID ~= nil then
            enemy.nowPosID = NowPosID 
        end

        singleGameData:getInstance():getMainLayer():addChild(enemy,CC_GAME_LAYER_LEVEL.Layer_scene_enemy)
end