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


function singleGameData:createTestData()
	--普通小怪数据，假数据
	self.actorData = {}

	self.actorData.name  		= "飞翔的小鸟"			-- 怪物名字
	self.actorData.life  		= 100  					-- 生命值
	self.actorData.speed 		= 15 					-- 速度值
	self.actorData.mainRes 		= "babyspirit/walk/"	-- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
	self.actorData.standName	= "stand"				-- 站立动作名字
	self.actorData.walk			= "walk"				-- 站立动作名字
	self.actorData.road			= 1						-- 站立动作名字
end