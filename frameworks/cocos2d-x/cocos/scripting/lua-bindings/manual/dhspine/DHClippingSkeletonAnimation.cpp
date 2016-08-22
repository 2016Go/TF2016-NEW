//
//  DHClippingSkeletonAnimation.cpp
//  battle-empire
//
//  Created by droidhang on 13-11-1.
//
//

#include "DHClippingSkeletonAnimation.h"
#include "DHSkeletonDataCache.h"

NS_CC_BEGIN

static GLint g_sStencilBits = -1;
// store the current stencil layer (position in the stencil buffer),
// this will allow nesting up to n ClippingNode,
// where n is the number of bits of the stencil buffer.
static GLint s_layer = -1;

static void setProgram(Node *n, GLProgram *p)
{
    n->setGLProgram(p);
    
    auto& children = n->getChildren();
    for(const auto &child : children) {
        setProgram(child, p);
    }
}

DHClippingSkeletonAnimation::DHClippingSkeletonAnimation()
:m_pStencil(NULL)
,m_fAlphaThreshold(0.0f)
,m_bInverted(false)
,m_startBoundSlotIndex(0)
,m_endBoundSlotIndex(1000000) {
    
}

DHClippingSkeletonAnimation::DHClippingSkeletonAnimation(DHSkeletonData* const data)
:DHSkeletonAnimation(data)
,m_pStencil(nullptr)
,m_fAlphaThreshold(0.0f)
,m_bInverted(false)
,m_startBoundSlotIndex(0)
,m_endBoundSlotIndex(1000000) {
    
}

DHClippingSkeletonAnimation::~DHClippingSkeletonAnimation()
{
    CC_SAFE_RELEASE(m_pStencil);
}

DHClippingSkeletonAnimation* DHClippingSkeletonAnimation::createWithKey(const char *const key, cocos2d::Node *pStencil) {
    DHSkeletonData* data = SDC->getSkeletonData(key);
    if (data) {
        return createWithData(data, pStencil);
    }
    CCLOGWARN("the SkeletonData key: %s is not find", key);
    return nullptr;
}

DHClippingSkeletonAnimation* DHClippingSkeletonAnimation::createWithFile(const char* const jsonPath, cocos2d::Node *pStencil) {
    DHSkeletonData* data = DHSpineLoader::loadSkeletonData(jsonPath);
    if (data) {
        return createWithData(data, pStencil);
    }
    CCLOGWARN("the jsonPath: %s is not find", jsonPath);
    return nullptr;
}

DHClippingSkeletonAnimation* DHClippingSkeletonAnimation::createWithData(DHSkeletonData* const data, cocos2d::Node *pStencil) {
    DHClippingSkeletonAnimation* skeleton = new DHClippingSkeletonAnimation(data);
    if (skeleton && skeleton->initWithStencil(pStencil)) {
        return (DHClippingSkeletonAnimation*)skeleton->autorelease();
    }
    CC_SAFE_RELEASE(skeleton);
    return nullptr;
}

bool DHClippingSkeletonAnimation::initWithStencil(Node *pStencil)
{
    if (!DHSkeletonAnimation::init()) {
        return false;
    }
    
    CC_SAFE_RELEASE(m_pStencil);
    m_pStencil = pStencil;
    CC_SAFE_RETAIN(m_pStencil);
    
    m_fAlphaThreshold = 1;
    m_bInverted = false;
    // get (only once) the number of bits of the stencil buffer
    static bool once = true;
    if (once)
    {
        glGetIntegerv(GL_STENCIL_BITS, &g_sStencilBits);
        if (g_sStencilBits <= 0)
        {
            CCLOG("Stencil buffer is not enabled.");
        }
        once = false;
    }
    
    return true;
}

void DHClippingSkeletonAnimation::onEnter()
{
    Node::onEnter();
    if (m_pStencil) {
        m_pStencil->onEnter();
    }
}

