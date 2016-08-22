//
//  DHActionRegisterAnimate.cpp
//  cocos2d_lua_bindings
//
//  Created by youbin on 16/4/14.
//
//

#include "DHActionRegisterAnimate.h"

//
//  DHActionAnimate.cpp
//  cocos2d_lua_bindings
//
//  Created by youbin on 15/12/11.
//
//

#include "DHActionAnimate.h"

NS_CC_BEGIN

DHActionRegisterAnimate::DHActionRegisterAnimate() {
    
}

DHActionRegisterAnimate::~DHActionRegisterAnimate() {
    
}

DHActionRegisterAnimate* DHActionRegisterAnimate::create(const std::string& name, unsigned int loop, bool autoRemove) {
    DHActionRegisterAnimate* action = new (std::nothrow) DHActionRegisterAnimate();
    
    if (action) {
        if (action->initWithRegister(name, loop, autoRemove)) {
            action->autorelease();
        }
        else {
            delete action;
            action = nullptr;
        }
    }
    
    return action;
}

bool DHActionRegisterAnimate::initWithRegister(const std::string& name, int loop, bool autoRemove) {
    m_name = name;
    m_loop = loop;
    m_autoRemove = autoRemove;
    return true;
}

void DHActionRegisterAnimate::update(float time) {
    CC_UNUSED_PARAM(time);
    DHSkeletonAnimation* anim = dynamic_cast<DHSkeletonAnimation*>(_target);
    if (anim) {
        anim->registerAnimation(m_name.c_str(), m_loop, m_autoRemove);
    }
}

NS_CC_END