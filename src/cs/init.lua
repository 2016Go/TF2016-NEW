module('cs.init',package.seeall)

----------------------------------------------------
-- 设计分辨率
----------------------------------------------------
--_G.C_DESIGN_RESOLUTION_DH = 540
--_G.C_DESIGN_RESOLUTION_DW = 960

----------------------------------------------------
-- C_BUILT_IN_OS:系统
--  windows         瘟到死
--  macosx          马克欧艾斯嚓
--  ios             艾欧艾斯
--  android         安捉欧德
-- C_BUILT_IN_OS_VER:系统版本
--  windows@7       Windows 7
--  windows@8       Windows 8
--  macosx@*        Mac OS X
--  ios@6           IOS 6
--  ios@7           IOS 7
--  ios@8           IOS 8
--  android@4       Android 4
--  {x}@unknown     {x}系统未知版本
----------------------------------------------------
_G.C_BUILT_IN_OS = "os"
_G.C_BUILT_IN_OS_VER = "os_ver"

function init(params)
    local cs = _G.cs or {} --创建G表

    -- 类
    cs.class = require('cs.class.class')
    
    -- 内存
    cs.memory = require('cs.memory.memory')

    -- 工具
    cs.util = require('cs.util.util')

    -- 事件
    cs.events = require('cs.events.events')
    
    -- 日志
    cs.logger = require('cs.logger.logger')
    
    -- 调度
    cs.schedule = require('cs.schedule.schedule')

    -- 缓存,用于管理单键类
    cs.cache = require('cs.cache.cache')

    -- 配置
    cs.conf = require('cs.conf.init')({})

    -- 配置文件载入
    if type(CC_CONFIG) == 'table' then
        for _,v in ipairs(CC_CONFIG) do
            print(v.src.." == "..v.name)
            cs.conf.attach(v.src,v.name)
        end
    end

    -- 语言报错框
    -- cs.i18n = require('cs.i18n.init')()
end