//
//  DHAnimationInfo.cpp
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#include "DHAnimationInfo.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

DHAnimationInfo::DHAnimationInfo()
:m_data(nullptr)
,m_owner(nullptr)
,m_loop(0)
,m_frameTime(0)
,m_alpha(1)
,m_inFadeOut(false)
,m_frameIndex(-1) {
    
}

DHAnimationInfo::DHAnimationInfo(DHAnimationData* const data, DHSkeletonAnimation* const owner, int loop)
:m_data(data)
,m_owner(owner)
,m_loop(loop)
,m_frameTime(0)
,m_alpha(1)
,m_inFadeOut(false)
,m_frameIndex(-1) {
    if (m_owner->isPlayBackwardsEnabled()) {
        m_frameTime = m_data->getDuration();
    }
    m_owner->setDirty(true);
}

DHAnimationInfo::~DHAnimationInfo() {
    
}

void DHAnimationInfo::apply() {
    if (m_owner->getFrameSequenceInterval() > 0.f) {
        float interval = m_owner->getFrameSequenceInterval();
        int frameIndex = m_frameTime / interval;
        m_data->applyTo(m_owner, frameIndex * interval, 1.f, m_inFadeOut);
    }
    else {
        m_data->applyTo(m_owner, m_frameTime, m_alpha, m_inFadeOut);
    }
}

void DHAnimationInfo::update(float delta, float alpha) {
    if (m_alpha != alpha) {
        m_alpha = alpha;
        m_owner->setDirty(true);
    }
    
    if (isComplete()) {
        m_frameTime += delta;
        return;
    }
    if (delta == 0) {
        return;
    }
    
    m_owner->setDirty(true);
    
    if (delta < 0) {
        if (!m_inFadeOut) {
            m_data->applyEventsTo(m_owner, m_frameTime, delta);
        }
        m_frameTime += delta;
        
        if (m_frameTime <= 0) {
            if (m_loop < 0) {
                m_frameTime = getDuration() + fmodf(m_frameTime, getDuration());
            } else if(m_loop > 1) {
                m_loop--;
                m_frameTime = getDuration() + fmodf(m_frameTime, getDuration());
            } else {
                m_loop = 0;
                m_frameTime = 0;
            }
            if (!m_inFadeOut && m_loop) {
                m_data->applyEventsToBackward(m_owner, m_frameTime, getDuration());
                m_data->applyEventsToFirstFrame(m_frameTime, m_owner);
            }
        }
    }
    else {
        if (!m_inFadeOut) {
            m_data->applyEventsTo(m_owner, m_frameTime, delta);
        }
        m_frameTime += delta;
        
        if (m_frameTime >= getDuration()) {
            if (m_loop < 0) {
                m_frameTime = fmodf(m_frameTime, getDuration());
            } else if(m_loop > 1) {
                m_loop--;
                m_frameTime = fmodf(m_frameTime, getDuration());
            } else {
                m_loop = 0;
            }
            if (!m_inFadeOut && m_loop) {
                m_data->applyEventsToFirstFrame(0.f, m_owner);
                m_data->applyEventsTo(m_owner, 0.f, m_frameTime);
            }
        }
    }
}

void DHAnimationInfo::applyEventsToFirstFrame(float frameTime) {
    m_data->applyEventsToFirstFrame(frameTime, m_owner);
}

float DHAnimationInfo::getCurrentFrameTime() {
    float duration = getDuration();
    if (m_frameTime > duration) {
        return duration;
    }
    return m_frameTime;
}

float DHAnimationInfo::getNextFrameTime(float delta) {
    float duration = getDuration();
    if (isComplete()) {
        return duration;
    }
    
    float frameTime = m_frameTime;
    if (delta < 0) {
        frameTime += delta;
        
        if (frameTime <= 0) {
            if (m_loop < 0) {
                frameTime = duration + fmodf(frameTime, duration);
            } else if(m_loop > 1) {
                frameTime = duration + fmodf(frameTime, duration);
            } else {
                frameTime = 0;
            }
        }
    }
    else {
        frameTime += delta;
        
        if (frameTime >= duration) {
            if (m_loop < 0) {
                frameTime = fmodf(frameTime, duration);
            } else if(m_loop > 1) {
                frameTime = fmodf(frameTime, duration);
            } else {
                frameTime = duration;
            }
        }
    }
    return frameTime;
}

