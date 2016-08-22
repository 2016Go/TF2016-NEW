//
//  DHAnimationData.h
//  dhspine
//
//  Created by youbin on 13-10-9.
//
//

#ifndef __dhspine__DHAnimationData__
#define __dhspine__DHAnimationData__

#include "DHBoneTransform.h"
#include "DHSlotTransform.h"
#include "DHIkConstraintTransform.h"
#include "DHFFDTransform.h"

NS_CC_BEGIN

struct DHDrawOrderKeyFrame : public DHTimeline {
    DHDrawOrderKeyFrame(int slotCount);
    
    virtual ~DHDrawOrderKeyFrame();
    
    int* drawOrders;
    
private:
    DHDrawOrderKeyFrame();
};

struct DHEvent : public Ref {
    std::string name;
    
    int intValue;
    float floatValue;
    std::string stringValue;
    
    DH_CREATE_FUNC(DHEvent);
};

struct DHEventsKeyFrame : public DHTimeline  {
    DHEventsKeyFrame();
    
    virtual ~DHEventsKeyFrame();
    
    DHEvent* data;
};

class DHSkeletonAnimation;

class DHAnimationData : public Ref {
    
public:
    DHAnimationData(unsigned int btCount, unsigned int stCount);
    
    ~DHAnimationData();
    
    static DHAnimationData* create(unsigned int btCount, unsigned int stCount);
    
    DHBoneTransform* createBoneTransform(unsigned int index, unsigned int boneIndex);
    
    DHSlotTransform* createSlotTransform(unsigned int index, unsigned int slotIndex);
    
    void createIkConstraintTimeline(unsigned int ikConstraintCount);
    
    DHIkConstraintTransform* createIkConstraintTransform(unsigned int index, unsigned int ikConstraintIndex);
    
    void createFFDTimeline(unsigned int ffdCount);
    
    void freeFFDTimeline(int endIndex);
    
    DHFFDTransform* createFFDTransform(unsigned int index, int slotIndex, DHAttachment* attachment, unsigned int verticesCount);
    
    void createEventTimeline(unsigned int eventCount);
    
    void createDrawOrderTimeLine(unsigned int drawOrderCount);
    
    DHEventsKeyFrame* createEventsKeyFrame(unsigned int frameIndex);
    
    DHDrawOrderKeyFrame* createDrawOrderKeyFrame(unsigned int frameIndex, unsigned int slotCount);
    
    void applyTo(DHSkeletonAnimation* owner, float frameTime, float alpha, bool inFadeOut);
    
    void applyEventsTo(DHSkeletonAnimation* owner, float lastTime, float delta);
    
    void applyEventsToBackward(DHSkeletonAnimation* owner, float lastTime, float delta);
    
    void applyEventsToFirstFrame(float frameTime, DHSkeletonAnimation* owner);
    
    void updateInfo();
    
    float getDuration() const {
        return m_duration;
    }
    
    float getLastEventTimeByName(const char* name);
    
    void setName(const std::string& name) {
        m_name = name;
    }
    
    const std::string& getName() {
        return m_name;
    }
    
protected:
    DHAnimationData();
    
private:
    int binarySearchforEvent(float time);
    
    void updateDuration(float duration);
    
    unsigned int m_eventCount;
    DHEventsKeyFrame** m_events;
    
    unsigned int m_drawOrderCount;
    DHDrawOrderKeyFrame** m_drawOrders;
    
    unsigned int m_btCount;
    DHBoneTransform** m_boneTransform;
    
    unsigned int m_stCount;
    DHSlotTransform** m_slotTransform;
    
    unsigned int m_ikConstraintCount;
    DHIkConstraintTransform** m_ikConstraintTransform;
    
    unsigned int m_ffdCount;
    DHFFDTransform** m_ffdTransform;
    
    float m_duration;
    
    std::string m_name;
};

NS_CC_END

#endif /* defined(__dhspine__DHAnimationData__) */