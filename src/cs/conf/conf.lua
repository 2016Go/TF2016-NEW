module('cs.conf.conf',package.seeall)

if not json then
    require "cocos.cocos2d.json"
end

------------------------------
local global_flename
local globals = {}

local _global_ = function(filename)
    local func = cs.util.compilef(filename)
    if not func then
        error('missing conf '..filename)
    end
    local values = func()
    table.insert(globals,1,values)
end

function reload_global()
    globals = {}
    
    if type(global_flename) == 'table' then
        for _,v in ipairs(global_flename) do
            _global_(v)
        end
    else
        _global_(global_flename)
    end
end

function global(filename)
    global_flename = filename
    reload_global()
end

function g(id,default)
    for _,values in ipairs(globals) do
        local value = values[id]
        if value then
            return value
        end
    end
    return default
end

------------------------------
local attaches = {}

function attach(filename,name)
    local func = cs.util.compilef(filename)
    if not func then
        error('missing conf '..filename)
    end

    local values = func()
    local data = {
        ['values'] = values,
        ['ids'] = {}
    }

    if values['_ids_'] then
        data['ids'] = values['_ids_']
        values['_ids_'] = nil
    end

    if values['_jsons_'] then
        local jsons = values['_jsons_']
        for id,value in pairs(values) do
            for name,j in pairs(value) do
                if table.containsv(jsons,name) then
                    if j == '' then
                        value[name] = {}
                    else
                        xpcall(function()
                            value[name] = json.decode(j)                           
                        end,function()
                            cs.logger.e(_NAME,'attach:'..filename..' id:'..id..' invalid json string:'..j)
                        end)
                    end
                end
            end
        end
        values['_jsons_'] = nil
    end

    attaches[name] = data
end

function attachidx(name,indexNames)
    -- 获取附加
    local attach = attaches[name]
    if not attach then
        return
    end

    -- 建立索引总表
    attach.indices = attach.indices or {}

    -- 搜索类型
    for _,indexName in ipairs(indexNames) do
        -- 建立类型索引表
        local typelookup = attach.indices[indexName] or {}

        -- 添加值
        for _,v in pairs(attach.values) do
            local idx_v = v[indexName]
            local idx_a = typelookup[idx_v] or {}
            table.insert(idx_a,v)
            typelookup[idx_v] = idx_a
        end

        -- 保存表
        attach.indices[indexName] = typelookup
    end
end

function a(name,id,default)
    local attach = attaches[name]
    if attach then
        local value = attach.values[id]
        if value then
            return value
        end
    end
    return default
end

function  size(name)
   local attach = attaches[name]
    if attach then
        local  num  = 0 
        for  _ ,value in pairs(attach.values) do
                if  value  ~= nil  then
                        num  =  num  +  1  
                end
        end
        return num
    end
    return nil
end

function getAllIndex(name)
        local attach = attaches[name]
        local idlist = {}
        local i = 1
        for _,v in pairs(attach.values) do
            idlist[i] = _
            i = i+1
        end
        return idlist or nil
end

function ai(name,typename,idxname,default)
    local attach = attaches[name]
    if (not attach) or (not attach.indices) then
        return default
    end

    local typelookup = attach.indices[typename]
    if not typelookup then
        return default
    end

    local idx = typelookup[idxname]
    return idx or default
end

function ids( name, default )
    local attach = attaches[name]
    if attach then
        return attach.ids or default
    end
    return default
end

function all( name )
    local attach = attaches[name]
    if attach then
        return attach
    end
    return nil
end