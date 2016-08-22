//
//  DHAnimationInfo.h
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#ifndef __dhspine__DHAnimation__
#define __dhspine__DHAnimation__

#include "DHAnimationData.h"

NS_CC_BEGIN

class DHSkeletonAnimation;

class DHAnimationInfo {
    
public:
    DHAnimationInfo(DHAnimationData* const data, DHSkeletonAnimation* const owner, int loop);
    
    ~DHAnimationInfo();
    
    void apply();
    
    void update(float delta, float alpha = 1.f);
    
    void setInFadeOut(bool inFadeOut) {
        m_inFadeOut = inFadeOut;
    }
    
    int getLoopCount() const {
        return m_loop;
    }
    
    void setLoopCount(int loop) {
        m_loop = loop;
    }
    
    float getFrameTime() const {
        return m_frameTime;
    }
    
    void setFrameTime(float frameTime) {
        m_frameTime = frameTime;
    }
    
    bool isComplete() const {
        return m_loop == 0;
    }
    
    DHAnimationData* const getData() {
        return m_data;
    }
    
    float getDuration() const {
        return m_data->getDuration();
    }
    
    void applyEventsToFirstFrame(float frameTime);
    
    float getCurrentFrameTime();
    
    float getNextFrameTime(float delta);
    
    void updateFrameTime(float delta);
    
    void updateToFrameIndex(float delta, float interval);
    
protected:
    DHAnimationInfo();
    
private:
    int m_loop;
    float m_frameTime;
    bool m_inFadeOut;
    float m_alpha;
    
    DHAnimationData* const m_data;
    DHSkeletonAnimation* const m_owner;
    
    int m_frameIndex;
};

NS_CC_END

#endif /* defined(__dhspine__DHAnimation__) */
