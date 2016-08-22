//
//  DHSlotData.h
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#ifndef __dhspine__DHSlotData__
#define __dhspine__DHSlotData__

#include "DHGlobal.h"

NS_CC_BEGIN

class DHSlotData : public Ref {
    
    friend class DHSlot;
    friend class DHSkeleton;
    friend class DHSpineLoader;
    friend class DHSkeletonData;
    friend class DHRegionAttachment;
    
public:
    DHSlotData(const char* name, const char* attachmentName);
    
    static DHSlotData* create(const char* name, const char* attachmentName);
    
    ~DHSlotData();
    
public:
    int m_index;
    int m_boneIndex;
    char* m_name;
    char* m_attachmentName;
    SpineBlendType m_blendMode;
    GLfloat m_r, m_g, m_b, m_a;
    
protected:
    DHSlotData();
    
};

NS_CC_END

#endif /* defined(__dhspine__DHSlotData__) */
