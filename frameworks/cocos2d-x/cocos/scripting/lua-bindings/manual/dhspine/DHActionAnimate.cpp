//
//  DHActionAnimate.cpp
//  cocos2d_lua_bindings
//
//  Created by youbin on 15/12/11.
//
//

#include "DHActionAnimate.h"

NS_CC_BEGIN

DHActionAnimate::DHActionAnimate()
:m_lastElapsed(0.f) {
    
}

DHActionAnimate::~DHActionAnimate() {
    
}

DHActionAnimate* DHActionAnimate::create(DHSkeletonAnimation* target, const std::string &name, int loop, float mixDuration) {
    DHActionAnimate* action = new (std::nothrow) DHActionAnimate();
    
    loop = loop == -1 ? 10000000 : loop;
    if (action) {
        if (action->initWithInfo(target, name, loop, mixDuration)) {
            action->autorelease();
        }
        else {
            delete action;
            action = nullptr;
        }
    }
    
    return action;
}

bool DHActionAnimate::initWithInfo(DHSkeletonAnimation* target, const std::string& name, unsigned int loop, float mixDuration) {
    auto data = target->getData();
    if (!data) {
        return false;
    }
    auto animData = data->findAnimaion(name.c_str());
    if (!animData) {
        return false;
    }
    if (!initWithDuration(animData->getDuration() * loop / target->getTimeScale())) {
        return false;
    }
    
    m_name = name;
    m_loop = loop;
    m_mixDuration = mixDuration;
    return true;
}

void DHActionAnimate::startWithTarget(Node *target) {
    ActionInterval::startWithTarget(target);
    DHSkeletonAnimation* anim = dynamic_cast<DHSkeletonAnimation*>(target);
    if (anim) {
        anim->playAnimation(m_name.c_str(), m_loop, m_mixDuration);
    }
}

void DHActionAnimate::update(float p) {
    float dt = getDuration() * p - m_lastElapsed;
    if (_target && !_target->isScheduled(CC_SCHEDULE_SELECTOR(DHSkeletonAnimation::update))) {
        _target->update(dt);
    }
    m_lastElapsed = p * getDuration();
}

NS_CC_END