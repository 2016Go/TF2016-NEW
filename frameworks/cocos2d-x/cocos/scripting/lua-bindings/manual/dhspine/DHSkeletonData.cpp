//
//  DHSkeletonData.cpp
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#include "DHSkeletonData.h"
#include "DHSkeleton.h"
#include "DHSkeletonDataCache.h"

NS_CC_BEGIN

DHSkeletonData::DHSkeletonData()
:m_defaultSkin(nullptr)
,m_boneCount(0)
,m_slotCount(0)
,m_ikCount(0)
,m_bones(nullptr)
,m_slots(nullptr)
,m_ikConstraint(nullptr) {
    m_boneMap = new DHDictionary();
    m_slotMap = new DHDictionary();
    m_skinMap = new DHDictionary();
    m_animMap = new DHDictionary();
    m_eventMap = new DHDictionary();
    m_ikConstraintMap = new DHDictionary();
}

DHSkeletonData::~DHSkeletonData() {
    CC_SAFE_RELEASE(m_defaultSkin);
    CC_SAFE_DELETE(m_boneMap);
    CC_SAFE_DELETE(m_slotMap);
    CC_SAFE_DELETE(m_skinMap);
    CC_SAFE_DELETE(m_animMap);
    CC_SAFE_DELETE(m_eventMap);
    CC_SAFE_DELETE(m_ikConstraintMap);
    
    CC_SAFE_DELETE_ARRAY(m_bones);
    CC_SAFE_DELETE_ARRAY(m_slots);
    CC_SAFE_DELETE_ARRAY(m_ikConstraint);
    
    SDC->removeRenderTextureCache(m_name);
}

void DHSkeletonData::createBoneDataArray(unsigned int boneCount) {
    m_bones = new DHBoneData*[ m_boneCount = boneCount];
}

void DHSkeletonData::createSlotDataArray(unsigned int slotCount) {
    m_slots = new DHSlotData*[ m_slotCount = slotCount];
}

DHBoneData* DHSkeletonData::createBoneData(unsigned int index, const char *boneName) {
    m_bones[index] = DHBoneData::create();
    m_boneMap->insertUnSafe(boneName, m_bones[index]);
    return m_bones[index];
}

DHSlotData* DHSkeletonData::createSlotData(unsigned int index, const char *slotName, const char* attachmentName) {
    m_slots[index] = DHSlotData::create(slotName, attachmentName);
    m_slotMap->insertUnSafe(slotName, m_slots[index]);
    return m_slots[index];
}

DHSkin* DHSkeletonData::createSkin(const char *skinName, unsigned int slotCount) {
    DHSkin* skin = DHSkin::create(slotCount);
    if (strcmp(skinName, "default") == 0) {
        m_defaultSkin = skin;
        m_defaultSkin->retain();
    } else {
        m_skinMap->insertUnSafe(skinName, skin);
    }
    return skin;
}

DHAnimationData* DHSkeletonData::createAnimation(const char *animName, unsigned int btCount, unsigned int stCount) {
    DHAnimationData* anim = DHAnimationData::create(btCount, stCount);
    m_animMap->insertUnSafe(animName, anim);
    return anim;
}

DHEvent* DHSkeletonData::createEvent(const char* evnetName) {
    DHEvent *event = DHEvent::create();
    m_eventMap->insertUnSafe(evnetName, event);
    return event;
}

void DHSkeletonData::createIkConstraintDataArray(unsigned int ikCount) {
    m_ikConstraint = new DHIkConstraintData*[m_ikCount = ikCount];
}

DHIkConstraintData* DHSkeletonData::createIkConstraintData(unsigned int index, const char* ikName, unsigned int bonesCount) {
    m_ikConstraint[index] = DHIkConstraintData::create(bonesCount);
    m_ikConstraintMap->insertUnSafe(ikName, m_ikConstraint[index]);
    return m_ikConstraint[index];
}