void DHClippingSkeletonAnimation::onEnterTransitionDidFinish()
{
    Node::onEnterTransitionDidFinish();
    if (m_pStencil) {
        m_pStencil->onEnterTransitionDidFinish();
    }
}

void DHClippingSkeletonAnimation::onExitTransitionDidStart()
{
    if (m_pStencil) {
        m_pStencil->onExitTransitionDidStart();
    }
    Node::onExitTransitionDidStart();
}

void DHClippingSkeletonAnimation::onExit()
{
    if (m_pStencil) {
        m_pStencil->onExit();
    }
    Node::onExit();
}

void DHClippingSkeletonAnimation::drawFullScreenQuadClearStencil()
{
    Director* director = Director::getInstance();
    CCASSERT(nullptr != director, "Director is null when seting matrix stack");
    
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    director->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    
    Vec2 vertices[] = {
        Vec2(-1, -1),
        Vec2(1, -1),
        Vec2(1, 1),
        Vec2(-1, 1)
    };
    
    auto glProgram = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_U_COLOR);
    
    int colorLocation = glProgram->getUniformLocation("u_color");
    CHECK_GL_ERROR_DEBUG();
    
    Color4F color(1, 1, 1, 1);
    
    glProgram->use();
    glProgram->setUniformsForBuiltins();
    glProgram->setUniformLocationWith4fv(colorLocation, (GLfloat*) &color.r, 1);
    
    GL::enableVertexAttribs( GL::VERTEX_ATTRIB_FLAG_POSITION );
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 4);
    
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

void DHClippingSkeletonAnimation::draw(Renderer *renderer, const Mat4& transform, uint32_t flags) {
    if (!m_pStencil) {
        DHSkeletonAnimation::draw(renderer, transform, flags);
        return;
    }
    
    if (m_startBoundSlotIndex > 0) {
        _drawCommand[0].init(_globalZOrder);
        _drawCommand[0].func = CC_CALLBACK_0(DHClippingSkeletonAnimation::drawBegin, this, transform, flags);
        renderer->addCommand(&_drawCommand[0]);
    }
    
    if (m_startBoundSlotIndex < m_data->getSlotCount()) {
        _drawCommand[1].init(_globalZOrder);
        _drawCommand[1].func = CC_CALLBACK_0(DHClippingSkeletonAnimation::drawClippingBefore, this);
        renderer->addCommand(&_drawCommand[1]);
        
        if (m_fAlphaThreshold < 1) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
#else
            // since glAlphaTest do not exists in OES, use a shader that writes
            // pixel only if greater than an alpha threshold
            GLProgram *program = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_ALPHA_TEST_NO_MV);
            GLint alphaValueLocation = glGetUniformLocation(program->getProgram(), GLProgram::UNIFORM_NAME_ALPHA_TEST_VALUE);
            // set our alphaThreshold
            program->use();
            program->setUniformLocationWith1f(alphaValueLocation, m_fAlphaThreshold);
            // we need to recursively apply this shader to all the nodes in the stencil node
            // FIXME: we should have a way to apply shader to all nodes without having to do this
            setProgram(m_pStencil, program);
            
#endif
        }
        
        m_pStencil->visit(renderer, transform, flags);
        
        _drawCommand[2].init(_globalZOrder);
        _drawCommand[2].func = CC_CALLBACK_0(DHClippingSkeletonAnimation::drawClipping, this, transform, flags);
        renderer->addCommand(&_drawCommand[2]);
    }
    
    if (m_endBoundSlotIndex + 1 < m_data->getSlotCount()) {
        _drawCommand[3].init(_globalZOrder);
        _drawCommand[3].func = CC_CALLBACK_0(DHClippingSkeletonAnimation::drawEnd, this, transform, flags);
        renderer->addCommand(&_drawCommand[3]);
    }
}

