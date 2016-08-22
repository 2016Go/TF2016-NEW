//
//  DHSkinnedMeshAttachment.h
//  MyTest
//
//  Created by youbin on 14-12-29.
//
//

#ifndef __MyTest__DHSkinnedMeshAttachment__
#define __MyTest__DHSkinnedMeshAttachment__

#include "DHRegionAttachment.h"

NS_CC_BEGIN

class DHSkinnedMeshAttachment : public DHRegionAttachment {
    
    friend class DHSlot;
    
public:
    struct SkinnedMeshData {
        unsigned int uvsCount;
        float* regionUVs;
        Tex2F* texCoords;
        
        int bonesCount;
        int* bones;
        
        int weightsCount;
        float* weights;
        
        int trianglesCount;
        int* triangles;
        
        int hullLength;
        
        GLfloat r, g, b, a;
        
        /* Nonessential. */
        int edgesCount;
        int* edges;
        
        float width, height;
        
        SkinnedMeshData()
        :regionUVs(nullptr)
        ,texCoords(nullptr)
        ,bones(nullptr)
        ,weights(nullptr)
        ,triangles(nullptr)
        ,edges(nullptr) {
            
        }
    };
    
public:
    DHSkinnedMeshAttachment(const SkinnedMeshData& data);
    
    virtual ~DHSkinnedMeshAttachment();
    
    static DHSkinnedMeshAttachment* createWithFile(const char* pszFileName, const SkinnedMeshData& data);
    
    static DHSkinnedMeshAttachment* createWithSpriteFrameName(const char* pszSpriteFrameName, const SkinnedMeshData& data);
    
    virtual void updateAabb(DHSlot* owner, float& minX, float& minY, float& maxX, float& maxY);
    
    virtual unsigned int getVerticesCount();
    
    virtual unsigned int getTrianglesCount();
    
    virtual PolygonDrawCmd* newDrawCmd(DHSlot* owner);
    
    virtual bool fillDrawData(const Mat4 &transform, PolygonDrawCmd* cmd, V2F_C4F_T2F* vertices, unsigned int& verticesCount, GLushort* triangles, unsigned int& trianglesCount, bool useCulling);
    
    const SkinnedMeshData& getData() const {
        return m_data;
    }
    
protected:
    DHSkinnedMeshAttachment();
    
    virtual void updateInfo();
    
private:
    SkinnedMeshData m_data;
};

NS_CC_END

#endif /* defined(__MyTest__DHSkinnedMeshAttachment__) */
