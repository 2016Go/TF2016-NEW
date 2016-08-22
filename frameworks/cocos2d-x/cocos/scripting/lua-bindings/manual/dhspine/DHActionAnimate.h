//
//  DHActionAnimate.hpp
//  cocos2d_lua_bindings
//
//  Created by youbin on 15/12/11.
//
//

#ifndef DHActionAnimate_h
#define DHActionAnimate_h

#include "DHGlobal.h"
#include "DHSkeletonAnimation.h"

NS_CC_BEGIN

class DHActionAnimate : public ActionInterval
{
public:
    static DHActionAnimate* create(DHSkeletonAnimation* target, const std::string& name, int loop = 1, float mixDuration = 0.1f);
    
    virtual void startWithTarget(Node *target) override;
    
    virtual void update(float p) override;
    
protected:
    DHActionAnimate();
    virtual ~DHActionAnimate();
    
    bool initWithInfo(DHSkeletonAnimation* target, const std::string& name, unsigned int loop, float mixDuration);
    
protected:
    std::string m_name;
    int m_loop;
    float m_mixDuration;
    float m_lastElapsed;
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(DHActionAnimate);
};

NS_CC_END

#endif /* DHActionAnimate_h */
