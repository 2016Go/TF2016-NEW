local fightLoadingUI = class("fightLoadingUI", function() return cc.Layer:create() end)

function fightLoadingUI:ctor()
	self.UI.loadingSp = cc.Sprite:create("UI/loading/loading.png")
	self:addChild(self.UI.loadingSp)
end

return fightLoadingUI