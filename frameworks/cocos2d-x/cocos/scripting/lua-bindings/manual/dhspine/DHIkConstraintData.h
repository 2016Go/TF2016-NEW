//
//  DHIkConstraintData.h
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#ifndef __MyTest__DHIkConstraintData__
#define __MyTest__DHIkConstraintData__

#include "DHBoneData.h"

NS_CC_BEGIN

class DHIkConstraintData : public Ref {
    
public:
    DHIkConstraintData(unsigned int bonesCount);
    
    static DHIkConstraintData* create(unsigned int bonesCount);
    
    ~DHIkConstraintData();
    
public:
    unsigned int m_index;
    
    unsigned int m_bonesCount;
    DHBoneData** m_bones;
    
    DHBoneData* m_target;
    int m_bendDirection;
    float m_mix;
    
protected:
    DHIkConstraintData();
    
};

NS_CC_END


#endif /* defined(__MyTest__DHIkConstraintData__) */
