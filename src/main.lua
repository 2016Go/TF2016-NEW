--------------------------------------------------------------
-- Search Paths 开始加入游戏内应该有的一些搜索路径
--------------------------------------------------------------
print("<<<<<cc.FileUtils:getInstance():setPopupNotify(false)>>>>")

cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")
require ("NativeHotUpdate"):init()
require "config"


-- 初始化核心
require('cs.init').init()

-- 此后不在允许随意创建全局变量
require"cocos.init"

--载入一个场景切换的单键类
require("gameUI.gameUIBase.singleUIData")
require("gameUI.gameUIBase.singleUIEvent")
require("gameUI.gameUIBase.singleManagerUI")

print("test  ", DHSkeletonAnimation, type(DHSkeletonAnimation))


-- 简单的报错（可能要写一套更加完善的）
local cclog = function(...)
    print(string.format(...))
end

function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
    return msg
end

local function main()
    -- 设定内存方面的清理
    collectgarbage("collect")
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    --创建随机种子
    math.randomseed(os.time())

    --获取数据单键
    singleUIData:getInstance()
    singleUIEvent:getInstance()

    --载入场景
    local startUI = require("gameUI.startUI"):create()
    singleManagerUI:getInstance():changeUI({} , startUI , CC_UI_GOTO_TPYE.UI_Rep_Scene)
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
