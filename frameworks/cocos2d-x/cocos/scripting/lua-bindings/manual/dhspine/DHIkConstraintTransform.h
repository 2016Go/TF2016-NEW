//
//  DHIkConstraintTransform.h
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#ifndef __MyTest__DHIkConstraintTransform__
#define __MyTest__DHIkConstraintTransform__

#include "DHBoneTransform.h"

NS_CC_BEGIN

struct DHIkConstraintKeyFrame : public DHCurveTimeline  {
    DHIkConstraintKeyFrame();
    
    virtual ~DHIkConstraintKeyFrame();
    
    float mix;
    int bendPositive;
};

class DHSkeletonAnimation;

class DHIkConstraintTransform {
    
public:
    DHIkConstraintTransform(int ikConstraintIndex);
    
    ~DHIkConstraintTransform();
    
    void createIkConstraintTimeline(unsigned int ikCount);
    
    DHIkConstraintKeyFrame* createIkConstraintKeyFrame(unsigned int frameIndex);
    
    float updateInfo();
    
    void applyTo(DHSkeletonAnimation* owner, float time, float alpha = 1.f);
    
protected:
    DHIkConstraintTransform();
    
    const int m_ikConstraintIndex;
    
    unsigned int m_ikConstraintCount;
    DHIkConstraintKeyFrame** m_ikConstraints;
};

NS_CC_END

#endif /* defined(__MyTest__DHIkConstraintTransform__) */
