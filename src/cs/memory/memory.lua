module('cs.memory.memory',package.seeall)

----------------------------------------------------
--内存管理类
----------------------------------------------------

----------------------------------------------------
-- class
----------------------------------------------------

--获取当前内存状态
function getNowMemory()
    local freeBytes = Util:getMemoryStatus(1)
    local usedBytes = Util:getMemoryStatus(2)
    return freeBytes,usedBytes
end

--清理当前内存
function cleanMemory()
    -- 清理缓存数据
    cc.Director:getInstance():purgeCachedData()

    -- 通知lua回收内存
    collectgarbage()
    collectgarbage()
    collectgarbage()
end

function checkMemory()
    local freeBytes = Util:getMemoryStatus(1)
    local usedBytes = Util:getMemoryStatus(2)
    if (freeBytes > 0) and (freeBytes < 1024 * 16) then
        cs.logger.i("main", '***********************')
        cs.logger.i("main", 'memory free < 16MB')
        cs.logger.i("main", '***********************')
        cleanMemory()
    end

    if (usedBytes > 0) and (usedBytes > 1024 * 192) then
        cs.logger.i("main", '***********************')
        cs.logger.i("main", 'memory used > 192MB')
        cs.logger.i("main", '***********************')
        cleanMemory()
    end
end 

--获取图片数据，如果没有加载图片到内存
function getImage(pathName)
    local textCache = cc.Director:getInstance():getTextureCache()
    return textCache:addImage(pathName)
end

--加载plist文件到内存
function addPilst(plist)
    cc.SpriteFrameCache:getInstance():addSpriteFrames(plist)
end

--播放plist序列帧接口，要求是调用addPilst接口之后才使用
function createAnimateWithPlist(plist,format,delay,isReverse)
    cc.SpriteFrameCache:getInstance():addSpriteFrames(plist)
    
    delay = delay or 0.08
    local from = 0
    local frames = {}

    for i = from, 99 do
        local i = (isReverse and (from * 2 - i) or i)
        local frame_name = string.format(format,i)
        local frame = cc.SpriteFrameCache:getInstance():getSpriteFrame(frame_name)

        if frame then
            table.insert(frames,frame)
        else
            break
        end
    end
    
    local animation = cc.Animation:createWithSpriteFrames(frames,delay)
    return cc.Animate:create(animation)
end

--播放骨骼动画
function  skeletonAnimationPlay  ( widget ,json  ,boneAtlas ,posx,posy ,name ,bool)
        local  body = sp.SkeletonAnimation:create(json,boneAtlas,1)
        body:setAnimation(0,name,bool)
        body:setPosition(posx,posy)
        widget:addChild(body)
        return  body
end