//
//  DHAttachment.h
//  dhspine
//
//  Created by youbin on 13-10-11.
//
//

#ifndef __dhspine__DHAttachment__
#define __dhspine__DHAttachment__

#include "DHBone.h"
#include "DHSlot.h"

NS_CC_BEGIN

enum class DHAttachmentType {
    at_region,
    at_mesh,
    at_skinned_mesh,
    at_boundingBox,
};

class DHAttachment : public Ref {
    
public:
    DHAttachment();
    
    virtual ~DHAttachment();
    
    void setType(DHAttachmentType type) {
        m_type = type;
    }
    
    DHAttachmentType getType() const {
        return m_type;
    }
    
    void setCurrentSlot(DHSlot* slot) {
        m_slot = slot;
    }
    
protected:
    DHSlot* m_slot;
    DHAttachmentType m_type;
};

NS_CC_END

#endif /* defined(__dhspine__DHAttachment__) */
