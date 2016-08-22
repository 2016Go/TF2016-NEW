
--------------------------------
-- @module DHSlot
-- @parent_module 

--------------------------------
-- 
-- @function [parent=#DHSlot] getBoundingBoxAttachment 
-- @param self
-- @return DHBoundingBoxAttachment#DHBoundingBoxAttachment ret (return value: cc.DHBoundingBoxAttachment)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getBone 
-- @param self
-- @return DHBone#DHBone ret (return value: cc.DHBone)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] setColorEnabled 
-- @param self
-- @param #bool colorEnabled
-- @return DHSlot#DHSlot self (return value: cc.DHSlot)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getFollowAttachmentChild 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getActiveAttachmentName 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] updateAttachment 
-- @param self
-- @return DHSlot#DHSlot self (return value: cc.DHSlot)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getName 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] setToSetupPose 
-- @param self
-- @return DHSlot#DHSlot self (return value: cc.DHSlot)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getRegionAttachment 
-- @param self
-- @return DHRegionAttachment#DHRegionAttachment ret (return value: cc.DHRegionAttachment)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] addFollowAttachment 
-- @param self
-- @param #cc.Node attachment
-- @param #bool enabledFollowColor
-- @return DHSlot#DHSlot self (return value: cc.DHSlot)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getAttachment 
-- @param self
-- @return DHAttachment#DHAttachment ret (return value: cc.DHAttachment)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] isColorEnabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getBlendMode 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] isEnabledFollowAttachment 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] getData 
-- @param self
-- @return DHSlotData#DHSlotData ret (return value: cc.DHSlotData)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] drawFollowAttachment 
-- @param self
-- @param #cc.Renderer renderer
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DHSlot#DHSlot self (return value: cc.DHSlot)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] removeFollowAttachment 
-- @param self
-- @return DHSlot#DHSlot self (return value: cc.DHSlot)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] updateFollowAttachment 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHSlot] DHSlot 
-- @param self
-- @param #cc.DHSlotData data
-- @param #cc.DHSkeleton skeleton
-- @return DHSlot#DHSlot self (return value: cc.DHSlot)
        
return nil
