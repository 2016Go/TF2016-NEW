//
//  DHSkeletonDataCache.cpp
//  dhspine
//
//  Created by youbin on 13-10-12.
//
//

#include "DHSkeletonDataCache.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

//shader

const GLchar* fragSource[] = {
    "                                                                       \n\
    #ifdef GL_ES                                                            \n\
    precision mediump float;                                                \n\
    #endif                                                                  \n\
    \n\
    varying vec2 v_texCoord;                                                \n\
    varying vec4 v_fragmentColor;                                           \n\
    uniform mat3 u_hue;                                                     \n\
    \n\
    void main()                                                             \n\
    {                                                                       \n\
    vec4 pixColor = texture2D(CC_Texture0, v_texCoord);                     \n\
    vec3 rgbColor = u_hue * pixColor.rgb;                                   \n\
    gl_FragColor = vec4(rgbColor, pixColor.a) * v_fragmentColor;            \n\
    }                                                                       \n\
    ",
};

DHSkeletonDataCache* DHSkeletonDataCache::m_instance = nullptr;

DHSkeletonDataCache::DHSkeletonDataCache() {
    m_skeletonDataMap = new DHDictionary();
    m_programMap = new DHDictionary();
    
    loadGLPrograms();
    
#if CC_ENABLE_CACHE_TEXTURE_DATA
    auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event) {
        /** listen the event that renderer was recreated on Android/WP8 */
        reloadGLPrograms();
    });
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
#endif
}

DHSkeletonDataCache::~DHSkeletonDataCache() {
    delete m_skeletonDataMap;
    delete m_programMap;
}

DHSkeletonDataCache* DHSkeletonDataCache::getInstance() {
    if (!m_instance) {
        m_instance = new DHSkeletonDataCache();
    }
    return m_instance;
}

void DHSkeletonDataCache::purgeCache() {
    m_skeletonDataMap->removeAll();
}

DHSkeletonData* DHSkeletonDataCache::loadSkeletonData(const char *key, const char *jsonPath, float scale) {
    Ref* value = m_skeletonDataMap->find(key);
    if (value) {
        CCLOGWARN("the key(%s) is already exists!", key);
        return (DHSkeletonData*)value;
    }
    else {
        DHSkeletonData* data = DHSpineLoader::loadSkeletonData(jsonPath, scale);
        if (data) {
            m_skeletonDataMap->insert(key, data);
            return data;
        }
    }
    return nullptr;
}

DHSkeletonData* DHSkeletonDataCache::getSkeletonData(const char *key) {
    Ref* value = m_skeletonDataMap->find(key);
    if (value) {
        return (DHSkeletonData*)value;
    }
    return nullptr;
}

void DHSkeletonDataCache::removeSkeletonData(const char *key) {
    m_skeletonDataMap->remove(key);
}

void DHSkeletonDataCache::setRelativeFilePath(const char *path) {
    DHStrFree(DHSpineLoader::relativeFilePath);
    DHSpineLoader::relativeFilePath = DHStrCopy(path);
}

void DHSkeletonDataCache::setResolutionScale(float resolutionScale) {
    DHSpineLoader::resolutionScale = resolutionScale;
}

GLProgram * DHSkeletonDataCache::getGLProgram(const char* key) {
    Ref* value = m_programMap->find(key);
    if (value) {
        return (GLProgram*)value;
    }
    return nullptr;
}

void DHSkeletonDataCache::addGLProgram(GLProgram* program, const char* key) {
    if (program) {
        m_programMap->insert(key, program);
    }
}

void DHSkeletonDataCache::loadGLPrograms() {
    GLProgram* glprogram = cocos2d::GLProgram::createWithByteArrays(cocos2d::ccPositionTextureColor_noMVP_vert, fragSource[0]);
    addGLProgram(glprogram, "hue_program");
}

