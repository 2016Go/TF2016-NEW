module('cs.i18n.init',package.seeall)

return function()
    local i18n = require('cs.i18n.i18n')
    i18n.init(cs.conf.g('init-i18n-prefix'),cs.conf.g('init-i18n-default'))
    return i18n
end
