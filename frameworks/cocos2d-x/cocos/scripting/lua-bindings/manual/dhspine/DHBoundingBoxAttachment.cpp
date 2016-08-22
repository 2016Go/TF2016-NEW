//
//  DHBoundingBoxAttachment.cpp
//  dhspine
//
//  Created by youbin on 13-10-11.
//
//

#include "DHBoundingBoxAttachment.h"
#include "DHSkeleton.h"

NS_CC_BEGIN

DHBoundingBoxAttachment::DHBoundingBoxAttachment()
:m_vertices(nullptr) {
    m_type = DHAttachmentType::at_boundingBox;
}

DHBoundingBoxAttachment::~DHBoundingBoxAttachment() {
    CC_SAFE_DELETE_ARRAY(m_vertices);
}

float* DHBoundingBoxAttachment::createVertices(unsigned int verticesCount) {
    return m_vertices = new float[ m_verticesCount = verticesCount];
}

void DHBoundingBoxAttachment::computeWorldVertices(float &x, float &y, int index) {
    x = m_vertices[index] * m_slot->m_bone->m_m00 + m_vertices[index + 1] * m_slot->m_bone->m_m01 + m_slot->m_bone->m_worldX;
    y = m_vertices[index] * m_slot->m_bone->m_m10 + m_vertices[index + 1] * m_slot->m_bone->m_m11 + m_slot->m_bone->m_worldY;
    
    if (m_slot->m_skeleton->isFlipX()) {
        x = -x;
    }
    if (m_slot->m_skeleton->isFlipY()) {
        y = -y;
    }
}

bool DHBoundingBoxAttachment::containsPoint(DHSlot* owner, float x, float y) {
    setCurrentSlot(owner);
    float prevX, prevY, vertexX, vertexY;
    computeWorldVertices(prevX, prevY, m_verticesCount - 2);
    bool inside = false;
	for (int i = 0; i < m_verticesCount; i += 2) {
		computeWorldVertices(vertexX, vertexY, i);
		if ((vertexY < y && prevY >= y) || (prevY < y && vertexY >= y)) {
			if (vertexX + (y - vertexY) / (prevY - vertexY) * (prevX - vertexX) < x) {
                inside ^= 1;
            }
		}
		prevX = vertexX;
        prevY = vertexY;
	}
    return inside;
}

void DHBoundingBoxAttachment::updateAabb(DHSlot* owner, float &minX, float &minY, float &maxX, float &maxY) {
    setCurrentSlot(owner);
    float vertexX, vertexY;
	for (int i = 0; i < m_verticesCount; i += 2) {
		computeWorldVertices(vertexX, vertexY, i);
		minX = DHMIN(minX, vertexX);
        minY = DHMIN(minY, vertexY);
        maxX = DHMAX(maxX, vertexX);
        maxY = DHMAX(maxY, vertexY);
	}
}

bool DHBoundingBoxAttachment::getIntersection(DHSlot* owner, const Point& start, const Point& end, Point& res) {
    setCurrentSlot(owner);
    
    Vec2 prev, vertex;
    computeWorldVertices(prev.x, prev.y, m_verticesCount - 2);
    bool intersection = false;
    for (int i = 0; i < m_verticesCount; i += 2) {
        computeWorldVertices(vertex.x, vertex.y, i);
        
        Vec2 sPoint, ePoint;
        float s, t;
        if (Vec2::isSegmentOverlap(start, end, vertex, prev, &sPoint, &ePoint)) {
            if (!intersection) {
                intersection = true;
                if (start.getDistanceSq(sPoint) < start.getDistanceSq(ePoint)) {
                    res = sPoint;
                }
                else {
                    res = ePoint;
                }
            }
            else {
                if (start.getDistanceSq(sPoint) < start.getDistanceSq(res)) {
                    res = sPoint;
                }
                if (start.getDistanceSq(ePoint) < start.getDistanceSq(res)) {
                    res = ePoint;
                }
            }
        }
        else if (Vec2::isLineIntersect(start, end, vertex, prev, &s, &t)) {
            if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
                Vec2 point;
                point.x = start.x + s * 0.95 * (end.x - start.x);
                point.y = start.y + s * 0.95 * (end.y - start.y);
                
                if (!intersection) {
                    intersection = true;
                    res = point;
                }
                else if (start.getDistanceSq(point) < start.getDistanceSq(res)) {
                    res = point;
                }
            }
        }
        
        prev = vertex;
    }
    return intersection;
}

NS_CC_END