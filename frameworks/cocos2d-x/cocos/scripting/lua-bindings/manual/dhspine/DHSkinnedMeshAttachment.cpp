//
//  DHSkinnedMeshAttachment.cpp
//  MyTest
//
//  Created by youbin on 14-12-29.
//
//

#include "DHSkinnedMeshAttachment.h"
#include "DHSkeleton.h"

NS_CC_BEGIN

DHSkinnedMeshAttachment::DHSkinnedMeshAttachment() {
    m_type = DHAttachmentType::at_skinned_mesh;
}

DHSkinnedMeshAttachment::DHSkinnedMeshAttachment(const SkinnedMeshData& data)
:m_data(data) {
    m_type = DHAttachmentType::at_skinned_mesh;
}

DHSkinnedMeshAttachment::~DHSkinnedMeshAttachment() {
    CC_SAFE_DELETE_ARRAY(m_data.regionUVs);
    CC_SAFE_DELETE_ARRAY(m_data.texCoords);
    CC_SAFE_DELETE_ARRAY(m_data.bones);
    CC_SAFE_DELETE_ARRAY(m_data.weights);
    CC_SAFE_DELETE_ARRAY(m_data.triangles);
    CC_SAFE_DELETE_ARRAY(m_data.edges);
}

DHSkinnedMeshAttachment* DHSkinnedMeshAttachment::createWithFile(const char* pszFileName, const SkinnedMeshData& data) {
    DHSkinnedMeshAttachment* attachment = new DHSkinnedMeshAttachment(data);
    if (attachment && attachment->initWithFile(pszFileName)) {
        attachment->autorelease();
        return attachment;
    }
    CC_SAFE_DELETE(attachment);
    CCLOG("dhspine skinMesh miss file %s", pszFileName);
    return nullptr;
}

DHSkinnedMeshAttachment* DHSkinnedMeshAttachment::createWithSpriteFrameName(const char* pszSpriteFrameName, const SkinnedMeshData& data) {
    DHSkinnedMeshAttachment* attachment = new DHSkinnedMeshAttachment(data);
    if (attachment && attachment->initWithSpriteFrameName(pszSpriteFrameName)) {
        attachment->autorelease();
        return attachment;
    }
#if DH_SPINE_RELEASE == 0
    if (attachment) {
        attachment->m_data = SkinnedMeshData();//keep data save
        delete attachment;
    }
#else
    CC_SAFE_DELETE(attachment);
#endif
    CCLOG("dhspine skinMesh miss SpriteFrameName %s", pszSpriteFrameName);
    return nullptr;
}

void DHSkinnedMeshAttachment::updateInfo() {
    float width = m_texCoords[2].u - m_texCoords[0].u;
    float height = m_texCoords[2].v - m_texCoords[0].v;
    float offsetX = m_relativeOffset.x + (m_untrimmedSize.width - m_rectSize.width) / 2;
    float offsetY = m_relativeOffset.y + (m_untrimmedSize.height - m_rectSize.height) / 2;
    
    CC_SAFE_DELETE_ARRAY(m_data.texCoords);
    
    m_data.texCoords = new Tex2F[m_data.uvsCount >> 1];
    
    if (m_rectRotated) {
        width *= (m_untrimmedSize.width / m_rectSize.width);
        height *= (m_untrimmedSize.height / m_rectSize.height);
        
        m_texCoords[0].u += offsetX / m_texture->getContentSize().width;
        m_texCoords[0].v -= offsetY / m_texture->getContentSize().height;
        
        for (int i = 0; i < m_data.uvsCount; i += 2) {
            m_data.texCoords[i >> 1].u = m_texCoords[0].u + width - m_data.regionUVs[i + 1] * width;
            m_data.texCoords[i >> 1].v = m_texCoords[0].v + m_data.regionUVs[i] * height;
        }
    }
    else {
        width *= (m_untrimmedSize.width / m_rectSize.width);
        height *= (m_untrimmedSize.height / m_rectSize.height);
        
        m_texCoords[0].u -= offsetX / m_texture->getContentSize().width;
        m_texCoords[0].v += offsetY / m_texture->getContentSize().height;
        
        for (int i = 0; i < m_data.uvsCount; i += 2) {
            m_data.texCoords[i >> 1].u = m_texCoords[0].u + m_data.regionUVs[i] * width;
            m_data.texCoords[i >> 1].v = m_texCoords[0].v + height - m_data.regionUVs[i + 1] * height;
        }
    }
}

