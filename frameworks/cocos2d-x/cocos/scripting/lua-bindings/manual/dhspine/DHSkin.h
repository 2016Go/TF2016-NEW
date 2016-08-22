//
//  DHSkin.h
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#ifndef __dhspine__DHSkin__
#define __dhspine__DHSkin__

#include "DHAttachment.h"
#include "DHDictionary.h"

NS_CC_BEGIN

struct DHSkinSlot {
    int slotIndex;
    DHDictionary* attachmentMap;
    
    static bool cmp(const DHSkinSlot* x,const DHSkinSlot* y) {
        return x->slotIndex < y->slotIndex;
    }
};

class DHSkin : public Ref {
    
public:
    DHSkin(unsigned int slotCount);
    
    ~DHSkin();
    
    static DHSkin* create(unsigned int slotCount);
    
    void createSkinSlot(int index, int slotIndex);
    
    void updateInfo();
    
    void addAttachment(int index, const char* attachmentName, DHAttachment* attachment);
    
    DHAttachment* getAttachment(int slotIndex, const char* attachmentName);
    
protected:
    DHSkin();
    
private:
    const unsigned int m_slotCount;
    DHSkinSlot** m_slots;
};

NS_CC_END

#endif /* defined(__dhspine__DHSkin__) */