void DHAnimationInfo::updateFrameTime(float delta) {
    if (isComplete()) {
        m_frameTime += delta;
        return;
    }
    if (delta == 0) {
        return;
    }
    
    if (delta < 0) {
        if (!m_inFadeOut) {
            m_data->applyEventsTo(m_owner, m_frameTime, delta);
        }
        m_frameTime += delta;
        
        if (m_frameTime <= 0) {
            if (m_loop < 0) {
                m_frameTime = getDuration() + fmodf(m_frameTime, getDuration());
            } else if(m_loop > 1) {
                m_loop--;
                m_frameTime = getDuration() + fmodf(m_frameTime, getDuration());
            } else {
                m_loop = 0;
                m_frameTime = 0;
            }
            if (!m_inFadeOut && m_loop) {
                m_data->applyEventsToBackward(m_owner, m_frameTime, getDuration());
                m_data->applyEventsToFirstFrame(m_frameTime, m_owner);
            }
        }
    }
    else {
        if (!m_inFadeOut) {
            m_data->applyEventsTo(m_owner, m_frameTime, delta);
        }
        m_frameTime += delta;
        
        if (m_frameTime >= getDuration()) {
            if (m_loop < 0) {
                m_frameTime = fmodf(m_frameTime, getDuration());
            } else if(m_loop > 1) {
                m_loop--;
                m_frameTime = fmodf(m_frameTime, getDuration());
            } else {
                m_loop = 0;
            }
            if (!m_inFadeOut && m_loop) {
                m_data->applyEventsToFirstFrame(0.f, m_owner);
                m_data->applyEventsTo(m_owner, 0.f, m_frameTime);
            }
        }
    }
}

void DHAnimationInfo::updateToFrameIndex(float delta, float interval) {
    if (isComplete()) {
        m_frameTime += delta;
        return;
    }
    if (delta == 0) {
        return;
    }
    
    if (delta < 0) {
        if (!m_inFadeOut) {
            m_data->applyEventsTo(m_owner, m_frameTime, delta);
        }
        m_frameTime += delta;
        
        if (m_frameTime <= 0) {
            if (m_loop < 0) {
                m_frameTime = getDuration() + fmodf(m_frameTime, getDuration());
            } else if(m_loop > 1) {
                m_loop--;
                m_frameTime = getDuration() + fmodf(m_frameTime, getDuration());
            } else {
                m_loop = 0;
                m_frameTime = 0;
            }
            if (!m_inFadeOut && m_loop) {
                m_data->applyEventsToBackward(m_owner, m_frameTime, getDuration());
                m_data->applyEventsToFirstFrame(m_frameTime, m_owner);
            }
        }
    }
    else {
        if (!m_inFadeOut) {
            m_data->applyEventsTo(m_owner, m_frameTime, delta);
        }
        m_frameTime += delta;
        
        if (m_frameTime >= getDuration()) {
            if (m_loop < 0) {
                m_frameTime = fmodf(m_frameTime, getDuration());
            } else if(m_loop > 1) {
                m_loop--;
                m_frameTime = fmodf(m_frameTime, getDuration());
            } else {
                m_loop = 0;
            }
            if (!m_inFadeOut && m_loop) {
                m_data->applyEventsToFirstFrame(0.f, m_owner);
                m_data->applyEventsTo(m_owner, 0.f, m_frameTime);
            }
        }
    }
    
    int frameIndex = m_frameTime / interval;
    if (frameIndex != m_frameIndex) {
        m_frameIndex = frameIndex;
        m_owner->setDirty(true);
    }
}

NS_CC_END