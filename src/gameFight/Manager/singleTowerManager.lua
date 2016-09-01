--战斗时间管理单键类
if cc.exports.singleTowerManager == nil then
    cc.exports.singleTowerManager = {} 
end

function singleTowerManager:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleTowerManager:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()
        self.instance:_init()
    end  
    return self.instance  
end 

--开始每帧更新敌人管理器
function singleTowerManager:UpData(dt , iCountTime)
    --如果双数计时，不执行，如此来提高游戏效率
    self.dt = self.dt + dt
    if iCountTime == 1 then
        return
    end    
    
    --先删除
    for i,v in pairs(self.nextFrameRemoveTower) do
        self:_removeTower(nextFrameRemoveTower)
    end 

    --再添加
    for i,v in pairs(self.nextFrameAddTower) do
        table.insert(self.allTower, v)
    end 

    --更新每一个塔的数据
    for k,v in pairs(self.allTower) do
       v:UpData(self.dt)
    end

    self.nextFrameAddTower = {}
    self.nextFrameRemoveTower = {}
    self.dt = 0
end


--加入一个塔
function singleTowerManager:addTower(myTower)
    table.insert(self.nextFrameAddTower, myTower)
end

--删除一个塔，下一帧
function singleTowerManager:removeTowerNextFrame(myTower)
    table.insert(self.nextFrameRemoveTower, myTower)
end

function singleTowerManager:_removeTower(myTower)
    for i,v in pairs(self.allTower) do
        if v == myTower then
            table.remove( self.allTower, i )
            --allTower:clear()
            return
        end
    end
end

--设定一个加载层级方便add
function singleTowerManager:setLayer( mainLayer )
    self.mainLayer = mainLayer
end

function singleTowerManager:_init()
    self.nextFrameRemoveTower = {}
    self.nextFrameAddTower = {}
    self.allTower = {}
    self.dt = 0
end
