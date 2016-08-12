local NativeHotUpdate = {}

function NativeHotUpdate:init()
    local app = cc.Application:getInstance()
    local target = app:getTargetPlatform()
	if target == 2 then--mac
		self.initFlag = true

		local filepath = "../../../../../"
		cc.FileUtils:getInstance():setSearchPaths({})
		cc.FileUtils:getInstance():addSearchPath(filepath.."src/")
		cc.FileUtils:getInstance():addSearchPath(filepath.."res/")

        cc.UserDefault:getInstance():setStringForKey("curHotUpdateVersion", "")
	end
end

function NativeHotUpdate:isReady()
    return self.initFlag == true
end

function NativeHotUpdate:restart(cleanup)
	if not self:isReady() then
		return
	end

    --清理资源
    if cleanup then
        local resourceManager = require("app.uiutils.ResourceManager")
        resourceManager:clear()
    else
        local soundManager = require("common.SoundManager")
        soundManager:stopAllSound()
    end

    --战斗逻辑清理
    local gameManager = require("battle.controls.GameManager")
    gameManager:cleanGame()

    --移除所有监听
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher() 
    eventDispatcher:removeAllEventListeners()

    --停掉所有全局定时器
    local schedulerUtil = require("app.utils.SchedulerUtil")
    schedulerUtil:unscheduleAll()

    --断开PC连接
    PC:close(nil, true)

	local hotUpdateHelper = require("common.HotUpdateHelper")
    hotUpdateHelper:clearModules()

    require("app.MyApp").startGame()
end

function NativeHotUpdate:onSceneInit(scene)
	if not self:isReady() then
        return
    end

    local HotUpdateLayer = require("app.ui.HotUpdateLayer")
	local layer = HotUpdateLayer.new()
	scene:addChild(layer, 10000)
end

return NativeHotUpdate