//
//  DHSkeletonAnimation.cpp
//  dhspine
//
//  Created by youbin on 13-10-7.
//
//

#include "DHSkeletonAnimation.h"
#include "DHSkeletonDataCache.h"

#if DH_LUA_ENABLED > 0
#include "CCLuaEngine.h"
#endif

NS_CC_BEGIN

bool DHRegisterAnimationInfo::onUpdate(float delta) {
    if (info->isComplete() && autoRemove) {
        return false;
    }
    
    info->update(delta);
    return true;
}

void DHRegisterRandomAnimationInfo::update(float delta) {
    if (playing) {
        info->update(delta);
        if (info->isComplete()) {
            playing = false;
        }
    }
    else {
        timeCount += delta;
        if (timeCount >= randomTime) {
            resetRandom();
            timeCount = 0.f;
            playing = true;
            info->setFrameTime(0.f);
            info->setLoopCount(1);
        }
    }
}

DHSkeletonAnimation::DHSkeletonAnimation()
:m_animation(nullptr)
,m_preAnimation(nullptr)
,m_eventsHandler(nullptr)
,m_senderEventsHandler(nullptr)
,m_scriptHandler(0)
,m_appendAnimationMap(nullptr)
,m_beinMix(false)
,m_pause(false)
,m_timeScale(1.f)
,m_autoRemove(false)
,m_playBackwardsEnabled(false)
,m_frameSequenceInterval(0.f)
,m_renderCacheSprite(nullptr)
,m_autoApply(true)
,m_dirty(true) {
    
}

DHSkeletonAnimation::DHSkeletonAnimation(DHSkeletonData* const data)
:DHSkeleton(data)
,m_animation(nullptr)
,m_preAnimation(nullptr)
,m_eventsHandler(nullptr)
,m_senderEventsHandler(nullptr)
,m_scriptHandler(0)
,m_beinMix(false)
,m_pause(false)
,m_timeScale(1.f)
,m_autoRemove(false)
,m_playBackwardsEnabled(false)
,m_frameSequenceInterval(0.f)
,m_renderCacheSprite(nullptr)
,m_autoApply(true)
,m_dirty(true) {
    m_appendAnimationMap = new DHDictionary();
    m_randomAnimationMap = new DHDictionary();
}

DHSkeletonAnimation::~DHSkeletonAnimation() {
    CC_SAFE_DELETE(m_animation);
    CC_SAFE_DELETE(m_preAnimation);
    CC_SAFE_DELETE(m_appendAnimationMap);
    CC_SAFE_DELETE(m_randomAnimationMap);
    CC_SAFE_RELEASE(m_renderCacheSprite);
    
    clearNextAnimation();
    
    clearCascadeChildSet();
    
#if DH_LUA_ENABLED > 0
    if (m_scriptHandler) {
        LuaEngine::getInstance()->removeScriptHandler(m_scriptHandler);
    }
#endif
}

DHSkeletonAnimation* DHSkeletonAnimation::createWithKey(const char* const key) {
    DHSkeletonData* data = SDC->getSkeletonData(key);
    if (data) {
        return createWithData(data);
    }
    return nullptr;
}

DHSkeletonAnimation* DHSkeletonAnimation::createWithFile(const char* const jsonPath) {
    DHSkeletonData* data = DHSpineLoader::loadSkeletonData(jsonPath);
    if (data) {
        return createWithData(data);
    }
    CCLOGWARN("the jsonPath: %s is not find", jsonPath);
    return nullptr;
}

DHSkeletonAnimation* DHSkeletonAnimation::createWithData(DHSkeletonData* const data) {
    DHSkeletonAnimation* anim = new DHSkeletonAnimation(data);
    if (anim && anim->init()) {
        return (DHSkeletonAnimation*)anim->autorelease();
    }
    CC_SAFE_RELEASE(anim);
    return nullptr;
}

void DHSkeletonAnimation::registerSkin(const char *skinName) {
    DHSkeleton::registerSkin(skinName);
    
    setDirty(true);
}

void DHSkeletonAnimation::unregisterSkin(const char *skinName) {
    DHSkeleton::unregisterSkin(skinName);
    
    setDirty(true);
}

