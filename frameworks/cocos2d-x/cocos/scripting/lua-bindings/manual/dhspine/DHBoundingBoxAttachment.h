//
//  DHBoundingBoxAttachment.h
//  dhspine
//
//  Created by youbin on 13-10-11.
//
//

#ifndef __dhspine__DHBoundingBoxAttachment__
#define __dhspine__DHBoundingBoxAttachment__

#include "DHAttachment.h"

NS_CC_BEGIN

class DHBoundingBoxAttachment : public DHAttachment {
    
public:
    DHBoundingBoxAttachment();
    
    virtual ~DHBoundingBoxAttachment();
    
    DH_CREATE_FUNC(DHBoundingBoxAttachment);
    
    float* createVertices(unsigned int verticesCount);
    
    void computeWorldVertices(float& x, float& y, int index);
    
    bool containsPoint(DHSlot* owner, float x, float y);
    
    void updateAabb(DHSlot* owner, float& minX, float& minY, float& maxX, float& maxY);
    
    unsigned int getVerticesCount() {
        return m_verticesCount;
    }
    
    bool getIntersection(DHSlot* owner, const Point& start, const Point& end, Point& res);
    
private:
    unsigned int m_verticesCount;
	float* m_vertices;
};

NS_CC_END

#endif /* defined(__dhspine__DHBoundingBoxAttachment__) */
