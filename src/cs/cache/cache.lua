module('cs.cache.cache',package.seeall)

----------------------------------------------------
-- 安全调用本地代码
----------------------------------------------------
local allSingle = {}

function get(name)
    if allSingle[name]  == nil then
        allSingle[name] = require("gameFight.fightMainScene"):create()
    end
    return allSingle[name]
end