void DHSkeletonAnimation::unregisterAllSkin() {
    DHSkeleton::unregisterAllSkin();
    
    setDirty(true);
}

void DHSkeletonAnimation::updateAnimation(float delta) {
    if (m_pause) {
        return;
    }
    
    if (m_timeScale != 1.f) {
        delta *= m_timeScale;
    }
    
    for (auto iter = m_cascadeChildSet.begin(); iter != m_cascadeChildSet.end();) {
        DHSkeletonAnimation* anim = *iter;
        if (anim->getParent()) {
            anim->update(delta);
            iter++;
        }
        else {
            anim->release();
            iter = m_cascadeChildSet.erase(iter);
        }
    }
    
    if (m_animation) {
        if (isPlayBackwardsEnabled()) {
            delta = -delta;
        }
        
        if (m_frameSequenceInterval > 0.f) {
            const std::string &path = getData()->getName();
            std::string fullKey = getFrameSequenceFullKey(delta);
            
            if (SDC->checkRenderTextureCache(path, fullKey)) {
                m_animation->updateFrameTime(delta);
            }
            else {
                m_animation->updateToFrameIndex(delta, m_frameSequenceInterval);
            }
        }
        else {
            if (m_beinMix) {
                m_mixTime += delta;
                float alpha = m_mixTime / m_mixDuration;
                if (alpha < 1.f) {
                    m_animation->update(delta, alpha);
                    if (m_preAnimation) {
                        m_preAnimation->update(delta, 1.f - alpha);
                    }
                }
                else {
                    m_beinMix = false;
                    delete m_preAnimation;
                    m_preAnimation = nullptr;
                    m_animation->update(delta);
                }
            }
            else {
                m_animation->update(delta);
            }
        }
    }
}

void DHSkeletonAnimation::updateAppendAnimation(float delta) {
    if (m_pause) {
        return;
    }
    
    if (m_timeScale != 1.f) {
        delta *= m_timeScale;
    }
    
    if (m_appendAnimationMap->getCount() > 0) {
        DHDictElement* element;
        DH_DICT_FOREACH(m_appendAnimationMap, element) {
            DHRegisterAnimationInfo* rgInfo = (DHRegisterAnimationInfo*)element->value;
            if (!rgInfo->onUpdate(delta)) {
                m_appendAnimationMap->removeForElememt(element);
            }
        }
    }
    
    if (m_randomAnimationMap->getCount() > 0) {
        DHDictElement* element;
        DH_DICT_FOREACH(m_randomAnimationMap, element) {
            DHRegisterRandomAnimationInfo* rdInfo = (DHRegisterRandomAnimationInfo*)element->value;
            rdInfo->update(delta);
        }
    }
}

void DHSkeletonAnimation::updateNextAnimation() {
    if (isComplete() && !m_nextAnimationQue.empty()) {
        DHNextAnimationInfo* info = m_nextAnimationQue.front();
        
        float retTime = 0.f;
        if (m_animation) {
            retTime = m_animation->getFrameTime() - m_animation->getDuration();
        }
        
        m_nextAnimationQue.pop();
        playAnimation(info->name, info->loop, info->mixDuration);
        delete info;
        
        if (retTime > 0.f) {
            update(retTime, 0.f);
        }
    }
}

void DHSkeletonAnimation::update(float delta) {
    update(delta, delta);
    
    if (isComplete() && m_autoRemove) {
        removeFromParent();
    }
}

bool DHSkeletonAnimation::isActive() const {
    return !isComplete() || m_appendAnimationMap->getCount() || m_randomAnimationMap->getCount();
}

void DHSkeletonAnimation::update(float delta, float appendDelata) {
    if (isActive()) {
        updateAnimation(delta);
        updateAppendAnimation(appendDelata);
        updateNextAnimation();
    }
}

bool DHSkeletonAnimation::onUpdate(float delta) {
    return onUpdate(delta, delta);
}

bool DHSkeletonAnimation::onUpdate(float delta, float appendDelta) {
    bool rt = isComplete();
    
    if (isActive()) {
        updateAnimation(delta);
        updateAppendAnimation(appendDelta);
    }
    
    return !rt;
}

