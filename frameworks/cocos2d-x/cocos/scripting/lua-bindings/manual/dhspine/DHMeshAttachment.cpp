//
//  DHMeshAttachment.cpp
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#include "DHMeshAttachment.h"
#include "DHSkeleton.h"

NS_CC_BEGIN

DHMeshAttachment::DHMeshAttachment() {
    m_type = DHAttachmentType::at_mesh;
}

DHMeshAttachment::DHMeshAttachment(const MeshData& data)
:m_data(data) {
    m_type = DHAttachmentType::at_mesh;
}

DHMeshAttachment::~DHMeshAttachment() {
    CC_SAFE_DELETE_ARRAY(m_data.vertices);
    CC_SAFE_DELETE_ARRAY(m_data.regionUVs);
    CC_SAFE_DELETE_ARRAY(m_data.texCoords);
    CC_SAFE_DELETE_ARRAY(m_data.bones);
    CC_SAFE_DELETE_ARRAY(m_data.triangles);
    CC_SAFE_DELETE_ARRAY(m_data.edges);
}

DHMeshAttachment* DHMeshAttachment::createWithFile(const char* pszFileName, const MeshData& data) {
    DHMeshAttachment* attachment = new DHMeshAttachment(data);
    if (attachment && attachment->initWithFile(pszFileName)) {
        attachment->autorelease();
        return attachment;
    }
    CC_SAFE_DELETE(attachment);
    CCLOG("dhspine mesh miss file %s", pszFileName);
    return nullptr;
}

DHMeshAttachment* DHMeshAttachment::createWithSpriteFrameName(const char* pszSpriteFrameName, const MeshData& data) {
    DHMeshAttachment* attachment = new DHMeshAttachment(data);
    if (attachment && attachment->initWithSpriteFrameName(pszSpriteFrameName)) {
        attachment->autorelease();
        return attachment;
    }
#if DH_SPINE_RELEASE == 0
    if (attachment) {
        attachment->m_data = MeshData();//keep data save
        delete attachment;
    }
#else
    CC_SAFE_DELETE(attachment);
#endif
    CCLOG("dhspine mesh miss SpriteFrameName %s", pszSpriteFrameName);
    return nullptr;
}

void DHMeshAttachment::updateInfo() {
    float width = m_texCoords[2].u - m_texCoords[0].u;
    float height = m_texCoords[2].v - m_texCoords[0].v;
    float offsetX = m_relativeOffset.x + (m_untrimmedSize.width - m_rectSize.width) / 2;
    float offsetY = m_relativeOffset.y + (m_untrimmedSize.height - m_rectSize.height) / 2;
    
    CC_SAFE_DELETE_ARRAY(m_data.texCoords);
    
    m_data.texCoords = new Tex2F[m_data.verticesCount >> 1];
    if (m_rectRotated) {
        width *= (m_untrimmedSize.width / m_rectSize.width);
        height *= (m_untrimmedSize.height / m_rectSize.height);
        
        m_texCoords[0].u += offsetX / m_texture->getContentSize().width;
        m_texCoords[0].v -= offsetY / m_texture->getContentSize().height;
        
        for (int i = 0; i < m_data.verticesCount; i += 2) {
            m_data.texCoords[i >> 1].u = m_texCoords[0].u + (1 - m_data.regionUVs[i + 1]) * width;
            m_data.texCoords[i >> 1].v = m_texCoords[0].v + m_data.regionUVs[i] * height;
        }
    }
    else {
        width *= (m_untrimmedSize.width / m_rectSize.width);
        height *= (m_untrimmedSize.height / m_rectSize.height);
        
        m_texCoords[0].u -= offsetX / m_texture->getContentSize().width;
        m_texCoords[0].v += offsetY / m_texture->getContentSize().height;
        
        for (int i = 0; i < m_data.verticesCount; i += 2) {
            m_data.texCoords[i >> 1].u = m_texCoords[0].u + m_data.regionUVs[i] * width;
            m_data.texCoords[i >> 1].v = m_texCoords[0].v + (1 - m_data.regionUVs[i + 1]) * height;
        }
    }
}

