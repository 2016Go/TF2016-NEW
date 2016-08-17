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
		local scene = cc.Director:getInstance():getRunningScene()

		--加入销毁回调函数
     	local function onNodeEvent(event)  
        	if event == "enter" then  
        		if changeUI.enter ~= nil then changeUI:enter() end
        	elseif event == "enterTransitionFinish" then  
            	if changeUI.enterTransitionFinish ~= nil then changeUI:enterTransitionFinish() end
        	elseif event == "exit" then  
            	if changeUI.exit ~= nil then changeUI:exit() end
        	elseif event == "exitTransitionStart" then  
            	if changeUI.exitTransitionStart ~= nil then changeUI:exitTransitionStart() end
        	elseif event == "cleanup" then  
            	if changeUI.cleanup ~= nil then changeUI:cleanup() end
        	end  
    	end  
  		changeUI:registerScriptHandler(onNodeEvent) 
    	
    	--创建这个层
		local scene = cc.Scene:create()
		scene:addChild(changeUI)
		cc.Director:getInstance():replaceScene(scene)
	end
end

--绑定某一个控件的监听事件
function singleManagerUI:bindListener(node,target,name)
	-- 分类型绑定
    local type = tolua.type(node)

    --不绑定Node
    if type == 'cc.Node' then
        return
    end

    if type == 'ccui.Button' then
        self:_bindTouch(node,target,name)
    elseif type == 'ccui.CheckBox' then
        --_do_bind_checkBox_(node,target)
        --_bindTouch(node,target,name,'CheckBox')
    elseif type == 'ccui.LoadingBar' then
       -- _bindTouch(node,target,name,'LoadingBar')
    elseif type == 'ccui.Slider' then
        --_bindTouch(node,target,name,'Slider')
    elseif type == 'ccui.ScrollView' then----
        --_bindTouch(node,target,name,'ScrollView')
        --_do_bind_scrollView_(node, target)
    elseif type == 'ccui.ListView' then----
        --_bindTouch(node,target,name,'ListView')
    elseif type == 'ccui.PageView' then---
        --_do_bind_pageView_(node,target)
        --_bindTouch(node,target,name,'PageView')
    else
        cs.logger.i("_bindTouch")
        self:_bindTouch(node,target,name)
    end
end

local _createEventFunc = function(widget,eventName)
    return function(target,...)
        if not cs.util.call(eventInterceptor,"before",widget,eventName,...) then
            cs.util.callm(target,widget:getName()..eventName,...)
            cs.util.call(eventInterceptor,"after",widget,eventName,...)
        end
    end
end

function singleManagerUI:_bindTouch(node,target,name)
    -- 获取参数
    local widget = tolua.cast(node,'ccui.Widget')
    widget:setName(name)
    -- 方法映射
    local mapping = 
    {
        [ccui.TouchEventType.began]     = _createEventFunc(widget,"TouchBegan"),
        [ccui.TouchEventType.moved]     = _createEventFunc(widget,'TouchMoved'),
        [ccui.TouchEventType.ended]     = _createEventFunc(widget,'TouchEnded'),
        [ccui.TouchEventType.canceled]  = _createEventFunc(widget,'TouchCanceled'),
    }

    local listener = function(sender,type)
        --保存第一次点击的 sender
        --to do youwei
        --制作防手抽代码

        -- 播放声音
        -- to do youwei
        --制作播放声音代码
        cs.logger.i("listener"..type)
        cs.util.call(mapping[type], target, sender, type)
    end

    -- 添加触控事件侦听器
    widget:addTouchEventListener(listener)
end
