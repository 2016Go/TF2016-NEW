//
//  DHSlot.h
//  dhspine
//
//  Created by youbin on 13-9-29.
//
//

#ifndef __dhspine__DHSlot__
#define __dhspine__DHSlot__

#include "DHSlotData.h"

NS_CC_BEGIN

class DHBone;
class DHSkeleton;
class DHAttachment;
class DHRegionAttachment;
class DHBoundingBoxAttachment;
class DHSkinnedMeshAttachment;

class DHSlot {
    
    friend class DHRegionAttachment;
    friend class DHBoundingBoxAttachment;
    friend class DHMeshAttachment;
    friend class DHSkinnedMeshAttachment;
    friend class DHSlotTransform;
    friend class DHFFDTransform;
    friend class DHSkeletonData;
    
public:
    DHSlot(DHSlotData* const data, DHSkeleton* const skeleton);
    
    ~DHSlot();
    
    void setToSetupPose();
    
    void updateAttachment();
    
    DHAttachment* getAttachment();
    
    DHRegionAttachment* getRegionAttachment();
    
    DHBoundingBoxAttachment* getBoundingBoxAttachment();
    
    const char* getActiveAttachmentName() {
        return m_activeName;
    }
    
    DHBone* getBone() {
        return m_bone;
    }
    
    DHSlotData* getData() {
        return m_data;
    }
    
    SpineBlendType getBlendMode() {
        return m_data->m_blendMode;;
    }
    
    void setColorEnabled(bool colorEnabled) {
        m_colorEnabled = colorEnabled;
    }
    
    bool isColorEnabled() {
        return m_colorEnabled;
    }
    
    const char* getName() {
        return m_data->m_name;
    }
    
    void addFollowAttachment(Node* attachment, bool enabledFollowColor);
    
    void removeFollowAttachment();
    
    Node* getFollowAttachmentChild();
    
    bool isEnabledFollowAttachment();
    
    bool updateFollowAttachment();
    
    void drawFollowAttachment(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
private:
    DHSlot();

    DHSlotData* const m_data;
    DHSkeleton* const m_skeleton;
    DHBone* m_bone;
	
    const char* m_activeName;
    DHAttachment* m_attachment;
    
    GLfloat m_r, m_g, m_b, m_a;
    GLfloat m_cr, m_cg, m_cb, m_ca;
    
    bool m_colorEnabled;
    
    Node* m_followAttachment;//virtualNode
    bool m_enabledFollowColor;
    
    unsigned int m_attachmentVerticesCapacity;
    unsigned int m_attachmentVerticesCount;
    float* m_attachmentVertices;
    
    Color3B m_followAttachmentColor;
    GLubyte m_followAttachmentOpacity;
};

NS_CC_END

#endif /* defined(__dhspine__DHSlot__) */