void DHMeshAttachment::updateAabb(DHSlot* owner, float& minX, float& minY, float& maxX, float& maxY) {
    if (owner->m_ca == 0 || m_data.a == 0) {
        return;
    }
    
    setCurrentSlot(owner);
    
    float* dataVertices = m_data.vertices;
    const DHBone* bone = m_slot->m_bone;
    
    if (m_slot->m_attachmentVerticesCount == m_data.verticesCount) {
        dataVertices = m_slot->m_attachmentVertices;
    }
    for (int i = 0; i < m_data.verticesCount; i += 2) {
        const float vx = dataVertices[i], vy = dataVertices[i + 1];
        float wx = vx * bone->m_m00 + vy * bone->m_m01 + bone->m_worldX;
        float wy = vx * bone->m_m10 + vy * bone->m_m11 + bone->m_worldY;
        minX = DHMIN(minX, wx);
        minY = DHMIN(minY, wy);
        maxX = DHMAX(maxX, wx);
        maxY = DHMAX(maxY, wy);
    }
}

unsigned int DHMeshAttachment::getVerticesCount() {
    return m_data.verticesCount >> 1;
}

unsigned int DHMeshAttachment::getTrianglesCount() {
    return m_data.trianglesCount;
}

PolygonDrawCmd* DHMeshAttachment::newDrawCmd(DHSlot* owner) {
    if (owner->m_ca == 0 || m_data.a == 0) {
        return nullptr;
    }
    
    setCurrentSlot(owner);
    
    PolygonDrawCmd* cmd = new PolygonDrawCmd();
    cmd->textureID = m_texture->getName();
    cmd->verticesCount = getVerticesCount();
    cmd->trianglesCount = getTrianglesCount();
    
    cmd->color.r = m_slot->m_cr * m_data.r;
    cmd->color.g = m_slot->m_cg * m_data.g;
    cmd->color.b = m_slot->m_cb * m_data.b;
    cmd->color.a = m_slot->m_ca * m_data.a;
    
    return cmd;
}

bool DHMeshAttachment::fillDrawData(const Mat4 &transform, PolygonDrawCmd* cmd, V2F_C4F_T2F* vertices, unsigned int& verticesCount, GLushort* triangles, unsigned int& trianglesCount, bool useCulling) {
    float* dataVertices = m_data.vertices;
    const DHBone* bone = m_slot->m_bone;
    
    if (m_slot->m_attachmentVerticesCount == m_data.verticesCount) {
        dataVertices = m_slot->m_attachmentVertices;
    }
    
    DHSkeleton* skeleton = m_slot->m_skeleton;
    for (int i = 0; i < m_data.verticesCount; i += 2) {
        const float vx = dataVertices[i], vy = dataVertices[i + 1];
        float wx = vx * bone->m_m00 + vy * bone->m_m01 + bone->m_worldX;
        float wy = vx * bone->m_m10 + vy * bone->m_m11 + bone->m_worldY;
        
        int j = (i >> 1);
        V2F_C4F_T2F& verticeInfo = vertices[verticesCount + j];
        Vec2 &vertice = verticeInfo.vertices;
        vertice.x = skeleton->isFlipX() ? -wx : wx;
        vertice.y = skeleton->isFlipY() ? -wy : wy;
        transformPoint(transform, vertice);
        
        verticeInfo.texCoords = m_data.texCoords[j];
        verticeInfo.colors = cmd->color;
    }
    
    if (useCulling && !checkVisibility(vertices, verticesCount)) {
        return false;
    }
    
    for (int i = 0; i < m_data.trianglesCount; i++) {
        triangles[trianglesCount + i] = m_data.triangles[i] + verticesCount;
    }
    
    verticesCount += cmd->verticesCount;
    trianglesCount += cmd->trianglesCount;
    
    return true;
}

NS_CC_END