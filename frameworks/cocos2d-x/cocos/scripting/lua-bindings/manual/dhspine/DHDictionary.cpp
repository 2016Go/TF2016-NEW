//
//  DHDictionary.cpp
//  dhspine
//
//  Created by youbin on 13-10-10.
//
//

#include "DHDictionary.h"

NS_CC_BEGIN

DHDictElement::DHDictElement() {
    
}

DHDictElement::DHDictElement(const char* srcKey, Ref* srcValue) {
    const char* pStart = srcKey;
    size_t len = strlen(srcKey);
    if (len > DH_MAX_KEY_LEN )
    {
        char* pEnd = (char*)&srcKey[len - 1];
        pStart = pEnd - (DH_MAX_KEY_LEN - 1);
    }
    strcpy(key, pStart);
    
    value = srcValue;
    memset(&hh, 0, sizeof(hh));
}

//

DHDictionary::DHDictionary()
:m_elements(nullptr) {
    
}

DHDictionary::~DHDictionary() {
    removeAll();
}

int DHDictionary::getCount() const {
    return HASH_COUNT(m_elements);
}

void DHDictionary::insert(const char *key, Ref *value) {
    DHDictElement *element = nullptr;
    HASH_FIND_STR(m_elements, key, element);
    if (element == nullptr) {
        insertUnSafe(key, value);
    }
    else if(element->value != value) {
        Ref* conflictValue = element->value;
        element->value = value;
        CC_SAFE_RETAIN(element->value);
        CC_SAFE_RELEASE(conflictValue);
    }
}

void DHDictionary::insertUnSafe(const char *key, Ref *value) {
    DHDictElement* element = new DHDictElement(key, value);
    HASH_ADD_STR(m_elements, key, element);
    CC_SAFE_RETAIN(value);
}

Ref* DHDictionary::find(const char *key) {
    DHDictElement *element = nullptr;
    HASH_FIND_STR(m_elements, key, element);
    return element ? element->value : nullptr;
}

DHDictElement* DHDictionary::getRandomElement() {
    float r = CCRANDOM_0_1();
    
    if (r == 1) {
        r = 0;
    }
    
    DHDictElement* element, * tmp;
    int index = r * HASH_COUNT(m_elements);
    
    HASH_ITER(hh, m_elements, element, tmp)
    {
        if (index-- == 0) {
            return element;
        }
    }
    
    return nullptr;
}

void DHDictionary::remove(const char *key) {
    DHDictElement *element = nullptr;
    HASH_FIND_STR(m_elements, key, element);
    if (element) {
        removeForElememt(element);
    }
}

void DHDictionary::removeForElememt(cocos2d::DHDictElement *element) {
    CC_SAFE_RELEASE(element->value);
    HASH_DEL(m_elements, element);
    CC_SAFE_DELETE(element);
}

void DHDictionary::removeAll() {
    DHDictElement *element, *tmp;
    HASH_ITER(hh, m_elements, element, tmp) {
        removeForElememt(element);
    }
}

NS_CC_END