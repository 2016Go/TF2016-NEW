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

function singleTowerManager:_init()
    self.tower_1 = {}
    self.tower_2 = {}
    self.tower_3 = {}
    self.tower_4 = {}

end
