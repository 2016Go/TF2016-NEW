//
//  DHSlotData.cpp
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#include "DHSlotData.h"

NS_CC_BEGIN

DHSlotData::DHSlotData() {
    
}

DHSlotData::DHSlotData(const char* name, const char* attachmentName) {
    m_name = DHStrCopy(name);
    m_attachmentName = DHStrCopy(attachmentName);
}

DHSlotData* DHSlotData::create(const char* name, const char* attachmentName) {
    DHSlotData* data = new DHSlotData(name, attachmentName);
    data->autorelease();
    return data;
}

DHSlotData::~DHSlotData() {
    DHStrFree(m_name);
    DHStrFree(m_attachmentName);
}

NS_CC_END