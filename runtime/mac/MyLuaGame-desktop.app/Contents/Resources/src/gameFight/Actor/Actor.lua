print("require actor")

local actor = class("actor", function()   print("cc.Node:create()") return cc.Node:create() end)

--初始化函数
function actor:ctor()
  	self.Camp = CC_CAMP.Camp_All
    print("actor:ctor()")
end  

--设置阵营
function actor:setActorCamp(myCamp)
	self.Camp = myCamp
  	print("actor:setActorCamp()")
end

return actor
