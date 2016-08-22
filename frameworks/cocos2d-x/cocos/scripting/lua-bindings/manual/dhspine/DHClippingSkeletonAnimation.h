//
//  DHClippingSkeletonAnimation.h
//  battle-empire
//
//  Created by droidhang on 13-11-1.
//
//

#ifndef __battle_empire__DHClippingSkeletonAnimation__
#define __battle_empire__DHClippingSkeletonAnimation__

#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

class DHClippingSkeletonAnimation : public DHSkeletonAnimation
{
protected:
    Node* m_pStencil;
    GLfloat m_fAlphaThreshold;
    bool    m_bInverted;
    
public:
    
    static DHClippingSkeletonAnimation* createWithKey(const char* const key, Node *pStencil);
    
    static DHClippingSkeletonAnimation* createWithFile(const char* const jsonPath, Node *pStencil);
    
    static DHClippingSkeletonAnimation* createWithData(DHSkeletonData* const data, Node *pStencil);
    
    DHClippingSkeletonAnimation(DHSkeletonData* const data);
    
    virtual ~DHClippingSkeletonAnimation();
    
    /** Initializes a clipping node with an other node as its stencil.
     The stencil node will be retained, and its parent will be set to this clipping node.
     */
    bool initWithStencil(Node *pStencil);
    
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExitTransitionDidStart();
    virtual void onExit();
    
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    void drawBegin(const Mat4& transform, uint32_t flags);
    void drawClippingBefore();
    void drawClipping(const Mat4& transform, uint32_t flags);
    void drawEnd(const Mat4 &transform, uint32_t flags);
    
    
    /** The CCNode to use as a stencil to do the clipping.
     The stencil node will be retained.
     This default to nil.
     */
    Node* getStencil() const;
    void setStencil(Node *pStencil);
    
    /** The alpha threshold.
     The content is drawn only where the stencil have pixel with alpha greater than the alphaThreshold.
     Should be a float between 0 and 1.
     This default to 1 (so alpha test is disabled).
     */
    GLfloat getAlphaThreshold() const;
    void setAlphaThreshold(GLfloat fAlphaThreshold);
    
    /** Inverted. If this is set to YES,
     the stencil is inverted, so the content is drawn where the stencil is NOT drawn.
     This default to NO.
     */
    bool isInverted() const;
    void setInverted(bool bInverted);
    
    void setStartBoundBySlotIndex(int slotIndex); // [
    
    void setStartBoundBySlotName(const char* slotName);
    
    void setEndBoundBySlotIndex(int slotIndex);  //  ]
    
    void setEndBoundBySlotName(const char* slotName);
    
private:
    DHClippingSkeletonAnimation();
    
    /**draw fullscreen quad to clear stencil bits*/
    void drawFullScreenQuadClearStencil();
    
    GLboolean _currentStencilEnabled;
    GLuint _currentStencilWriteMask;
    GLenum _currentStencilFunc;
    GLint _currentStencilRef;
    GLuint _currentStencilValueMask;
    GLenum _currentStencilFail;
    GLenum _currentStencilPassDepthFail;
    GLenum _currentStencilPassDepthPass;
    GLboolean _currentDepthWriteMask;
    
    GLboolean _currentAlphaTestEnabled;
    GLenum _currentAlphaTestFunc;
    GLclampf _currentAlphaTestRef;
    
    GLint _mask_layer_le;
    
    GroupCommand _groupCommand;
    CustomCommand _drawCommand[4];
    
private:
    int m_startBoundSlotIndex;
    int m_endBoundSlotIndex;
};

NS_CC_END

#endif /* defined(__battle_empire__DHClippingSkeletonAnimation__) */
