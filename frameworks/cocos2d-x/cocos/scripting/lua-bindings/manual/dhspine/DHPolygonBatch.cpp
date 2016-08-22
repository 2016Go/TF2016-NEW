//
//  DHPolygonBatch.cpp
//  MyTest
//
//  Created by youbin on 14-12-28.
//
//

#include "DHPolygonBatch.h"
#include "DHSkeleton.h"

NS_CC_BEGIN

DHPolygonBatch::DHPolygonBatch()
:m_verticesCount(0)
,m_trianglesCount(0)
,m_drawCmd(nullptr)
,m_hue(0)
,m_saturation(1)
,m_brightness(1) {
    
}

DHPolygonBatch::~DHPolygonBatch() {
    glDeleteBuffers(2, m_buffersVBO);
    
    if (Configuration::getInstance()->supportsShareableVAO()) {
        glDeleteVertexArrays(1, &m_buffersVAO);
        GL::bindVAO(0);
    }
}

void DHPolygonBatch::initGLView() {
#if CC_ENABLE_CACHE_TEXTURE_DATA
    auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event) {
        /** listen the event that renderer was recreated on Android/WP8 */
        setupBuffer();
    });
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
#endif
    
    setupBuffer();
}

void DHPolygonBatch::setupBuffer()
{
    if(Configuration::getInstance()->supportsShareableVAO()) {
        setupVBOAndVAO();
    }
    else {
        setupVBO();
    }
}

void DHPolygonBatch::setupVBOAndVAO()
{
    //generate vbo and vao for trianglesCommand
    glGenVertexArrays(1, &m_buffersVAO);
    GL::bindVAO(m_buffersVAO);
    
    glGenBuffers(2, &m_buffersVBO[0]);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices[0]) * VBO_SIZE, m_vertices, GL_DYNAMIC_DRAW);
    
    // vertices
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4F_T2F), (GLvoid*) offsetof( V2F_C4F_T2F, vertices));
    
    // colors
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(V2F_C4F_T2F), (GLvoid*) offsetof( V2F_C4F_T2F, colors));
    
    // tex coords
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_TEX_COORD);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4F_T2F), (GLvoid*) offsetof( V2F_C4F_T2F, texCoords));
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffersVBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_triangles[0]) * INDEX_VBO_SIZE, m_triangles, GL_STATIC_DRAW);
    
    // Must unbind the VAO before changing the element buffer.
    GL::bindVAO(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    CHECK_GL_ERROR_DEBUG();
}

void DHPolygonBatch::setupVBO()
{
    glGenBuffers(2, &m_buffersVBO[0]);
    mapBuffers();
}

void DHPolygonBatch::mapBuffers()
{
    // Avoid changing the element buffer for whatever VAO might be bound.
    GL::bindVAO(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices[0]) * VBO_SIZE, m_vertices, GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffersVBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_triangles[0]) * INDEX_VBO_SIZE, m_triangles, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    CHECK_GL_ERROR_DEBUG();
}

bool DHPolygonBatch::addDrawCmd(DHRegionAttachment* attachment, DHSlot* slot, bool useCulling) {
    bool flushFlag = false;
    PolygonDrawCmd* cmd = attachment->newDrawCmd(slot);
    if (cmd) {
        CCASSERT(cmd->verticesCount < VBO_SIZE, "VBO for vertex is not big enough, please break the data down or resize VBO_SIZE++");
        CCASSERT(cmd->trianglesCount < INDEX_VBO_SIZE, "VBO for index is not big enough, please break the data down or resize VBO_SIZE++");
        
        if (m_verticesCount + cmd->verticesCount > VBO_SIZE || m_trianglesCount + cmd->trianglesCount > INDEX_VBO_SIZE) {
            flush();
            flushFlag = true;
        }
        
        if (slot->isColorEnabled()) {
            const auto& color = m_owner->getReallyColor();
            cmd->color.r *= color.r;
            cmd->color.g *= color.g;
            cmd->color.b *= color.b;
            cmd->color.a *= color.a;
        }
        
        //now ignore: cmd->texture->hasPremultipliedAlpha()
        if (cmd->color.a != 1.f) {
            cmd->color.r *= cmd->color.a;
            cmd->color.g *= cmd->color.a;
            cmd->color.b *= cmd->color.a;
        }
        
        if (attachment->fillDrawData(m_modelView, cmd, m_vertices, m_verticesCount, m_triangles, m_trianglesCount, useCulling)) {
            cmd->blendMode = slot->getBlendMode();
            cmd->hue = m_owner->getHue(slot->getName());
            cmd->saturation = m_owner->getSaturation(slot->getName());
            cmd->brightness = m_owner->getBrightness(slot->getName());
            
            if (m_drawCmd == nullptr || m_drawCmd->textureID != cmd->textureID
                || m_drawCmd->blendMode != cmd->blendMode || m_drawCmd->hue != cmd->hue || m_drawCmd->saturation != cmd->saturation || m_drawCmd->brightness != cmd->brightness) {
                m_drawCmd = cmd;
                m_batchedCommandVec.push_back(m_drawCmd);
            }
            else {
                m_drawCmd->verticesCount += cmd->verticesCount;
                m_drawCmd->trianglesCount += cmd->trianglesCount;
                delete cmd;
            }
        }
        else {
            delete cmd;
        }
    }
    return flushFlag;
}

