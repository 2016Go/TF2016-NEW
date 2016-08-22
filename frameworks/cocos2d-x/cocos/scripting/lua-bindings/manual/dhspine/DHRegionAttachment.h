//
//  DHRegionAttachment.h
//  dhspine
//
//  Created by youbin on 13-10-11.
//
//

#ifndef __dhspine__DHRegionAttachment__
#define __dhspine__DHRegionAttachment__

#include "DHAttachment.h"

NS_CC_BEGIN

class DHRegionAttachment : public DHAttachment {
    
    friend class DHSlot;
    
public:
    struct RegionData {
        float x, y;
        float rotation;
        float scaleX, scaleY;
        float width, height;
        
        GLfloat r, g, b, a;
    };
    
public:
    DHRegionAttachment(const RegionData& data);
    
    virtual ~DHRegionAttachment();
    
    static DHRegionAttachment* createWithFile(const char* pszFileName, const RegionData& data);
    
    static DHRegionAttachment* createWithSpriteFrameName(const char* pszSpriteFrameName, const RegionData& data);
    
    bool initWithFile(const char *pszFilename);
    
    bool initWithSpriteFrameName(const char* pszSpriteFrameName);
    
    bool initWithTexture(Texture2D *pTexture, const Rect& rect);
    
    bool init(Texture2D *pTexture);
    
    bool isTextureRectRotated() const {
        return m_rectRotated;
    }
    
    const RegionData& getData() const {
        return m_data;
    }
    
    bool containsPoint(DHSlot* owner, float x, float y);
    
    virtual void updateAabb(DHSlot* owner, float& minX, float& minY, float& maxX, float& maxY);
    
    virtual unsigned int getVerticesCount();
    
    virtual unsigned int getTrianglesCount();
    
    virtual PolygonDrawCmd* newDrawCmd(DHSlot* owner);
    
    virtual bool fillDrawData(const Mat4 &transform, PolygonDrawCmd* cmd, V2F_C4F_T2F* vertices, unsigned int& verticesCount, GLushort* triangles, unsigned int& trianglesCount, bool useCulling);
    
    void transformPoint(const Mat4 &transform, Vec2& vertice);
    
    bool checkVisibility(V2F_C4F_T2F* vertices, unsigned int& verticesCount);
    
protected:
    DHRegionAttachment();
    
    virtual void updateInfo();
    
    void setVertex(const Rect& rect,const Point& relativeOffset, const Size& untrimmedSize);
    
    void setTextureCoords(Rect rect, bool rotated);
    
    void computeWorldVertices(GLfloat& x, GLfloat& y, int index);
    
protected:
    Texture2D* m_texture;
    Vec2 m_vertices[4];
    Tex2F m_texCoords[4];
    bool m_rectRotated;
    
    Size m_rectSize;
    Size m_untrimmedSize;
    Vec2 m_relativeOffset;
    
private:
    RegionData m_data;
};

NS_CC_END

#endif /* defined(__dhspine__DHRegionAttachment__) */
