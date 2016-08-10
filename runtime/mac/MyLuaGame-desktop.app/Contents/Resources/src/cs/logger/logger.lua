module('cs.logger.logger',package.seeall)

----------------------------------------------------
-- locals
----------------------------------------------------
local _isOn_ = {
    d = true,
    i = true,
    w = true,
    e = true,
}

local function _on_(key,value)
    assert(type(key) == 'string','key must be string')
    assert(type(value) == 'boolean','key must be boolean')

    if key == 'd' or key == 'i' or key == 'w' or key == 'e' then
        _isOn_[key] = value
    else
        error('unknown key['..key..']')
    end
end

local function _s_(...)
    local s = ''

    for i = 1,select('#',...) do
        local v = select(i,...)
        s = s..tostring(v)..' '
    end

    return s
end

----------------------------------------------------
-- apis
----------------------------------------------------
function on(key,value)
    _on_(key,value)
end

function isOn(key)
    return _isOn_[key]
end

function d(name,...)
    if _isOn_.d then
        local message = 'debug '..name..' - '.._s_(...)
        print(message)
    end
end

function i(name,...)
    if _isOn_.i then
        local message = 'info '..name..' - '.._s_(...)
        print(message)
    end
end

function w(name,...)
    if _isOn_.w then
        local message = 'warn '..name..' - '.._s_(...)
        print(message)
    end
end

function e(name,...)
    if _isOn_.e then
        local message = 'error '..name..' - '.._s_(...)
        print(message)
    end
end

----------------------------------------------------
-- logger
----------------------------------------------------
class = cs.class.class(_NAME)

function class:init(name)
    self.name = name
end

function class:getName()
    return self.name
end

function class:isOn(key)
    return isOn(key)
end

function class:d(...)
    d(self.name,...)
end

function class:i(...)
    i(self.name,...)
end

function class:w(...)
    w(self.name,...)
end

function class:e(...)
    e(self.name,...)
end

----------------------------------------------------
-- mixin
----------------------------------------------------
function mixin(target)
    assert(type(target) == 'table','target must be table')
    assert(getmetatable(target),'target must be object')

    local name = getmetatable(target).__classname

    cs.class.mixin(target,'logger',class:new(name))
end