bool DHSkeletonAnimation::isUpdateFill(float delta) {
    return isUpdateFill(delta, delta);
}

bool DHSkeletonAnimation::isUpdateFill(float delta, float appendDelta) {
    if (isActive()) {
        updateAnimation(delta);
        updateAppendAnimation(appendDelta);
    }
    
    return isComplete();
}

bool DHSkeletonAnimation::onUpdateAndDelayTransform(float delta) {
    bool rt = isComplete();
    
    if (isActive()) {
        setToSetupPose();
        updateAnimation(delta);
        updateAppendAnimation(delta);
        applyAnimation(false);
    }
    
    return !rt;
}

void DHSkeletonAnimation::stepAnimation(float delta, const ValueMap &appendDelataMap) {
    if (isActive()) {
        updateAnimation(delta);
        
        std::set<std::string> animNameSet;
        for (const auto& iter : appendDelataMap) {
            const char* animationName = iter.first.c_str();
            auto value = m_appendAnimationMap->find(animationName);
            if (value) {
                DHRegisterAnimationInfo* rgInfo = (DHRegisterAnimationInfo*)value;
                float appendDelta = iter.second.asFloat();
                if (!rgInfo->onUpdate(appendDelta)) {
                    m_appendAnimationMap->remove(animationName);
                }
                animNameSet.insert(animationName);
            }
        }
        
        if (animNameSet.size() < m_appendAnimationMap->getCount()) {
            DHDictElement* element;
            DH_DICT_FOREACH(m_appendAnimationMap, element) {
                DHRegisterAnimationInfo* rgInfo = (DHRegisterAnimationInfo*)element->value;
                if (animNameSet.find(element->key) == animNameSet.end()) {
                    if (!rgInfo->onUpdate(delta)) {
                        m_appendAnimationMap->removeForElememt(element);
                    }
                }
            }
        }
        
        if (m_randomAnimationMap->getCount() > 0) {
            DHDictElement* element;
            DH_DICT_FOREACH(m_randomAnimationMap, element) {
                DHRegisterRandomAnimationInfo* rdInfo = (DHRegisterRandomAnimationInfo*)element->value;
                rdInfo->update(delta);
            }
        }
    }
}

void DHSkeletonAnimation::stopAnimation() {
    CC_SAFE_DELETE(m_preAnimation);
    CC_SAFE_DELETE(m_animation);
    setDirty(true);
}

void DHSkeletonAnimation::playAnimation(const char *animationName, int loop, float mixDuration) {
    DHAnimationData* data = m_data->findAnimaion(animationName);
    
    if (!data) {
        return;
    }
    setDirty(true);
    
    if (mixDuration > 0.f && m_frameSequenceInterval <= 0.f) {
        m_beinMix = true;
        if (m_preAnimation) {
            if (m_mixTime > m_mixDuration * 0.5f) {
                delete m_preAnimation;
                m_preAnimation = m_animation;
                m_preAnimation->setInFadeOut(true);
                m_mixDuration = mixDuration;
            }
            else {
                CC_SAFE_DELETE(m_animation);
            }
        }
        else {
            m_preAnimation = m_animation;
            if (m_preAnimation) {
                m_preAnimation->setInFadeOut(true);
            }
            else {
                m_beinMix = false;//prevent mix from setup
            }
            m_mixDuration = mixDuration;
        }
    }
    else {
        CC_SAFE_DELETE(m_animation);
        if (m_preAnimation) {
            delete m_preAnimation;
            m_preAnimation = nullptr;
        }
        m_beinMix = false;
    }
    m_mixTime = 0;
    m_animation = new DHAnimationInfo(data, this, loop);
    
    updateAnimation(0.f);
    updateAppendAnimation(0.f);
    
    m_animation->applyEventsToFirstFrame(0.f);
}

DHAnimationInfo* DHSkeletonAnimation::getRegisteredAnimation(const char *animationName) {
    void* value = m_appendAnimationMap->find(animationName);
    return value ? ((DHRegisterAnimationInfo*)value)->info : nullptr;
}

