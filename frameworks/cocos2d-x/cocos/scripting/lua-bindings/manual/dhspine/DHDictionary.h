//
//  DHDictionary.h
//  dhspine
//
//  Created by youbin on 13-10-10.
//
//

#ifndef __dhspine__DHDictionary__
#define __dhspine__DHDictionary__

#include "cocos2d.h"
#include "base/uthash.h"

NS_CC_BEGIN

#define   DH_MAX_KEY_LEN   256

struct DHDictElement {
    
    DHDictElement(const char* srcKey, Ref* srcValue);
    
    char key[DH_MAX_KEY_LEN];
    Ref* value;
    UT_hash_handle hh;
    
private:
    DHDictElement();
};

class DHDictionary {
    
public:
    DHDictionary();
    
    ~DHDictionary();
    
    int getCount() const ;
    
    void insert(const char* key, Ref* value);
    
    void insertUnSafe(const char* key, Ref* value);
    
    Ref* find(const char* key);
    
    DHDictElement* getRandomElement();
    
    void remove(const char* key);
    
    void removeForElememt(DHDictElement* element);
    
    void removeAll();
    
    DHDictElement* getHashHead() const {
        return m_elements;
    }
    
private:
    DHDictElement* m_elements;
    
};

#define DH_DICT_FOREACH(__dict__, __el__) \
DHDictElement* temp = NULL; \
if (__dict__) \
    HASH_ITER(hh, (__dict__)->getHashHead(), __el__, temp)

NS_CC_END

#endif /* defined(__dhspine__DHDictionary__) */
