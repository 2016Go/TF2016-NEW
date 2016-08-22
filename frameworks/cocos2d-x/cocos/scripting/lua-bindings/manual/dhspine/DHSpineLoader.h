//
//  DHSpineLoader.h
//  dhspine
//
//  Created by youbin on 13-10-3.
//
//

#ifndef __dhspine__DHSpineLoader__
#define __dhspine__DHSpineLoader__

#include "DHJson.h"
#include "DHAnimationData.h"
#include "DHSkeletonData.h"

NS_CC_BEGIN

class DHSpineLoader {
    
public:
    static DHSkeletonData* loadSkeletonData(const char* path, float scale = 1.f);
    
    static char* relativeFilePath;
    
    static float resolutionScale;
    
    static void setXXTEAKeyAndSign(const char *key, int keyLen, const char *sign, int signLen);
    
private:
    static DHSkeletonData* loadSkeletonFromData(const char* data, float scale);
    
    static void loadAnimation(DHJson* root, DHSkeletonData* skeletonData, float scale);
    
    static GLfloat toColor (const char* value, int index);
    
    static void loadCurve(DHJson* root, DHCurveTimeline* frame);
    
    static void cleanupXXTEAKeyAndSign();
    
    static bool  m_xxteaEnabled;
    static char* m_xxteaKey;
    static int   m_xxteaKeyLen;
    static char* m_xxteaSign;
    static int   m_xxteaSignLen;
    
};
NS_CC_END

#endif /* defined(__dhspine__DHSpineLoader__) */