void DHSkeletonDataCache::reloadGLPrograms() {
    DHDictElement* element;
    DH_DICT_FOREACH(m_programMap, element) {
        GLProgram* glprogram = (GLProgram*)element->value;
        glprogram->reset();
        glprogram->link();
        glprogram->updateUniforms();
    }
}

void DHSkeletonDataCache::removeRenderTextureCache(const std::string& path) {
    if (m_renderTextureCacheMap.empty()) {
        return;
    }
    
    auto iter = m_renderTextureCacheMap.find(path);
    if (iter != m_renderTextureCacheMap.end()) {
        for (const auto& mapIter : iter->second) {
            DHRenderTextureCacheInfo* info = mapIter.second;
            info->renderTexture->release();
            info->spriteFrame->release();
            delete info;
        }
        m_renderTextureCacheMap.erase(iter);
    }
}

bool DHSkeletonDataCache::checkRenderTextureCache(const std::string& path, const std::string& key) {
    auto iter = m_renderTextureCacheMap.find(path);
    if (iter != m_renderTextureCacheMap.end()) {
        const auto& keyMap = iter->second;
        auto keyIter = keyMap.find(key);
        if (keyIter != keyMap.end()) {
            return true;
        }
    }
    return false;
}

DHRenderTextureCacheInfo* DHSkeletonDataCache::getRenderTextureCacheInfo(const std::string& path, const std::string& key) {
    auto iter = m_renderTextureCacheMap.find(path);
    if (iter != m_renderTextureCacheMap.end()) {
        const auto& keyMap = iter->second;
        auto keyIter = keyMap.find(key);
        if (keyIter != keyMap.end()) {
            return keyIter->second;
        }
    }
    return nullptr;
}

DHRenderTextureCacheInfo* DHSkeletonDataCache::addRenderTextureCache(const std::string& path, const std::string& key, RenderTexture* renderTexture, float minX, float maxX, float minY, float maxY) {
    DHRenderTextureCacheInfo* info = new DHRenderTextureCacheInfo();
    renderTexture->retain();
    info->renderTexture = renderTexture;
    
    Texture2D* texture = renderTexture->getSprite()->getTexture();
    Vec2 offset = Vec2((maxX + minX) * 0.5f, -(maxY + minY) * 0.5f);
    Size untrimmed = Size(DHMAX(fabsf(minX), fabsf(maxX)) * 2, DHMAX(fabsf(minY), fabsf(maxY)) * 2);
    Rect rect = Rect::ZERO;
    rect.size = texture->getContentSize();
    
    
    info->spriteFrame = SpriteFrame::createWithTexture(texture, rect, false, offset, untrimmed);
    info->spriteFrame->retain();
    texture->setAntiAliasTexParameters();
    m_renderTextureCacheMap[path].insert(make_pair(key, info));
    
    return info;
}

void DHSkeletonDataCache::clearRenderTextureCache() {
    for (const auto& iter : m_renderTextureCacheMap) {
        for (const auto& keyIter : iter.second) {
            DHRenderTextureCacheInfo* info = keyIter.second;
            info->renderTexture->release();
            info->spriteFrame->release();
            delete info;
        }
    }
}

void DHSkeletonDataCache::preloadFrameSequence(const char* key, const char* jsonPath, float interval, Node* loadNode, float scale) {
    DHSkeletonData* data = loadSkeletonData(key, jsonPath, scale);
    
    DHDictElement* elements;
    DH_DICT_FOREACH(data->m_animMap, elements) {
        DHAnimationData* animData = (DHAnimationData*)elements->value;
        int frameCount = animData->getDuration() / interval;
        for (int i = 0; i <= frameCount; i++) {
            DHSkeletonAnimation* anim = DHSkeletonAnimation::createWithData(data);
            anim->setFrameSequenceInterval(interval);
            anim->playAnimation(elements->key, 1);
            anim->update(i * interval);
            loadNode->addChild(anim);
        }
    }
}

NS_CC_END