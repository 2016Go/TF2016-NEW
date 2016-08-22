//
//  DHSkeletonProgressTimer.h
//  battle-empire
//
//  Created by youbin on 13-10-14.
//
//

#ifndef __battle_empire__DHSkeletonProgressTimer__
#define __battle_empire__DHSkeletonProgressTimer__

#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

class DHSkeletonProgressTimer : public DHSkeletonAnimation {
    
public:
    DHSkeletonProgressTimer(DHSkeletonData* const data);
    
    virtual ~DHSkeletonProgressTimer();
    
    static DHSkeletonProgressTimer* createWithKey(const char* const key);
    
    static DHSkeletonProgressTimer* createWithFile(const char* const jsonPath);
    
    static DHSkeletonProgressTimer* createWithData(DHSkeletonData* const data);
    
    virtual bool drawSlot(DHSlot* slot);
    
    virtual bool init();
    
    void setPercentage(int slotIndex, float percentage);
    void setPercentage(const char* slotName, float percentage);
    
    float getPercentage(int slotIndex);
    float getPercentage(const char* slotName);
    
    void setReverseDirection(bool reverseDirection);
    bool isReverseDirection();
    
protected:
    DHSkeletonProgressTimer();
    
private:
    
    Tex2F textureCoordFromAlphaPoint(Point alpha);
    
    Vec2 vertexFromAlphaPoint(Point alpha);
    
    void updateBar(int slotIndex);
    
    float* m_percentage;
    
    bool m_rectRotated;
    Tex2F m_orgTextureCoord[2];
    Vec2 m_orgVertex[2];
    
    Tex2F m_dataTextureCoord[4];
    
    bool m_reverseDirection;
};

NS_CC_END

#endif /* defined(__battle_empire__DHSkeletonProgressTimer__) */
