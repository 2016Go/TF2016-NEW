//
//  DHBone.h
//  dhspine
//
//  Created by youbin on 13-9-29.
//
//

#ifndef __dhspine__DHBone__
#define __dhspine__DHBone__

#include "DHBoneData.h"

NS_CC_BEGIN

class DHSlot;
class DHSkeleton;

class DHBone {
    
    friend class DHSlot;
    friend class DHRegionAttachment;
    friend class DHBoundingBoxAttachment;
    friend class DHBoneTransform;
    friend class DHSkeletonData;
    
public:
    DHBone(DHBoneData* data);
    
    ~DHBone();
    
    void setToSetupPose();
    
    void updateWorldTransform();
    
    int getIndex() const {
        return m_data->m_index;
    }
    
    DHBoneData* getData() {
        return m_data;
    }
    
    void updateFollowAttachment(bool isFlipX, bool isFlipY);
    
    void addFollowAttachment(Node *attachment);
    
    void removeFollowAttachment();
    
    Node* getFollowAttachmentChild();
    
    void localToWorld(float localX, float localY, float* worldX, float* worldY);
    
    void worldToLocal(float worldX, float worldY, float* localX, float* localY);
    
    float getX() const {
        return m_x;
    }
    
    float getY() const {
        return m_y;
    }
    
    void setX(float x) {
        m_x = x;
    }
    
    void setY(float y) {
        m_y = y;
    }
    
    float getRotation() const {
        return m_rotation;
    }
    
    void setRotation(float rotation) {
        m_rotation = rotation;
    }
    
    float getScaleX() const {
        return m_scaleX;
    }
    
    float getScaleY() const {
        return m_scaleY;
    }
    
    void setScaleX(float scaleX) {
        m_scaleX = scaleX;
    }
    
    void setScaleY(float scaleY) {
        m_scaleY = scaleY;
    }
    
    float getWorldX() const {
        return m_worldX;
    }
    
    float getWorldY() const {
        return m_worldY;
    }
    
    float getWorldScaleX() const {
        return m_worldScaleX;
    }
    
    float getWorldScaleY() const {
        return m_worldScaleY;
    }
    
    //public data
    float m_x, m_y;
	float m_rotation, m_rotationIK;
	float m_scaleX, m_scaleY;
    bool m_flipX, m_flipY;
    
    float m_m00, m_m01, m_worldX; /* a b x */
    float m_m10, m_m11, m_worldY; /* c d y */
    float m_worldRotation;
    float m_worldScaleX, m_worldScaleY;
    bool m_worldFlipX, m_worldFlipY;
    
    DHBone* m_parent;
    
protected:
    DHBone();
    
private:
    
	DHBoneData* const m_data;
    
    Node* m_followAttachment;
};

NS_CC_END

#endif /* defined(__dhspine__DHBone__) */
