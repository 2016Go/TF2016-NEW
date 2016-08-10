--战斗场景单键类
if cc.exports.singleUtil == nil then
    cc.exports.singleUtil = {} 
end

function singleUtil:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleUtil:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
    end  
    return self.instance  
end 

--读取地图xml信息
function singleUtil:createFrameCache(namePath, namePng, icount, iEnd)
    --约定没有特使情况的话，图片名字个数不得超过64
    local iCountEnd = iEnd or 64

    --创建足够的数组
    local frameArr = {}
    local animation =cc.Animation:create()

    if cc.FileUtils:getInstance():isFileExist(namePath) then
        local prefixPath = cc.FileUtils:getInstance():fullPathForFilename(namePath)

        --约定每个动作图片最多不得超过iCountEnd
        for j=0,64 do
            local fullPath = prefixPath.."/"..namePng..string.format("%04d.png",j)
            if cc.FileUtils:getInstance():isFileExist(fullPath)  then
                cs.logger.i("youwei",fullPath)
                local frame = cc.SpriteFrameCache:getInstance():getSpriteFrameByName(namePath.."/"..string.format("%04d.png",j))
                print(frame)
                animation:addSpriteFrame(frame)  
            end
        end
    end

    animation:setDelayPerUnit(0.15)          --设置两个帧播放时间
    animation:setRestoreOriginalFrame(true)    --动画执行后还原初始状态 

    if animation == nil then
        cs.logger.w("animation is nil ",namePath)
    end

    return animation
end