void DHSkeletonAnimation::registerAnimation(const char *animationName, int loop, bool autoRemove) {
    if (m_frameSequenceInterval > 0.f) {
        return;
    }
    
    DHAnimationData* animationData = m_data->findAnimaion(animationName);
    if (animationData) {
        DHRegisterAnimationInfo* rgInfo = DHRegisterAnimationInfo::create(animationData, this, loop, autoRemove);
        m_appendAnimationMap->insert(animationName, rgInfo);
    }
}

void DHSkeletonAnimation::unregisterAnimation(const char *animationName) {
    m_appendAnimationMap->remove(animationName);
}

void DHSkeletonAnimation::unregisterAllAnimation() {
    m_appendAnimationMap->removeAll();
}

void DHSkeletonAnimation::handleEvents(const cocos2d::DHEvent *event) {
    if (m_eventsHandler) {
        m_eventsHandler(event);
    }
    if (m_senderEventsHandler) {
        m_senderEventsHandler(this, event);
    }
    
#if DH_LUA_ENABLED > 0
    if (m_scriptHandler) {
        LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
        stack->clean();
        stack->pushString(event->name.c_str());
        stack->pushInt(this->getTag());
        stack->pushInt(event->intValue);
        stack->pushInt(event->floatValue);
        stack->executeFunctionByHandler(m_scriptHandler, 4);
        stack->clean();
    }
#endif
}

void DHSkeletonAnimation::appendNextAnimation(const char *animationName, int loop, float mixDuration) {
    DHAnimationData* animationData = m_data->findAnimaion(animationName);
    if (animationData) {
        DHNextAnimationInfo* info = new DHNextAnimationInfo(animationName, loop, mixDuration);
        m_nextAnimationQue.push(info);
    }
}

void DHSkeletonAnimation::clearNextAnimation() {
    while (!m_nextAnimationQue.empty()) {
        delete m_nextAnimationQue.front();
        m_nextAnimationQue.pop();
    }
}

void DHSkeletonAnimation::registerRandomAnimation(const char *animationName, float minRange, float maxRange) {
    if (m_frameSequenceInterval > 0.f) {
        return;
    }
    
    DHAnimationData* animationData = m_data->findAnimaion(animationName);
    if (animationData) {
        DHRegisterRandomAnimationInfo* rdInfo = DHRegisterRandomAnimationInfo::create(animationData, this, minRange, maxRange);
        m_randomAnimationMap->insert(animationName, rdInfo);
    }
}

void DHSkeletonAnimation::unregisterRandomAnimation(const char *animationName) {
    m_randomAnimationMap->remove(animationName);
}

void DHSkeletonAnimation::unregisterAllRandomAnimation() {
    m_randomAnimationMap->removeAll();
}

DHAnimationInfo* DHSkeletonAnimation::getRegisteredRandomAnimation(const char *animationName) {
    void* value = m_randomAnimationMap->find(animationName);
    return value ? ((DHRegisterRandomAnimationInfo*)value)->info : nullptr;
}

void DHSkeletonAnimation::addCascadeChildToSet(cocos2d::DHSkeletonAnimation *child) {
    if (child && m_cascadeChildSet.find(child) == m_cascadeChildSet.end()) {
        child->retain();
        m_cascadeChildSet.insert(child);
    }
}

void DHSkeletonAnimation::removeCascadeChildFromSet(cocos2d::DHSkeletonAnimation *child) {
    if (child && m_cascadeChildSet.find(child) != m_cascadeChildSet.end()) {
        child->release();
        m_cascadeChildSet.erase(child);
    }
}

void DHSkeletonAnimation::clearCascadeChildSet() {
    for (const auto& iter : m_cascadeChildSet) {
        iter->release();
    }
    m_cascadeChildSet.clear();
}

void DHSkeletonAnimation::scheduleUpdateLua() {
    scheduleUpdate();
}

float DHSkeletonAnimation::getAnimationTime(const char* anim) {
    return getData()->findAnimaion(anim)->getDuration();
}

float DHSkeletonAnimation::getEventTime(const char* anim, const char* e) {
    return getData()->findAnimaion(anim)->getLastEventTimeByName(e);
}

