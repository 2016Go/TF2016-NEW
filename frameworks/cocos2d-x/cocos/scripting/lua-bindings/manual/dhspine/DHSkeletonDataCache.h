//
//  DHSkeletonDataCache.h
//  dhspine
//
//  Created by youbin on 13-10-12.
//
//

#ifndef __dhspine__DHSkeletonDataCache__
#define __dhspine__DHSkeletonDataCache__

#include "DHSpineLoader.h"
#include "DHDictionary.h"

NS_CC_BEGIN

struct DHRenderTextureCacheInfo {
    RenderTexture* renderTexture;
    SpriteFrame* spriteFrame;
};

class DHSkeletonDataCache {
    
public:
    ~DHSkeletonDataCache();
    
    static DHSkeletonDataCache* getInstance();
    
    /// add an SkeletonData from jsonPath
    DHSkeletonData* loadSkeletonData(const char* key, const char* jsonPath, float scale = 1.f);
	
	/// get an Skeleton by key
	DHSkeletonData* getSkeletonData(const char* key);
    
	/// remove all cached SkeletonData
	void purgeCache();
    
    void removeSkeletonData(const char* key);
    
    void setRelativeFilePath(const char* path);
    
    void setResolutionScale(float resolutionScale);
    
    float getResolutionScale() const {
        return DHSpineLoader::resolutionScale;
    }
    
    GLProgram * getGLProgram(const char* key);
    
    void addGLProgram(GLProgram* program, const char* key);
    
    void loadGLPrograms();
    
    void reloadGLPrograms();
    
    void removeRenderTextureCache(const std::string& path);
    
    bool checkRenderTextureCache(const std::string& path, const std::string& key);
    
    DHRenderTextureCacheInfo* getRenderTextureCacheInfo(const std::string& path, const std::string& key);
    
    DHRenderTextureCacheInfo* addRenderTextureCache(const std::string& path, const std::string& key, RenderTexture* renderTexture, float minX, float maxX, float minY, float maxY);
    
    void clearRenderTextureCache();
    
    // std::function<void()> callback
    void preloadFrameSequence(const char* key, const char* jsonPath, float interval, Node* loadNode, float scale = 1.f);
    
protected:
    DHSkeletonDataCache();
    
private:
    static DHSkeletonDataCache* m_instance;
    
    DHDictionary* m_skeletonDataMap;
    
    DHDictionary* m_programMap;
    
    std::map<std::string, std::map<std::string, DHRenderTextureCacheInfo*>> m_renderTextureCacheMap;
};

#define SDC    DHSkeletonDataCache::getInstance()

NS_CC_END

#endif /* defined(__dhspine__DHSkeletonDataCache__) */
