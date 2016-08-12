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
    self:_checkAddEnemt()

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
    end
end


--内部调用初始化函数
function singleEnemyManager:_init()
    self.allEnemy = {}
    self.nextFrameRemoveEnemy = {}
    self.timeGo = 0
    self.waveData = {}
    self.nowEnemyID = 1

    --加入一个监听事件
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_EnemyGoOver, self)
end

function singleEnemyManager:_checkAddEnemt()
    if self.waveData == nil then
        return
    end

    local nowItem = self.waveData["e"][self.nowEnemyID]
    if nowItem == nil then
        --处理一波完成事件
        self.waveData = nil
        return
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
        actorData.speed        = 50                    -- 速度值
        actorData.mainRes      = "babyspirit"          -- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
        actorData.standName    = "stand"               -- 站立动作名字
        actorData.walk         = "walk"                -- 站立动作名字
        actorData.road         = 1                     -- 站立动作名字

        local Enemy1 = require("gameFight.actor.enemy"):create()
        Enemy1:setData(singleGameData:getInstance().actorData)
        Enemy1.nowState = CC_ENEMY_STATE.State_Born
        self:addEnemy(Enemy1)
        singleGameData:getInstance():getMainLayer():addChild(Enemy1,99)
    end
end