void DHClippingSkeletonAnimation::drawClippingBefore() {
    ///////////////////////////////////
    // INIT
    
    // increment the current layer
    s_layer++;
    
    // mask of the current layer (ie: for layer 3: 00000100)
    GLint mask_layer = 0x1 << s_layer;
    // mask of all layers less than the current (ie: for layer 3: 00000011)
    GLint mask_layer_l = mask_layer - 1;
    // mask of all layers less than or equal to the current (ie: for layer 3: 00000111)
    _mask_layer_le = mask_layer | mask_layer_l;
    
    // manually save the stencil state
    
    _currentStencilEnabled = glIsEnabled(GL_STENCIL_TEST);
    glGetIntegerv(GL_STENCIL_WRITEMASK, (GLint *)&_currentStencilWriteMask);
    glGetIntegerv(GL_STENCIL_FUNC, (GLint *)&_currentStencilFunc);
    glGetIntegerv(GL_STENCIL_REF, &_currentStencilRef);
    glGetIntegerv(GL_STENCIL_VALUE_MASK, (GLint *)&_currentStencilValueMask);
    glGetIntegerv(GL_STENCIL_FAIL, (GLint *)&_currentStencilFail);
    glGetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, (GLint *)&_currentStencilPassDepthFail);
    glGetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, (GLint *)&_currentStencilPassDepthPass);
    
    // enable stencil use
    glEnable(GL_STENCIL_TEST);
    // check for OpenGL error while enabling stencil test
    CHECK_GL_ERROR_DEBUG();
    
    // all bits on the stencil buffer are readonly, except the current layer bit,
    // this means that operation like glClear or glStencilOp will be masked with this value
    glStencilMask(mask_layer);
    
    // manually save the depth test state
    
    glGetBooleanv(GL_DEPTH_WRITEMASK, &_currentDepthWriteMask);
    
    // disable depth test while drawing the stencil
    //glDisable(GL_DEPTH_TEST);
    // disable update to the depth buffer while drawing the stencil,
    // as the stencil is not meant to be rendered in the real scene,
    // it should never prevent something else to be drawn,
    // only disabling depth buffer update should do
    glDepthMask(GL_FALSE);
    
    ///////////////////////////////////
    // CLEAR STENCIL BUFFER
    
    // manually clear the stencil buffer by drawing a fullscreen rectangle on it
    // setup the stencil test func like this:
    // for each pixel in the fullscreen rectangle
    //     never draw it into the frame buffer
    //     if not in inverted mode: set the current layer value to 0 in the stencil buffer
    //     if in inverted mode: set the current layer value to 1 in the stencil buffer
    glStencilFunc(GL_NEVER, mask_layer, mask_layer);
    glStencilOp(!m_bInverted ? GL_ZERO : GL_REPLACE, GL_KEEP, GL_KEEP);
    
    // draw a fullscreen solid rectangle to clear the stencil buffer
    //ccDrawSolidRect(Vec2::ZERO, ccpFromSize([[Director sharedDirector] winSize]), Color4F(1, 1, 1, 1));
    drawFullScreenQuadClearStencil();
    
    ///////////////////////////////////
    // DRAW CLIPPING STENCIL
    
    // setup the stencil test func like this:
    // for each pixel in the stencil node
    //     never draw it into the frame buffer
    //     if not in inverted mode: set the current layer value to 1 in the stencil buffer
    //     if in inverted mode: set the current layer value to 0 in the stencil buffer
    glStencilFunc(GL_NEVER, mask_layer, mask_layer);
    glStencilOp(!m_bInverted ? GL_REPLACE : GL_ZERO, GL_KEEP, GL_KEEP);
    
    // enable alpha test only if the alpha threshold < 1,
    // indeed if alpha threshold == 1, every pixel will be drawn anyways
    if (m_fAlphaThreshold < 1) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        // manually save the alpha test state
        _currentAlphaTestEnabled = glIsEnabled(GL_ALPHA_TEST);
        glGetIntegerv(GL_ALPHA_TEST_FUNC, (GLint *)&_currentAlphaTestFunc);
        glGetFloatv(GL_ALPHA_TEST_REF, &_currentAlphaTestRef);
        // enable alpha testing
        glEnable(GL_ALPHA_TEST);
        // check for OpenGL error while enabling alpha test
        CHECK_GL_ERROR_DEBUG();
        // pixel will be drawn only if greater than an alpha threshold
        glAlphaFunc(GL_GREATER, m_fAlphaThreshold);
