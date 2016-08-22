//
//  DHIkConstraintTransform.cpp
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#include "DHIkConstraintTransform.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

DHIkConstraintKeyFrame::DHIkConstraintKeyFrame() {
    
}

DHIkConstraintKeyFrame::~DHIkConstraintKeyFrame() {
    
}

DHIkConstraintTransform::DHIkConstraintTransform()
:m_ikConstraintIndex(0)
,m_ikConstraintCount(0)
,m_ikConstraints(nullptr) {
    
}

DHIkConstraintTransform::DHIkConstraintTransform(int ikConstraintIndex)
:m_ikConstraintIndex(ikConstraintIndex)
,m_ikConstraintCount(0)
,m_ikConstraints(nullptr) {
    
}

DHIkConstraintTransform::~DHIkConstraintTransform() {
    DH_ARRAY_DELETE(m_ikConstraints, m_ikConstraintCount);
}

void DHIkConstraintTransform::createIkConstraintTimeline(unsigned int ikCount) {
    m_ikConstraints = new DHIkConstraintKeyFrame*[m_ikConstraintCount = ikCount];
}

DHIkConstraintKeyFrame* DHIkConstraintTransform::createIkConstraintKeyFrame(unsigned int frameIndex) {
    return m_ikConstraints[frameIndex] = new DHIkConstraintKeyFrame();
}

float DHIkConstraintTransform::updateInfo() {
    DH_UPDATE_DIFF_TIME(m_ikConstraints, m_ikConstraintCount)
    
    float maxs = 0.f;
    DH_GET_DURATION(m_ikConstraints, m_ikConstraintCount, maxs)
    
    return maxs;
}

void DHIkConstraintTransform::applyTo(cocos2d::DHSkeletonAnimation *owner, float time, float alpha) {
    if (m_ikConstraints[0]->time <= time) {
        float mix = 0.f;
        int bendDirection = 0;
        if (m_ikConstraints[m_ikConstraintCount - 1]->time <= time) {
            DHIkConstraintKeyFrame* frame = m_ikConstraints[m_ikConstraintCount -1];
            mix = frame->mix;
            bendDirection = frame->bendPositive;
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_ikConstraints, m_ikConstraintCount, time, frameIndex)
            DHIkConstraintKeyFrame* frames = m_ikConstraints[frameIndex];
            DHIkConstraintKeyFrame* lastFrame = m_ikConstraints[frameIndex - 1];
            float percent = lastFrame->getInterpolationPercent(time - lastFrame->time);
            
            mix = lastFrame->mix + (frames->mix - lastFrame->mix) * percent;
            bendDirection = lastFrame->bendPositive;
        }
        
        DHIkConstraint* ikConstraint = owner->getIkConstraints(m_ikConstraintIndex);
        ikConstraint->m_mix += mix * alpha;
        ikConstraint->m_bendDirection = bendDirection;
    }
}

NS_CC_END