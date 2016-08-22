//
//  DHSlotTransform.h
//  dhspine
//
//  Created by youbin on 13-10-7.
//
//

#ifndef __dhspine__DHSlotTransform__
#define __dhspine__DHSlotTransform__

#include "DHBoneTransform.h"

NS_CC_BEGIN

struct DHColorKeyFrame : public DHCurveTimeline {
    GLfloat r, g, b, a;
};


struct DHAttachmentKeyFrame : public DHTimeline {
    DHAttachmentKeyFrame(const char* name);
    
    virtual ~DHAttachmentKeyFrame();
    
    char* attachmentName;
    
protected:
    DHAttachmentKeyFrame();
};

class DHSkeletonAnimation;

class DHSlotTransform {
    
public:
    DHSlotTransform(int slotIndex);
    
    ~DHSlotTransform();
    
    void createColorTimeline(unsigned int colorCount);
    
    void createAttachmentTimeline(unsigned int attachmentCount);
    
    DHColorKeyFrame* createColorKeyFrame(unsigned int frameIndex);
    
    DHAttachmentKeyFrame* createAttachmentKeyFrame(unsigned int frameIndex, const char* attachmentName);
    
    void applyTo(DHSkeletonAnimation* owner, float time, float alpha = 1.f);
    
    float updateInfo();
    
private:
    DHSlotTransform();
    
    const int m_slotIndex;
    
    unsigned int m_colorCount;
    DHColorKeyFrame** m_color;
    
    unsigned int m_attachmentCount;
    DHAttachmentKeyFrame** m_attachment;
};

NS_CC_END

#endif /* defined(__dhspine__DHSlotTransform__) */