void DHSkeletonAnimation::registerLuaHandler(int handler) {
#if DH_LUA_ENABLED > 0
    if (m_scriptHandler) {
        LuaEngine::getInstance()->removeScriptHandler(m_scriptHandler);
    }
    m_scriptHandler = handler;
#endif
}

void DHSkeletonAnimation::setFrameSequenceInterval(float interval) {
    m_frameSequenceInterval = interval;
    setUseCulling(interval > 0);
}

void DHSkeletonAnimation::applyAnimation(bool transformFlag) {
    if (m_animation) {
        m_animation->apply();
    }
    if (m_preAnimation) {
        m_preAnimation->apply();
    }
    if (m_appendAnimationMap->getCount() > 0) {
        DHDictElement* element;
        DH_DICT_FOREACH(m_appendAnimationMap, element) {
            DHRegisterAnimationInfo* rgInfo = (DHRegisterAnimationInfo*)element->value;
            rgInfo->info->apply();
        }
    }
    
    if (m_randomAnimationMap->getCount() > 0) {
        DHDictElement* element;
        DH_DICT_FOREACH(m_randomAnimationMap, element) {
            DHRegisterRandomAnimationInfo* rdInfo = (DHRegisterRandomAnimationInfo*)element->value;
            if (rdInfo->playing) {
                rdInfo->info->apply();
            }
        }
    }
    
    if (transformFlag) {
        updateWorldTransform();
    }
}

void DHSkeletonAnimation::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags) {
    if (!_visible) {
        return;
    }
    
    if (m_autoApply && isDirty()) {
        setToSetupPose();
        applyAnimation(true);
        setDirty(false);
    }
    
    DHSkeleton::visit(renderer, parentTransform, parentFlags);
}

