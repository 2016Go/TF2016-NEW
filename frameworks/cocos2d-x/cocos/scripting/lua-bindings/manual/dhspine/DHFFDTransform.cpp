//
//  DHFFDTransform.cpp
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#include "DHFFDTransform.h"
#include "DHSkeletonAnimation.h"
#include "DHMeshAttachment.h"
#include "DHSkinnedMeshAttachment.h"

NS_CC_BEGIN

DHFFDKeyFrame::DHFFDKeyFrame()
:vertices(nullptr) {
    
}

DHFFDKeyFrame::DHFFDKeyFrame(unsigned int verticesCount) {
    vertices = new float[verticesCount];
}

DHFFDKeyFrame::~DHFFDKeyFrame() {
    CC_SAFE_DELETE_ARRAY(vertices);
}

//

DHFFDTransform::DHFFDTransform()
:m_slotIndex(-1)
,m_attachment(nullptr)
,m_verticesCount(0) {
    
}

DHFFDTransform::DHFFDTransform(int slotIndex, DHAttachment* attachment, unsigned int verticesCount)
:m_slotIndex(slotIndex)
,m_attachment(attachment)
,m_verticesCount(verticesCount)
,m_ffdCount(0)
,m_ffds(nullptr) {
    
}

DHFFDTransform::~DHFFDTransform() {
    DH_ARRAY_DELETE(m_ffds, m_ffdCount)
}

void DHFFDTransform::createFFDTimeline(unsigned int ffdCount) {
    m_ffds = new DHFFDKeyFrame*[m_ffdCount = ffdCount];
}

DHFFDKeyFrame* DHFFDTransform::createFFDKeyFrame(unsigned int frameIndex) {
    return m_ffds[frameIndex] = new DHFFDKeyFrame(m_verticesCount);
}

float DHFFDTransform::updateInfo() {
    DH_UPDATE_DIFF_TIME(m_ffds, m_ffdCount)
    
    float maxs = 0.f;
    DH_GET_DURATION(m_ffds, m_ffdCount, maxs)
    
    return maxs;
}

void DHFFDTransform::applyTo(cocos2d::DHSkeletonAnimation *owner, float time, float alpha) {
    DHSlot* slot = owner->getSlotByIndex(m_slotIndex);
    if (slot->getAttachment() != m_attachment) {
        return;
    }
    
    float* vertices = nullptr;
    if (m_attachment->getType() == DHAttachmentType::at_mesh) {
        vertices = ((DHMeshAttachment*)m_attachment)->getData().vertices;
    }
    
    if (m_ffds[0]->time <= time) {
        if (slot->m_attachmentVerticesCount < m_verticesCount) {
            if (slot->m_attachmentVerticesCapacity < m_verticesCount) {
                CC_SAFE_DELETE_ARRAY(slot->m_attachmentVertices);
                slot->m_attachmentVertices = new float[m_verticesCount];
                slot->m_attachmentVerticesCapacity = m_verticesCount;
                memset(slot->m_attachmentVertices, 0, sizeof(float) * slot->m_attachmentVerticesCapacity);
            }
            if (vertices) {
                for (int i = 0; i < m_verticesCount; ++i) {
                    slot->m_attachmentVertices[i] = vertices[i];
                }
            }
            else {
                memset(slot->m_attachmentVertices, 0, sizeof(float) * slot->m_attachmentVerticesCapacity);
            }
        }
        else if (slot->m_attachmentVerticesCount > m_verticesCount) {
            if (vertices) {
                for (int i = 0; i < m_verticesCount; ++i) {
                    slot->m_attachmentVertices[i] = vertices[i];
                }
            }
        }
        slot->m_attachmentVerticesCount = m_verticesCount;
        
        if (m_ffds[m_ffdCount - 1]->time <= time) {
            DHFFDKeyFrame* frame = m_ffds[m_ffdCount -1];
            
            const float* lastVertices = frame->vertices;
            if (vertices) {
                for (int i = 0; i < m_verticesCount; ++i) {
                    slot->m_attachmentVertices[i] += (lastVertices[i] - vertices[i]) * alpha;
                }
            }
            else {
                for (int i = 0; i < m_verticesCount; ++i) {
                    slot->m_attachmentVertices[i] += lastVertices[i] * alpha;
                }
            }
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_ffds, m_ffdCount, time, frameIndex)
            DHFFDKeyFrame* frames = m_ffds[frameIndex];
            DHFFDKeyFrame* lastFrame = m_ffds[frameIndex - 1];
            float percent = lastFrame->getInterpolationPercent(time - lastFrame->time);
            
            const float* prevVertices = lastFrame->vertices;
            const float* nextVertices = frames->vertices;
            if (vertices) {
                for (int i = 0; i < m_verticesCount; ++i) {
                    float prev = prevVertices[i] - vertices[i];
                    slot->m_attachmentVertices[i] += (prev + (nextVertices[i] - vertices[i]  - prev) * percent) * alpha;
                }
            }
            else {
                for (int i = 0; i < m_verticesCount; ++i) {
                    float prev = prevVertices[i];
                    slot->m_attachmentVertices[i] += (prev + (nextVertices[i] - prev) * percent) * alpha;
                }
            }
        }
    }
    
}

NS_CC_END