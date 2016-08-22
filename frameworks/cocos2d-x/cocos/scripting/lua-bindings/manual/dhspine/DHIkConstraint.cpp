//
//  IkConstraint.cpp
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#include "DHIkConstraint.h"
#include "DHBone.h"
#include "DHSkeleton.h"

NS_CC_BEGIN

DHIkConstraint::DHIkConstraint()
:m_data(nullptr)
,m_skeleton(nullptr)
,m_bones(nullptr) {
    
}

DHIkConstraint::DHIkConstraint(DHIkConstraintData* const data, DHSkeleton* const skeleton)
:m_data(data)
,m_skeleton(skeleton) {
    m_bonesCount = m_data->m_bonesCount;
    m_bones = new DHBone*[m_bonesCount];
    
    for (int i = 0; i < m_bonesCount; ++i) {
        m_bones[i] = m_skeleton->getBoneByIndex(m_data->m_bones[i]->m_index);
    }
    
    m_target = m_skeleton->getBoneByIndex(m_data->m_target->m_index);
    
    setToSetupPose();
}

DHIkConstraint::~DHIkConstraint() {
    CC_SAFE_DELETE_ARRAY(m_bones);
}

void DHIkConstraint::setToSetupPose() {
    m_bendDirection = m_data->m_bendDirection;
    m_mix = m_data->m_mix;
}

void DHIkConstraint::apply() {
    switch (m_bonesCount) {
        case 1:
            apply1(m_bones[0], m_target->m_worldX, m_target->m_worldY, m_mix);
            break;
        case 2:
            apply2(m_bones[0], m_bones[1], m_target->m_worldX, m_target->m_worldY, m_bendDirection, m_mix);
            break;
        default:
            break;
    }
}

void DHIkConstraint::apply1(cocos2d::DHBone *bone, float targetX, float targetY, float alpha) {
    float parentRotation = (!bone->getData()->m_inheritRotation || !bone->m_parent) ? 0 : bone->m_parent->m_worldRotation;
    float rotation = bone->m_rotation;
    float rotationIK = atan2f(targetY - bone->m_worldY, targetX - bone->m_worldX) * RAD_DEG - parentRotation;
    bone->m_rotationIK = rotation + (rotationIK - rotation) * alpha;
}

void DHIkConstraint::apply2(cocos2d::DHBone *parent, cocos2d::DHBone *child, float targetX, float targetY, int bendDirection, float alpha) {
    float positionX, positionY, childX, childY, offset, len1, len2, cosDenom, cos, childAngle, adjacent, opposite, parentAngle, rotation;
    DHBone* parentParent;
    float childRotation = child->m_rotation, parentRotation = parent->m_rotation;
    if (alpha == 0) {
        child->m_rotationIK = childRotation;
        parent->m_rotationIK = parentRotation;
        return;
    }
    parentParent = parent->m_parent;
    if (parentParent) {
        parentParent->worldToLocal(targetX, targetY, &positionX, &positionY);
        targetX = (positionX - parent->m_x) * parentParent->m_worldScaleX;
        targetY = (positionY - parent->m_y) * parentParent->m_worldScaleY;
    } else {
        targetX -= parent->m_x;
        targetY -= parent->m_y;
    }
    if (child->m_parent == parent) {
        positionX = child->m_x;
        positionY = child->m_y;
    } else {
        child->m_parent->localToWorld(child->m_x, child->m_y, &positionX, &positionY);
        parent->worldToLocal(positionX, positionY, &positionX, &positionY);
    }
    childX = positionX * parent->m_worldScaleX;
    childY = positionY * parent->m_worldScaleY;
    offset = atan2f(childY, childX);
    len1 = sqrtf(childX * childX + childY * childY);
    len2 = child->getData()->m_length * child->m_worldScaleX;
    /* Based on code by Ryan Juckett with permission: Copyright (c) 2008-2009 Ryan Juckett, http://www.ryanjuckett.com/ */
    cosDenom = 2 * len1 * len2;
    if (cosDenom < 0.0001f) {
        child->m_rotationIK = childRotation + (atan2f(targetY, targetX) * RAD_DEG - parentRotation - childRotation) * alpha;
        return;
    }
    cos = (targetX * targetX + targetY * targetY - len1 * len1 - len2 * len2) / cosDenom;
    if (cos < -1)
        cos = -1;
    else if (cos > 1) /**/
        cos = 1;
    childAngle = acosf(cos) * bendDirection;
    adjacent = len1 + len2 * cos;
    opposite = len2 * sinf(childAngle);
    parentAngle = atan2f(targetY * adjacent - targetX * opposite, targetX * adjacent + targetY * opposite);
    rotation = (parentAngle - offset) * RAD_DEG - parentRotation;
    if (rotation > 180)
        rotation -= 360;
    else if (rotation < -180) /**/
        rotation += 360;
    parent->m_rotationIK = parentRotation + rotation * alpha;
    rotation = (childAngle + offset) * RAD_DEG - childRotation;
    if (rotation > 180)
        rotation -= 360;
    else if (rotation < -180) /**/
        rotation += 360;
    child->m_rotationIK = childRotation + (rotation + parent->m_worldRotation - child->m_parent->m_worldRotation) * alpha;
}

NS_CC_END