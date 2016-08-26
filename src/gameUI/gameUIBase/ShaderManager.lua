local ShaderType = {
    HIGHTLIGHT = 1,
    GRAY = 2,
    COFFEE = 3,
    TIMER_GRAY = 4,
}

local ShaderManager = {}

ShaderManager.cache = {
    [ShaderType.HIGHTLIGHT] = {
        vPath = "shader/DefaultShader.vsh",
        fPath = "shader/HighlightShader.fsh",
    },

    [ShaderType.GRAY] = {
        vPath = "shader/DefaultShader.vsh",
        fPath = "shader/GrayShader.fsh",
    },

    [ShaderType.COFFEE] = {
        vPath = "shader/DefaultShader.vsh",
        fPath = "shader/CoffeeShader.fsh",
    },

    [ShaderType.TIMER_GRAY] = {
        vPath = "shader/MvpShader.vsh",
        fPath = "shader/GrayShader.fsh",
    },
}

ShaderManager.ShaderType = ShaderType

function ShaderManager:load()
    for id, info in pairs(self.cache) do
        local shader = cc.GLProgram:createWithFilenames(info.vPath, info.fPath)
        shader:bindAttribLocation(cc.ATTRIBUTE_NAME_POSITION, cc.VERTEX_ATTRIB_POSITION)
        shader:bindAttribLocation(cc.ATTRIBUTE_NAME_COLOR, cc.VERTEX_ATTRIB_COLOR)
        shader:bindAttribLocation(cc.ATTRIBUTE_NAME_TEX_COORD, cc.VERTEX_ATTRIB_TEX_COORD)
        
        shader:retain()
        self.cache[id].shader = shader
	end
    
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
    local customListener = cc.EventListenerCustom:create("event_renderer_recreated", function (event)
        self:reload()
    end)
    
    eventDispatcher:addEventListenerWithFixedPriority(customListener, 1)
end

function ShaderManager:reload()
    for _, info in pairs(self.cache) do
        local shader = info.shader
        shader:reset()
        shader:initWithFilenames(info.vPath, info.fPath)
        shader:bindAttribLocation(cc.ATTRIBUTE_NAME_POSITION, cc.VERTEX_ATTRIB_POSITION)
        shader:bindAttribLocation(cc.ATTRIBUTE_NAME_COLOR, cc.VERTEX_ATTRIB_COLOR)
        shader:bindAttribLocation(cc.ATTRIBUTE_NAME_TEX_COORD, cc.VERTEX_ATTRIB_TEX_COORD)
        shader:link()
        shader:updateUniforms()
    end
end

function ShaderManager:getShader(typeIndex)
    return self.cache[typeIndex].shader
end

function ShaderManager:getDefaultShader()
    return cc.GLProgramCache:getInstance():getGLProgram("ShaderPositionTextureColor_noMVP")
end

function ShaderManager:getDefaultMvpShader()
    return cc.GLProgramCache:getInstance():getGLProgram("ShaderPositionTextureColor_MVP")
end

return ShaderManager