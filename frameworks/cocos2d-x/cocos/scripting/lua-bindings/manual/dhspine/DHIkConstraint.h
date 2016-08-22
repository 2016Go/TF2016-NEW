//
//  IkConstraint.h
//  MyTest
//
//  Created by youbin on 14-12-30.
//
//

#ifndef __MyTest__IkConstraint__
#define __MyTest__IkConstraint__

#include "DHIkConstraintData.h"

NS_CC_BEGIN

class DHSkeleton;

class DHIkConstraint {
    
    friend class DHSkeleton;
    friend class DHIkConstraintTransform;
    
public:
    DHIkConstraint(DHIkConstraintData* const data, DHSkeleton* const skeleton);
    
    ~DHIkConstraint();
    
    void apply();
    
    void setToSetupPose();
    
protected:
    DHIkConstraint();
    
    void apply1(DHBone* bone, float targetX, float targetY, float alpha);
    
    void apply2(DHBone* parent, DHBone* child, float targetX, float targetY, int bendDirection, float alpha);
    
private:
    
    DHIkConstraintData* const m_data;
    DHSkeleton* const m_skeleton;
    
    int m_bonesCount;
    DHBone** m_bones;
    
    DHBone* m_target;
    int m_bendDirection;
    float m_mix;
};

NS_CC_END

#endif /* defined(__MyTest__IkConstraint__) */
