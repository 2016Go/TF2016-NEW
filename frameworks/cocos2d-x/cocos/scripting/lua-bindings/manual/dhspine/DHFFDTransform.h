//
//  DHFFDTransform.h
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#ifndef __MyTest__DHFFDTransform__
#define __MyTest__DHFFDTransform__

#include "DHBoneTransform.h"
#include "DHAttachment.h"

NS_CC_BEGIN

struct DHFFDKeyFrame : public DHCurveTimeline  {
    DHFFDKeyFrame(unsigned int verticesCount);
    
    virtual ~DHFFDKeyFrame();
    
    float* vertices;
    
private:
    DHFFDKeyFrame();
};

class DHSkeletonAnimation;

class DHFFDTransform {
    
public:
    DHFFDTransform(int slotIndex, DHAttachment* attachment, unsigned int verticesCount);
    
    ~DHFFDTransform();
    
    void createFFDTimeline(unsigned int ffdCount);
    
    DHFFDKeyFrame* createFFDKeyFrame(unsigned int frameIndex);
    
    float updateInfo();
    
    void applyTo(DHSkeletonAnimation* owner, float time, float alpha = 1.f);
    
protected:
    DHFFDTransform();
    
    const int m_slotIndex;
    const DHAttachment* m_attachment;
    const unsigned int m_verticesCount;
    
    unsigned int m_ffdCount;
    DHFFDKeyFrame** m_ffds;
};

NS_CC_END

#endif /* defined(__MyTest__DHFFDTransform__) */
