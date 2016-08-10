module('cs.schedule.schedule',package.seeall)

----------------------------------------------------
-- class
----------------------------------------------------
class = cs.class.class(_NAME)

local totalScheduleCount = 0

function class:init(target)
    cs.logger.mixin(self)

    self.target = target
    self.entryIDs = {}
end

function class:on(name,interval,pause)
    assert(type(name)=='string','target must be string')

    if self.entryIDs[name] then
        self:logger():e('schedule func['..name..'] twice')
        return
    end
    
    totalScheduleCount = totalScheduleCount + 1
    print("scheduleCount = "..totalScheduleCount)

    local function callback(delta)
        cs.util.callm(self.target,name,delta)
    end
    local entryID = cs.util.schedule(callback,interval,pause)
    self.entryIDs[name] = entryID
end

function class:isScheduleOn(name)
    if self.entryIDs[name] == nil then
        return false
    end
    return true
end

function class:off(name)
    
    if self.entryIDs[name] then
        cs.util.unschedule(self.entryIDs[name])
        self.entryIDs[name] = nil
        totalScheduleCount = totalScheduleCount -1
    end
end

function class:onTotal(name,interval,pause)
    local wrapper = '__shedule_total_wrapper_'..name..'__'
    local method = self.target[name]
    local total = 0
    self.target[wrapper] = function(self,delta)
        total = total + delta
        method(self,total)
    end
    self:on(wrapper,interval,pause)
end

function class:offTotal(name)
    local wrapper = '__shedule_total_wrapper_'..name..'__'
    self:off(wrapper)
end

function class:cleanup()
    for _,entryID in pairs(self.entryIDs) do
        totalScheduleCount = totalScheduleCount -1
        cs.util.unschedule(entryID)
    end
    self.entryIDs = {}
end

----------------------------------------------------
-- apis
----------------------------------------------------
function mixin(target)
    cs.class.mixin(target,'schedule',class:new(target))
end