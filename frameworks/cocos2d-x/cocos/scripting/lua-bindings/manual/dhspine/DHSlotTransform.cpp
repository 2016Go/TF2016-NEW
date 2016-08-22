//
//  DHSlotTransform.cpp
//  dhspine
//
//  Created by youbin on 13-10-7.
//
//

#include "DHGlobal.h"
#include "DHSlot.h"
#include "DHSlotTransform.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

DHAttachmentKeyFrame::DHAttachmentKeyFrame() {
    
}

DHAttachmentKeyFrame::DHAttachmentKeyFrame(const char* name) {
    attachmentName = DHStrCopy(name);
}

DHAttachmentKeyFrame::~DHAttachmentKeyFrame() {
    DHStrFree(attachmentName);
}


DHSlotTransform::DHSlotTransform()
:m_slotIndex(-1)
,m_color(nullptr)
,m_attachment(nullptr)
,m_colorCount(0)
,m_attachmentCount(0) {
    
}

DHSlotTransform::DHSlotTransform(int slotIndex)
:m_slotIndex(slotIndex)
,m_color(nullptr)
,m_attachment(nullptr)
,m_colorCount(0)
,m_attachmentCount(0) {
    
}

DHSlotTransform::~DHSlotTransform() {
    DH_ARRAY_DELETE(m_color, m_colorCount)
    DH_ARRAY_DELETE(m_attachment, m_attachmentCount)
}

void DHSlotTransform::createColorTimeline(unsigned int colorCount) {
    m_color = new DHColorKeyFrame*[m_colorCount = colorCount];
}

void DHSlotTransform::createAttachmentTimeline(unsigned int attachmentCount) {
    m_attachment = new DHAttachmentKeyFrame*[m_attachmentCount = attachmentCount];
}

DHColorKeyFrame* DHSlotTransform::createColorKeyFrame(unsigned int frameIndex) {
    return m_color[frameIndex] = new DHColorKeyFrame();
}

DHAttachmentKeyFrame* DHSlotTransform::createAttachmentKeyFrame(unsigned int frameIndex, const char* attachmentName) {
    return m_attachment[frameIndex] = new DHAttachmentKeyFrame(attachmentName);
}

float DHSlotTransform::updateInfo() {
    DH_UPDATE_DIFF_TIME(m_color, m_colorCount)
    
    float maxs = 0.f;
    DH_GET_DURATION(m_color, m_colorCount, maxs)
    DH_GET_DURATION(m_attachment, m_attachmentCount, maxs)
    
    return maxs;
}

void DHSlotTransform::applyTo(cocos2d::DHSkeletonAnimation *owner, float time, float alpha) {
    DHSlot* slot = owner->getSlotByIndex(m_slotIndex);
    
    if (m_color && m_color[0]->time <= time) {
        GLfloat r, g, b, a;
        
        if (m_color[m_colorCount - 1]->time <= time) {
            DHColorKeyFrame* frame = m_color[m_colorCount - 1];
            r = frame->r;
            g = frame->g;
            b = frame->b;
            a = frame->a;
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_color, m_colorCount, time, frameIndex)
            DHColorKeyFrame* frames = m_color[frameIndex];
            DHColorKeyFrame* lastFrame = m_color[frameIndex - 1];
            float percent = lastFrame->getInterpolationPercent(time - lastFrame->time);
            r = lastFrame->r + (frames->r - lastFrame->r) * percent;
            g = lastFrame->g + (frames->g - lastFrame->g) * percent;
            b = lastFrame->b + (frames->b - lastFrame->b) * percent;
            a = lastFrame->a + (frames->a - lastFrame->a) * percent;
        }
        
        if (owner->isColorMixEnabled()) {
            if (alpha < 1.f) {
                slot->m_r += (r - slot->m_data->m_r) * alpha;
                slot->m_g += (g - slot->m_data->m_g) * alpha;
                slot->m_b += (b - slot->m_data->m_b) * alpha;
                slot->m_a += (a - slot->m_data->m_a) * alpha;
            }
            else {
                slot->m_r = r;
                slot->m_g = g;
                slot->m_b = b;
                slot->m_a = a;
            }
        }
        else {
            slot->m_r = r;
            slot->m_g = g;
            slot->m_b = b;
            slot->m_a = a;
        }
    }
    
    if (m_attachment && m_attachment[0]->time <= time) {
        int frameIndex;
        if (m_attachment[m_attachmentCount - 1]->time <= time) {
            frameIndex = m_attachmentCount;
        }
        else {
            DH_BINARY_SEARCH(m_attachment, m_attachmentCount, time, frameIndex)
        }
        slot->m_activeName = m_attachment[frameIndex - 1]->attachmentName;
    }
}

NS_CC_END