//
//  DHRegionAttachment.cpp
//  dhspine
//
//  Created by youbin on 13-10-11.
//
//

#include "DHRegionAttachment.h"
#include "DHSkeleton.h"

NS_CC_BEGIN

DHRegionAttachment::DHRegionAttachment()
:m_texture(nullptr) {
    m_type = DHAttachmentType::at_region;
}

DHRegionAttachment::DHRegionAttachment(const RegionData& data)
:m_data(data)
,m_texture(nullptr) {
    m_type = DHAttachmentType::at_region;
}

DHRegionAttachment::~DHRegionAttachment() {
    CC_SAFE_RELEASE(m_texture);
}

DHRegionAttachment* DHRegionAttachment::createWithFile(const char* pszFileName, const RegionData& data) {
    DHRegionAttachment* attachment = new DHRegionAttachment(data);
    if (attachment && attachment->initWithFile(pszFileName)) {
        attachment->autorelease();
        return attachment;
    }
    CCLOG("miss file : %s", pszFileName);
    CC_SAFE_DELETE(attachment);
    return nullptr;
}

DHRegionAttachment* DHRegionAttachment::createWithSpriteFrameName(const char* pszSpriteFrameName, const RegionData& data) {
    DHRegionAttachment* attachment = new DHRegionAttachment(data);
    if (attachment && attachment->initWithSpriteFrameName(pszSpriteFrameName)) {
        attachment->autorelease();
        return attachment;
    }
    CCLOG("miss file : %s", pszSpriteFrameName);
    CC_SAFE_DELETE(attachment);
    return nullptr;
}

void DHRegionAttachment::updateInfo() {
    Vec2 point1 = Vec2(m_relativeOffset.x, m_relativeOffset.y);
    Vec2 point2 = Vec2(m_rectSize.width, m_rectSize.height);
    
    float localX = (point1.x - point2.x / 2) * m_data.scaleX;
    float localY = (point1.y - point2.y / 2) * m_data.scaleY;
    float localX2 = localX + point2.x * m_data.scaleX;
    float localY2 = localY + point2.y * m_data.scaleY;
    float radians = CC_DEGREES_TO_RADIANS(m_data.rotation);
    float cosine = cosf(radians);
	float sine = sinf(radians);
    
    float localXCos = localX * cosine + m_data.x;
	float localXSin = localX * sine;
	float localYCos = localY * cosine + m_data.y;
	float localYSin = localY * sine;
	float localX2Cos = localX2 * cosine + m_data.x;
	float localX2Sin = localX2 * sine;
	float localY2Cos = localY2 * cosine + m_data.y;
	float localY2Sin = localY2 * sine;
    
    m_vertices[0] = Vec2(localXCos - localYSin, localYCos + localXSin);
    m_vertices[1] = Vec2(localXCos - localY2Sin, localY2Cos + localXSin);
    m_vertices[2] = Vec2(localX2Cos - localY2Sin, localY2Cos + localX2Sin);
    m_vertices[3] = Vec2(localX2Cos - localYSin, localYCos + localX2Sin);

}

bool DHRegionAttachment::initWithFile(const char *pszFilename) {
    Texture2D *pTexture = Director::getInstance()->getTextureCache()->addImage(pszFilename);
    if (pTexture) {
        Rect rect = Rect::ZERO;
        rect.size = pTexture->getContentSize();
        
        m_data.width = rect.size.width;
        m_data.height = rect.size.height;
        
        return initWithTexture(pTexture, rect);
    }
    return false;
}

bool DHRegionAttachment::init(cocos2d::Texture2D *pTexture) {
    m_texture = pTexture;
    if (!m_texture) {
        return false;
    }
    m_texture->retain();
    return true;
}

bool DHRegionAttachment::initWithTexture(cocos2d::Texture2D *pTexture, const cocos2d::Rect &rect) {
    if (!init(pTexture)) {
        return false;
    }
    
    setVertex(rect, Vec2::ZERO, rect.size);
    setTextureCoords(rect, false);
    
    updateInfo();
    
    return true;
}

