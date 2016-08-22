//
//  DHIkConstraintData.cpp
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#include "DHIkConstraintData.h"

NS_CC_BEGIN

DHIkConstraintData::DHIkConstraintData()
:m_bendDirection(1)
,m_mix(1.f)
,m_bones(nullptr)
,m_index(0) {
    
}

DHIkConstraintData::DHIkConstraintData(unsigned int bonesCount)
:m_bendDirection(1)
,m_mix(1.f)
,m_index(0) {
    m_bones = new DHBoneData*[m_bonesCount = bonesCount];
}

DHIkConstraintData::~DHIkConstraintData() {
    CC_SAFE_DELETE_ARRAY(m_bones);
}

DHIkConstraintData* DHIkConstraintData::create(unsigned int bonesCount) {
    DHIkConstraintData* data = new DHIkConstraintData(bonesCount);
    data->autorelease();
    return data;
}

NS_CC_END