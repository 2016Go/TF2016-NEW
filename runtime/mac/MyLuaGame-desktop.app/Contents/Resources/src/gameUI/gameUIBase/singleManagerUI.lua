--战斗场景单键类
if cc.exports.singleManagerUI == nil then
    cc.exports.singleManagerUI = {} 
end

function singleManagerUI:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleManagerUI:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
    end  
    return self.instance  
end

function singleManagerUI:changeUI(nowUI , changeUI, changeTpye)  
	if nowUI == nil then
		cs.logger.w("nowUI == nil")
	end

	if changeUI == nil then
		cs.logger.w("changeUI == nil")
	end

	changeTpye = changeTpye or CC_UI_GOTO_TPYE.UI_Add_Layer
	if changeTpye == CC_UI_GOTO_TPYE.UI_Add_Layer then
		
	elseif changeTpye == CC_UI_GOTO_TPYE.UI_Add_Bomb then
	
	elseif changeTpye == CC_UI_GOTO_TPYE.UI_Rep_Scene then
		local scene = cc.Scene:create()
		scene:addChild(changeUI)
		cc.Director:getInstance():replaceScene(scene)
	end
end




--[[界面跳转的方式
CC_UI_GOTO_TPYE = 
{
    UI_Add_Layer = 1,           --层直接覆盖跳转
    UI_Add_Bomb  = 2,           --弹框覆盖跳转
    UI_Rep_Scene = 3            --场景切换
}
--]]

