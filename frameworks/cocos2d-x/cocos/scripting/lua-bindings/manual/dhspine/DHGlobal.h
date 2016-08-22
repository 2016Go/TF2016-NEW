//
//  DHGlobal.h
//  dhspine
//
//  Created by youbin on 13-10-11.
//
//

#ifndef dhspine_DHGlobal_h
#define dhspine_DHGlobal_h

#include "cocos2d.h"

NS_CC_BEGIN

#define DH_SPINE_RELEASE 0

#define DH_LUA_ENABLED 1

#define DH_SPINE_USE_CULLING_X 1
#define DH_SPINE_USE_CULLING_Y 0

#ifdef WP8
#define DHMAX   max
#else
#define DHMAX   std::max
#endif

#ifdef WP8
#define DHMIN   min
#else
#define DHMIN   std::min
#endif

///

#define DH_ARRAY_FOREACH(__count__)                                                                         \
for (int i = 0; i < __count__; ++i)

///

#define DH_ARRAY_DELETE(__array__, __count__)   \
if(__array__) {                                 \
    for (int i = 0; i < __count__; ++i) { delete __array__[i]; }       \
    delete [] __array__;                                             \
}

///

#define DH_GET_DURATION(__array__, __count__, __duration__)  \
if(__array__) { __duration__ = DHMAX(__duration__, __array__[__count__ - 1]->time); }

#define DH_UPDATE_DIFF_TIME(__array__, __count__)   \
if(__array__) {                                \
    int count = __count__ - 1;                  \
    for (int i = 0; i < count; ++i) { __array__[i]->diffTime = __array__[i + 1]->time - __array__[i]->time; }  \
}

///

#define DH_BINARY_SEARCH(__array__, __count__, __time__, __frameIndex__)   \
{                                                                          \
    int left = 0;                                                          \
    int right = __count__ - 1;                                             \
    while (left < right) {                                                   \
        int mid = (left + right) >> 1;                                       \
        if (__array__[mid]->time <= __time__) left = mid + 1;              \
        else right = mid;                                                  \
    }                                                                      \
    __frameIndex__ = left;                                                 \
}

///

#define DH_CREATE_FUNC(__TYPE__) \
static __TYPE__* create() { \
    __TYPE__ *pRet = new __TYPE__(); \
    pRet->autorelease(); \
    return pRet; \
}

#define PI 3.1415926535897932385f
#define DEG_RAD (PI / 180)
#define RAD_DEG (180 / PI)

///

static char* DHStrCopy(const char* src) {
    if(src == nullptr) {
        return nullptr;
    }
    size_t len = strlen(src);
    char* dst = (char*)calloc(len + 1, sizeof(char));
    memcpy(dst, src, len);
    return dst;
}

static const void DHStrFree(char* str) {
    if (str) {
        free(str);
    }
}

enum class SpineBlendType {
    sbt_none,
    sbt_additive,
    sbt_multiply,
    sbt_screen,
};

struct PolygonDrawCmd {
    GLuint textureID;
    Color4F color;
    SpineBlendType blendMode;
    float hue;
    float saturation;
    float brightness;
    
    unsigned int verticesCount;
    unsigned int trianglesCount;
    
    PolygonDrawCmd();
    
    ~PolygonDrawCmd();
};

//matrix function
struct DHMatrix {
    float mat[3][3];
    
    static void matrixMult(float a[3][3], float b[3][3], float c[3][3]);
    
    static void xRotateMat(float mat[3][3], float rs, float rc);
    
    static void yRotateMat(float mat[3][3], float rs, float rc);
    
    static void zRotateMat(float mat[3][3], float rs, float rc);
    
    void hueMatrix(float angle);
    
    void saturationMatrix(float s);
    
    void brightnessMatrix(float b);
    
    void premultiplyAlpha(float alpha);
};

namespace DHMatrixHelper {
    
    static void xRotateMat(float mat[3][3], float rs, float rc);
    
    static void yRotateMat(float mat[3][3], float rs, float rc);
    
    static void zRotateMat(float mat[3][3], float rs, float rc);
    
    static void matrixMult(float a[3][3], float b[3][3], float c[3][3]);
}

NS_CC_END

#endif
