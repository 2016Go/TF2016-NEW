module('cs.conf.init',package.seeall)

return function(params)
    local conf = require('cs.conf.conf')
    conf.global(params)
    return conf
end
