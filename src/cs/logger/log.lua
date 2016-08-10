module('cs.logger.log',package.seeall)

-- debug
if Util:isDebug() then

--------------------------------------------------------------
-- 打印一条日志
--------------------------------------------------------------
function _G.log(level, log)
    Log:instance():printL(level, log)
end

--------------------------------------------------------------
-- 设置日志打印规则，参数为字符串，可以设置的规则有(>*, <*, *, *>, *<)，*代表自然数
--------------------------------------------------------------
function _G.setLogRule(...)
    local table = {...}
    Log:instance():setPrintRuleL(table)
end

--------------------------------------------------------------
-- 清除打印规则
--------------------------------------------------------------
function _G.clearRule()
    Log:instance():clearRul()
end

--------------------------------------------------------------
-- 打印指定等级的所有日志
--------------------------------------------------------------
function _G.logA(level, del)
    Log:instance():printA(level, del)
end

else    -- release

function _G.log(...)
end

function _G.setLogRule(...)
end

function _G.clearRule(...)
end

function _G.logA(...)
end

end