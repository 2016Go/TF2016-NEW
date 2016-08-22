//
//  DHAnimationData.cpp
//  dhspine
//
//  Created by youbin on 13-10-9.
//
//

#include "DHAnimationData.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

DHEventsKeyFrame::DHEventsKeyFrame() {
    data = new DHEvent();
}

DHEventsKeyFrame::~DHEventsKeyFrame() {
    delete data;
}

DHDrawOrderKeyFrame::DHDrawOrderKeyFrame()
:drawOrders(nullptr) {
    
}

DHDrawOrderKeyFrame::DHDrawOrderKeyFrame(int slotCount) {
    drawOrders = slotCount > 0 ? new int[slotCount] : nullptr;
}

DHDrawOrderKeyFrame::~DHDrawOrderKeyFrame() {
    CC_SAFE_DELETE_ARRAY(drawOrders);
}

//

DHAnimationData::DHAnimationData()
:m_duration(0.f)
,m_btCount(0)
,m_stCount(0)
,m_eventCount(0)
,m_drawOrderCount(0)
,m_ikConstraintCount(0)
,m_ffdCount(0)
,m_events(nullptr)
,m_drawOrders(nullptr)
,m_ikConstraintTransform(nullptr)
,m_ffdTransform(nullptr) {
    
}

DHAnimationData::DHAnimationData(unsigned int btCount, unsigned int stCount)
:m_duration(0.f)
,m_btCount(btCount)
,m_stCount(stCount)
,m_eventCount(0)
,m_drawOrderCount(0)
,m_ikConstraintCount(0)
,m_ffdCount(0)
,m_events(nullptr)
,m_drawOrders(nullptr)
,m_ikConstraintTransform(nullptr)
,m_ffdTransform(nullptr) {
    m_boneTransform = m_btCount ? new DHBoneTransform*[m_btCount] : nullptr;
    m_slotTransform = m_stCount ? new DHSlotTransform*[m_stCount] : nullptr;
}

DHAnimationData::~DHAnimationData() {
    DH_ARRAY_DELETE(m_boneTransform, m_btCount)
    DH_ARRAY_DELETE(m_slotTransform, m_stCount)
    DH_ARRAY_DELETE(m_events, m_eventCount)
    DH_ARRAY_DELETE(m_drawOrders, m_drawOrderCount)
    DH_ARRAY_DELETE(m_ikConstraintTransform, m_ikConstraintCount)
    DH_ARRAY_DELETE(m_ffdTransform, m_ffdCount)
}

DHAnimationData* DHAnimationData::create(unsigned int btCount, unsigned int stCount) {
    DHAnimationData* data = new DHAnimationData(btCount, stCount);
    data->autorelease();
    return data;
}

DHBoneTransform* DHAnimationData::createBoneTransform(unsigned int index, unsigned int boneIndex) {
    return m_boneTransform[index] = new DHBoneTransform(boneIndex);
}

DHSlotTransform* DHAnimationData::createSlotTransform(unsigned int index, unsigned int slotIndex) {
    return m_slotTransform[index] = new DHSlotTransform(slotIndex);
}

void DHAnimationData::createIkConstraintTimeline(unsigned int ikConstraintCount) {
    m_ikConstraintTransform = new DHIkConstraintTransform*[m_ikConstraintCount = ikConstraintCount];
}

DHIkConstraintTransform* DHAnimationData::createIkConstraintTransform(unsigned int index, unsigned int ikConstraintIndex) {
    return m_ikConstraintTransform[index] = new DHIkConstraintTransform(ikConstraintIndex);
}

void DHAnimationData::createFFDTimeline(unsigned int ffdCount) {
    m_ffdTransform = new DHFFDTransform*[m_ffdCount = ffdCount];
}

void DHAnimationData::freeFFDTimeline(int endIndex) {
    if (m_ffdCount && m_ffdTransform) {
        for (int i = 0; i < endIndex; i++) {
            delete m_ffdTransform[i];
        }
        delete [] m_ffdTransform;
        
        m_ffdTransform = nullptr;
        m_ffdCount = 0;
    }
}

DHFFDTransform* DHAnimationData::createFFDTransform(unsigned int index, int slotIndex, cocos2d::DHAttachment *attachment, unsigned int verticesCount) {
    return m_ffdTransform[index] = new DHFFDTransform(slotIndex, attachment, verticesCount);
}

void DHAnimationData::createEventTimeline(unsigned int eventCount) {
    m_events = new DHEventsKeyFrame*[m_eventCount = eventCount];
}

void DHAnimationData::createDrawOrderTimeLine(unsigned int drawOrderCount) {
    m_drawOrders = new DHDrawOrderKeyFrame*[m_drawOrderCount = drawOrderCount];
}

DHEventsKeyFrame* DHAnimationData::createEventsKeyFrame(unsigned int frameIndex) {
    return m_events[frameIndex] = new DHEventsKeyFrame();
}

