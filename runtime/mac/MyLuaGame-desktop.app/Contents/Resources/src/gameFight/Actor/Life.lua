local Life = class("Actor.Life")

--成员函数
local Life = nil

--[[
function Life:create(configs)
    --其阵营表示
    self.Camp = CC_CAMP.Camp_All
  
end
--]]

function  Life:setLifeData(LifeData)
	self.LifeData = {}

	self.LifeData.life = LifeData.life  --生命值
	self.LifeData.speed = LifeData.speed -- 速度值
	
end

return Life