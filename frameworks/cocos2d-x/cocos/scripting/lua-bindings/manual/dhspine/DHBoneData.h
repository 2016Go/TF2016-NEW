//
//  DHBoneData.h
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#ifndef __dhspine__DHBoneData__
#define __dhspine__DHBoneData__

#include "DHGlobal.h"

NS_CC_BEGIN

class DHBone;

class DHBoneData : public Ref {
    
public:
    DHBoneData();
    
    ~DHBoneData();
    
    DH_CREATE_FUNC(DHBoneData);
    
public:
    int m_index;
	int m_parentIndex;
	float m_length;
	float m_x, m_y;
	float m_rotation;
	float m_scaleX, m_scaleY;
	bool m_inheritScale, m_inheritRotation;
    bool m_flipX, m_flipY;
};

NS_CC_END

#endif /* defined(__dhspine__DHBoneData__) */