bool DHRegionAttachment::initWithSpriteFrameName(const char *pszSpriteFrameName) {
    SpriteFrame *pSpriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pszSpriteFrameName);
    
    if (!pSpriteFrame || !init(pSpriteFrame->getTexture())) {
        return false;
    }
    
    Size size = pSpriteFrame->getOriginalSize();
    m_data.width = size.width;
    m_data.height = size.height;
    
    setVertex(pSpriteFrame->getRect(), pSpriteFrame->getOffset(), pSpriteFrame->getOriginalSize());
    setTextureCoords(pSpriteFrame->getRect(), pSpriteFrame->isRotated());
    
    updateInfo();
    
    return true;
}

void DHRegionAttachment::setVertex(const cocos2d::Rect &rect, const cocos2d::Point &relativeOffset, const Size& untrimmedSize) {
    m_rectSize = rect.size;
    m_relativeOffset = relativeOffset;
    m_untrimmedSize = untrimmedSize;
}

void DHRegionAttachment::setTextureCoords(cocos2d::Rect rect, bool rotated) {
    m_rectRotated = rotated;
    
    rect = CC_RECT_POINTS_TO_PIXELS(rect);
    
    float atlasWidth = (float)m_texture->getPixelsWide();
    float atlasHeight = (float)m_texture->getPixelsHigh();
    
    float left, right, top, bottom;
    
    if (m_rectRotated) {
        
#if CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL
        left    = (2*rect.origin.x+1)/(2*atlasWidth);
        right    = left+(rect.size.height*2-2)/(2*atlasWidth);
        top        = (2*rect.origin.y+1)/(2*atlasHeight);
        bottom    = top+(rect.size.width*2-2)/(2*atlasHeight);
#else
        left    = rect.origin.x/atlasWidth;
        right    = (rect.origin.x+rect.size.height) / atlasWidth;
        top        = rect.origin.y/atlasHeight;
        bottom    = (rect.origin.y+rect.size.width) / atlasHeight;
#endif // CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL
        
        m_texCoords[3].u = left;
        m_texCoords[3].v = bottom;
        m_texCoords[0].u = left;
        m_texCoords[0].v = top;
        m_texCoords[1].u = right;
        m_texCoords[1].v = top;
        m_texCoords[2].u = right;
        m_texCoords[2].v = bottom;
        
    } else {
        
#if CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL
        left    = (2*rect.origin.x+1)/(2*atlasWidth);
        right    = left + (rect.size.width*2-2)/(2*atlasWidth);
        top        = (2*rect.origin.y+1)/(2*atlasHeight);
        bottom    = top + (rect.size.height*2-2)/(2*atlasHeight);
#else
        left    = rect.origin.x/atlasWidth;
        right    = (rect.origin.x + rect.size.width) / atlasWidth;
        top        = rect.origin.y/atlasHeight;
        bottom    = (rect.origin.y + rect.size.height) / atlasHeight;
#endif // ! CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL
        
        m_texCoords[0].u = left;
        m_texCoords[0].v = bottom;
        m_texCoords[1].u = left;
        m_texCoords[1].v = top;
        m_texCoords[2].u = right;
        m_texCoords[2].v = top;
        m_texCoords[3].u = right;
        m_texCoords[3].v = bottom;
    }
}

void DHRegionAttachment::computeWorldVertices(GLfloat &x, GLfloat &y, int index) {
    x = m_vertices[index].x * m_slot->m_bone->m_m00 + m_vertices[index].y * m_slot->m_bone->m_m01 + m_slot->m_bone->m_worldX;
	y = m_vertices[index].x * m_slot->m_bone->m_m10 + m_vertices[index].y * m_slot->m_bone->m_m11 + m_slot->m_bone->m_worldY;
}

unsigned int DHRegionAttachment::getVerticesCount() {
    return 4;
}

unsigned int DHRegionAttachment::getTrianglesCount() {
    return 6;
}

