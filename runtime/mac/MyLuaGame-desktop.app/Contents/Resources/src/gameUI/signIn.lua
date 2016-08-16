local signInUI = class("signInUI", function() return cc.Layer:create() end)

--初始化函数
function signInUI:ctor()
	--初始化监听数据，初始化数据
	cs.logger.i("signInUI:ctor()")

	self.UI = {}
	self.UI.bgSp = cc.Sprite:create("UI/bg.png")
	self:addChlid(self.UI.bgSp)

end  

return signInUI
