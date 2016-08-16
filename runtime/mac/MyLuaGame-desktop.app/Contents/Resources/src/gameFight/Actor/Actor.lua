local actor = class("actor", function() return cc.Layer:create() end)

--初始化函数
function actor:ctor()
  	self.Camp = CC_CAMP.Camp_All
end  

--设置阵营
function actor:setActorCamp(myCamp)
	self.Camp = myCamp
end

return actor
