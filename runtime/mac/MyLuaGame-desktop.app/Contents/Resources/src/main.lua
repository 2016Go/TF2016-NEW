--------------------------------------------------------------
-- Search Paths 开始加入游戏内应该有的一些搜索路径
--------------------------------------------------------------
print("<<<<<cc.FileUtils:getInstance():setPopupNotify(false)>>>>")
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")

require "config"


-- 初始化核心
require('cs.init').init()

-- 此后不在允许随意创建全局变量
require "cocos.init"

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

    --cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(1334, 750, cc.ResolutionPolicy.NO_BORDER) 

    require("gameFight.fightMainScene"):create()
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
