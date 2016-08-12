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
        self.AllEnemy = {}
        self.NextFrameRemoveEnemy = {}
    end  
    return self.instance  
end 

--开始每帧更新敌人管理器
function singleEnemyManager:UpData(dt)
    for i,v in ipairs(self.AllEnemy) do
        v:UpData(dt)
    end
end

--加入一个敌人
function singleEnemyManager:addEnemy(myEnemy)
    table.insert(self.AllEnemy, myEnemy)
end

--删除一个敌人，下一帧
function singleEnemyManager:removeEnemyNextFrame(myEnemy)
    table.insert(self.NextFrameRemoveEnemy, myEnemy)
end

--删除一个敌人，内部调用
function singleEnemyManager:removeEnemy(myEnemy)
    for i,v in ipairs(self.AllEnemy) do
        if v == myEnemy then
            table.remove( self.AllEnemy, i )
        end
    end
end