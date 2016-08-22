//
//  DHPolygonBatch.h
//  MyTest
//
//  Created by youbin on 14-12-28.
//
//

#ifndef __MyTest__DHPolygonBatch__
#define __MyTest__DHPolygonBatch__

#include "DHGlobal.h"
#include "DHSlot.h"
#include "DHRegionAttachment.h"

class DHSkeleton;

NS_CC_BEGIN

class DHPolygonBatch {
public:
    DHPolygonBatch();
    
    virtual ~DHPolygonBatch();
    
    void initGLView();
    
    void flush();
    
    void apply(DHSkeleton* owner, const Mat4& modelView);
    
    bool addDrawCmd(DHRegionAttachment* attachment, DHSlot* slot, bool useCulling);
    
    void hueUniformCallback(cocos2d::GLProgram *p, cocos2d::Uniform *u);
    
    unsigned int getVerticesCount();
    
    bool addBuffer(DHRegionAttachment* attachment);
    
    void resetBuffer();
    
protected:
    void setupBuffer();
    
    void setupVBOAndVAO();
    
    void setupVBO();
    
    void mapBuffers();
    
private:
    /**The max number of vertices in a vertex buffer object.*/
    static const int VBO_SIZE = 8192;
    /**The max numer of indices in a index buffer.*/
    static const int INDEX_VBO_SIZE = VBO_SIZE * 3 / 2;
    
    V2F_C4F_T2F m_vertices[VBO_SIZE];
    unsigned int m_verticesCount;
    
    GLushort m_triangles[INDEX_VBO_SIZE];
    unsigned int m_trianglesCount;
    
    Mat4 m_modelView;
    
    GLuint m_buffersVAO;
    GLuint m_buffersVBO[2]; //0: vertex  1: indices
    
    PolygonDrawCmd* m_drawCmd;
    std::vector<const PolygonDrawCmd*> m_batchedCommandVec;
    
    float m_hue;
    float m_saturation;
    float m_brightness;
    DHSkeleton* m_owner;
};

NS_CC_END

#endif /* defined(__MyTest__DHPolygonBatch__) */
