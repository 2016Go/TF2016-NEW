module('cs.i18n.i18n',package.seeall)

local _prefix_ = nil
local _default_ = {}
local _languages_ = {}

local function fail(filename,reason)
    cs.logger.e(_NAME,'load i18n file '..filename..' failed('..reason..')')
end

function init(prefix,default)
    if prefix then
        _prefix_ = prefix
    end

    if default then
        _default_ = default
    end
end

function load(lang)
    assert(type(lang)=='string','lang must be string')

    local language = _languages_[lang]
    if not language then
        local filename = _prefix_..lang..'.conf'
        local func = cs.util.compilef(filename)
        if not func then
            fail(filename,'can not compile file')
            return
        end

        language = func()
        _languages_[lang] = language
    end

    return language
end

function i18n(langid,id,...)
    local language = load(langid)
    if not language then
        return id
    end

    local lang = language[id]
    if not lang then
        return id
    end

    for i=1,select('#',...) do
        local k = '{'..i..'}'
        local v = select(i,...)
        lang = string.gsub(lang,k,v)
    end

    return lang
end

function get(id,...)
    return i18n(_default_,id,...)
end