void DHSkeletonAnimation::draw(Renderer *renderer, const Mat4& transform, uint32_t flags) {
    if (m_frameSequenceInterval > 0.f) {
        const std::string &path = getData()->getName();
        std::string fullKey = getFrameSequenceFullKey(0.f);
        
        DHRenderTextureCacheInfo* cacheInfo = SDC->getRenderTextureCacheInfo(path, fullKey);
        
        if (!cacheInfo) {
            float minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
            DH_ARRAY_FOREACH(m_data->getSlotCount()) {
                DHSlot* slot = m_drawOrder[i];
                
                DHAttachment* attachment = slot->getAttachment();
                if (attachment) {
                    switch (attachment->getType()) {
                        case DHAttachmentType::at_region:
                        case DHAttachmentType::at_mesh:
                        case DHAttachmentType::at_skinned_mesh: {
                            DHRegionAttachment* regionAttachment = (DHRegionAttachment*)attachment;
                            regionAttachment->updateAabb(slot, minX, minY, maxX, maxY);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
            
            if (minX == INT_MAX) {
                return;
            }
            
            int width = ceil(maxX - minX);
            int height = ceil(maxY - minY);
            Vec2 offset = Vec2(-minX, -minY);
            
            float scaleX = getScaleX();
            float scaleY = getScaleY();
            float rotation = getRotation();
            Vec2 position = getPosition();
            
            setScale(1.f);
            setRotation(0);
            setPosition(offset);
            
            const Mat4& modelViewTransform = this->getNodeToParentTransform();
            
            RenderTexture* renderTexture = RenderTexture::create(width, height);
            renderTexture->begin();
            drawFrameSequence(renderer, modelViewTransform);
            renderTexture->end();
            
            setScaleX(scaleX);
            setScaleY(scaleY);
            setRotation(rotation);
            setPosition(position);
            
            cacheInfo = SDC->addRenderTextureCache(path, fullKey, renderTexture, minX, maxX, minY, maxY);
        }
        
        SpriteFrame* spriteFrame = cacheInfo->spriteFrame;
        if (m_renderCacheSprite) {
            if (m_renderCacheSprite->getSpriteFrame() != spriteFrame) {
                m_renderCacheSprite->setSpriteFrame(spriteFrame);
                m_renderCacheSprite->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
                m_renderCacheSprite->setOpacityModifyRGB(true);
            }
        }
        else {
            m_renderCacheSprite = Sprite::createWithSpriteFrame(spriteFrame);
            m_renderCacheSprite->setFlippedY(true);
            m_renderCacheSprite->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
            m_renderCacheSprite->setOpacityModifyRGB(true);
            m_renderCacheSprite->retain();
        }
        
        m_renderCacheSprite->setGlobalZOrder(getGlobalZOrder());
        m_renderCacheSprite->setFlippedX(isFlipX());
        m_renderCacheSprite->setFlippedY(!isFlipY());
        m_renderCacheSprite->setGLProgram(getGLProgram());
        
        const auto& reallyColor = getReallyColor();
        Color3B color = Color3B(reallyColor.r * 255, reallyColor.g * 255, reallyColor.b * 255);
        m_renderCacheSprite->setColor(color);
        m_renderCacheSprite->setOpacity(reallyColor.a * 255);
        
        m_renderCacheSprite->visit(renderer, transform, flags);
    }
    else {
        DHSkeleton::draw(renderer, transform, flags);
    }
}

void DHSkeletonAnimation::drawFrameSequence(Renderer *renderer, const Mat4& transform) {
    int drawCommandIndex = 0;
    auto addDrawCommad = [&]() {
        if (drawCommandIndex >= m_drawCommandVec.size()) {
            m_drawCommandVec.push_back(new CustomCommand());
        }
        
        CustomCommand* drawCommand = m_drawCommandVec[drawCommandIndex++];
        drawCommand->init(_globalZOrder);
        drawCommand->func = CC_CALLBACK_0(DHSkeletonAnimation::drawSkeletonFrameSequence, this, transform);
        renderer->addCommand(drawCommand);
    };
    
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        DHSlot* slot = m_drawOrder[i];
        
        DHAttachment* attachment = slot->getAttachment();
        if (attachment) {
            switch (attachment->getType()) {
                case DHAttachmentType::at_region:
                case DHAttachmentType::at_mesh:
                case DHAttachmentType::at_skinned_mesh: {
                    DHRegionAttachment* regionAttachment = (DHRegionAttachment*)attachment;
                    if (m_batch->addBuffer(regionAttachment)) {
                        addDrawCommad();
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    if (m_batch->getVerticesCount() > 0) {
        addDrawCommad();
        m_batch->resetBuffer();
    }
    
    m_drawSlotIndex = 0;
}

void DHSkeletonAnimation::drawSkeletonFrameSequence(const Mat4& transform) {
    bool flipX = isFlipX();
    bool flipY = isFlipY();
    Color4F realColor = getReallyColor();
    GLProgram* shader = getGLProgram();
    
    setFlipX(false);
    setFlipY(false);
    m_realColor = Color4F::WHITE;
    setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
    
    getGLProgramState()->apply(transform);

    m_batch->apply(this, transform);
    
    while (m_drawSlotIndex < m_data->getSlotCount()) {
        if (drawSlot(m_drawOrder[m_drawSlotIndex++])) {
            return;
        }
    }
    
    m_batch->flush();
    
    setFlipX(flipX);
    setFlipY(flipY);
    m_realColor = realColor;
    setGLProgram(shader);
}

std::string DHSkeletonAnimation::getFrameSequenceFullKey(float delta) {
    std::set<std::string> skinNameSet;
    DHDictElement* element;
    DH_DICT_FOREACH(m_skinMap, element) {
        skinNameSet.insert(element->key);
    }
    std::string skinName = "";
    if (!skinNameSet.empty()) {
        for (const auto& iter : skinNameSet) {
            skinName += iter;
        }
    }
    
    char frameKey[128];
    if (m_animation) {
        int frameIndex = (fabsf(delta) > 0.f ? m_animation->getNextFrameTime(delta) : m_animation->getCurrentFrameTime()) / m_frameSequenceInterval;
        sprintf(frameKey, "%s@%d@", m_animation->getData()->getName().c_str(), frameIndex);
    }
    else {
        sprintf(frameKey, "setup@");
    }
    
    std::string fullKey = frameKey + skinName;
    return fullKey;
}

NS_CC_END