//
//  DHBoneTransform.cpp
//  dhspine
//
//  Created by youbin on 13-10-7.
//
//

#include "DHBoneTransform.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

const float DHCurveTimeline::CURVE_LINEAR = -1.f;
const float DHCurveTimeline::CURVE_STEPPED = 0.f;
const int DHCurveTimeline::CURVE_SEGMENTS = 10;

void DHCurveTimeline::setLinear() {
    curves[0] = CURVE_LINEAR;
}

void DHCurveTimeline::setStepped() {
    curves[0] = CURVE_STEPPED;
}

void DHCurveTimeline::setCurve(float cp1X, float cp1Y, float cp2X, float cp2Y) {
    static float subdiv_step = 1.0f / CURVE_SEGMENTS;
    static float subdiv_step2 = subdiv_step * subdiv_step;
    static float subdiv_step3 = subdiv_step2 * subdiv_step;
    float pre1 = 3 * subdiv_step;
    float pre2 = 3 * subdiv_step2;
    float pre4 = 6 * subdiv_step2;
    float pre5 = 6 * subdiv_step3;
    float tmp1x = -cp1X * 2 + cp2X;
    float tmp1y = -cp1Y * 2 + cp2Y;
    float tmp2x = (cp1X - cp2X) * 3 + 1;
    float tmp2y = (cp1Y - cp2Y) * 3 + 1;
    
    curves[0] = cp1X * pre1 + tmp1x * pre2 + tmp2x * subdiv_step3;
    curves[1] = cp1Y * pre1 + tmp1y * pre2 + tmp2y * subdiv_step3;
    curves[2] = tmp1x * pre4 + tmp2x * pre5;
    curves[3] = tmp1y * pre4 + tmp2y * pre5;
    curves[4] = tmp2x * pre5;
    curves[5] = tmp2y * pre5;
}

float DHCurveTimeline::getInterpolationPercent(float passTime) {
    if (curves[0] == CURVE_LINEAR) {
        return passTime / diffTime;
    }
    else if(curves[0] == CURVE_STEPPED) {
        return 0.f;
    }
    else {
        float percent = passTime / diffTime;;
        float dfx = curves[0];
        float dfy = curves[1];
        float ddfx = curves[2];
        float ddfy = curves[3];
        float dddfx = curves[4];
        float dddfy = curves[5];
        float x = dfx;
        float y = dfy;
        int i = CURVE_SEGMENTS - 2;
        
        while (1) {
            if (x >= percent) {
                float lastX = x - dfx;
                float lastY = y - dfy;
                return lastY + (y - lastY) * (percent - lastX) / (x - lastX);
            }
            if (i == 0) break;
            i--;
            dfx += ddfx;
            dfy += ddfy;
            ddfx += dddfx;
            ddfy += dddfy;
            x += dfx;
            y += dfy;
        }
        return y + (1 - y) * (percent - x) / (1 - x);
    }
}


DHBoneTransform::DHBoneTransform()
:m_boneIndex(-1)
,m_rotate(nullptr)
,m_translate(nullptr)
,m_scale(nullptr)
,m_flipX(nullptr)
,m_flipY(nullptr)
,m_rotateCount(0)
,m_translateCount(0)
,m_scaleCount(0)
,m_flipXCount(0)
,m_flipYCount(0) {
    
}

DHBoneTransform::DHBoneTransform(int boneIndex)
:m_boneIndex(boneIndex)
,m_rotate(nullptr)
,m_translate(nullptr)
,m_scale(nullptr)
,m_flipX(nullptr)
,m_flipY(nullptr)
,m_rotateCount(0)
,m_translateCount(0)
,m_scaleCount(0)
,m_flipXCount(0)
,m_flipYCount(0) {
    
}

DHBoneTransform::~DHBoneTransform() {
    DH_ARRAY_DELETE(m_rotate, m_rotateCount);
    DH_ARRAY_DELETE(m_translate, m_translateCount);
    DH_ARRAY_DELETE(m_scale, m_scaleCount);
    DH_ARRAY_DELETE(m_flipX, m_flipXCount);
    DH_ARRAY_DELETE(m_flipY, m_flipYCount);
}

void DHBoneTransform::createRotationTimeLine(unsigned int rotateCount) {
    m_rotate = new DHRotateKeyFrame*[m_rotateCount = rotateCount];
}

void DHBoneTransform::createTranslationTimeLine(unsigned int translateCount) {
    m_translate = new DHTranslateKeyFrame*[m_translateCount = translateCount];
}

void DHBoneTransform::createScaleTimeLine(unsigned int scaleCount) {
    m_scale = new DHScaleKeyFrame*[m_scaleCount = scaleCount];
}

void DHBoneTransform::createFlipTimeLine(unsigned int flipCount, bool x) {
    if (x) {
        m_flipX = new DHFlipKeyFrame*[m_flipXCount = flipCount];
    }
    else {
        m_flipY = new DHFlipKeyFrame*[m_flipYCount = flipCount];
    }
}

DHRotateKeyFrame* DHBoneTransform::createRotationKeyFrame(unsigned int frameIndex) {
    return m_rotate[frameIndex] = new DHRotateKeyFrame();
}

DHTranslateKeyFrame* DHBoneTransform::createTranslationKeyFrame(unsigned int frameIndex) {
    return m_translate[frameIndex] = new DHTranslateKeyFrame();
}

