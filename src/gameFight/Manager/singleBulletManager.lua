--战斗时间管理单键类
if cc.exports.singleBulletManager == nil then
    cc.exports.singleBulletManager = {} 
end

function singleBulletManager:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleBulletManager:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()
        self.instance:_init()
    end  
    return self.instance  
end 

--开始每帧更新敌人管理器
function singleBulletManager:UpData(dt , iCountTime)
    --如果双数计时，不执行，如此来提高游戏效率
  
      --更新每一个塔的数据
    for k,v in pairs(self.allBullet) do
       v:UpData(dt)
    end

    --先删除
    for i,v in pairs(self.nextFrameRemoveBullet) do
        self:_removeBullet(v)
    end 

    --再添加
    for i,v in pairs(self.nextFrameAddBullet) do
        table.insert(self.allBullet, v)
    end 

    self.nextFrameAddBullet = {}
    self.nextFrameRemoveBullet = {}
end

--加入一个塔
function singleBulletManager:addBullet(myBullet)
    table.insert(self.nextFrameAddBullet, myBullet)
end

--删除一个塔，下一帧
function singleBulletManager:removeBulletNextFrame(myBullet)
    table.insert(self.nextFrameRemoveBullet, myBullet)
end

function singleBulletManager:eventResponse(gameEventID, eventSender, parameter)
    if gameEventID == CC_GAME_EVENT.GameEvent_BuildBullet then
        local thisBullet = require("gameFight.actor.bullet"):create()
        --在其出生里面设定坐标位置
        thisBullet:born(parameter)
        thisBullet:setFirer(eventSender)
        self.mainLayer:addChild( thisBullet , CC_GAME_LAYER_LEVEL.Layer_scene_bullet )
        self:addBullet(thisBullet)
    elseif gameEventID == CC_GAME_EVENT.GameEvent_BulletCollision then
        --if parameter.aoe == 0 then

        --对敌方造成伤害
        for k,v in pairs(parameter.targetEnemy) do
            if self:_checkBulletTarget(v) == true then
                v:Hit(parameter)
            end
        end

        --如果为弹射子弹，子弹弹射次数减少1次
        if eventSender.bulletData['fireMode']["mode"] == 3 then
            eventSender.bulletData['fireMode']["iTime"] = eventSender.bulletData['fireMode']["iTime"] -1
        end
    --删除子弹
    elseif gameEventID == CC_GAME_EVENT.GameEvent_BulletDie then
            print("move")
            self:removeBulletNextFrame(eventSender)
    end 
end


--检测子弹目标的有效性
function singleBulletManager:_checkBulletTarget(targetEnemy)
    if targetEnemy == nil then
        return
    end

    --判断目标是否依旧在管理器中
    if singleEnemyManager:getInstance():checkEnemyIsInManager( targetEnemy ) == false then
        return false
    end

    --判断目标是否还有生命值
    if targetEnemy.actorData.life <= 0 then
        return false
    end

    return true
end

--设定一个加载层级方便add
function singleBulletManager:setLayer( mainLayer )
    self.mainLayer = mainLayer
end

function singleBulletManager:_removeBullet(myBullet)
    for i,v in pairs(self.allBullet) do
        if v == myBullet then
            table.remove( self.allBullet, i )
            v:clear()
            return
        end
    end
end

function singleBulletManager:_init()
    self.nextFrameRemoveBullet = {}
    self.nextFrameAddBullet = {}
    self.allBullet = {}

    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_BulletDie, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_BuildBullet, self)
    singleGameEventPool:getInstance():addEventListenerInPool(CC_GAME_EVENT.GameEvent_BulletCollision, self)
end