#else
        
#endif
    }
    
    //Draw _stencil
}

void DHClippingSkeletonAnimation::drawBegin(const Mat4 &transform, uint32_t flags) {
    getGLProgramState()->apply(transform);
    
    m_batch->apply(this, transform);
    
    for(int i = 0; i < m_startBoundSlotIndex; ++i) {
        drawSlot(m_drawOrder[i]);
    }
    
    m_batch->flush();
}

void DHClippingSkeletonAnimation::drawClipping(const Mat4& transform, uint32_t flags) {
    // restore alpha test state
    if (m_fAlphaThreshold < 1)
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        // manually restore the alpha test state
        glAlphaFunc(_currentAlphaTestFunc, _currentAlphaTestRef);
        if (!_currentAlphaTestEnabled)
        {
            glDisable(GL_ALPHA_TEST);
        }
#else
        // FIXME: we need to find a way to restore the shaders of the stencil node and its childs
#endif
    }
    
    // restore the depth test state
    glDepthMask(_currentDepthWriteMask);
    //if (currentDepthTestEnabled) {
    //    glEnable(GL_DEPTH_TEST);
    //}
    
    ///////////////////////////////////
    // DRAW CONTENT
    
    // setup the stencil test func like this:
    // for each pixel of this node and its childs
    //     if all layers less than or equals to the current are set to 1 in the stencil buffer
    //         draw the pixel and keep the current layer in the stencil buffer
    //     else
    //         do not draw the pixel but keep the current layer in the stencil buffer
    glStencilFunc(GL_EQUAL, _mask_layer_le, _mask_layer_le);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    
    // draw (according to the stencil test func) this node and its childs
    
    getGLProgramState()->apply(transform);
    
    m_batch->apply(this, transform);
    
    for(int i = m_startBoundSlotIndex; i <= m_endBoundSlotIndex && i < m_data->getSlotCount(); ++i) {
        drawSlot(m_drawOrder[i]);
    }
    
    m_batch->flush();
    
    ///////////////////////////////////
    // CLEANUP
    
    // manually restore the stencil state
    glStencilFunc(_currentStencilFunc, _currentStencilRef, _currentStencilValueMask);
    glStencilOp(_currentStencilFail, _currentStencilPassDepthFail, _currentStencilPassDepthPass);
    glStencilMask(_currentStencilWriteMask);
    if (!_currentStencilEnabled)
    {
        glDisable(GL_STENCIL_TEST);
    }
    
    // we are done using this layer, decrement
    s_layer--;
}

void DHClippingSkeletonAnimation::drawEnd(const Mat4 &transform, uint32_t flags) {
    getGLProgramState()->apply(transform);
    
    m_batch->apply(this, transform);
    
    for(int i = m_endBoundSlotIndex + 1; i < m_data->getSlotCount(); ++i) {
        drawSlot(m_drawOrder[i]);
    }
    
    m_batch->flush();
}

