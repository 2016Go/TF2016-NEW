module('cs.class.class',package.seeall)

----------------------------------------------------
-- new
----------------------------------------------------
local new = function(thisclass,...)
    local self = {}
    setmetatable(self,thisclass)

    local super = nil
    if thisclass.__superclass then
        super = thisclass.__superclass:new(...)
        self.super = super
        self.super.__index = super
        setmetatable(thisclass,self.super)
    end

    local init = rawget(thisclass,'init')
    if type(init) == 'function' then
        init(self,...)
    end

    return self
end

----------------------------------------------------
-- partial
----------------------------------------------------
function partial(thisclass,part)
    if getmetatable(thisclass) == nil then
        setmetatable(thisclass,part)       
    else
        partial(getmetatable(thisclass),part)
    end
end

----------------------------------------------------
-- 创建类
----------------------------------------------------
function class(classname,superclass)
    assert(type(classname) == 'string','classname must be string')

    thisclass = {} --创建一个全局table
    thisclass.__index = thisclass  --设置搜索表
    thisclass.__classname = classname --设置名字
    thisclass.__superclass = superclass --设置父类？
    thisclass.new = new  --设置new函数

    return thisclass
end

----------------------------------------------------
-- 混合对象
----------------------------------------------------
function mixin(target,name,object)
    target.__mixin__ = target.__mixin__ or {}
    target.__mixin__[name] = object
    target[name] = function(self)
        return self.__mixin__[name]
    end
end

----------------------------------------------------
-- 简单的继承
----------------------------------------------------
function setFather(target,FatherName)
    local Father = { __index = require(FatherName) }
    Father.__index:create()
    setmetatable(target,Father)
end

----------------------------------------------------
-- 全局方法
----------------------------------------------------
_G.CLASS = class