void DHPolygonBatch::flush() {
    if (!m_verticesCount) {
        return;
    }
    
    if (Configuration::getInstance()->supportsShareableVAO()) {
        //Bind VAO
        GL::bindVAO(m_buffersVAO);
        //Set VBO data
        glBindBuffer(GL_ARRAY_BUFFER, m_buffersVBO[0]);
        
        // option 1: subdata
        //        glBufferSubData(GL_ARRAY_BUFFER, sizeof(_quads[0])*start, sizeof(_quads[0]) * n , &_quads[start] );
        
        // option 2: data
        //        glBufferData(GL_ARRAY_BUFFER, sizeof(quads_[0]) * (n-start), &quads_[start], GL_DYNAMIC_DRAW);
        
        // option 3: orphaning + glMapBuffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices[0]) * m_verticesCount, nullptr, GL_DYNAMIC_DRAW);
        void *buf = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        memcpy(buf, m_vertices, sizeof(m_vertices[0])* m_verticesCount);
        glUnmapBuffer(GL_ARRAY_BUFFER);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffersVBO[1]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_triangles[0]) * m_trianglesCount, m_triangles, GL_STATIC_DRAW);
    }
    else {
#define kQuadSize sizeof(m_vertices[0])
        glBindBuffer(GL_ARRAY_BUFFER, m_buffersVBO[0]);
        
        glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices[0]) * m_verticesCount , m_vertices, GL_DYNAMIC_DRAW);
        
        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);
        
        // vertices
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*) offsetof(V2F_C4F_T2F, vertices));
        
        // colors
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*) offsetof(V2F_C4F_T2F, colors));
        
        // tex coords
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*) offsetof(V2F_C4F_T2F, texCoords));
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffersVBO[1]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_triangles[0]) * m_trianglesCount, m_triangles, GL_STATIC_DRAW);
    }
    
    int startIndex = 0;
    for(const auto& cmd : m_batchedCommandVec) {
        GL::bindTexture2D(cmd->textureID);
        
        switch (cmd->blendMode) {
            case SpineBlendType::sbt_additive:
                GL::blendFunc(GL_ONE, GL_ONE);
                break;
            case SpineBlendType::sbt_multiply:
                GL::blendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
                break;
            case SpineBlendType::sbt_screen:
                GL::blendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
                break;
            default:
                GL::blendFunc(CC_BLEND_SRC, CC_BLEND_DST);
                break;
        }
        
        if (m_owner->isColorRotationInit() && (m_hue != cmd->hue || m_saturation != cmd->saturation || m_brightness != cmd->brightness)) {
            m_hue = cmd->hue;
            m_saturation = cmd->saturation;
            m_brightness = cmd->brightness;
            m_owner->getGLProgramState()->applyUniforms();
        }
        
        glDrawElements(GL_TRIANGLES, (GLsizei) cmd->trianglesCount, GL_UNSIGNED_SHORT, (GLvoid*) (startIndex*sizeof(m_triangles[0])) );
        startIndex += cmd->trianglesCount;
    }
    
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(m_batchedCommandVec.size(), m_verticesCount);
    
    CHECK_GL_ERROR_DEBUG();
    
    if (Configuration::getInstance()->supportsShareableVAO()) {
        //Unbind VAO
        GL::bindVAO(0);
    }
    else {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    
    //clean up
    m_verticesCount = 0;
    m_trianglesCount = 0;
    m_drawCmd = nullptr;
    
    for (const auto& iter : m_batchedCommandVec) {
        delete iter;
    }
    m_batchedCommandVec.clear();
}

void DHPolygonBatch::apply(DHSkeleton* owner, const Mat4& modelView) {
    m_owner = owner;
    m_modelView = modelView;
}

void DHPolygonBatch::hueUniformCallback(cocos2d::GLProgram *p, cocos2d::Uniform *u) {
    DHMatrix matrix;
    matrix.hueMatrix(m_hue);
    matrix.saturationMatrix(m_saturation);
    matrix.brightnessMatrix(m_brightness);
    matrix.premultiplyAlpha(m_owner->getReallyOpacity());
    glUniformMatrix3fv(u->location, 1, GL_FALSE, (GLfloat*)&matrix.mat);
}

unsigned int DHPolygonBatch::getVerticesCount() {
    return m_verticesCount;
}

bool DHPolygonBatch::addBuffer(DHRegionAttachment* attachment) {
    bool addCmdFlag = false;
    unsigned int verticesCount = attachment->getVerticesCount();
    unsigned int trianglesCount = attachment->getTrianglesCount();
    if (m_verticesCount + verticesCount > VBO_SIZE || m_trianglesCount + trianglesCount > INDEX_VBO_SIZE) {
        addCmdFlag = true;
        resetBuffer();
    }
    m_verticesCount += verticesCount;
    m_trianglesCount += trianglesCount;
    return addCmdFlag;
}

void DHPolygonBatch::resetBuffer() {
    m_verticesCount = 0;
    m_trianglesCount = 0;
}

NS_CC_END