DHDrawOrderKeyFrame* DHAnimationData::createDrawOrderKeyFrame(unsigned int frameIndex, unsigned int slotCount) {
    return m_drawOrders[frameIndex] = new DHDrawOrderKeyFrame(slotCount);
}

int DHAnimationData::binarySearchforEvent(float time) {
    if (time >= m_events[m_eventCount - 1]->time) {
        return -1;
    }
    int left = 0;
    int right = m_eventCount - 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (m_events[mid]->time <= time) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return  left;
}

void DHAnimationData::applyTo(DHSkeletonAnimation* owner, float frameTime, float alpha, bool inFadeOut) {
    DH_ARRAY_FOREACH(m_btCount) {
        m_boneTransform[i]->applyTo(owner, frameTime, alpha);
    }
    DH_ARRAY_FOREACH(m_stCount) {
        m_slotTransform[i]->applyTo(owner, frameTime, alpha);
    }
    DH_ARRAY_FOREACH(m_ikConstraintCount) {
        m_ikConstraintTransform[i]->applyTo(owner, frameTime, alpha);
    }
    DH_ARRAY_FOREACH(m_ffdCount) {
        m_ffdTransform[i]->applyTo(owner, frameTime, alpha);
    }
    
    if (!inFadeOut && m_drawOrders && m_drawOrders[0]->time <= frameTime) {
        int frameIndex;
        if (m_drawOrders[m_drawOrderCount - 1]->time <= frameTime) {
            frameIndex = m_drawOrderCount;
        }
        else {
            DH_BINARY_SEARCH(m_drawOrders, m_drawOrderCount, frameTime, frameIndex)
        }
        owner->setDrawOrder(m_drawOrders[frameIndex - 1]->drawOrders);
    }
}

void DHAnimationData::applyEventsTo(cocos2d::DHSkeletonAnimation *owner, float lastTime, float delta) {
    if (m_events) {
        int frameIndex = binarySearchforEvent(lastTime);
        if (frameIndex >= 0 && frameIndex < m_eventCount) {
            float frameTime = lastTime + delta;
            do {
                DHEventsKeyFrame* frame = m_events[frameIndex++];
                if (frame->time > frameTime) {
                    break;
                }
                owner->handleEvents(frame->data);
            } while (frameIndex < m_eventCount);
        }
    }
}

void DHAnimationData::applyEventsToBackward(DHSkeletonAnimation* owner, float lastTime, float delta) {
    if (m_events) {
        std::vector<DHEvent*> eventsVec;
        int frameIndex = binarySearchforEvent(lastTime);
        if (frameIndex >= 0 && frameIndex < m_eventCount) {
            float frameTime = lastTime + delta;
            do {
                DHEventsKeyFrame* frame = m_events[frameIndex++];
                if (frame->time > frameTime) {
                    break;
                }
                eventsVec.push_back(frame->data);
            } while (frameIndex < m_eventCount);
        }
        for (auto iter = eventsVec.rbegin(); iter != eventsVec.rend(); iter++) {
            owner->handleEvents(*iter);
        }
    }
}

void DHAnimationData::applyEventsToFirstFrame(float frameTime, cocos2d::DHSkeletonAnimation *owner) {
    if (m_events) {
        int frameIndex = 0;
        do {
            DHEventsKeyFrame* frame = m_events[frameIndex++];
            if (frame->time != frameTime) {
                break;
            }
            owner->handleEvents(frame->data);
        } while (frameIndex < m_eventCount);
    }
}

#define DH_UPDATE_DURATION(__array__, __count__)                                                         \
if (__count__) { updateDuration(__array__[__count__ - 1]->time); }

void DHAnimationData::updateInfo() {
    DH_ARRAY_FOREACH(m_btCount) {
        updateDuration(m_boneTransform[i]->updateInfo());
    }
    DH_ARRAY_FOREACH(m_stCount) {
        updateDuration(m_slotTransform[i]->updateInfo());
    }
    DH_ARRAY_FOREACH(m_ikConstraintCount) {
        updateDuration(m_ikConstraintTransform[i]->updateInfo());
    }
    DH_ARRAY_FOREACH(m_ffdCount) {
        updateDuration(m_ffdTransform[i]->updateInfo());
    }
    
    DH_UPDATE_DURATION(m_events, m_eventCount)
    DH_UPDATE_DURATION(m_drawOrders, m_drawOrderCount)
    
    if (m_duration <= 0.f) {
        m_duration = 1 / 30.f;
    }
}

void DHAnimationData::updateDuration(float duration) {
    if (duration > m_duration) {
        m_duration = duration;
    }
}

float DHAnimationData::getLastEventTimeByName(const char *name) {
    for (int i = m_eventCount - 1; i >= 0; i--) {
        if (m_events[i]->data->name == name) {
            return m_events[i]->time;
        }
    }
    return 0.f;
}

NS_CC_END