void DHSkinnedMeshAttachment::updateAabb(DHSlot* owner, float& minX, float& minY, float& maxX, float& maxY) {
    if (owner->m_ca == 0 || m_data.a == 0) {
        return;
    }
    
    setCurrentSlot(owner);
    
    int w = 0, b = 0, f = 0;
    DHSkeleton* skeleton = m_slot->m_skeleton;
    
    if (m_slot->m_attachmentVerticesCount == 0) {
        for (int v = 0; v < m_data.bonesCount; w += 2) {
            float wx = 0, wy = 0;
            const int nn = m_data.bones[v] + v;
            v++;
            for (; v <= nn; v++, b += 3) {
                const DHBone* bone = skeleton->getBoneByIndex(m_data.bones[v]);
                
                const float vx = m_data.weights[b], vy = m_data.weights[b + 1], weight = m_data.weights[b + 2];
                wx += (vx * bone->m_m00 + vy * bone->m_m01 + bone->m_worldX) * weight;
                wy += (vx * bone->m_m10 + vy * bone->m_m11 + bone->m_worldY) * weight;
            }
            minX = DHMIN(minX, wx);
            minY = DHMIN(minY, wy);
            maxX = DHMAX(maxX, wx);
            maxY = DHMAX(maxY, wy);
        }
    }
    else {
        const float* ffd = m_slot->m_attachmentVertices;
        for (int v = 0; v < m_data.bonesCount; w += 2) {
            float wx = 0, wy = 0;
            const int nn = m_data.bones[v] + v;
            v++;
            for (; v <= nn; v++, b += 3, f += 2) {
                const DHBone* bone = skeleton->getBoneByIndex(m_data.bones[v]);
                const float vx = m_data.weights[b] + ffd[f], vy = m_data.weights[b + 1] + ffd[f + 1], weight = m_data.weights[b + 2];
                wx += (vx * bone->m_m00 + vy * bone->m_m01 + bone->m_worldX) * weight;
                wy += (vx * bone->m_m10 + vy * bone->m_m11 + bone->m_worldY) * weight;
            }
            minX = DHMIN(minX, wx);
            minY = DHMIN(minY, wy);
            maxX = DHMAX(maxX, wx);
            maxY = DHMAX(maxY, wy);
        }
    }
}

unsigned int DHSkinnedMeshAttachment::getVerticesCount() {
    return m_data.uvsCount >> 1;
}

unsigned int DHSkinnedMeshAttachment::getTrianglesCount() {
    return m_data.trianglesCount;
}

PolygonDrawCmd* DHSkinnedMeshAttachment::newDrawCmd(DHSlot* owner) {
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

bool DHSkinnedMeshAttachment::fillDrawData(const Mat4 &transform, PolygonDrawCmd* cmd, V2F_C4F_T2F* vertices, unsigned int& verticesCount, GLushort* triangles, unsigned int& trianglesCount, bool useCulling) {
    int w = 0, b = 0, f = 0;
    DHSkeleton* skeleton = m_slot->m_skeleton;
    
    if (m_slot->m_attachmentVerticesCount == 0) {
        for (int v = 0; v < m_data.bonesCount; w += 2) {
            float wx = 0, wy = 0;
            const int nn = m_data.bones[v] + v;
            v++;
            for (; v <= nn; v++, b += 3) {
                const DHBone* bone = skeleton->getBoneByIndex(m_data.bones[v]);
                
                const float vx = m_data.weights[b], vy = m_data.weights[b + 1], weight = m_data.weights[b + 2];
                wx += (vx * bone->m_m00 + vy * bone->m_m01 + bone->m_worldX) * weight;
                wy += (vx * bone->m_m10 + vy * bone->m_m11 + bone->m_worldY) * weight;
            }
            int i = (w >> 1);
            V2F_C4F_T2F& verticeInfo = vertices[verticesCount + i];
            Vec2 &vertice = verticeInfo.vertices;
            vertice.x = skeleton->isFlipX() ? -wx : wx;
            vertice.y = skeleton->isFlipY() ? -wy : wy;
            transformPoint(transform, vertice);
            
            verticeInfo.texCoords = m_data.texCoords[i];
            verticeInfo.colors = cmd->color;
        }
    }
    else {
        const float* ffd = m_slot->m_attachmentVertices;
        for (int v = 0; v < m_data.bonesCount; w += 2) {
            float wx = 0, wy = 0;
            const int nn = m_data.bones[v] + v;
            v++;
            for (; v <= nn; v++, b += 3, f += 2) {
                const DHBone* bone = skeleton->getBoneByIndex(m_data.bones[v]);
                const float vx = m_data.weights[b] + ffd[f], vy = m_data.weights[b + 1] + ffd[f + 1], weight = m_data.weights[b + 2];
                wx += (vx * bone->m_m00 + vy * bone->m_m01 + bone->m_worldX) * weight;
                wy += (vx * bone->m_m10 + vy * bone->m_m11 + bone->m_worldY) * weight;
            }
            int i = (w >> 1);
            V2F_C4F_T2F& verticeInfo = vertices[verticesCount + i];
            Vec2 &vertice = verticeInfo.vertices;
            vertice.x = skeleton->isFlipX() ? -wx : wx;
            vertice.y = skeleton->isFlipY() ? -wy : wy;
            transformPoint(transform, vertice);
            
            verticeInfo.texCoords = m_data.texCoords[i];
            verticeInfo.colors = cmd->color;
        }
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