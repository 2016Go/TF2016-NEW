//
//  DHSkeletonAnimation.h
//  dhspine
//
//  Created by youbin on 13-10-7.
//
//

#ifndef __dhspine__DHSkeletonAnimation__
#define __dhspine__DHSkeletonAnimation__

#include "DHSkeleton.h"
#include "DHAnimationInfo.h"

#include <queue>
#include <vector>

NS_CC_BEGIN

struct DHRegisterAnimationInfo : public Ref {
    DHAnimationInfo* info;
    bool autoRemove;
    
    DHRegisterAnimationInfo(DHAnimationData* const _data, DHSkeletonAnimation* const _owner, int _loop, bool _autoRemove)
    :autoRemove(_autoRemove) {
        info = new DHAnimationInfo(_data, _owner, _loop);
    }
    
    ~DHRegisterAnimationInfo() {
        CC_SAFE_DELETE(info);
    }
    
    static DHRegisterAnimationInfo* create(DHAnimationData* const _data, DHSkeletonAnimation* const _owner, int _loop, bool _autoRemove) {
        DHRegisterAnimationInfo* info = new DHRegisterAnimationInfo(_data, _owner, _loop, _autoRemove);
        info->autorelease();
        return info;
    }
    
    bool onUpdate(float delta);
};

struct DHRegisterRandomAnimationInfo : public Ref {
    DHAnimationInfo* info;
    float minRange;
    float maxRange;
    float randomTime;
    float timeCount;
    bool playing;
    
    DHRegisterRandomAnimationInfo(DHAnimationData* const _data, DHSkeletonAnimation* const _owner, float _minRange, float _maxRange)
    :minRange(_minRange)
    ,maxRange(_maxRange)
    ,timeCount(0.f)
    ,playing(false) {
        info = new DHAnimationInfo(_data, _owner, 1);
        resetRandom();
    }
    
    ~DHRegisterRandomAnimationInfo() {
        CC_SAFE_DELETE(info);
    }
    
    static DHRegisterRandomAnimationInfo* create(DHAnimationData* const _data, DHSkeletonAnimation* const _owner, float _minRange, float _maxRange) {
        DHRegisterRandomAnimationInfo* info = new DHRegisterRandomAnimationInfo(_data, _owner, _minRange, _maxRange);
        info->autorelease();
        return info;
    }
    
    void resetRandom() {
        randomTime = minRange + CCRANDOM_0_1() * (maxRange - minRange);
    }
    
    virtual void update(float delta);
};

struct DHNextAnimationInfo {
    char* name;
    int loop;
    float mixDuration;
    
    DHNextAnimationInfo(const char* _name, int _loop, float _mixDuration)
    :loop(_loop)
    ,mixDuration(_mixDuration) {
        name = DHStrCopy(_name);
    }
    
    ~DHNextAnimationInfo() {
        DHStrFree(name);
    }
};

class DHSkeletonAnimation : public DHSkeleton {
    
public:
    DHSkeletonAnimation(DHSkeletonData* const data);
    
    virtual ~DHSkeletonAnimation();
    
    static DHSkeletonAnimation* createWithKey(const char* const key);
    
    static DHSkeletonAnimation* createWithFile(const char* const jsonPath);
    
    static DHSkeletonAnimation* createWithData(DHSkeletonData* const data);
    
    DHAnimationInfo* getAnimationInfo() {
        return m_animation;
    }
    
    DHAnimationData* getAnimationData() {
        return m_animation ? m_animation->getData() : nullptr;
    }
    
    virtual void registerSkin(const char* skinName);
    
    virtual void unregisterSkin(const char* skinName);
    
    virtual void unregisterAllSkin();
    
    virtual void update(float delta);
    
    bool isActive() const;
    
    void update(float delta, float appendDelata);
    
    bool onUpdate(float delta);
    
    bool onUpdate(float delta, float appendDelata);
    
    bool isUpdateFill(float delta);
    
    bool isUpdateFill(float delta, float appendDelata);
    
    bool onUpdateAndDelayTransform(float delta);
    
    //for lua
    void stepAnimation(float delta, const ValueMap& appendDelataMap);
    
    void stopAnimation();
    
    void playAnimation(const char* animationName, int loop = 1, float mixDuration = 0.1f);
    
