//
//  DHMeshAttachment.h
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#ifndef __MyTest__DHMeshAttachment__
#define __MyTest__DHMeshAttachment__

#include "DHRegionAttachment.h"

NS_CC_BEGIN

class DHMeshAttachment : public DHRegionAttachment {
    
    friend class DHSlot;
    
public:
    struct MeshData {
        int verticesCount;
        float* vertices;
        int hullLength;
        
        float* regionUVs;
        Tex2F* texCoords;
        
        int bonesCount;
        int* bones;
        
        int trianglesCount;
        int* triangles;
        
        GLfloat r, g, b, a;
        
        /* Nonessential. */
        int edgesCount;
        int* edges;
        
        float width, height;
        
        MeshData()
        :vertices(nullptr)
        ,regionUVs(nullptr)
        ,texCoords(nullptr)
        ,bones(nullptr)
        ,triangles(nullptr)
        ,edges(nullptr) {
            
        }
    };
    
public:
    DHMeshAttachment(const MeshData& data);
    
    virtual ~DHMeshAttachment();
    
    static DHMeshAttachment* createWithFile(const char* pszFileName, const MeshData& data);
    
    static DHMeshAttachment* createWithSpriteFrameName(const char* pszSpriteFrameName, const MeshData& data);
    
    virtual void updateAabb(DHSlot* owner, float& minX, float& minY, float& maxX, float& maxY);
    
    virtual unsigned int getVerticesCount();
    
    virtual unsigned int getTrianglesCount();
    
    virtual PolygonDrawCmd* newDrawCmd(DHSlot* owner);
    
    virtual bool fillDrawData(const Mat4 &transform, PolygonDrawCmd* cmd, V2F_C4F_T2F* vertices, unsigned int& verticesCount, GLushort* triangles, unsigned int& trianglesCount, bool useCulling);
    
    const MeshData& getData() const {
        return m_data;
    }
    
protected:
    DHMeshAttachment();
    
    virtual void updateInfo();
    
private:
    MeshData m_data;
};

NS_CC_END

#endif /* defined(__MyTest__DHMeshAttachment__) */
