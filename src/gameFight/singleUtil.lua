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

function singleUtil:addPlist(plistPath)
    local fullpath = cc.FileUtils:getInstance():fullPathForFilename(plistPath)
    cs.logger.i(fullpath)
    cc.SpriteFrameCache:getInstance():addSpriteFrames(plistPath)
end

function singleUtil:removePlist(plistPath)
    cc.SpriteFrameCache:getInstance():removeSpriteFramesFromFile(plistPath)
end

--加载config中所有记录的plist
function singleUtil:addAllPlist()
    for k,v in pairs(CC_PLIST) do
        self.instance:addPlist(v)
    end
end

--移除所有
function singleUtil:removeAllPlist()
    self.instance:removeSpriteFrames()
end

--读取地图xml信息，PngPath最后一个字符要求带有/，
function singleUtil:createFrameCache(PngPath, Prefix, DelayUnit, iCount, iEnd, format)
    --约定没有特使情况的话，图片名字个数不得超过64
    iEnd = iEnd or 64
    iCount = iCount or 64
    format = format or "%04d.png"
    --local frameArr = {}
    --local animation =cc.Animation:create()
    --local cache = cc.AnimationCache:getInstance()
    --cache:addAnimationsWithFile("test.plist")

    --创建一个动作
    local animation = cc.Animation:create()
    local fristFrame = nil

    --约定每个动作图片最多不得超过iCountEnd
    for j=0,iEnd do
        --如果所有数据已经进去那么就走人
        if iCount == 0 then
            break
        end
        --组装路径
        local fullPath = PngPath..Prefix..string.format(format,j)
        local frame = cc.SpriteFrameCache:getInstance():getSpriteFrame(fullPath)

        if frame ~= nil then
            animation:addSpriteFrame(frame)
            --cs.logger.i(fullPath)
            if fristFrame == nil then
                fristFrame = cc.SpriteFrameCache:getInstance():getSpriteFrame(fullPath)
            end
            iCount = iCount - 1
        end
    end

    if fristFrame == nil then
        cs.logger.i("can not find sprite:",PngPath..Prefix..string.format(format,0))
    end

    animation:setDelayPerUnit(DelayUnit)        --设置两个帧播放时间
    animation:setRestoreOriginalFrame(true)     --动画执行后还原初始状态 

    return fristFrame , animation
end

