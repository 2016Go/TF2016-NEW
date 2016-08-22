
--------------------------------
-- @module DHSkeletonAnimation
-- @extend DHSkeleton
-- @parent_module 

--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] registerEventsHandler 
-- @param self
-- @param #function handler
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] setTimeScale 
-- @param self
-- @param #float timeScale
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] setAutoRemove 
-- @param self
-- @param #bool autoRemove
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterSenderEventsHandler 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] registerRandomAnimation 
-- @param self
-- @param #char animationName
-- @param #float minRange
-- @param #float maxRange
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterSkin 
-- @param self
-- @param #char skinName
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] setPause 
-- @param self
-- @param #bool pause
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] setAutoApply 
-- @param self
-- @param #bool autoApply
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] clearCascadeChildSet 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getRegisteredAnimation 
-- @param self
-- @param #char animationName
-- @return DHAnimationInfo#DHAnimationInfo ret (return value: cc.DHAnimationInfo)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getEventTime 
-- @param self
-- @param #char anim
-- @param #char e
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] stepAnimation 
-- @param self
-- @param #float delta
-- @param #map_table appendDelataMap
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] onUpdateAndDelayTransform 
-- @param self
-- @param #float delta
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] registerAnimation 
-- @param self
-- @param #char animationName
-- @param #int loop
-- @param #bool autoRemove
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] setDirty 
-- @param self
-- @param #bool dirty
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] isComplete 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, float, float         
-- @overload self, float         
-- @function [parent=#DHSkeletonAnimation] isUpdateFill
-- @param self
-- @param #float delta
-- @param #float appendDelata
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] isPlayBackwardsEnabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterAllRandomAnimation 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterAnimation 
-- @param self
-- @param #char animationName
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getFrameSequenceInterval 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getAnimationInfo 
-- @param self
-- @return DHAnimationInfo#DHAnimationInfo ret (return value: cc.DHAnimationInfo)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] clearNextAnimation 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] removeCascadeChildFromSet 
-- @param self
-- @param #cc.DHSkeletonAnimation child
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- @overload self, float, float         
-- @overload self, float         
-- @function [parent=#DHSkeletonAnimation] update
-- @param self
-- @param #float delta
-- @param #float appendDelata
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)

--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getAnimationData 
-- @param self
-- @return DHAnimationData#DHAnimationData ret (return value: cc.DHAnimationData)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] playAnimation 
-- @param self
-- @param #char animationName
-- @param #int loop
-- @param #float mixDuration
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- @overload self, float, float         
-- @overload self, float         
-- @function [parent=#DHSkeletonAnimation] onUpdate
-- @param self
-- @param #float delta
-- @param #float appendDelata
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] addCascadeChildToSet 
-- @param self
-- @param #cc.DHSkeletonAnimation child
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] applyAnimation 
-- @param self
-- @param #bool transformFlag
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterAllSkin 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] isDirty 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] isActive 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getTimeScale 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterEventsHandler 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] registerSkin 
-- @param self
-- @param #char skinName
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getRegisteredRandomAnimation 
-- @param self
-- @param #char animationName
-- @return DHAnimationInfo#DHAnimationInfo ret (return value: cc.DHAnimationInfo)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] appendNextAnimation 
-- @param self
-- @param #char animationName
-- @param #int loop
-- @param #float mixDuration
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterAllAnimation 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] setFrameSequenceInterval 
-- @param self
-- @param #float interval
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] handleEvents 
-- @param self
-- @param #cc.DHEvent event
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] setPlayBackwardsEnabled 
-- @param self
-- @param #bool enabled
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] getAnimationTime 
-- @param self
-- @param #char anim
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] stopAnimation 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] unregisterRandomAnimation 
-- @param self
-- @param #char animationName
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] registerSenderEventsHandler 
-- @param self
-- @param #function handler
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] scheduleUpdateLua 
-- @param self
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] createWithFile 
-- @param self
-- @param #char jsonPath
-- @return DHSkeletonAnimation#DHSkeletonAnimation ret (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] createWithData 
-- @param self
-- @param #cc.DHSkeletonData data
-- @return DHSkeletonAnimation#DHSkeletonAnimation ret (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] createWithKey 
-- @param self
-- @param #char key
-- @return DHSkeletonAnimation#DHSkeletonAnimation ret (return value: cc.DHSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHSkeletonAnimation] DHSkeletonAnimation 
-- @param self
-- @param #cc.DHSkeletonData data
-- @return DHSkeletonAnimation#DHSkeletonAnimation self (return value: cc.DHSkeletonAnimation)
        
return nil
