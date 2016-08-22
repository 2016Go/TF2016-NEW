//
//  DHSlot.cpp
//  dhspine
//
//  Created by youbin on 13-9-29.
//
//

#include "DHSlot.h"
#include "DHSkeleton.h"

NS_CC_BEGIN

DHSlot::DHSlot()
:m_data(nullptr)
,m_skeleton(nullptr)
,m_colorEnabled(true)
,m_attachmentVertices(nullptr)
,m_attachmentVerticesCount(0)
,m_attachmentVerticesCapacity(0) {
    
}

DHSlot::DHSlot(DHSlotData* const data, DHSkeleton* const skeleton)
:m_data(data)
,m_skeleton(skeleton)
,m_colorEnabled(true)
,m_followAttachment(nullptr)
,m_attachmentVertices(nullptr)
,m_attachmentVerticesCount(0)
,m_attachmentVerticesCapacity(0) {
    setToSetupPose();
}

DHSlot::~DHSlot() {
    CC_SAFE_RELEASE(m_followAttachment);
    CC_SAFE_DELETE_ARRAY(m_attachmentVertices);
}

void DHSlot::setToSetupPose() {
    m_r = m_data->m_r;
    m_g = m_data->m_g;
    m_b = m_data->m_b;
    m_a = m_data->m_a;
    m_activeName = m_data->m_attachmentName;
    m_attachmentVerticesCount = 0;
}

void DHSlot::updateAttachment() {
    m_cr = m_r;
    m_cg = m_g;
    m_cb = m_b;
    m_ca = m_a;
    m_attachment = m_skeleton->getAttachment(m_data->m_index, m_activeName);
    //setToSetupPose();
}

DHAttachment* DHSlot::getAttachment() {
    return m_attachment;
}

DHRegionAttachment* DHSlot::getRegionAttachment() {
    if (m_attachment && m_attachment->getType() == DHAttachmentType::at_region) {
        return (DHRegionAttachment*)m_attachment;
    }
    return nullptr;
}

DHBoundingBoxAttachment* DHSlot::getBoundingBoxAttachment() {
    if (m_attachment && m_attachment->getType() == DHAttachmentType::at_boundingBox) {
        return (DHBoundingBoxAttachment*)m_attachment;
    }
    return nullptr;
}

void DHSlot::addFollowAttachment(cocos2d::Node *attachment, bool enabledFollowColor) {
    removeFollowAttachment();
    m_followAttachment = attachment;
    m_followAttachment->retain();
    m_enabledFollowColor = enabledFollowColor;
    
    m_followAttachmentColor = attachment->getColor();
    m_followAttachmentOpacity = attachment->getOpacity();
    m_followAttachment->setColor(m_followAttachmentColor);
    m_followAttachment->setOpacity(m_followAttachmentOpacity);
}

void DHSlot::removeFollowAttachment() {
    if (m_followAttachment) {
        m_skeleton->removeSlotFollowAttachment(m_followAttachment);
        m_followAttachment->removeFromParent();
        m_followAttachment->release();
        m_followAttachment = nullptr;
    }
}

Node* DHSlot::getFollowAttachmentChild() {
    if (m_followAttachment) {
        Vector<Node*>& children = m_followAttachment->getChildren();
        return children.at(0);
    }
    return nullptr;
}

bool DHSlot::isEnabledFollowAttachment() {
    return m_followAttachment != nullptr;
}

bool DHSlot::updateFollowAttachment() {
    if (m_followAttachment && m_followAttachment->getOpacity() > 0) {
        if (m_followAttachment->getParent() && m_followAttachment->getChildrenCount()) {
            Vector<Node*>&  children = m_followAttachment->getChildren();
            Node* actualNode = children.at(0);
            DHBone* bone = getBone();
            
            if (m_skeleton->isFlipX()) {
                m_followAttachment->setPositionX(-bone->m_worldX);
            }
            else {
                m_followAttachment->setPositionX(bone->m_worldX);
            }
            
            if (m_skeleton->isFlipY()) {
                m_followAttachment->setPositionY(-bone->m_worldY);
            }
            else {
                m_followAttachment->setPositionY(bone->m_worldY);
            }
            
            m_followAttachment->setRotation(-bone->m_worldRotation);
            m_followAttachment->setScaleX(bone->m_worldScaleX);
            m_followAttachment->setScaleY(bone->m_worldScaleY);
            
            if (m_enabledFollowColor) {
                if (m_followAttachmentColor != actualNode->getColor()) {
                    m_followAttachment->setColor(actualNode->getColor());
                }
                if (m_followAttachmentOpacity != actualNode->getOpacity()) {
                    m_followAttachment->setOpacity(actualNode->getOpacity());
                }
                
                Color3B color = m_followAttachment->getColor();
                GLubyte opacity = m_followAttachment->getOpacity();
                
                const Color4F& ownerColor = m_skeleton->getReallyColor();
                actualNode->setColor(Color3B(m_cr * ownerColor.r * color.r, m_cg * ownerColor.g * color.g, m_cb * ownerColor.b * color.b));
                actualNode->setOpacity(m_ca * ownerColor.a * opacity);
                
                m_followAttachmentColor = actualNode->getColor();
                m_followAttachmentOpacity = actualNode->getOpacity();
            }
            
            return true;
        }
        else {
            removeFollowAttachment();
        }
    }
    return false;
}

void DHSlot::drawFollowAttachment(Renderer *renderer, const Mat4& transform, uint32_t flags) {
    if (m_followAttachment->getOpacity() > 0) {
        m_followAttachment->visit(renderer, transform, flags);
    }
}

NS_CC_END