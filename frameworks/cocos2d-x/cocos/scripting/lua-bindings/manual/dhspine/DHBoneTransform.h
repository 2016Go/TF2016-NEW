//
//  DHBoneTransform.h
//  dhspine
//
//  Created by youbin on 13-10-7.
//
//

#ifndef __dhspine__DHBoneTransform__
#define __dhspine__DHBoneTransform__

#include "DHGlobal.h"

NS_CC_BEGIN

struct DHTimeline {
    float time;
};

struct DHCurveTimeline : public DHTimeline {
    float diffTime;
    float curves[6];/* type or dfx, dfy, ddfx, ddfy, dddfx, dddfy, ... */
    
    void setLinear();
    
    void setStepped();
    
    void setCurve(float cp1X,float cp1Y,float cp2X,float cp2Y);
    
    float getInterpolationPercent(float passTime);
    
    static const float CURVE_LINEAR;
    static const float CURVE_STEPPED;
    static const int CURVE_SEGMENTS;
};

struct DHRotateKeyFrame : public DHCurveTimeline {
    float angle;
};


struct DHTranslateKeyFrame : public DHCurveTimeline {
    float x, y;
};

struct DHScaleKeyFrame : public DHCurveTimeline {
    float scaleX, scaleY;
};

struct DHFlipKeyFrame : public DHTimeline {
    bool flip;
};

class DHSkeletonAnimation;

class DHBoneTransform {
    
public:
    DHBoneTransform(int boneIndex);
    
    ~DHBoneTransform();
    
    void applyTo(DHSkeletonAnimation* owner, float time, float alpha = 1.f);
    
    void createRotationTimeLine(unsigned int rotateCount);
    
    void createTranslationTimeLine(unsigned int translateCount);
    
    void createScaleTimeLine(unsigned int scaleCount);
    
    void createFlipTimeLine(unsigned int flipCount, bool x);
    
    DHRotateKeyFrame* createRotationKeyFrame(unsigned int frameIndex);
    
    DHTranslateKeyFrame* createTranslationKeyFrame(unsigned int frameIndex);
    
    DHScaleKeyFrame* createScaleKeyFrame(unsigned int frameIndex);
    
    DHFlipKeyFrame* createFlipKeyFrame(unsigned int frameIndex, bool x);
    
    float updateInfo();
    
private:
    DHBoneTransform();
    
    const int m_boneIndex;
    
    unsigned int m_rotateCount;
    DHRotateKeyFrame** m_rotate;
    
    unsigned int m_translateCount;
    DHTranslateKeyFrame** m_translate;
    
    unsigned int m_scaleCount;
    DHScaleKeyFrame** m_scale;
    
    unsigned int m_flipXCount;
    DHFlipKeyFrame** m_flipX;
    
    unsigned int m_flipYCount;
    DHFlipKeyFrame** m_flipY;
};

NS_CC_END

#endif /* defined(__dhspine__DHBoneTransform__) */
