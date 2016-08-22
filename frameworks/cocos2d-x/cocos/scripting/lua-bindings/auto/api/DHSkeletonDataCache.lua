
--------------------------------
-- @module DHSkeletonDataCache
-- @parent_module 

--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] setRelativeFilePath 
-- @param self
-- @param #char path
-- @return DHSkeletonDataCache#DHSkeletonDataCache self (return value: cc.DHSkeletonDataCache)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] removeRenderTextureCache 
-- @param self
-- @param #string path
-- @return DHSkeletonDataCache#DHSkeletonDataCache self (return value: cc.DHSkeletonDataCache)
        
--------------------------------
-- / get an Skeleton by key
-- @function [parent=#DHSkeletonDataCache] getSkeletonData 
-- @param self
-- @param #char key
-- @return DHSkeletonData#DHSkeletonData ret (return value: cc.DHSkeletonData)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] preloadFrameSequence 
-- @param self
-- @param #char key
-- @param #char jsonPath
-- @param #float interval
-- @param #cc.Node loadNode
-- @param #float scale
-- @return DHSkeletonDataCache#DHSkeletonDataCache self (return value: cc.DHSkeletonDataCache)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] setResolutionScale 
-- @param self
-- @param #float resolutionScale
-- @return DHSkeletonDataCache#DHSkeletonDataCache self (return value: cc.DHSkeletonDataCache)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] clearRenderTextureCache 
-- @param self
-- @return DHSkeletonDataCache#DHSkeletonDataCache self (return value: cc.DHSkeletonDataCache)
        
--------------------------------
-- / add an SkeletonData from jsonPath
-- @function [parent=#DHSkeletonDataCache] loadSkeletonData 
-- @param self
-- @param #char key
-- @param #char jsonPath
-- @param #float scale
-- @return DHSkeletonData#DHSkeletonData ret (return value: cc.DHSkeletonData)
        
--------------------------------
-- / remove all cached SkeletonData
-- @function [parent=#DHSkeletonDataCache] purgeCache 
-- @param self
-- @return DHSkeletonDataCache#DHSkeletonDataCache self (return value: cc.DHSkeletonDataCache)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] getResolutionScale 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] removeSkeletonData 
-- @param self
-- @param #char key
-- @return DHSkeletonDataCache#DHSkeletonDataCache self (return value: cc.DHSkeletonDataCache)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonDataCache] getInstance 
-- @param self
-- @return DHSkeletonDataCache#DHSkeletonDataCache ret (return value: cc.DHSkeletonDataCache)
        
return nil
