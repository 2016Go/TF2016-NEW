module('cs.util.util',package.seeall)

----------------------------------------------------
-- 安全调用本地代码
----------------------------------------------------
function native(target,method,arg0,...)
    assert(type(target) == "string","target must be string")
    assert(type(method) == "string","method must be string")

    -- 只有使用objc或者java的反射调用第一个参数才是表
    -- 所以使用第一个参数是否为表来判断哪个native调用方式
    if type(arg0) == "table" then
        -- 获取系统信息
        local os = native("BuiltIn","get",C_BUILT_IN_OS) or "unknown"

        -- 调用方法映射
        local mapping = {
            ["windows"] = nil,
            ["macosx"] = luaoc.callStaticMethod,
            ["ios"] = luaoc.callStaticMethod,
            ["android"] = luaj.callStaticMethod,
        }

        -- 调用
        local callable = mapping[os]
        if callable then
            return callable(target,method,arg0)
        else
            cs.logger.w(_NAME, "call native failed("..os.." not support)", target, method, arg0, ...)
        end
    else
        -- 获取目标类
        local callableTarget = _G[target]
        if type(callableTarget) ~= "table" then
            cs.logger.w(_NAME, "call native failed", target, method, arg0, ...)
            return
        end

        -- 获取方法
        local callableMethod = callableTarget[method]
        if type(callableMethod) ~= "function" then
            cs.logger.w(_NAME, "call native failed", target, method, arg0, ...)
            return
        end

        -- 调用
        if arg0 then
            return callableMethod(callableTarget,arg0,...)
        else
            return callableMethod(callableTarget)
        end
    end
end

----------------------------------------------------
-- apis
----------------------------------------------------