DHScaleKeyFrame* DHBoneTransform::createScaleKeyFrame(unsigned int frameIndex) {
    return m_scale[frameIndex] = new DHScaleKeyFrame();
}

DHFlipKeyFrame* DHBoneTransform::createFlipKeyFrame(unsigned int frameIndex, bool x) {
    if (x) {
        return m_flipX[frameIndex] = new DHFlipKeyFrame();
    }
    else {
        return m_flipY[frameIndex] = new DHFlipKeyFrame();
    }
}

float DHBoneTransform::updateInfo() {
    DH_UPDATE_DIFF_TIME(m_rotate, m_rotateCount)
    DH_UPDATE_DIFF_TIME(m_translate, m_translateCount)
    DH_UPDATE_DIFF_TIME(m_scale, m_scaleCount)
    
    float maxs = 0.f;
    DH_GET_DURATION(m_rotate, m_rotateCount, maxs)
    DH_GET_DURATION(m_translate, m_translateCount, maxs)
    DH_GET_DURATION(m_scale, m_scaleCount, maxs)
    DH_GET_DURATION(m_flipX, m_flipXCount, maxs)
    DH_GET_DURATION(m_flipY, m_flipYCount, maxs)
    
    return maxs;
}

void DHBoneTransform::applyTo(cocos2d::DHSkeletonAnimation *owner, float time, float alpha) {
    DHBone* bone = owner->getBoneByIndex(m_boneIndex);
    
    if (m_rotate && m_rotate[0]->time <= time) {
        float amount;
        if (m_rotate[m_rotateCount - 1]->time <= time) {
            amount = m_rotate[m_rotateCount - 1]->angle;
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_rotate, m_rotateCount, time, frameIndex);
            DHRotateKeyFrame* frames = m_rotate[frameIndex];
            DHRotateKeyFrame* lastFrame = m_rotate[frameIndex - 1];
            float percent = lastFrame->getInterpolationPercent(time - lastFrame->time);
            amount = frames->angle - lastFrame->angle;
            
            while (amount > 180) {
                amount -= 360;
            }
            while (amount < -180) {
                amount += 360;
            }
            
            amount = lastFrame->angle + amount * percent;
        }
        
        while (amount > 180) {
            amount -= 360;
        }
        while (amount < -180) {
            amount += 360;
        }
        
        bone->m_rotation += amount * alpha;
    }
    
    if (m_translate && m_translate[0]->time <= time) {
        float x, y;
        if (m_translate[m_translateCount - 1]->time <= time) {
            DHTranslateKeyFrame* frame = m_translate[m_translateCount -1];
            x = frame->x;
            y = frame->y;
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_translate, m_translateCount, time, frameIndex)
            DHTranslateKeyFrame* frames = m_translate[frameIndex];
            DHTranslateKeyFrame* lastFrame = m_translate[frameIndex - 1];
            float percent = lastFrame->getInterpolationPercent(time - lastFrame->time);
            x = lastFrame->x + (frames->x - lastFrame->x) * percent;
            y = lastFrame->y + (frames->y - lastFrame->y) * percent;
        }
        bone->m_x += x * alpha;
        bone->m_y += y * alpha;
    }
    
    if (m_scale && m_scale[0]->time <= time) {
        float scaleX, scaleY;
        if (m_scale[m_scaleCount - 1]->time <= time) {
            DHScaleKeyFrame* frame = m_scale[m_scaleCount -1];
            scaleX = frame->scaleX;
            scaleY = frame->scaleY;
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_scale, m_scaleCount, time, frameIndex)
            DHScaleKeyFrame* frames = m_scale[frameIndex];
            DHScaleKeyFrame* lastFrame = m_scale[frameIndex - 1];
            float percent = lastFrame->getInterpolationPercent(time - lastFrame->time);
            scaleX = lastFrame->scaleX + (frames->scaleX - lastFrame->scaleX) * percent;
            scaleY = lastFrame->scaleY + (frames->scaleY - lastFrame->scaleY) * percent;
        }
        if (owner->getData()->getVersion() < 2000) {
            bone->m_scaleX += (scaleX - 1.f) * alpha;
            bone->m_scaleY += (scaleY - 1.f) * alpha;
        }
        else {
            bone->m_scaleX += (scaleX - 1.f) * bone->m_data->m_scaleX * alpha;
            bone->m_scaleY += (scaleY - 1.f) * bone->m_data->m_scaleY * alpha;
        }
    }
    
    if (m_flipX && m_flipX[0]->time <= time) {
        bool flipX = false;
        if (m_flipX[m_flipXCount - 1]->time <= time) {
            DHFlipKeyFrame* frame = m_flipX[m_flipXCount -1];
            flipX = frame->flip;
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_flipX, m_flipXCount, time, frameIndex)
            DHFlipKeyFrame* lastFrame = m_flipX[frameIndex - 1];
            flipX = lastFrame->flip;
        }
        bone->m_flipX = flipX;
    }
    
    if (m_flipY && m_flipY[0]->time <= time) {
        bool flipY = false;
        if (m_flipY[m_flipYCount - 1]->time <= time) {
            DHFlipKeyFrame* frame = m_flipY[m_flipYCount -1];
            flipY = frame->flip;
        }
        else {
            int frameIndex;
            DH_BINARY_SEARCH(m_flipY, m_flipYCount, time, frameIndex)
            DHFlipKeyFrame* lastFrame = m_flipY[frameIndex - 1];
            flipY = lastFrame->flip;
        }
        bone->m_flipY = flipY;
    }
}

NS_CC_END