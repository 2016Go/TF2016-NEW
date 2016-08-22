
--------------------------------
-- @module DHSkeleton
-- @extend Node
-- @parent_module 

--------------------------------
-- 
-- @function [parent=#DHSkeleton] removeSlotFollowAttachment 
-- @param self
-- @param #cc.Node followAttachment
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] isUseCulling 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setExtendOpacity 
-- @param self
-- @param #float opacity
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getBoneByName 
-- @param self
-- @param #char boneName
-- @return DHBone#DHBone ret (return value: cc.DHBone)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] isFlipY 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setUseCulling 
-- @param self
-- @param #bool useCulling
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setSaturation 
-- @param self
-- @param #string slotName
-- @param #float saturation
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getReallyColor 
-- @param self
-- @return color4f_table#color4f_table ret (return value: color4f_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] isColorRotationInit 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] createDrawNodeBoundingBoxBySlot 
-- @param self
-- @param #char slotName
-- @param #bool flipX
-- @return DrawNode#DrawNode ret (return value: cc.DrawNode)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setSkinEnabled 
-- @param self
-- @param #char skinName
-- @param #bool enabled
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getReallyOpacity 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] addChildFollowBone 
-- @param self
-- @param #char boneName
-- @param #cc.Node child
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] regionContainsPoint 
-- @param self
-- @param #vec2_table point
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getAabbBoundingBoxBySlot 
-- @param self
-- @param #char slotName
-- @return rect_table#rect_table ret (return value: rect_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setHue 
-- @param self
-- @param #string slotName
-- @param #float hue
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setColorMixEnabled 
-- @param self
-- @param #bool enabled
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getAabbBoundingBox 
-- @param self
-- @return rect_table#rect_table ret (return value: rect_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setToSetupPose 
-- @param self
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setOpacity 
-- @param self
-- @param #unsigned char opacity
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] isColorMixEnabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getHue 
-- @param self
-- @param #string slotName
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getChildFollowBone 
-- @param self
-- @param #char boneName
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] aabbIntersectsSkeleton 
-- @param self
-- @param #cc.DHSkeleton other
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] isFlipX 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getData 
-- @param self
-- @return DHSkeletonData#DHSkeletonData ret (return value: cc.DHSkeletonData)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] unregisterSkin 
-- @param self
-- @param #char skinName
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setBrightness 
-- @param self
-- @param #string slotName
-- @param #float brightness
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setExtendColor 
-- @param self
-- @param #color4f_table color
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getBoneLocation 
-- @param self
-- @param #char boneName
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] removeChildFollowBone 
-- @param self
-- @param #char boneName
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getAabbContentSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setFlipY 
-- @param self
-- @param #bool flipY
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getAttachment 
-- @param self
-- @param #int slotIndex
-- @param #char attachmentName
-- @return DHAttachment#DHAttachment ret (return value: cc.DHAttachment)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] isSkinRegistered 
-- @param self
-- @param #char skinName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] registerSkin 
-- @param self
-- @param #char skinName
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getBoneByIndex 
-- @param self
-- @param #int boneIndex
-- @return DHBone#DHBone ret (return value: cc.DHBone)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getSaturation 
-- @param self
-- @param #string slotName
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] unregisterAllSkin 
-- @param self
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getChildFollowSlot 
-- @param self
-- @param #char slotName
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getBrightness 
-- @param self
-- @param #string slotName
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getEventTimeLine 
-- @param self
-- @param #char animName
-- @param #char eventName
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setAllSlotColorEnabled 
-- @param self
-- @param #bool colorEnabled
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getExtendColor 
-- @param self
-- @return color4f_table#color4f_table ret (return value: color4f_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getBonePosition 
-- @param self
-- @param #char boneName
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] containsPointBySlot 
-- @param self
-- @param #char slotName
-- @param #vec2_table point
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setColor 
-- @param self
-- @param #color3b_table color
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getSlotByName 
-- @param self
-- @param #char slotName
-- @return DHSlot#DHSlot ret (return value: cc.DHSlot)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] addChildFollowSlot 
-- @param self
-- @param #char slotName
-- @param #cc.Node child
-- @param #bool enabledFollowColor
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] setFlipX 
-- @param self
-- @param #bool flipX
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getExtendOpacity 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getBonePositionRelativeToWorld 
-- @param self
-- @param #char boneName
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getSlotByIndex 
-- @param self
-- @param #int slotIndex
-- @return DHSlot#DHSlot ret (return value: cc.DHSlot)
        
--------------------------------
-- @overload self, cc.Node, bool         
-- @overload self, cc.Node         
-- @function [parent=#DHSkeleton] removeChild
-- @param self
-- @param #cc.Node child
-- @param #bool cleanup
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)

--------------------------------
-- 
-- @function [parent=#DHSkeleton] getBonePositionRelativeToLayer 
-- @param self
-- @param #char boneName
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] getAnimationDuration 
-- @param self
-- @param #char animName
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] updateWorldTransform 
-- @param self
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] removeChildFollowSlot 
-- @param self
-- @param #char slotName
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] containsPoint 
-- @param self
-- @param #vec2_table point
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] aabbRegionContainsPoint 
-- @param self
-- @param #vec2_table point
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] createWithFile 
-- @param self
-- @param #char jsonPath
-- @return DHSkeleton#DHSkeleton ret (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] createWithData 
-- @param self
-- @param #cc.DHSkeletonData data
-- @return DHSkeleton#DHSkeleton ret (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] createWithKey 
-- @param self
-- @param #char key
-- @return DHSkeleton#DHSkeleton ret (return value: cc.DHSkeleton)
        
--------------------------------
-- 
-- @function [parent=#DHSkeleton] DHSkeleton 
-- @param self
-- @param #cc.DHSkeletonData data
-- @return DHSkeleton#DHSkeleton self (return value: cc.DHSkeleton)
        
return nil
