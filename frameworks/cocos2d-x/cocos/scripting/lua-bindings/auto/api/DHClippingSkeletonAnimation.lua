
--------------------------------
-- @module DHClippingSkeletonAnimation
-- @extend DHSkeletonAnimation
-- @parent_module 

--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] onEnter 
-- @param self
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] setStencil 
-- @param self
-- @param #cc.Node pStencil
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] drawBegin 
-- @param self
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
--  The CCNode to use as a stencil to do the clipping.<br>
-- The stencil node will be retained.<br>
-- This default to nil.
-- @function [parent=#DHClippingSkeletonAnimation] getStencil 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
--  Inverted. If this is set to YES,<br>
-- the stencil is inverted, so the content is drawn where the stencil is NOT drawn.<br>
-- This default to NO.
-- @function [parent=#DHClippingSkeletonAnimation] isInverted 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] setStartBoundBySlotIndex 
-- @param self
-- @param #int slotIndex
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] visit 
-- @param self
-- @param #cc.Renderer renderer
-- @param #mat4_table parentTransform
-- @param #unsigned int parentFlags
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] drawClippingBefore 
-- @param self
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] drawClipping 
-- @param self
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] draw 
-- @param self
-- @param #cc.Renderer renderer
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] setEndBoundBySlotIndex 
-- @param self
-- @param #int slotIndex
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] setEndBoundBySlotName 
-- @param self
-- @param #char slotName
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] onExitTransitionDidStart 
-- @param self
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] setAlphaThreshold 
-- @param self
-- @param #float fAlphaThreshold
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] drawEnd 
-- @param self
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] onExit 
-- @param self
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] setInverted 
-- @param self
-- @param #bool bInverted
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] setStartBoundBySlotName 
-- @param self
-- @param #char slotName
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
--  The alpha threshold.<br>
-- The content is drawn only where the stencil have pixel with alpha greater than the alphaThreshold.<br>
-- Should be a float between 0 and 1.<br>
-- This default to 1 (so alpha test is disabled).
-- @function [parent=#DHClippingSkeletonAnimation] getAlphaThreshold 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
--  Initializes a clipping node with an other node as its stencil.<br>
-- The stencil node will be retained, and its parent will be set to this clipping node.
-- @function [parent=#DHClippingSkeletonAnimation] initWithStencil 
-- @param self
-- @param #cc.Node pStencil
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] onEnterTransitionDidFinish 
-- @param self
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] createWithFile 
-- @param self
-- @param #char jsonPath
-- @param #cc.Node pStencil
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation ret (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] createWithData 
-- @param self
-- @param #cc.DHSkeletonData data
-- @param #cc.Node pStencil
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation ret (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] createWithKey 
-- @param self
-- @param #char key
-- @param #cc.Node pStencil
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation ret (return value: cc.DHClippingSkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#DHClippingSkeletonAnimation] DHClippingSkeletonAnimation 
-- @param self
-- @param #cc.DHSkeletonData data
-- @return DHClippingSkeletonAnimation#DHClippingSkeletonAnimation self (return value: cc.DHClippingSkeletonAnimation)
        
return nil
