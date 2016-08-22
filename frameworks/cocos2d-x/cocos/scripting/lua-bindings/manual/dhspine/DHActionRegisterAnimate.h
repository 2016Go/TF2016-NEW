//
//  DHActionRegisterAnimate.hpp
//  cocos2d_lua_bindings
//
//  Created by youbin on 16/4/14.
//
//

#ifndef DHActionRegisterAnimate_h
#define DHActionRegisterAnimate_h

#include "DHGlobal.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

class DHActionRegisterAnimate : public ActionInstant
{
public:
    static DHActionRegisterAnimate* create(const std::string& name, unsigned int loop = 1, bool autoRemove = true);
    
    virtual void update(float time) override;
    
protected:
    DHActionRegisterAnimate();
    virtual ~DHActionRegisterAnimate();
    
    bool initWithRegister(const std::string& name, int loop, bool autoRemove);
    
protected:
    std::string m_name;
    int m_loop;
    bool m_autoRemove;
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(DHActionRegisterAnimate);
};

NS_CC_END

#endif /* DHActionRegisterAnimate_h */
