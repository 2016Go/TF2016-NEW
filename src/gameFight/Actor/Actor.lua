local Actor = class("Actor")

--创建函数
function Actor:create()  
  	self.Camp = CC_CAMP.Camp_All
    print("Actor:create()")
end  

--设置阵营
function Actor:setActorCamp(myCamp)
	self.Camp = myCamp
  	print("Actor:setActorCamp()")
end

return Actor
