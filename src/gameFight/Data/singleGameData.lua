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
    end  
    return self.instance  
end 


function singleGameData:setStageData()

end

function singleGameData:setMainLayer(mainLayer)
	self.mainLayer = mainLayer
end

function singleGameData:getMainLayer()
	return self.mainLayer
end