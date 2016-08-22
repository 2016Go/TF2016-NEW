//
//  DHSkeletonProgressTimer.cpp
//  battle-empire
//
//  Created by youbin on 13-10-14.
//
//

#include "DHSkeletonProgressTimer.h"
#include "DHSkeletonDataCache.h"
#include "DHRegionAttachment.h"

NS_CC_BEGIN

DHSkeletonProgressTimer::DHSkeletonProgressTimer()
:m_percentage(nullptr)
,m_reverseDirection(false) {
    
}

DHSkeletonProgressTimer::DHSkeletonProgressTimer(DHSkeletonData* const data)
:DHSkeletonAnimation(data)
,m_percentage(nullptr)
,m_reverseDirection(false) {
    
}

DHSkeletonProgressTimer::~DHSkeletonProgressTimer() {
    CC_SAFE_DELETE_ARRAY(m_percentage);
}

DHSkeletonProgressTimer* DHSkeletonProgressTimer::createWithKey(const char* const key) {
    DHSkeletonData* data = SDC->getSkeletonData(key);
    if (data) {
        return createWithData(data);
    }
    CCLOGWARN("the SkeletonData key: %s is not find", key);
    return nullptr;
}

DHSkeletonProgressTimer* DHSkeletonProgressTimer::createWithFile(const char* const jsonPath) {
    DHSkeletonData* data = DHSpineLoader::loadSkeletonData(jsonPath);
    if (data) {
        return createWithData(data);
    }
    CCLOGWARN("the jsonPath: %s is not find", jsonPath);
    return nullptr;
}

DHSkeletonProgressTimer* DHSkeletonProgressTimer::createWithData(DHSkeletonData* const data) {
    DHSkeletonProgressTimer* skeleton = new DHSkeletonProgressTimer(data);
    if (skeleton && skeleton->init()) {
        return (DHSkeletonProgressTimer*)skeleton->autorelease();
    }
    CC_SAFE_RELEASE(skeleton);
    return nullptr;
}

bool DHSkeletonProgressTimer::init() {
    if (!DHSkeleton::init()) {
        return false;
    }
    m_percentage = new float[m_data->getSlotCount()];
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        m_percentage[i] = 1.f;
    }
    return true;
}

bool DHSkeletonProgressTimer::drawSlot(cocos2d::DHSlot *slot) {
    return false;
//    if (slot->isEnabledFollowAttachment()) {
//        m_batch->flush();
//        slot->drawFollowAttachment();
//    }
//    else {
//        DHAttachment* attachment = slot->getAttachment();
//        if (!attachment) {
//            return;
//        }
//        
//        m_drawCmd->texture = nullptr;
//        switch (attachment->getType()) {
//            case DHAttachmentType::at_region:
//            case DHAttachmentType::at_mesh:
//            case DHAttachmentType::at_skinned_mesh: {
//                DHRegionAttachment* regionAttachment = (DHRegionAttachment*)attachment;
//                regionAttachment->updateDrawCmd(m_drawCmd, slot);
//                m_rectRotated = regionAttachment->isTextureRectRotated();
//                break;
//            }
//            default:
//                break;
//        }
//        
//        if (m_drawCmd->texture) {
//            if (slot->isColorEnabled()) {
//                m_drawCmd->color = getReallyColor();
//                
//                if (m_drawCmd->texture->hasPremultipliedAlpha()) {
//                    m_drawCmd->color.r *= m_drawCmd->color.a;
//                    m_drawCmd->color.g *= m_drawCmd->color.a;
//                    m_drawCmd->color.b *= m_drawCmd->color.a;
//                }
//            }
//            else {
//                m_drawCmd->color = Color4F::WHITE;
//            }
//            
//            m_drawCmd->blendMode = slot->getBlendMode();
//            
//            if (attachment->getType() == DHAttachmentType::at_region) {
//                updateBar(slot->getData()->m_index);
//            }
//            
//            m_batch->add(m_drawCmd);
//        }
//    }
}

void DHSkeletonProgressTimer::setPercentage(int slotIndex, float percentage) {
    if (slotIndex >= 0 && slotIndex < m_data->getSlotCount()) {
        m_percentage[slotIndex] = clampf(percentage, 0.f, 1.f);
    }
    else {
        CCLOGERROR("the slotIndex(%d) is not in range!", slotIndex);
    }
}

void DHSkeletonProgressTimer::setPercentage(const char *slotName, float percentage) {
    setPercentage(m_data->findSlotIndex(slotName), percentage);
}

