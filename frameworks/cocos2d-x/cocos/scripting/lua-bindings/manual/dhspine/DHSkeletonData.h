//
//  DHSkeletonData.h
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#ifndef __dhspine__DHSkeletonData__
#define __dhspine__DHSkeletonData__

#include "DHBoneData.h"
#include "DHSlotData.h"
#include "DHSkin.h"
#include "DHAnimationData.h"
#include "DHBone.h"
#include "DHSlot.h"
#include "DHDictionary.h"
#include "DHIkConstraintData.h"
#include "DHIkConstraint.h"

NS_CC_BEGIN

class DHSkeletonData : public Ref {
    
public:
    friend class DHSkeletonDataCache;
    
    DHSkeletonData();
    
    ~DHSkeletonData();
    
    DH_CREATE_FUNC(DHSkeletonData);
    
    void createBoneDataArray(unsigned int boneCount);
    
    void createSlotDataArray(unsigned int slotCount);
    
    DHBoneData* createBoneData(unsigned int index, const char* boneName);
    
    DHSlotData* createSlotData(unsigned int index, const char* slotName, const char* attachmentName);
    
    DHSkin* createSkin(const char* skinName, unsigned int slotCount);
    
    DHAnimationData* createAnimation(const char* animName, unsigned int btCount, unsigned int stCount);
    
    DHEvent* createEvent(const char* evnetName);
    
    void createIkConstraintDataArray(unsigned int ikCount);
    
    DHIkConstraintData* createIkConstraintData(unsigned int index, const char* ikName, unsigned int bonesCount);
    
    DHBone** newBones();
    
    DHSlot** newSlots(DHSkeleton* owner);
    
    DHIkConstraint** newIkConstraints(DHSkeleton* owner);
    
    DHBoneData* findBone(const char* boneName);
    
    DHSlotData* findSlot(const char* slotName);
    
    DHSkin* findSkin(const char* skinName);
    
    DHIkConstraintData* findIkConstraint(const char* ikName);
    
    DHAnimationData* findAnimaion(const char* animName);
    
    const char* getRandomAnimationName();
    
    std::vector<const char*> getAllAnimationName();
    
    DHEvent* findEvent(const char* eventName);
    
    int findBoneIndex(const char* boneName);
    
    int findSlotIndex(const char* slotName);
    
    DHAttachment* getDefaultAttachment(int slotIndex, const char *attachmentName);
    
    DHSkin* getDefaultSkin() {
        return m_defaultSkin;
    }
    
    unsigned int getBoneCount() const {
        return m_boneCount;
    }
    
    unsigned int getSlotCount() const {
        return m_slotCount;
    }
    
    unsigned int getIkConstraintCount() const {
        return m_ikCount;
    }
    
    void addSoundToSet(const std::string& fileName) {
        m_soundSet.insert(fileName);
    }
    
    const std::set<std::string>& getSoundSet() {
        return m_soundSet;
    }
    
    void setVersion(const char* versionInfo);
    
    int getVersion() {
        return m_version;
    }
    
    void setName(const std::string& name) {
        m_name = name;
    }
    
    const std::string& getName() {
        return m_name;
    }
    
private:
    unsigned int m_boneCount;
    DHBoneData** m_bones;
    
    unsigned int m_slotCount;
    DHSlotData** m_slots;
    
    DHSkin* m_defaultSkin;
    
    unsigned int m_ikCount;
    DHIkConstraintData** m_ikConstraint;

    DHDictionary* m_boneMap;
    DHDictionary* m_slotMap;
    DHDictionary* m_skinMap;
    DHDictionary* m_animMap;
    DHDictionary* m_eventMap;
    DHDictionary* m_ikConstraintMap;
    
    std::set<std::string> m_soundSet;
    
    int m_version;
    std::string m_name;
};

NS_CC_END

#endif /* defined(__dhspine__DHSkeletonData__) */
