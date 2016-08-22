//
//  DHSkin.cpp
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#include "DHSkin.h"

#include <algorithm>

NS_CC_BEGIN

DHSkin::DHSkin()
:m_slotCount(0)
,m_slots(nullptr) {
    
}

DHSkin::DHSkin(unsigned int slotCount)
:m_slotCount(slotCount) {
    m_slots = new DHSkinSlot*[m_slotCount];
}

DHSkin::~DHSkin() {
    DH_ARRAY_FOREACH(m_slotCount) {
        CC_SAFE_DELETE(m_slots[i]->attachmentMap);
        delete m_slots[i];
    }
    delete [] m_slots;
}

DHSkin* DHSkin::create(unsigned int slotCount) {
    DHSkin* skin = new DHSkin(slotCount);
    skin->autorelease();
    return skin;
}

void DHSkin::createSkinSlot(int index, int slotIndex) {
    m_slots[index] = new DHSkinSlot();
    m_slots[index]->slotIndex = slotIndex;
    m_slots[index]->attachmentMap = new DHDictionary();
}

void DHSkin::addAttachment(int index, const char* attachmentName, DHAttachment* attachment) {
    if (attachment) {
        m_slots[index]->attachmentMap->insertUnSafe(attachmentName, attachment);
    }
}

void DHSkin::updateInfo() {
    std::sort(m_slots, m_slots + m_slotCount, DHSkinSlot::cmp);
}

DHAttachment* DHSkin::getAttachment(int slotIndex, const char *attachmentName) {
    if (m_slotCount) {
        DHDictionary* attachmentMap = nullptr;
        
        int l = 0;
        int r = m_slotCount - 1;
        while (l <= r ) {
            int mid = (l + r) >> 1;
            if (m_slots[mid]->slotIndex < slotIndex) {
                l = mid + 1;
            }
            else if (m_slots[mid]->slotIndex > slotIndex) {
                r = mid - 1;
            }
            else {
                attachmentMap = m_slots[mid]->attachmentMap;
                break;
            }
        }
        
        return attachmentMap ? (DHAttachment*)attachmentMap->find(attachmentName) : nullptr;
    }
    return nullptr;
}

NS_CC_END