    void registerAnimation(const char* animationName, int loop = 1, bool autoRemove = true);
    
    void unregisterAnimation(const char* animationName);
    
    void unregisterAllAnimation();
    
    DHAnimationInfo* getRegisteredAnimation(const char* animationName);
    
    void appendNextAnimation(const char* animationName, int loop = 1, float mixDuration = 0.1f);
    
    void clearNextAnimation();
    
    void registerRandomAnimation(const char* animationName, float minRange, float maxRange);
    
    void unregisterRandomAnimation(const char* animationName);
    
    void unregisterAllRandomAnimation();
    
    DHAnimationInfo* getRegisteredRandomAnimation(const char* animationName);
    
    void setPause(bool pause) {
        m_pause = pause;
    }
    
    void setAutoRemove(bool autoRemove) {
        m_autoRemove = autoRemove;
    }
    
    void addCascadeChildToSet(DHSkeletonAnimation *child);
    
    void removeCascadeChildFromSet(DHSkeletonAnimation *child);
    
    void clearCascadeChildSet();
    
    void setTimeScale(float timeScale) {
        m_timeScale = timeScale;
    }
    
    float getTimeScale() const {
        return m_timeScale;
    }
    
    bool isComplete() const {
        return !m_animation || m_animation->isComplete();
    }
    
    void registerEventsHandler(std::function<void(const DHEvent*)> handler) {
        m_eventsHandler = handler;
    }
    
    void unregisterEventsHandler() {
        m_eventsHandler = nullptr;
    }
    
    void registerSenderEventsHandler(std::function<void(DHSkeletonAnimation*, const DHEvent*)> handler) {
        m_senderEventsHandler = handler;
    }
    
    void unregisterSenderEventsHandler() {
        m_senderEventsHandler = nullptr;
    }
    
    void handleEvents(const DHEvent* event);
    
    float getAnimationTime(const char* anim);
    
    float getEventTime(const char* anim, const char* e);
    
    //for lua
    void scheduleUpdateLua();
    
    //for lua
    void registerLuaHandler(int handler);
    
    void setPlayBackwardsEnabled(bool enabled) {
        m_playBackwardsEnabled = enabled;
    }
    
    bool isPlayBackwardsEnabled() {
        return m_playBackwardsEnabled;
    }
    
    void setAutoApply(bool autoApply) {
        m_autoApply = autoApply;
    }
    
    void setFrameSequenceInterval(float interval);
    
    float getFrameSequenceInterval() const {
        return m_frameSequenceInterval;
    }
    
    void applyAnimation(bool transformFlag);
    
    bool isDirty() const {
        return m_dirty;
    }
    
    void setDirty(bool dirty) {
        m_dirty = dirty;
    }
    
protected:
    DHSkeletonAnimation();
    
    void updateAnimation(float delta);
    
    void updateAppendAnimation(float delta);
    
    void updateNextAnimation();
    
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    void drawFrameSequence(Renderer *renderer, const Mat4& transform);
    
    void drawSkeletonFrameSequence(const Mat4& transform);
    
    std::string getFrameSequenceFullKey(float delta);
    
protected:
    bool m_autoApply;
    
private:
    DHAnimationInfo* m_animation;
    DHAnimationInfo* m_preAnimation;
    
    DHDictionary* m_appendAnimationMap;
    DHDictionary* m_randomAnimationMap;
    
    std::queue<DHNextAnimationInfo*> m_nextAnimationQue;
    
    std::set<DHSkeletonAnimation*> m_cascadeChildSet;
    
    bool m_beinMix;
    float m_mixTime;
    float m_mixDuration;
    
    float m_timeScale;
    
    bool m_pause;
    
    bool m_autoRemove;
    
    std::function<void(const DHEvent*)> m_eventsHandler;
    std::function<void(DHSkeletonAnimation*, const DHEvent*)> m_senderEventsHandler;
    
    int m_scriptHandler;
    bool m_playBackwardsEnabled;
    
    float m_frameSequenceInterval;
    Sprite* m_renderCacheSprite;
    
    bool m_dirty;
};

typedef std::function<void(DHSkeletonAnimation*, const DHEvent*)> DHCallbackFunc;

NS_CC_END

#endif /* defined(__dhspine__DHSkeletonAnimation__) */