DHBone** DHSkeletonData::newBones() {
    DHBone** bones = new DHBone*[m_boneCount];
    DH_ARRAY_FOREACH(m_boneCount) {
        bones[i] = new DHBone(m_bones[i]);
        bones[i]->m_parent = m_bones[i]->m_parentIndex >= 0 ? bones[m_bones[i]->m_parentIndex] : nullptr;
    }
    return bones;
}

DHSlot** DHSkeletonData::newSlots(DHSkeleton* owner) {
    DHSlot** slots = new DHSlot*[m_slotCount];
    DH_ARRAY_FOREACH(m_slotCount) {
        slots[i] = new DHSlot(m_slots[i], owner);
        slots[i]->m_bone = owner->getBoneByIndex(m_slots[i]->m_boneIndex);
    }
    return slots;
}

DHIkConstraint** DHSkeletonData::newIkConstraints(DHSkeleton *owner) {
    DHIkConstraint** ikConstraint = new DHIkConstraint*[m_ikCount];
    DH_ARRAY_FOREACH(m_ikCount) {
        ikConstraint[i] = new DHIkConstraint(m_ikConstraint[i], owner);
    }
    return ikConstraint;
}

DHBoneData* DHSkeletonData::findBone(const char *boneName) {
    void* value = m_boneMap->find(boneName);
    if (value) {
        return (DHBoneData*)value;
    }
    return nullptr;
}

DHSlotData* DHSkeletonData::findSlot(const char *slotName) {
    void* value = m_slotMap->find(slotName);
    if (value) {
        return (DHSlotData*)value;
    }
    return nullptr;
}

DHSkin* DHSkeletonData::findSkin(const char *skinName) {
    if (!strcmp(skinName, "default")) {
        return m_defaultSkin;
    }
    
    void* value = m_skinMap->find(skinName);
    if (value) {
        return (DHSkin*)value;
    }
    return nullptr;
}

DHIkConstraintData* DHSkeletonData::findIkConstraint(const char* ikName) {
    void* value = m_ikConstraintMap->find(ikName);
    if (value) {
        return (DHIkConstraintData*)value;
    }
    return nullptr;
}

DHAnimationData* DHSkeletonData::findAnimaion(const char *animName) {
    void* value = m_animMap->find(animName);
    if (value) {
        return (DHAnimationData*)value;
    }
    CCLOGWARN("the animation(%s) is not find!",animName);
    return nullptr;
}

const char* DHSkeletonData::getRandomAnimationName() {
    DHDictElement* element = m_animMap->getRandomElement();
    if (element) {
        return element->key;
    }
    return nullptr;
}

std::vector<const char*> DHSkeletonData::getAllAnimationName() {
    std::vector<const char*> resVec;
    DHDictElement* element;
    DH_DICT_FOREACH(m_animMap, element) {
        resVec.push_back(element->key);
    }
    return resVec;
}

DHEvent* DHSkeletonData::findEvent(const char *eventName) {
    void* value = m_eventMap->find(eventName);
    if (value) {
        return (DHEvent*)value;
    }
    return nullptr;
}

int DHSkeletonData::findBoneIndex(const char *boneName) {
    DHBoneData* bone = findBone(boneName);
    return bone ? bone->m_index : -1;
}

int DHSkeletonData::findSlotIndex(const char *slotName) {
    DHSlotData* slot = findSlot(slotName);
    return slot ? slot->m_index : -1;
}

DHAttachment* DHSkeletonData::getDefaultAttachment(int slotIndex, const char *attachmentName) {
    return m_defaultSkin ? m_defaultSkin->getAttachment(slotIndex, attachmentName) : nullptr;
}

void DHSkeletonData::setVersion(const char* versionInfo) {
    m_version = 0;
    
    if (versionInfo) {
        size_t len = strlen(versionInfo);
        for (int i = 0; i < len; i++) {
            if (versionInfo[i] >= '0' && versionInfo[i] <= '9') {
                m_version *= 10;
                m_version += (versionInfo[i] - '0');
            }
        }
    }
}

NS_CC_END