module('cs.events.events',package.seeall)

----------------------------------------------------
-- class
----------------------------------------------------
class = cs.class.class(_NAME)

function class:init()
    self.listenerArrays = {}
end

function class:on(name,target,func)
    assert(type(name) == 'string' or type(name) == 'number','name must be string or number')
    assert(type(target) == 'table','target must be table')
    assert(type(func) == 'string','func must be string')

    local listeners = self.listenerArrays[name]
    if not listeners then
        self.listenerArrays[name] = {}
        listeners = self.listenerArrays[name]
    end

    local listener = {
        target = target,
        func = func,
    }

    table.insert(listeners,listener)
    self.listenerArrays[name] = listeners
end

function class:off(name,target)
    assert(type(name) == 'string' or type(name) == 'number','name must be string or number')
    assert(type(target) == 'table','target must be table')

    local listeners = self.listenerArrays[name]
    if listeners then
        for i,v in ipairs(listeners) do
            if v.target == target then
                table.remove(listeners,i)
            end
        end
    end
end

------
--发送事件，并加入事件回馈机制
-------
function class:fire(name,...)
    assert(type(name) == 'string' or type(name) == 'number','name must be string or number')
    print(' events listeners name : '..name)

    local listeners = self.listenerArrays[name]

    --如果没有监听事件，返回
    if listeners then
        local args = {...}
        for _,v in ipairs(listeners) do
            xpcall(function()
                local target = v.target
                local name = v.func
                local func = target[name]
                if type(func) == 'function' then
                    func(target,unpack(args))
                end
            end,__G__TRACKBACK__)
        end
    end
end

----------------------------------------------------
-- apis
----------------------------------------------------
function mixin(target)
    cs.class.mixin(target,'events',class:new())
end
