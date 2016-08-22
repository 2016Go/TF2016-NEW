//
//  DHBone.cpp
//  dhspine
//
//  Created by youbin on 13-9-29.
//
//

#include "DHBone.h"
#include "DHBoneTransform.h"

NS_CC_BEGIN

DHBone::DHBone()
:m_data(nullptr)
,m_parent(nullptr)
,m_followAttachment(nullptr) {
    
}

DHBone::DHBone(DHBoneData* const data)
:m_data(data)
,m_parent(nullptr)
,m_followAttachment(nullptr) {
    setToSetupPose();
}

DHBone::~DHBone() {
    CC_SAFE_RELEASE(m_followAttachment);
}

void DHBone::setToSetupPose() {
    m_x = m_data->m_x;
    m_y = m_data->m_y;
    m_rotation = m_data->m_rotation;
    m_rotationIK = m_rotation;
    m_scaleX = m_data->m_scaleX;
    m_scaleY = m_data->m_scaleY;
    m_flipX = m_data->m_flipX;
    m_flipY = m_data->m_flipY;
}

void DHBone::updateWorldTransform() {
    if (m_parent) {
        m_worldX = m_x * m_parent->m_m00 + m_y * m_parent->m_m01 + m_parent->m_worldX;
        m_worldY = m_x * m_parent->m_m10 + m_y * m_parent->m_m11 + m_parent->m_worldY;
        m_worldRotation = m_data->m_inheritRotation ? m_parent->m_worldRotation + m_rotationIK : m_rotationIK;
        if (m_data->m_inheritScale) {
            m_worldScaleX = m_parent->m_worldScaleX * m_scaleX;
            m_worldScaleY = m_parent->m_worldScaleY * m_scaleY;
        }
        else {
            m_worldScaleX = m_scaleX;
            m_worldScaleY = m_scaleY;
        }
        m_worldFlipX = m_parent->m_worldFlipX ^ m_flipX;
        m_worldFlipY = m_parent->m_worldFlipY ^ m_flipY;
    }
    else {
        m_worldX = m_x;
        m_worldY = m_y;
        m_worldRotation = m_rotationIK;
        m_worldScaleX = m_scaleX;
        m_worldScaleY = m_scaleY;
        m_worldFlipX = m_flipX;
        m_worldFlipY = m_flipY;
    }
    float radians = m_worldRotation * DEG_RAD;
    float cosine = cosf(radians);
    float sine = sinf(radians);
    if (m_worldFlipX) {
        m_m00 = -cosine * m_worldScaleX;
        m_m01 = sine * m_worldScaleY;
    }
    else {
        m_m00 = cosine * m_worldScaleX;
        m_m01 = -sine * m_worldScaleY;
    }
    if (m_worldFlipY) {//TODO yDown
        m_m10 = -sine * m_worldScaleX;
        m_m11 = -cosine * m_worldScaleY;
    }
    else {
        m_m10 = sine * m_worldScaleX;
        m_m11 = cosine * m_worldScaleY;
    }
}

void DHBone::updateFollowAttachment(bool isFlipX, bool isFlipY) {
    if (m_followAttachment) {
        if (m_followAttachment->getParent() && m_followAttachment->getChildrenCount()) {
            if (isFlipX) {
                m_followAttachment->setPositionX(-m_worldX);
            }
            else {
                m_followAttachment->setPositionX(m_worldX);
            }
            
            if (isFlipY) {
                m_followAttachment->setPositionY(-m_worldY);
            }
            else {
                m_followAttachment->setPositionY(m_worldY);
            }
            
            m_followAttachment->setRotation(-m_worldRotation);
            m_followAttachment->setScaleX(m_worldScaleX);
            m_followAttachment->setScaleY(m_worldScaleY);
        }
        else {
            m_followAttachment->release();
            m_followAttachment = nullptr;
        }
    }
}

void DHBone::addFollowAttachment(cocos2d::Node *attachment) {
    removeFollowAttachment();
    m_followAttachment = attachment;
    m_followAttachment->retain();
}

void DHBone::removeFollowAttachment() {
    if (m_followAttachment) {
        m_followAttachment->removeFromParent();
        m_followAttachment->release();
        m_followAttachment = nullptr;
    }
}

Node* DHBone::getFollowAttachmentChild() {
    if (m_followAttachment) {
        Vector<Node*>& children = m_followAttachment->getChildren();
        return children.at(0);
    }
    return nullptr;
}

void DHBone::localToWorld(float localX, float localY, float* worldX, float* worldY) {
    *worldX = localX * m_m00 + localY * m_m01 + m_worldX;
    *worldY = localX * m_m10 + localY * m_m11 + m_worldY;
}

void DHBone::worldToLocal(float worldX, float worldY, float* localX, float* localY) {
    float invDet;
    float dx = worldX - m_worldX, dy = worldY - m_worldY;
    float m00 = m_m00, m11 = m_m11;

    //TODO yDown
    if (m_worldFlipX != m_worldFlipY) {
        m00 *= -1;
        m11 *= -1;
    }
    
    invDet = 1 / (m00 * m11 - m_m01 * m_m10);
    *localX = (dx * m00 * invDet - dy * m_m01 * invDet);
    *localY = (dy * m11 * invDet - dx * m_m10 * invDet);
}

NS_CC_END