void DHClippingSkeletonAnimation::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags) {
    
    // if stencil buffer disabled
    if (g_sStencilBits < 1)
    {
        // draw everything, as if there where no stencil
        DHSkeletonAnimation::visit(renderer, parentTransform, parentFlags);
        return;
    }
    
    // return fast (draw nothing, or draw everything if in inverted mode) if:
    // - nil stencil node
    // - or stencil node invisible:
    if (!m_pStencil || !m_pStencil->isVisible())
    {
        if (m_bInverted)
        {
            // draw everything
            DHSkeletonAnimation::visit(renderer, parentTransform, parentFlags);
        }
        return;
    }
    
    if (!_visible)
    {
        return;
    }
    
    if (m_autoApply && isDirty()) {
        setToSetupPose();
        applyAnimation(true);
        setDirty(false);
    }
    
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    
    // IMPORTANT:
    // To ease the migration to v3.0, we still support the Mat4 stack,
    // but it is deprecated and your code should not rely on it
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    DH_ARRAY_FOREACH(m_data->getBoneCount()) {
        m_bones[i]->updateFollowAttachment(isFlipX(), isFlipY());
    }
    
    //Add group command
    
    _groupCommand.init(_globalZOrder);
    renderer->addCommand(&_groupCommand);
    
    renderer->pushGroup(_groupCommand.getRenderQueueID());
    
    int i = 0;
    bool visibleByCamera = isVisitableByVisitingCamera();
    
    if(!_children.empty())
    {
        sortAllChildren();
        
        // draw children zOrder < 0
        for( ; i < _children.size(); i++ )
        {
            auto node = _children.at(i);
            
            if ( node && node->getLocalZOrder() < 0 ) {
                if (m_slotFollowAttachmentSet.find(node) == m_slotFollowAttachmentSet.end()) {
                    node->visit(renderer, _modelViewTransform, flags);
                }
            }
            else
                break;
            
            
        }
        
        // self draw
        if (visibleByCamera)
            this->draw(renderer, _modelViewTransform, flags);
        
        for(auto it=_children.cbegin()+i; it != _children.cend(); ++it) {
            auto node = *it;
            if (node && m_slotFollowAttachmentSet.find(node) == m_slotFollowAttachmentSet.end()) {
                node->visit(renderer, _modelViewTransform, flags);
            }
            
        }
    }
    else if (visibleByCamera)
    {
        this->draw(renderer, _modelViewTransform, flags);
    }
    
    renderer->popGroup();
    
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

Node* DHClippingSkeletonAnimation::getStencil() const
{
    return m_pStencil;
}

void DHClippingSkeletonAnimation::setStencil(Node *pStencil)
{
    if (m_pStencil) {
        if (isRunning()) {
            m_pStencil->onExitTransitionDidStart();
            m_pStencil->onExit();
        }
        m_pStencil->release();
    }
    
    m_pStencil = pStencil;
    
    if (m_pStencil) {
        if (isRunning()) {
            m_pStencil->onEnter();
            m_pStencil->onEnterTransitionDidFinish();
        }
        m_pStencil->retain();
    }
}

GLfloat DHClippingSkeletonAnimation::getAlphaThreshold() const
{
    return m_fAlphaThreshold;
}

void DHClippingSkeletonAnimation::setAlphaThreshold(GLfloat fAlphaThreshold)
{
    m_fAlphaThreshold = fAlphaThreshold;
}

bool DHClippingSkeletonAnimation::isInverted() const
{
    return m_bInverted;
}

void DHClippingSkeletonAnimation::setInverted(bool bInverted)
{
    m_bInverted = bInverted;
}

void DHClippingSkeletonAnimation::setStartBoundBySlotIndex(int slotIndex) {
    if (slotIndex < 0) {
        m_startBoundSlotIndex = 0;
    }
    else {
        m_startBoundSlotIndex = slotIndex;
    }
}

void DHClippingSkeletonAnimation::setStartBoundBySlotName(const char *slotName) {
    setStartBoundBySlotIndex(m_data->findSlotIndex(slotName));
}

void DHClippingSkeletonAnimation::setEndBoundBySlotIndex(int slotIndex) {
    if (slotIndex < 0) {
        m_endBoundSlotIndex = 1000000;
    }
    else {
        m_endBoundSlotIndex = slotIndex;
    }
}

void DHClippingSkeletonAnimation::setEndBoundBySlotName(const char *slotName) {
    setEndBoundBySlotIndex(m_data->findSlotIndex(slotName));
}

NS_CC_END