PolygonDrawCmd* DHRegionAttachment::newDrawCmd(DHSlot* owner) {
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

void DHRegionAttachment::transformPoint(const Mat4 &transform, Vec2& vertice) {
    float x = vertice.x;
    float y = vertice.y;
    vertice.x = x * transform.m[0] + y * transform.m[4] + transform.m[12];
    vertice.y = x * transform.m[1] + y * transform.m[5] + transform.m[13];
}

bool DHRegionAttachment::fillDrawData(const Mat4 &transform, PolygonDrawCmd* cmd, V2F_C4F_T2F* vertices, unsigned int& verticesCount, GLushort* triangles, unsigned int& trianglesCount, bool useCulling) {
    for (int i = 0; i < getVerticesCount(); i++) {
        V2F_C4F_T2F& verticeInfo = vertices[verticesCount + i];
        Vec2 &vertice = verticeInfo.vertices;
        computeWorldVertices(vertice.x, vertice.y, i);
        if (m_slot->m_skeleton->isFlipX()) {
            vertice.x = -vertice.x;
        }
        if (m_slot->m_skeleton->isFlipY()) {
            vertice.y = -vertice.y;
        }
        transformPoint(transform, vertice);
        
        verticeInfo.texCoords = m_texCoords[i];
        verticeInfo.colors = cmd->color;
    }
    
    if (useCulling && !checkVisibility(vertices, verticesCount)) {
        return false;
    }
    
    static const int quadTriangles[6] = {0, 1, 2, 2, 3, 0};
    for (int i = 0; i < 6; i++) {
        triangles[trianglesCount + i] = quadTriangles[i] + verticesCount;
    }
    
    verticesCount += cmd->verticesCount;
    trianglesCount += cmd->trianglesCount;
    
    return true;
}

void DHRegionAttachment::updateAabb(DHSlot* owner, float &minX, float &minY, float &maxX, float &maxY) {
    if (owner->m_ca == 0 || m_data.a == 0) {
        return;
    }
    
    setCurrentSlot(owner);
    Vec2 vertices;
    for (int i = 0; i < 4; i++) {
        computeWorldVertices(vertices.x, vertices.y, i);
        minX = DHMIN(minX, vertices.x);
        minY = DHMIN(minY, vertices.y);
        maxX = DHMAX(maxX, vertices.x);
        maxY = DHMAX(maxY, vertices.y);
    }
}

bool DHRegionAttachment::containsPoint(cocos2d::DHSlot *owner, float x, float y) {
    setCurrentSlot(owner);
    Vec2 vertices[4];
    for (int i = 0; i < 4; i++) {
        computeWorldVertices(vertices[i].x, vertices[i].y, i);
        if (m_slot->m_skeleton->isFlipX()) {
            vertices[i].x = -vertices[i].x;
        }
        if (m_slot->m_skeleton->isFlipY()) {
            vertices[i].y = -vertices[i].y;
        }
    }
    
    int prevIndex = 0;
	bool inside = false;
	for (int i = 3; i >=0; --i) {
		float vertexY = vertices[i].y;
		float prevY = vertices[prevIndex].y;
		if ((vertexY < y && prevY >= y) || (prevY < y && vertexY >= y)) {
			float vertexX = vertices[i].x;
			if (vertexX + (y - vertexY) / (prevY - vertexY) * (vertices[prevIndex].x - vertexX) < x) {
                inside ^= 1;
            }
		}
		prevIndex = i;
	}
	return inside;
}

bool DHRegionAttachment::checkVisibility(V2F_C4F_T2F* vertices, unsigned int& verticesCount) {
#if !DH_SPINE_USE_CULLING_X && !DH_SPINE_USE_CULLING_Y
    return true;
#endif
    
    unsigned int addVecCount = getVerticesCount();
    
#if DH_SPINE_USE_CULLING_X
    float minX = INT_MAX, maxX = INT_MIN;
#endif
#if DH_SPINE_USE_CULLING_Y
    float minY = INT_MAX, maxY = INT_MIN;
#endif
    for (int i = 0; i < addVecCount; i++) {
        const Vec2& vertice = vertices[verticesCount + i].vertices;
#if DH_SPINE_USE_CULLING_X
        minX = DHMIN(minX, vertice.x);
        maxX = DHMAX(maxX, vertice.x);
#endif
#if DH_SPINE_USE_CULLING_Y
        minY = DHMIN(minY, vertice.y);
        maxY = DHMAX(maxY, vertice.y);
#endif
    }
    
    auto director = Director::getInstance();
    const Vec2& origin = director->getVisibleOrigin();
    const Size& size = director->getVisibleSize();
    
#if DH_SPINE_USE_CULLING_X && DH_SPINE_USE_CULLING_Y
    return !(origin.x + size.width < minX || maxX < origin.x || origin.y + size.height < minY || maxY < origin.y);
#elif DH_SPINE_USE_CULLING_X
    return !(origin.x + size.width < minX || maxX < origin.x);
#elif DH_SPINE_USE_CULLING_Y
    return !(origin.y + size.height < minY || maxY < origin.y);
#endif
}

NS_CC_END