float DHSkeletonProgressTimer::getPercentage(int slotIndex) {
    if (slotIndex >= 0 && slotIndex < m_data->getSlotCount()) {
        return m_percentage[slotIndex];
    }
    else {
        return 0.f;
        CCLOGERROR("the slotIndex(%d) is not in range!", slotIndex);
    }
}

float DHSkeletonProgressTimer::getPercentage(const char* slotName) {
    return getPercentage(m_data->findSlotIndex(slotName));
}

void DHSkeletonProgressTimer::updateBar(int slotIndex) {
//    m_orgVertex[0] = m_drawCmd->vertices[0];
//    m_orgTextureCoord[0] = m_drawCmd->texCoords[0];
//    
//    m_orgVertex[1] = m_drawCmd->vertices[2];
//    m_orgTextureCoord[1] = m_drawCmd->texCoords[2];
//    
//    if (m_reverseDirection) {
//        Point min = Point(m_percentage[slotIndex], 0.f);
//        Point max = Point(1, 1);
//        
//        m_dataTextureCoord[0] = textureCoordFromAlphaPoint(Point(min.x,min.y));
//        m_drawCmd->vertices[0] = vertexFromAlphaPoint(Point(min.x,min.y));
//        
//        m_dataTextureCoord[1] = textureCoordFromAlphaPoint(Point(min.x,max.y));
//        m_drawCmd->vertices[1] = vertexFromAlphaPoint(Point(min.x,max.y));
//        
//        m_dataTextureCoord[2] = textureCoordFromAlphaPoint(Point(max.x,max.y));
//        m_drawCmd->vertices[2] = vertexFromAlphaPoint(Point(max.x,max.y));
//        
//        m_dataTextureCoord[3] = textureCoordFromAlphaPoint(Point(max.x,min.y));
//        m_drawCmd->vertices[3] = vertexFromAlphaPoint(Point(max.x,min.y));
//    }
//    else {
//        Point min = Point::ZERO;
//        Point max = Point(m_percentage[slotIndex], 1);
//        
//        m_dataTextureCoord[0] = textureCoordFromAlphaPoint(Point(min.x,min.y));
//        m_drawCmd->vertices[0] = vertexFromAlphaPoint(Point(min.x,min.y));
//        
//        m_dataTextureCoord[1] = textureCoordFromAlphaPoint(Point(min.x,max.y));
//        m_drawCmd->vertices[1] = vertexFromAlphaPoint(Point(min.x,max.y));
//        
//        m_dataTextureCoord[2] = textureCoordFromAlphaPoint(Point(max.x,max.y));
//        m_drawCmd->vertices[2] = vertexFromAlphaPoint(Point(max.x,max.y));
//        
//        m_dataTextureCoord[3] = textureCoordFromAlphaPoint(Point(max.x,min.y));
//        m_drawCmd->vertices[3] = vertexFromAlphaPoint(Point(max.x,min.y));
//    }
//    
//    m_drawCmd->texCoords = m_dataTextureCoord;
}

Tex2F DHSkeletonProgressTimer::textureCoordFromAlphaPoint(Point alpha) {
    
    Point min = Point(m_orgTextureCoord[0].u, m_orgTextureCoord[0].v);
    Point max = Point(m_orgTextureCoord[1].u, m_orgTextureCoord[1].v);
    
    if (m_rectRotated) {
        CC_SWAP(alpha.x, alpha.y, float);
    }
    
    return Tex2F(min.x * (1.0f - alpha.x) + max.x * alpha.x, min.y * (1.0f - alpha.y) + max.y * alpha.y);
}

Vec2 DHSkeletonProgressTimer::vertexFromAlphaPoint(Vec2 alpha) {
    Vec2 ret = Vec2(0.0f, 0.0f);
    
    Vec2 min = Vec2(m_orgVertex[0].x, m_orgVertex[0].y);
    Vec2 max = Vec2(m_orgVertex[1].x, m_orgVertex[1].y);
    ret.x = min.x * (1.0f - alpha.x) + max.x * alpha.x;
    ret.y = min.y * (1.0f - alpha.y) + max.y * alpha.y;
    
    return ret;
}

void DHSkeletonProgressTimer::setReverseDirection(bool reverseDirection) {
    if (reverseDirection != m_reverseDirection) {
        m_reverseDirection = reverseDirection;
        if (m_reverseDirection) {
            DH_ARRAY_FOREACH(m_data->getSlotCount()) {
                m_percentage[i] = 0.f;
            }
        }
        else {
            DH_ARRAY_FOREACH(m_data->getSlotCount()) {
                m_percentage[i] = 1.f;
            }
        }
    }
}

bool DHSkeletonProgressTimer::isReverseDirection() {
    return m_reverseDirection;
}

NS_CC_END