-- 分割字符串
function split(src, token)
    local sub_str_tab = {}

    while (true) do
        local pos = string.find(src, token)

        if (not pos) then
            sub_str_tab[#sub_str_tab + 1] = src
            break
        end

        local sub_str = string.sub(src, 1, pos - 1)
        sub_str_tab[#sub_str_tab + 1] = sub_str
        src = string.sub(src, pos + 1, #src)
    end

    return sub_str_tab
end

--判断字符串是否仅由字母和数字组成
function isalphanum (str)
    if str == nil then
        return false
    end
    local len = string.len(str)
    for i = 1, len do
        local ch = string.sub(str, i, i)
        if not ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9')) then
            return false
        end
    end
    return true
end

-- 表拷贝
function tablecpy(src)
    if not src then
        return
    end

    local lookup = {}
    local function cpy(src)
        if type(src) ~= 'table' then
            return src
        elseif lookup[src] then
            return lookup[src]
        end

        local new_table = {}
        lookup[src] = new_table

        for i,v in pairs(src) do
            new_table[cpy(i)] = cpy(v)
        end

        return setmetatable(new_table,getmetatable(src))
    end

    return cpy(src)
end

-- 调用函数
function callf(target,name,...)
    if type(target[name]) == 'function' then
        target[name](...)
    end
end

-- 调用方法
function callm(target,name,...)
    if type(target[name]) == 'function' then
        target[name](target,...)
    end
end

-- 调用方法
function call(data,...)
    if not data then
        return
    end

    local tData = type(data)
    local func = nil
    local target = nil
    if tData=='function' then
        func = data
        target = nil
    elseif tData=='table' then
        func = data[1]
        target = data[2]
    end
    local tTarget = type(target)

    if tTarget=='table' then
        local tFunc = type(func)

        if tFunc=='string' then
            --print('going callm-157')
            callm(target,func,...)
        elseif tFunc=='function' then
            --print('going func-160')
            func(target,...)
        end
    else
        local tFunc = type(func)

        if tFunc=='string' then
            --print('going callf-167')
            callf(target,func,...)
        elseif tFunc=='function' then
            --print('going func-170')
            --print(func)
            func(...)
        end
    end
end

-- 注册调度
function schedule(handler,interval,paused)
    return cc.Director:getInstance():getScheduler():scheduleScriptFunc(handler,interval or 0,paused or false);
end

-- 注销调度
function unschedule(entryID)
    cc.Director:getInstance():getScheduler():unscheduleScriptEntry(entryID)
end

-- 编译文件
function compilef(filename,fixfunc)
    local data = cc.FileUtils:getInstance():getStringFromFile(filename);
    if not data or data == '' then
        return
    end

    local code = (type(fixfunc)=='function') and fixfunc(data) or 'return {\n'..data..'\n}'
    local func,err = loadstring(code)
    if not func then
        return nil,err
    end

    return func
end

-- 获取UserDefault
function readUD(key,default)
    local value = cc.UserDefault:getInstance():getStringForKey(key)
    return value=='' and default or value
end

-- 设置UserDefault
function writeUD(key,value)
    if value then
        cc.UserDefault:getInstance():setStringForKey(key,value)
    end
end

-- 写入UserDefault
function flushUD()
    cc.UserDefault:getInstance():flush()
end

function dlog(t,indent,_tk)
    if indent then
        indent = indent .. '  '
    else
        indent = ''
    end    
    print(indent..(_tk and _tk..' = ' or '')..'{')
    for k, v in pairs(t or {}) do
        if (type(v) == 'table') then
            dlog(v,indent,k)
        else
            print('  '..indent..k..'='..tostring(v))
        end
    end
    print(indent..'}')
end

----------------------------------------------------
-- 安全json解码
----------------------------------------------------
function json_decode(src)
    src = string.gsub(src,"\r","")
    src = string.gsub(src,"\n","")
    return json.decode(src)
end

----------------------------------------------------
-- 合并路径
----------------------------------------------------
function combine_path(...)
    local len = select("#",...)
    assert(len>0,"no args")

    local combined = select(1,...)

    for i=2,select("#",...) do
        local part = select(i,...)
        combined = combined .. "/" .. part
    end

    local fixed = Util:fixPath(combined)
    return fixed
end

----------------------------------------------------
-- 基于WritablePath合并路径
----------------------------------------------------
function combine_writable_path(...)
    local writablePath = cc.FileUtils:getInstance():getWritablePath()
    return combine_path(writablePath,...)
end

function _printTable( lua_table, indent )
    local function print_func(str)
        print("[>>>>>>>] " .. tostring(str))
    end
    indent = indent or 0
    for k, v in pairs(lua_table) do
        if type(k) == "string" then
            k = string.format("%q", k)
        end
        local szSuffix = ""
        if type(v) == "table" then
            szSuffix = "{"
        end
        local szPrefix = string.rep("    ", indent)
        formatting = szPrefix.."["..k.."]".." = "..szSuffix
        if type(v) == "table" then
            print_func(formatting)
            _printTable(v, indent + 1)
            print_func(szPrefix.."},")
        else
            local szValue = ""
            if type(v) == "string" then
                szValue = string.format("%q", v)
            else
                szValue = tostring(v)
            end
            print_func(formatting..szValue..",")
        end
    end
end

--------------------------------------
-- @brief   输出table数据
--------------------------------------
function printTable (lua_table, indent)
    if lua_table == nil or type(lua_table) ~= "table" then
        print('[printTable]>>>>>>>>> table is nil or invalid table.')
        return
    end

    print('----------------printTable begin-------------------')
    _printTable(lua_table, indent)
    print('----------------printTable end---------------------\n')
end

----------------------------------------------------
-- extends
----------------------------------------------------
_G.table.containsk = function(table,key)
    for k,v in pairs(table) do
        if key == k then
            return v
        end
    end
end

_G.table.containsv = function(table,value)
    for k,v in pairs(table) do
        if value == v then
            return k
        end
    end
end

_G.table.first = function(table,func)
    for k,v in pairs(table) do
        if func(k,v) then
            return k,v
        end
    end
end

_G.table.icombine = function(...)
    local res = {}

    local len = select("#",...)
    for i = 1, len do
        local t = select(i,...)
        for k,v in ipairs(t) do
            table.insert(res,v)
        end
    end

    return res
end