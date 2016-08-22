#include "lua_cocos2dx_dhspine.hpp"
#include "DHSkeletonDataCache.h"
#include "DHSkeletonAnimation.h"
#include "DHSkeleton.h"
#include "DHAnimationInfo.h"
#include "DHBone.h"
#include "DHSkeletonData.h"
#include "DHSlot.h"
#include "DHActionAnimate.h"
#include "DHSlot.h"
#include "DHClippingSkeletonAnimation.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_cocos2dx_dhspine_DHBone_getWorldScaleX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getWorldScaleX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getWorldScaleX'", nullptr);
            return 0;
        }
        double ret = cobj->getWorldScaleX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getWorldScaleX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getWorldScaleX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getWorldScaleY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getWorldScaleY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getWorldScaleY'", nullptr);
            return 0;
        }
        double ret = cobj->getWorldScaleY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getWorldScaleY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getWorldScaleY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getX'", nullptr);
            return 0;
        }
        double ret = cobj->getX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getY'", nullptr);
            return 0;
        }
        double ret = cobj->getY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getRotation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getRotation'", nullptr);
            return 0;
        }
        double ret = cobj->getRotation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getRotation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_localToWorld(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_localToWorld'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        float* arg2;
        float* arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHBone:localToWorld");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHBone:localToWorld");

        #pragma warning NO CONVERSION TO NATIVE FOR float*
		ok = false;

        #pragma warning NO CONVERSION TO NATIVE FOR float*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_localToWorld'", nullptr);
            return 0;
        }
        cobj->localToWorld(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:localToWorld",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_localToWorld'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getScaleY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getScaleY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getScaleY'", nullptr);
            return 0;
        }
        double ret = cobj->getScaleY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getScaleY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getScaleY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getScaleX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getScaleX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getScaleX'", nullptr);
            return 0;
        }
        double ret = cobj->getScaleX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getScaleX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getScaleX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_worldToLocal(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_worldToLocal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        float* arg2;
        float* arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHBone:worldToLocal");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHBone:worldToLocal");

        #pragma warning NO CONVERSION TO NATIVE FOR float*
		ok = false;

        #pragma warning NO CONVERSION TO NATIVE FOR float*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_worldToLocal'", nullptr);
            return 0;
        }
        cobj->worldToLocal(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:worldToLocal",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_worldToLocal'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_setToSetupPose(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_setToSetupPose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_setToSetupPose'", nullptr);
            return 0;
        }
        cobj->setToSetupPose();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:setToSetupPose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_setToSetupPose'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_updateFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_updateFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        bool arg0;
        bool arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHBone:updateFollowAttachment");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.DHBone:updateFollowAttachment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_updateFollowAttachment'", nullptr);
            return 0;
        }
        cobj->updateFollowAttachment(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:updateFollowAttachment",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_updateFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_setRotation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_setRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHBone:setRotation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_setRotation'", nullptr);
            return 0;
        }
        cobj->setRotation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:setRotation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_setRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getData'", nullptr);
            return 0;
        }
        cocos2d::DHBoneData* ret = cobj->getData();
        object_to_luaval<cocos2d::DHBoneData>(tolua_S, "cc.DHBoneData",(cocos2d::DHBoneData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_setScaleY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_setScaleY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHBone:setScaleY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_setScaleY'", nullptr);
            return 0;
        }
        cobj->setScaleY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:setScaleY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_setScaleY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_setScaleX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_setScaleX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHBone:setScaleX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_setScaleX'", nullptr);
            return 0;
        }
        cobj->setScaleX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:setScaleX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_setScaleX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getFollowAttachmentChild(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getFollowAttachmentChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getFollowAttachmentChild'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getFollowAttachmentChild();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getFollowAttachmentChild",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getFollowAttachmentChild'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_updateWorldTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_updateWorldTransform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_updateWorldTransform'", nullptr);
            return 0;
        }
        cobj->updateWorldTransform();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:updateWorldTransform",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_updateWorldTransform'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_setX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_setX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHBone:setX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_setX'", nullptr);
            return 0;
        }
        cobj->setX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:setX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_setX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_setY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_setY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHBone:setY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_setY'", nullptr);
            return 0;
        }
        cobj->setY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:setY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_setY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_removeFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_removeFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_removeFollowAttachment'", nullptr);
            return 0;
        }
        cobj->removeFollowAttachment();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:removeFollowAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_removeFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_addFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_addFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cc.DHBone:addFollowAttachment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_addFollowAttachment'", nullptr);
            return 0;
        }
        cobj->addFollowAttachment(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:addFollowAttachment",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_addFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getWorldY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getWorldY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getWorldY'", nullptr);
            return 0;
        }
        double ret = cobj->getWorldY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getWorldY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getWorldY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_getWorldX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHBone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHBone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHBone_getWorldX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_getWorldX'", nullptr);
            return 0;
        }
        double ret = cobj->getWorldX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:getWorldX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_getWorldX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHBone_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHBone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DHBoneData* arg0;

        ok &= luaval_to_object<cocos2d::DHBoneData>(tolua_S, 2, "cc.DHBoneData",&arg0, "cc.DHBone:DHBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHBone_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::DHBone(arg0);
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.DHBone");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHBone:DHBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHBone_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dhspine_DHBone_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHBone)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHBone(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHBone");
    tolua_cclass(tolua_S,"DHBone","cc.DHBone","",nullptr);

    tolua_beginmodule(tolua_S,"DHBone");
        tolua_function(tolua_S,"new",lua_cocos2dx_dhspine_DHBone_constructor);
        tolua_function(tolua_S,"getWorldScaleX",lua_cocos2dx_dhspine_DHBone_getWorldScaleX);
        tolua_function(tolua_S,"getWorldScaleY",lua_cocos2dx_dhspine_DHBone_getWorldScaleY);
        tolua_function(tolua_S,"getX",lua_cocos2dx_dhspine_DHBone_getX);
        tolua_function(tolua_S,"getY",lua_cocos2dx_dhspine_DHBone_getY);
        tolua_function(tolua_S,"getRotation",lua_cocos2dx_dhspine_DHBone_getRotation);
        tolua_function(tolua_S,"getIndex",lua_cocos2dx_dhspine_DHBone_getIndex);
        tolua_function(tolua_S,"localToWorld",lua_cocos2dx_dhspine_DHBone_localToWorld);
        tolua_function(tolua_S,"getScaleY",lua_cocos2dx_dhspine_DHBone_getScaleY);
        tolua_function(tolua_S,"getScaleX",lua_cocos2dx_dhspine_DHBone_getScaleX);
        tolua_function(tolua_S,"worldToLocal",lua_cocos2dx_dhspine_DHBone_worldToLocal);
        tolua_function(tolua_S,"setToSetupPose",lua_cocos2dx_dhspine_DHBone_setToSetupPose);
        tolua_function(tolua_S,"updateFollowAttachment",lua_cocos2dx_dhspine_DHBone_updateFollowAttachment);
        tolua_function(tolua_S,"setRotation",lua_cocos2dx_dhspine_DHBone_setRotation);
        tolua_function(tolua_S,"getData",lua_cocos2dx_dhspine_DHBone_getData);
        tolua_function(tolua_S,"setScaleY",lua_cocos2dx_dhspine_DHBone_setScaleY);
        tolua_function(tolua_S,"setScaleX",lua_cocos2dx_dhspine_DHBone_setScaleX);
        tolua_function(tolua_S,"getFollowAttachmentChild",lua_cocos2dx_dhspine_DHBone_getFollowAttachmentChild);
        tolua_function(tolua_S,"updateWorldTransform",lua_cocos2dx_dhspine_DHBone_updateWorldTransform);
        tolua_function(tolua_S,"setX",lua_cocos2dx_dhspine_DHBone_setX);
        tolua_function(tolua_S,"setY",lua_cocos2dx_dhspine_DHBone_setY);
        tolua_function(tolua_S,"removeFollowAttachment",lua_cocos2dx_dhspine_DHBone_removeFollowAttachment);
        tolua_function(tolua_S,"addFollowAttachment",lua_cocos2dx_dhspine_DHBone_addFollowAttachment);
        tolua_function(tolua_S,"getWorldY",lua_cocos2dx_dhspine_DHBone_getWorldY);
        tolua_function(tolua_S,"getWorldX",lua_cocos2dx_dhspine_DHBone_getWorldX);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHBone).name();
    g_luaType[typeName] = "cc.DHBone";
    g_typeCast["DHBone"] = "cc.DHBone";
    return 1;
}

int lua_cocos2dx_dhspine_DHSlot_getBoundingBoxAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getBoundingBoxAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getBoundingBoxAttachment'", nullptr);
            return 0;
        }
        cocos2d::DHBoundingBoxAttachment* ret = cobj->getBoundingBoxAttachment();
        object_to_luaval<cocos2d::DHBoundingBoxAttachment>(tolua_S, "cc.DHBoundingBoxAttachment",(cocos2d::DHBoundingBoxAttachment*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getBoundingBoxAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getBoundingBoxAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getBone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getBone'", nullptr);
            return 0;
        }
        cocos2d::DHBone* ret = cobj->getBone();
        object_to_luaval<cocos2d::DHBone>(tolua_S, "cc.DHBone",(cocos2d::DHBone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getBone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getBone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_setColorEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_setColorEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSlot:setColorEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_setColorEnabled'", nullptr);
            return 0;
        }
        cobj->setColorEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:setColorEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_setColorEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getFollowAttachmentChild(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getFollowAttachmentChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getFollowAttachmentChild'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getFollowAttachmentChild();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getFollowAttachmentChild",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getFollowAttachmentChild'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getActiveAttachmentName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getActiveAttachmentName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getActiveAttachmentName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getActiveAttachmentName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getActiveAttachmentName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getActiveAttachmentName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_updateAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_updateAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_updateAttachment'", nullptr);
            return 0;
        }
        cobj->updateAttachment();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:updateAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_updateAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_setToSetupPose(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_setToSetupPose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_setToSetupPose'", nullptr);
            return 0;
        }
        cobj->setToSetupPose();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:setToSetupPose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_setToSetupPose'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getRegionAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getRegionAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getRegionAttachment'", nullptr);
            return 0;
        }
        cocos2d::DHRegionAttachment* ret = cobj->getRegionAttachment();
        object_to_luaval<cocos2d::DHRegionAttachment>(tolua_S, "cc.DHRegionAttachment",(cocos2d::DHRegionAttachment*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getRegionAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getRegionAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_addFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_addFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        bool arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cc.DHSlot:addFollowAttachment");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.DHSlot:addFollowAttachment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_addFollowAttachment'", nullptr);
            return 0;
        }
        cobj->addFollowAttachment(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:addFollowAttachment",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_addFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getAttachment'", nullptr);
            return 0;
        }
        cocos2d::DHAttachment* ret = cobj->getAttachment();
        object_to_luaval<cocos2d::DHAttachment>(tolua_S, "cc.DHAttachment",(cocos2d::DHAttachment*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_isColorEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_isColorEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_isColorEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isColorEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:isColorEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_isColorEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getBlendMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getBlendMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getBlendMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_isEnabledFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_isEnabledFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_isEnabledFollowAttachment'", nullptr);
            return 0;
        }
        bool ret = cobj->isEnabledFollowAttachment();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:isEnabledFollowAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_isEnabledFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_getData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_getData'", nullptr);
            return 0;
        }
        cocos2d::DHSlotData* ret = cobj->getData();
        object_to_luaval<cocos2d::DHSlotData>(tolua_S, "cc.DHSlotData",(cocos2d::DHSlotData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_drawFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_drawFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "cc.DHSlot:drawFollowAttachment");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "cc.DHSlot:drawFollowAttachment");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "cc.DHSlot:drawFollowAttachment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_drawFollowAttachment'", nullptr);
            return 0;
        }
        cobj->drawFollowAttachment(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:drawFollowAttachment",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_drawFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_removeFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_removeFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_removeFollowAttachment'", nullptr);
            return 0;
        }
        cobj->removeFollowAttachment();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:removeFollowAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_removeFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_updateFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSlot_updateFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_updateFollowAttachment'", nullptr);
            return 0;
        }
        bool ret = cobj->updateFollowAttachment();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:updateFollowAttachment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_updateFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSlot_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::DHSlotData* arg0;
        cocos2d::DHSkeleton* arg1;

        ok &= luaval_to_object<cocos2d::DHSlotData>(tolua_S, 2, "cc.DHSlotData",&arg0, "cc.DHSlot:DHSlot");

        ok &= luaval_to_object<cocos2d::DHSkeleton>(tolua_S, 3, "cc.DHSkeleton",&arg1, "cc.DHSlot:DHSlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSlot_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::DHSlot(arg0, arg1);
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.DHSlot");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSlot:DHSlot",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSlot_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dhspine_DHSlot_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHSlot)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHSlot(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHSlot");
    tolua_cclass(tolua_S,"DHSlot","cc.DHSlot","",nullptr);

    tolua_beginmodule(tolua_S,"DHSlot");
        tolua_function(tolua_S,"new",lua_cocos2dx_dhspine_DHSlot_constructor);
        tolua_function(tolua_S,"getBoundingBoxAttachment",lua_cocos2dx_dhspine_DHSlot_getBoundingBoxAttachment);
        tolua_function(tolua_S,"getBone",lua_cocos2dx_dhspine_DHSlot_getBone);
        tolua_function(tolua_S,"setColorEnabled",lua_cocos2dx_dhspine_DHSlot_setColorEnabled);
        tolua_function(tolua_S,"getFollowAttachmentChild",lua_cocos2dx_dhspine_DHSlot_getFollowAttachmentChild);
        tolua_function(tolua_S,"getActiveAttachmentName",lua_cocos2dx_dhspine_DHSlot_getActiveAttachmentName);
        tolua_function(tolua_S,"updateAttachment",lua_cocos2dx_dhspine_DHSlot_updateAttachment);
        tolua_function(tolua_S,"getName",lua_cocos2dx_dhspine_DHSlot_getName);
        tolua_function(tolua_S,"setToSetupPose",lua_cocos2dx_dhspine_DHSlot_setToSetupPose);
        tolua_function(tolua_S,"getRegionAttachment",lua_cocos2dx_dhspine_DHSlot_getRegionAttachment);
        tolua_function(tolua_S,"addFollowAttachment",lua_cocos2dx_dhspine_DHSlot_addFollowAttachment);
        tolua_function(tolua_S,"getAttachment",lua_cocos2dx_dhspine_DHSlot_getAttachment);
        tolua_function(tolua_S,"isColorEnabled",lua_cocos2dx_dhspine_DHSlot_isColorEnabled);
        tolua_function(tolua_S,"getBlendMode",lua_cocos2dx_dhspine_DHSlot_getBlendMode);
        tolua_function(tolua_S,"isEnabledFollowAttachment",lua_cocos2dx_dhspine_DHSlot_isEnabledFollowAttachment);
        tolua_function(tolua_S,"getData",lua_cocos2dx_dhspine_DHSlot_getData);
        tolua_function(tolua_S,"drawFollowAttachment",lua_cocos2dx_dhspine_DHSlot_drawFollowAttachment);
        tolua_function(tolua_S,"removeFollowAttachment",lua_cocos2dx_dhspine_DHSlot_removeFollowAttachment);
        tolua_function(tolua_S,"updateFollowAttachment",lua_cocos2dx_dhspine_DHSlot_updateFollowAttachment);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHSlot).name();
    g_luaType[typeName] = "cc.DHSlot";
    g_typeCast["DHSlot"] = "cc.DHSlot";
    return 1;
}

int lua_cocos2dx_dhspine_DHSkeletonData_getBoneCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonData_getBoneCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonData_getBoneCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getBoneCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonData:getBoneCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonData_getBoneCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonData_setName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonData_setName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeletonData:setName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonData_setName'", nullptr);
            return 0;
        }
        cobj->setName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonData:setName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonData_setName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonData_getRandomAnimationName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonData_getRandomAnimationName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonData_getRandomAnimationName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getRandomAnimationName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonData:getRandomAnimationName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonData_getRandomAnimationName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonData_getSlotCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonData_getSlotCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonData_getSlotCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getSlotCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonData:getSlotCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonData_getSlotCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonData_getName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonData_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonData_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonData:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonData_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeletonData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonData_create'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonData* ret = cocos2d::DHSkeletonData::create();
        object_to_luaval<cocos2d::DHSkeletonData>(tolua_S, "cc.DHSkeletonData",(cocos2d::DHSkeletonData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeletonData:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonData_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::DHSkeletonData();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.DHSkeletonData");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonData:DHSkeletonData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dhspine_DHSkeletonData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHSkeletonData)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHSkeletonData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHSkeletonData");
    tolua_cclass(tolua_S,"DHSkeletonData","cc.DHSkeletonData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"DHSkeletonData");
        tolua_function(tolua_S,"new",lua_cocos2dx_dhspine_DHSkeletonData_constructor);
        tolua_function(tolua_S,"getBoneCount",lua_cocos2dx_dhspine_DHSkeletonData_getBoneCount);
        tolua_function(tolua_S,"setName",lua_cocos2dx_dhspine_DHSkeletonData_setName);
        tolua_function(tolua_S,"getRandomAnimationName",lua_cocos2dx_dhspine_DHSkeletonData_getRandomAnimationName);
        tolua_function(tolua_S,"getSlotCount",lua_cocos2dx_dhspine_DHSkeletonData_getSlotCount);
        tolua_function(tolua_S,"getName",lua_cocos2dx_dhspine_DHSkeletonData_getName);
        tolua_function(tolua_S,"create", lua_cocos2dx_dhspine_DHSkeletonData_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHSkeletonData).name();
    g_luaType[typeName] = "cc.DHSkeletonData";
    g_typeCast["DHSkeletonData"] = "cc.DHSkeletonData";
    return 1;
}

int lua_cocos2dx_dhspine_DHSkeletonDataCache_setRelativeFilePath(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_setRelativeFilePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonDataCache:setRelativeFilePath"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_setRelativeFilePath'", nullptr);
            return 0;
        }
        cobj->setRelativeFilePath(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:setRelativeFilePath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_setRelativeFilePath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_removeRenderTextureCache(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_removeRenderTextureCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeletonDataCache:removeRenderTextureCache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_removeRenderTextureCache'", nullptr);
            return 0;
        }
        cobj->removeRenderTextureCache(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:removeRenderTextureCache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_removeRenderTextureCache'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_getSkeletonData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getSkeletonData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonDataCache:getSkeletonData"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getSkeletonData'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonData* ret = cobj->getSkeletonData(arg0);
        object_to_luaval<cocos2d::DHSkeletonData>(tolua_S, "cc.DHSkeletonData",(cocos2d::DHSkeletonData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:getSkeletonData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getSkeletonData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_preloadFrameSequence(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_preloadFrameSequence'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        const char* arg0;
        const char* arg1;
        double arg2;
        cocos2d::Node* arg3;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonDataCache:preloadFrameSequence"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.DHSkeletonDataCache:preloadFrameSequence"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.DHSkeletonDataCache:preloadFrameSequence");

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 5, "cc.Node",&arg3, "cc.DHSkeletonDataCache:preloadFrameSequence");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_preloadFrameSequence'", nullptr);
            return 0;
        }
        cobj->preloadFrameSequence(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        const char* arg0;
        const char* arg1;
        double arg2;
        cocos2d::Node* arg3;
        double arg4;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonDataCache:preloadFrameSequence"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.DHSkeletonDataCache:preloadFrameSequence"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.DHSkeletonDataCache:preloadFrameSequence");

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 5, "cc.Node",&arg3, "cc.DHSkeletonDataCache:preloadFrameSequence");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "cc.DHSkeletonDataCache:preloadFrameSequence");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_preloadFrameSequence'", nullptr);
            return 0;
        }
        cobj->preloadFrameSequence(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:preloadFrameSequence",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_preloadFrameSequence'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_setResolutionScale(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_setResolutionScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonDataCache:setResolutionScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_setResolutionScale'", nullptr);
            return 0;
        }
        cobj->setResolutionScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:setResolutionScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_setResolutionScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_clearRenderTextureCache(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_clearRenderTextureCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_clearRenderTextureCache'", nullptr);
            return 0;
        }
        cobj->clearRenderTextureCache();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:clearRenderTextureCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_clearRenderTextureCache'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_loadSkeletonData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_loadSkeletonData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonDataCache:loadSkeletonData"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.DHSkeletonDataCache:loadSkeletonData"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_loadSkeletonData'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonData* ret = cobj->loadSkeletonData(arg0, arg1);
        object_to_luaval<cocos2d::DHSkeletonData>(tolua_S, "cc.DHSkeletonData",(cocos2d::DHSkeletonData*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonDataCache:loadSkeletonData"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.DHSkeletonDataCache:loadSkeletonData"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.DHSkeletonDataCache:loadSkeletonData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_loadSkeletonData'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonData* ret = cobj->loadSkeletonData(arg0, arg1, arg2);
        object_to_luaval<cocos2d::DHSkeletonData>(tolua_S, "cc.DHSkeletonData",(cocos2d::DHSkeletonData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:loadSkeletonData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_loadSkeletonData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_purgeCache(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_purgeCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_purgeCache'", nullptr);
            return 0;
        }
        cobj->purgeCache();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:purgeCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_purgeCache'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_getResolutionScale(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getResolutionScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getResolutionScale'", nullptr);
            return 0;
        }
        double ret = cobj->getResolutionScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:getResolutionScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getResolutionScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_removeSkeletonData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonDataCache* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonDataCache*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_removeSkeletonData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonDataCache:removeSkeletonData"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_removeSkeletonData'", nullptr);
            return 0;
        }
        cobj->removeSkeletonData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonDataCache:removeSkeletonData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_removeSkeletonData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonDataCache_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeletonDataCache",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getInstance'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonDataCache* ret = cocos2d::DHSkeletonDataCache::getInstance();
        object_to_luaval<cocos2d::DHSkeletonDataCache>(tolua_S, "cc.DHSkeletonDataCache",(cocos2d::DHSkeletonDataCache*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeletonDataCache:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonDataCache_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_dhspine_DHSkeletonDataCache_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHSkeletonDataCache)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHSkeletonDataCache(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHSkeletonDataCache");
    tolua_cclass(tolua_S,"DHSkeletonDataCache","cc.DHSkeletonDataCache","",nullptr);

    tolua_beginmodule(tolua_S,"DHSkeletonDataCache");
        tolua_function(tolua_S,"setRelativeFilePath",lua_cocos2dx_dhspine_DHSkeletonDataCache_setRelativeFilePath);
        tolua_function(tolua_S,"removeRenderTextureCache",lua_cocos2dx_dhspine_DHSkeletonDataCache_removeRenderTextureCache);
        tolua_function(tolua_S,"getSkeletonData",lua_cocos2dx_dhspine_DHSkeletonDataCache_getSkeletonData);
        tolua_function(tolua_S,"preloadFrameSequence",lua_cocos2dx_dhspine_DHSkeletonDataCache_preloadFrameSequence);
        tolua_function(tolua_S,"setResolutionScale",lua_cocos2dx_dhspine_DHSkeletonDataCache_setResolutionScale);
        tolua_function(tolua_S,"clearRenderTextureCache",lua_cocos2dx_dhspine_DHSkeletonDataCache_clearRenderTextureCache);
        tolua_function(tolua_S,"loadSkeletonData",lua_cocos2dx_dhspine_DHSkeletonDataCache_loadSkeletonData);
        tolua_function(tolua_S,"purgeCache",lua_cocos2dx_dhspine_DHSkeletonDataCache_purgeCache);
        tolua_function(tolua_S,"getResolutionScale",lua_cocos2dx_dhspine_DHSkeletonDataCache_getResolutionScale);
        tolua_function(tolua_S,"removeSkeletonData",lua_cocos2dx_dhspine_DHSkeletonDataCache_removeSkeletonData);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_dhspine_DHSkeletonDataCache_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHSkeletonDataCache).name();
    g_luaType[typeName] = "cc.DHSkeletonDataCache";
    g_typeCast["DHSkeletonDataCache"] = "cc.DHSkeletonDataCache";
    return 1;
}

int lua_cocos2dx_dhspine_DHSkeleton_removeSlotFollowAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_removeSlotFollowAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cc.DHSkeleton:removeSlotFollowAttachment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_removeSlotFollowAttachment'", nullptr);
            return 0;
        }
        cobj->removeSlotFollowAttachment(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:removeSlotFollowAttachment",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_removeSlotFollowAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_isUseCulling(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_isUseCulling'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_isUseCulling'", nullptr);
            return 0;
        }
        bool ret = cobj->isUseCulling();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:isUseCulling",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_isUseCulling'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setExtendOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setExtendOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeleton:setExtendOpacity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setExtendOpacity'", nullptr);
            return 0;
        }
        cobj->setExtendOpacity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setExtendOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setExtendOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getBoneByName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getBoneByName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneByName'", nullptr);
            return 0;
        }
        cocos2d::DHBone* ret = cobj->getBoneByName(arg0);
        object_to_luaval<cocos2d::DHBone>(tolua_S, "cc.DHBone",(cocos2d::DHBone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getBoneByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneByName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_isFlipY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_isFlipY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_isFlipY'", nullptr);
            return 0;
        }
        bool ret = cobj->isFlipY();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:isFlipY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_isFlipY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setUseCulling(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setUseCulling'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeleton:setUseCulling");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setUseCulling'", nullptr);
            return 0;
        }
        cobj->setUseCulling(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setUseCulling",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setUseCulling'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setSaturation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setSaturation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeleton:setSaturation");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHSkeleton:setSaturation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setSaturation'", nullptr);
            return 0;
        }
        cobj->setSaturation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setSaturation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setSaturation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getReallyColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getReallyColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getReallyColor'", nullptr);
            return 0;
        }
        const cocos2d::Color4F& ret = cobj->getReallyColor();
        color4f_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getReallyColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getReallyColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_isColorRotationInit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_isColorRotationInit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_isColorRotationInit'", nullptr);
            return 0;
        }
        bool ret = cobj->isColorRotationInit();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:isColorRotationInit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_isColorRotationInit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_createDrawNodeBoundingBoxBySlot(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_createDrawNodeBoundingBoxBySlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:createDrawNodeBoundingBoxBySlot"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_createDrawNodeBoundingBoxBySlot'", nullptr);
            return 0;
        }
        cocos2d::DrawNode* ret = cobj->createDrawNodeBoundingBoxBySlot(arg0);
        object_to_luaval<cocos2d::DrawNode>(tolua_S, "cc.DrawNode",(cocos2d::DrawNode*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:createDrawNodeBoundingBoxBySlot"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.DHSkeleton:createDrawNodeBoundingBoxBySlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_createDrawNodeBoundingBoxBySlot'", nullptr);
            return 0;
        }
        cocos2d::DrawNode* ret = cobj->createDrawNodeBoundingBoxBySlot(arg0, arg1);
        object_to_luaval<cocos2d::DrawNode>(tolua_S, "cc.DrawNode",(cocos2d::DrawNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:createDrawNodeBoundingBoxBySlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_createDrawNodeBoundingBoxBySlot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setSkinEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setSkinEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:setSkinEnabled"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.DHSkeleton:setSkinEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setSkinEnabled'", nullptr);
            return 0;
        }
        cobj->setSkinEnabled(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setSkinEnabled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setSkinEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getReallyOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getReallyOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getReallyOpacity'", nullptr);
            return 0;
        }
        double ret = cobj->getReallyOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getReallyOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getReallyOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_addChildFollowBone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_addChildFollowBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Node* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:addChildFollowBone"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "cc.DHSkeleton:addChildFollowBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_addChildFollowBone'", nullptr);
            return 0;
        }
        cobj->addChildFollowBone(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:addChildFollowBone",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_addChildFollowBone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_regionContainsPoint(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_regionContainsPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "cc.DHSkeleton:regionContainsPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_regionContainsPoint'", nullptr);
            return 0;
        }
        bool ret = cobj->regionContainsPoint(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:regionContainsPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_regionContainsPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBoxBySlot(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBoxBySlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getAabbBoundingBoxBySlot"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBoxBySlot'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->getAabbBoundingBoxBySlot(arg0);
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getAabbBoundingBoxBySlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBoxBySlot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setHue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setHue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeleton:setHue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHSkeleton:setHue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setHue'", nullptr);
            return 0;
        }
        cobj->setHue(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setHue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setHue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setColorMixEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setColorMixEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeleton:setColorMixEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setColorMixEnabled'", nullptr);
            return 0;
        }
        cobj->setColorMixEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setColorMixEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setColorMixEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBox(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBox'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBox'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->getAabbBoundingBox();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getAabbBoundingBox",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBox'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setToSetupPose(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setToSetupPose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setToSetupPose'", nullptr);
            return 0;
        }
        cobj->setToSetupPose();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setToSetupPose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setToSetupPose'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "cc.DHSkeleton:setOpacity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setOpacity'", nullptr);
            return 0;
        }
        cobj->setOpacity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_isColorMixEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_isColorMixEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_isColorMixEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isColorMixEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:isColorMixEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_isColorMixEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getHue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getHue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeleton:getHue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getHue'", nullptr);
            return 0;
        }
        double ret = cobj->getHue(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getHue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getHue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getChildFollowBone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getChildFollowBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getChildFollowBone"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getChildFollowBone'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getChildFollowBone(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getChildFollowBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getChildFollowBone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_aabbIntersectsSkeleton(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_aabbIntersectsSkeleton'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DHSkeleton* arg0;

        ok &= luaval_to_object<cocos2d::DHSkeleton>(tolua_S, 2, "cc.DHSkeleton",&arg0, "cc.DHSkeleton:aabbIntersectsSkeleton");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_aabbIntersectsSkeleton'", nullptr);
            return 0;
        }
        bool ret = cobj->aabbIntersectsSkeleton(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:aabbIntersectsSkeleton",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_aabbIntersectsSkeleton'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_isFlipX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_isFlipX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_isFlipX'", nullptr);
            return 0;
        }
        bool ret = cobj->isFlipX();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:isFlipX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_isFlipX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getData'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonData* ret = cobj->getData();
        object_to_luaval<cocos2d::DHSkeletonData>(tolua_S, "cc.DHSkeletonData",(cocos2d::DHSkeletonData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_unregisterSkin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_unregisterSkin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:unregisterSkin"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_unregisterSkin'", nullptr);
            return 0;
        }
        cobj->unregisterSkin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:unregisterSkin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_unregisterSkin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setBrightness(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setBrightness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeleton:setBrightness");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHSkeleton:setBrightness");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setBrightness'", nullptr);
            return 0;
        }
        cobj->setBrightness(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setBrightness",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setBrightness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setExtendColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setExtendColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4F arg0;

        ok &=luaval_to_color4f(tolua_S, 2, &arg0, "cc.DHSkeleton:setExtendColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setExtendColor'", nullptr);
            return 0;
        }
        cobj->setExtendColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setExtendColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setExtendColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getBoneLocation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneLocation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getBoneLocation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneLocation'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getBoneLocation(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getBoneLocation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneLocation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowBone(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:removeChildFollowBone"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowBone'", nullptr);
            return 0;
        }
        cobj->removeChildFollowBone(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:removeChildFollowBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowBone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getAabbContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbContentSize'", nullptr);
            return 0;
        }
        cocos2d::Size ret = cobj->getAabbContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getAabbContentSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getAabbContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setFlipY(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setFlipY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeleton:setFlipY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setFlipY'", nullptr);
            return 0;
        }
        cobj->setFlipY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setFlipY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setFlipY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getAttachment(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getAttachment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        const char* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.DHSkeleton:getAttachment");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.DHSkeleton:getAttachment"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getAttachment'", nullptr);
            return 0;
        }
        cocos2d::DHAttachment* ret = cobj->getAttachment(arg0, arg1);
        object_to_luaval<cocos2d::DHAttachment>(tolua_S, "cc.DHAttachment",(cocos2d::DHAttachment*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getAttachment",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getAttachment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_isSkinRegistered(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_isSkinRegistered'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:isSkinRegistered"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_isSkinRegistered'", nullptr);
            return 0;
        }
        bool ret = cobj->isSkinRegistered(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:isSkinRegistered",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_isSkinRegistered'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_registerSkin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_registerSkin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:registerSkin"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_registerSkin'", nullptr);
            return 0;
        }
        cobj->registerSkin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:registerSkin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_registerSkin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getBoneByIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.DHSkeleton:getBoneByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneByIndex'", nullptr);
            return 0;
        }
        cocos2d::DHBone* ret = cobj->getBoneByIndex(arg0);
        object_to_luaval<cocos2d::DHBone>(tolua_S, "cc.DHBone",(cocos2d::DHBone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getBoneByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getBoneByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getSaturation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getSaturation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeleton:getSaturation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getSaturation'", nullptr);
            return 0;
        }
        double ret = cobj->getSaturation(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getSaturation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getSaturation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_unregisterAllSkin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_unregisterAllSkin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_unregisterAllSkin'", nullptr);
            return 0;
        }
        cobj->unregisterAllSkin();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:unregisterAllSkin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_unregisterAllSkin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getChildFollowSlot(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getChildFollowSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getChildFollowSlot"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getChildFollowSlot'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getChildFollowSlot(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getChildFollowSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getChildFollowSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getBrightness(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getBrightness'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.DHSkeleton:getBrightness");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getBrightness'", nullptr);
            return 0;
        }
        double ret = cobj->getBrightness(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getBrightness",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getBrightness'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getEventTimeLine(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getEventTimeLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getEventTimeLine"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.DHSkeleton:getEventTimeLine"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getEventTimeLine'", nullptr);
            return 0;
        }
        double ret = cobj->getEventTimeLine(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getEventTimeLine",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getEventTimeLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setAllSlotColorEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setAllSlotColorEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeleton:setAllSlotColorEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setAllSlotColorEnabled'", nullptr);
            return 0;
        }
        cobj->setAllSlotColorEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setAllSlotColorEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setAllSlotColorEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getExtendColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getExtendColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getExtendColor'", nullptr);
            return 0;
        }
        const cocos2d::Color4F& ret = cobj->getExtendColor();
        color4f_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getExtendColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getExtendColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getBonePosition(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getBonePosition"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePosition'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getBonePosition(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getBonePosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_containsPointBySlot(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_containsPointBySlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Point arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:containsPointBySlot"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_point(tolua_S, 3, &arg1, "cc.DHSkeleton:containsPointBySlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_containsPointBySlot'", nullptr);
            return 0;
        }
        bool ret = cobj->containsPointBySlot(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:containsPointBySlot",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_containsPointBySlot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "cc.DHSkeleton:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getSlotByName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getSlotByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getSlotByName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getSlotByName'", nullptr);
            return 0;
        }
        cocos2d::DHSlot* ret = cobj->getSlotByName(arg0);
        object_to_luaval<cocos2d::DHSlot>(tolua_S, "cc.DHSlot",(cocos2d::DHSlot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getSlotByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getSlotByName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_addChildFollowSlot(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_addChildFollowSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Node* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:addChildFollowSlot"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "cc.DHSkeleton:addChildFollowSlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_addChildFollowSlot'", nullptr);
            return 0;
        }
        cobj->addChildFollowSlot(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        cocos2d::Node* arg1;
        bool arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:addChildFollowSlot"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "cc.DHSkeleton:addChildFollowSlot");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "cc.DHSkeleton:addChildFollowSlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_addChildFollowSlot'", nullptr);
            return 0;
        }
        cobj->addChildFollowSlot(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:addChildFollowSlot",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_addChildFollowSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_setFlipX(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_setFlipX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeleton:setFlipX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_setFlipX'", nullptr);
            return 0;
        }
        cobj->setFlipX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:setFlipX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_setFlipX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getExtendOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getExtendOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getExtendOpacity'", nullptr);
            return 0;
        }
        double ret = cobj->getExtendOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getExtendOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getExtendOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToWorld(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToWorld'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getBonePositionRelativeToWorld"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToWorld'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getBonePositionRelativeToWorld(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getBonePositionRelativeToWorld",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToWorld'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getSlotByIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getSlotByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.DHSkeleton:getSlotByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getSlotByIndex'", nullptr);
            return 0;
        }
        cocos2d::DHSlot* ret = cobj->getSlotByIndex(arg0);
        object_to_luaval<cocos2d::DHSlot>(tolua_S, "cc.DHSlot",(cocos2d::DHSlot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getSlotByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getSlotByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_removeChild(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChild'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cc.DHSkeleton:removeChild");

            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.DHSkeleton:removeChild");

            if (!ok) { break; }
            cobj->removeChild(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cc.DHSkeleton:removeChild");

            if (!ok) { break; }
            cobj->removeChild(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.DHSkeleton:removeChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChild'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToLayer(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getBonePositionRelativeToLayer"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToLayer'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getBonePositionRelativeToLayer(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getBonePositionRelativeToLayer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_getAnimationDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getAnimationDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getAnimationDuration"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getAnimationDuration'", nullptr);
            return 0;
        }
        double ret = cobj->getAnimationDuration(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getAnimationDuration",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getAnimationDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_updateWorldTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_updateWorldTransform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_updateWorldTransform'", nullptr);
            return 0;
        }
        cobj->updateWorldTransform();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:updateWorldTransform",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_updateWorldTransform'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowSlot(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:removeChildFollowSlot"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowSlot'", nullptr);
            return 0;
        }
        cobj->removeChildFollowSlot(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:removeChildFollowSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_containsPoint(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_containsPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "cc.DHSkeleton:containsPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_containsPoint'", nullptr);
            return 0;
        }
        bool ret = cobj->containsPoint(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:containsPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_containsPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_aabbRegionContainsPoint(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeleton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_aabbRegionContainsPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "cc.DHSkeleton:aabbRegionContainsPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_aabbRegionContainsPoint'", nullptr);
            return 0;
        }
        bool ret = cobj->aabbRegionContainsPoint(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:aabbRegionContainsPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_aabbRegionContainsPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_createWithFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:createWithFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_createWithFile'", nullptr);
            return 0;
        }
        cocos2d::DHSkeleton* ret = cocos2d::DHSkeleton::createWithFile(arg0);
        object_to_luaval<cocos2d::DHSkeleton>(tolua_S, "cc.DHSkeleton",(cocos2d::DHSkeleton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeleton:createWithFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_createWithFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_createWithData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::DHSkeletonData* arg0;
        ok &= luaval_to_object<cocos2d::DHSkeletonData>(tolua_S, 2, "cc.DHSkeletonData",&arg0, "cc.DHSkeleton:createWithData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_createWithData'", nullptr);
            return 0;
        }
        cocos2d::DHSkeleton* ret = cocos2d::DHSkeleton::createWithData(arg0);
        object_to_luaval<cocos2d::DHSkeleton>(tolua_S, "cc.DHSkeleton",(cocos2d::DHSkeleton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeleton:createWithData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_createWithData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_createWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeleton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:createWithKey"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_createWithKey'", nullptr);
            return 0;
        }
        cocos2d::DHSkeleton* ret = cocos2d::DHSkeleton::createWithKey(arg0);
        object_to_luaval<cocos2d::DHSkeleton>(tolua_S, "cc.DHSkeleton",(cocos2d::DHSkeleton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeleton:createWithKey",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_createWithKey'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHSkeleton_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeleton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DHSkeletonData* arg0;

        ok &= luaval_to_object<cocos2d::DHSkeletonData>(tolua_S, 2, "cc.DHSkeletonData",&arg0, "cc.DHSkeleton:DHSkeleton");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::DHSkeleton(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.DHSkeleton");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:DHSkeleton",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dhspine_DHSkeleton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHSkeleton)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHSkeleton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHSkeleton");
    tolua_cclass(tolua_S,"DHSkeleton","cc.DHSkeleton","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"DHSkeleton");
        tolua_function(tolua_S,"new",lua_cocos2dx_dhspine_DHSkeleton_constructor);
        tolua_function(tolua_S,"removeSlotFollowAttachment",lua_cocos2dx_dhspine_DHSkeleton_removeSlotFollowAttachment);
        tolua_function(tolua_S,"isUseCulling",lua_cocos2dx_dhspine_DHSkeleton_isUseCulling);
        tolua_function(tolua_S,"setExtendOpacity",lua_cocos2dx_dhspine_DHSkeleton_setExtendOpacity);
        tolua_function(tolua_S,"getBoneByName",lua_cocos2dx_dhspine_DHSkeleton_getBoneByName);
        tolua_function(tolua_S,"isFlipY",lua_cocos2dx_dhspine_DHSkeleton_isFlipY);
        tolua_function(tolua_S,"setUseCulling",lua_cocos2dx_dhspine_DHSkeleton_setUseCulling);
        tolua_function(tolua_S,"setSaturation",lua_cocos2dx_dhspine_DHSkeleton_setSaturation);
        tolua_function(tolua_S,"getReallyColor",lua_cocos2dx_dhspine_DHSkeleton_getReallyColor);
        tolua_function(tolua_S,"isColorRotationInit",lua_cocos2dx_dhspine_DHSkeleton_isColorRotationInit);
        tolua_function(tolua_S,"createDrawNodeBoundingBoxBySlot",lua_cocos2dx_dhspine_DHSkeleton_createDrawNodeBoundingBoxBySlot);
        tolua_function(tolua_S,"setSkinEnabled",lua_cocos2dx_dhspine_DHSkeleton_setSkinEnabled);
        tolua_function(tolua_S,"getReallyOpacity",lua_cocos2dx_dhspine_DHSkeleton_getReallyOpacity);
        tolua_function(tolua_S,"addChildFollowBone",lua_cocos2dx_dhspine_DHSkeleton_addChildFollowBone);
        tolua_function(tolua_S,"regionContainsPoint",lua_cocos2dx_dhspine_DHSkeleton_regionContainsPoint);
        tolua_function(tolua_S,"getAabbBoundingBoxBySlot",lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBoxBySlot);
        tolua_function(tolua_S,"setHue",lua_cocos2dx_dhspine_DHSkeleton_setHue);
        tolua_function(tolua_S,"setColorMixEnabled",lua_cocos2dx_dhspine_DHSkeleton_setColorMixEnabled);
        tolua_function(tolua_S,"getAabbBoundingBox",lua_cocos2dx_dhspine_DHSkeleton_getAabbBoundingBox);
        tolua_function(tolua_S,"setToSetupPose",lua_cocos2dx_dhspine_DHSkeleton_setToSetupPose);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_dhspine_DHSkeleton_setOpacity);
        tolua_function(tolua_S,"isColorMixEnabled",lua_cocos2dx_dhspine_DHSkeleton_isColorMixEnabled);
        tolua_function(tolua_S,"getHue",lua_cocos2dx_dhspine_DHSkeleton_getHue);
        tolua_function(tolua_S,"init",lua_cocos2dx_dhspine_DHSkeleton_init);
        tolua_function(tolua_S,"getChildFollowBone",lua_cocos2dx_dhspine_DHSkeleton_getChildFollowBone);
        tolua_function(tolua_S,"aabbIntersectsSkeleton",lua_cocos2dx_dhspine_DHSkeleton_aabbIntersectsSkeleton);
        tolua_function(tolua_S,"isFlipX",lua_cocos2dx_dhspine_DHSkeleton_isFlipX);
        tolua_function(tolua_S,"getData",lua_cocos2dx_dhspine_DHSkeleton_getData);
        tolua_function(tolua_S,"unregisterSkin",lua_cocos2dx_dhspine_DHSkeleton_unregisterSkin);
        tolua_function(tolua_S,"setBrightness",lua_cocos2dx_dhspine_DHSkeleton_setBrightness);
        tolua_function(tolua_S,"setExtendColor",lua_cocos2dx_dhspine_DHSkeleton_setExtendColor);
        tolua_function(tolua_S,"getBoneLocation",lua_cocos2dx_dhspine_DHSkeleton_getBoneLocation);
        tolua_function(tolua_S,"removeChildFollowBone",lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowBone);
        tolua_function(tolua_S,"getAabbContentSize",lua_cocos2dx_dhspine_DHSkeleton_getAabbContentSize);
        tolua_function(tolua_S,"setFlipY",lua_cocos2dx_dhspine_DHSkeleton_setFlipY);
        tolua_function(tolua_S,"getAttachment",lua_cocos2dx_dhspine_DHSkeleton_getAttachment);
        tolua_function(tolua_S,"isSkinRegistered",lua_cocos2dx_dhspine_DHSkeleton_isSkinRegistered);
        tolua_function(tolua_S,"registerSkin",lua_cocos2dx_dhspine_DHSkeleton_registerSkin);
        tolua_function(tolua_S,"getBoneByIndex",lua_cocos2dx_dhspine_DHSkeleton_getBoneByIndex);
        tolua_function(tolua_S,"getSaturation",lua_cocos2dx_dhspine_DHSkeleton_getSaturation);
        tolua_function(tolua_S,"unregisterAllSkin",lua_cocos2dx_dhspine_DHSkeleton_unregisterAllSkin);
        tolua_function(tolua_S,"getChildFollowSlot",lua_cocos2dx_dhspine_DHSkeleton_getChildFollowSlot);
        tolua_function(tolua_S,"getBrightness",lua_cocos2dx_dhspine_DHSkeleton_getBrightness);
        tolua_function(tolua_S,"getEventTimeLine",lua_cocos2dx_dhspine_DHSkeleton_getEventTimeLine);
        tolua_function(tolua_S,"setAllSlotColorEnabled",lua_cocos2dx_dhspine_DHSkeleton_setAllSlotColorEnabled);
        tolua_function(tolua_S,"getExtendColor",lua_cocos2dx_dhspine_DHSkeleton_getExtendColor);
        tolua_function(tolua_S,"getBonePosition",lua_cocos2dx_dhspine_DHSkeleton_getBonePosition);
        tolua_function(tolua_S,"containsPointBySlot",lua_cocos2dx_dhspine_DHSkeleton_containsPointBySlot);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_dhspine_DHSkeleton_setColor);
        tolua_function(tolua_S,"getSlotByName",lua_cocos2dx_dhspine_DHSkeleton_getSlotByName);
        tolua_function(tolua_S,"addChildFollowSlot",lua_cocos2dx_dhspine_DHSkeleton_addChildFollowSlot);
        tolua_function(tolua_S,"setFlipX",lua_cocos2dx_dhspine_DHSkeleton_setFlipX);
        tolua_function(tolua_S,"getExtendOpacity",lua_cocos2dx_dhspine_DHSkeleton_getExtendOpacity);
        tolua_function(tolua_S,"getBonePositionRelativeToWorld",lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToWorld);
        tolua_function(tolua_S,"getSlotByIndex",lua_cocos2dx_dhspine_DHSkeleton_getSlotByIndex);
        tolua_function(tolua_S,"removeChild",lua_cocos2dx_dhspine_DHSkeleton_removeChild);
        tolua_function(tolua_S,"getBonePositionRelativeToLayer",lua_cocos2dx_dhspine_DHSkeleton_getBonePositionRelativeToLayer);
        tolua_function(tolua_S,"getAnimationDuration",lua_cocos2dx_dhspine_DHSkeleton_getAnimationDuration);
        tolua_function(tolua_S,"updateWorldTransform",lua_cocos2dx_dhspine_DHSkeleton_updateWorldTransform);
        tolua_function(tolua_S,"removeChildFollowSlot",lua_cocos2dx_dhspine_DHSkeleton_removeChildFollowSlot);
        tolua_function(tolua_S,"containsPoint",lua_cocos2dx_dhspine_DHSkeleton_containsPoint);
        tolua_function(tolua_S,"aabbRegionContainsPoint",lua_cocos2dx_dhspine_DHSkeleton_aabbRegionContainsPoint);
        tolua_function(tolua_S,"createWithFile", lua_cocos2dx_dhspine_DHSkeleton_createWithFile);
        tolua_function(tolua_S,"createWithData", lua_cocos2dx_dhspine_DHSkeleton_createWithData);
        tolua_function(tolua_S,"createWithKey", lua_cocos2dx_dhspine_DHSkeleton_createWithKey);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHSkeleton).name();
    g_luaType[typeName] = "cc.DHSkeleton";
    g_typeCast["DHSkeleton"] = "cc.DHSkeleton";
    return 1;
}

int lua_cocos2dx_dhspine_DHAnimationInfo_setLoopCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setLoopCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.DHAnimationInfo:setLoopCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setLoopCount'", nullptr);
            return 0;
        }
        cobj->setLoopCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:setLoopCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setLoopCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_setInFadeOut(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setInFadeOut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHAnimationInfo:setInFadeOut");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setInFadeOut'", nullptr);
            return 0;
        }
        cobj->setInFadeOut(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:setInFadeOut",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setInFadeOut'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_setFrameTime(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setFrameTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHAnimationInfo:setFrameTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setFrameTime'", nullptr);
            return 0;
        }
        cobj->setFrameTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:setFrameTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_setFrameTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_getCurrentFrameTime(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getCurrentFrameTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getCurrentFrameTime'", nullptr);
            return 0;
        }
        double ret = cobj->getCurrentFrameTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:getCurrentFrameTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getCurrentFrameTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_getDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getDuration'", nullptr);
            return 0;
        }
        double ret = cobj->getDuration();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:getDuration",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_getFrameTime(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getFrameTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getFrameTime'", nullptr);
            return 0;
        }
        double ret = cobj->getFrameTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:getFrameTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getFrameTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHAnimationInfo:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHAnimationInfo:update");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHAnimationInfo:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_update'", nullptr);
            return 0;
        }
        cobj->update(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_updateFrameTime(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_updateFrameTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHAnimationInfo:updateFrameTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_updateFrameTime'", nullptr);
            return 0;
        }
        cobj->updateFrameTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:updateFrameTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_updateFrameTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_getLoopCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getLoopCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getLoopCount'", nullptr);
            return 0;
        }
        int ret = cobj->getLoopCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:getLoopCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getLoopCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_updateToFrameIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_updateToFrameIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHAnimationInfo:updateToFrameIndex");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHAnimationInfo:updateToFrameIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_updateToFrameIndex'", nullptr);
            return 0;
        }
        cobj->updateToFrameIndex(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:updateToFrameIndex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_updateToFrameIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_applyEventsToFirstFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_applyEventsToFirstFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHAnimationInfo:applyEventsToFirstFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_applyEventsToFirstFrame'", nullptr);
            return 0;
        }
        cobj->applyEventsToFirstFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:applyEventsToFirstFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_applyEventsToFirstFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_apply(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_apply'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_apply'", nullptr);
            return 0;
        }
        cobj->apply();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:apply",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_apply'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_isComplete(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_isComplete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_isComplete'", nullptr);
            return 0;
        }
        bool ret = cobj->isComplete();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:isComplete",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_isComplete'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_getData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getData'", nullptr);
            return 0;
        }
        cocos2d::DHAnimationData* ret = cobj->getData();
        object_to_luaval<cocos2d::DHAnimationData>(tolua_S, "cc.DHAnimationData",(cocos2d::DHAnimationData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_getNextFrameTime(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHAnimationInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHAnimationInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getNextFrameTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHAnimationInfo:getNextFrameTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getNextFrameTime'", nullptr);
            return 0;
        }
        double ret = cobj->getNextFrameTime(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:getNextFrameTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_getNextFrameTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHAnimationInfo_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHAnimationInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::DHAnimationData* arg0;
        cocos2d::DHSkeletonAnimation* arg1;
        int arg2;

        ok &= luaval_to_object<cocos2d::DHAnimationData>(tolua_S, 2, "cc.DHAnimationData",&arg0, "cc.DHAnimationInfo:DHAnimationInfo");

        ok &= luaval_to_object<cocos2d::DHSkeletonAnimation>(tolua_S, 3, "cc.DHSkeletonAnimation",&arg1, "cc.DHAnimationInfo:DHAnimationInfo");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.DHAnimationInfo:DHAnimationInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHAnimationInfo_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::DHAnimationInfo(arg0, arg1, arg2);
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.DHAnimationInfo");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHAnimationInfo:DHAnimationInfo",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHAnimationInfo_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dhspine_DHAnimationInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHAnimationInfo)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHAnimationInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHAnimationInfo");
    tolua_cclass(tolua_S,"DHAnimationInfo","cc.DHAnimationInfo","",nullptr);

    tolua_beginmodule(tolua_S,"DHAnimationInfo");
        tolua_function(tolua_S,"new",lua_cocos2dx_dhspine_DHAnimationInfo_constructor);
        tolua_function(tolua_S,"setLoopCount",lua_cocos2dx_dhspine_DHAnimationInfo_setLoopCount);
        tolua_function(tolua_S,"setInFadeOut",lua_cocos2dx_dhspine_DHAnimationInfo_setInFadeOut);
        tolua_function(tolua_S,"setFrameTime",lua_cocos2dx_dhspine_DHAnimationInfo_setFrameTime);
        tolua_function(tolua_S,"getCurrentFrameTime",lua_cocos2dx_dhspine_DHAnimationInfo_getCurrentFrameTime);
        tolua_function(tolua_S,"getDuration",lua_cocos2dx_dhspine_DHAnimationInfo_getDuration);
        tolua_function(tolua_S,"getFrameTime",lua_cocos2dx_dhspine_DHAnimationInfo_getFrameTime);
        tolua_function(tolua_S,"update",lua_cocos2dx_dhspine_DHAnimationInfo_update);
        tolua_function(tolua_S,"updateFrameTime",lua_cocos2dx_dhspine_DHAnimationInfo_updateFrameTime);
        tolua_function(tolua_S,"getLoopCount",lua_cocos2dx_dhspine_DHAnimationInfo_getLoopCount);
        tolua_function(tolua_S,"updateToFrameIndex",lua_cocos2dx_dhspine_DHAnimationInfo_updateToFrameIndex);
        tolua_function(tolua_S,"applyEventsToFirstFrame",lua_cocos2dx_dhspine_DHAnimationInfo_applyEventsToFirstFrame);
        tolua_function(tolua_S,"apply",lua_cocos2dx_dhspine_DHAnimationInfo_apply);
        tolua_function(tolua_S,"isComplete",lua_cocos2dx_dhspine_DHAnimationInfo_isComplete);
        tolua_function(tolua_S,"getData",lua_cocos2dx_dhspine_DHAnimationInfo_getData);
        tolua_function(tolua_S,"getNextFrameTime",lua_cocos2dx_dhspine_DHAnimationInfo_getNextFrameTime);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHAnimationInfo).name();
    g_luaType[typeName] = "cc.DHAnimationInfo";
    g_typeCast["DHAnimationInfo"] = "cc.DHAnimationInfo";
    return 1;
}

int lua_cocos2dx_dhspine_DHSkeletonAnimation_registerEventsHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerEventsHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (const cocos2d::DHEvent *)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerEventsHandler'", nullptr);
            return 0;
        }
        cobj->registerEventsHandler(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:registerEventsHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerEventsHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:setTimeScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setTimeScale'", nullptr);
            return 0;
        }
        cobj->setTimeScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoRemove(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoRemove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:setAutoRemove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoRemove'", nullptr);
            return 0;
        }
        cobj->setAutoRemove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:setAutoRemove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoRemove'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSenderEventsHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSenderEventsHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSenderEventsHandler'", nullptr);
            return 0;
        }
        cobj->unregisterSenderEventsHandler();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterSenderEventsHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSenderEventsHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_registerRandomAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerRandomAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        double arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:registerRandomAnimation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHSkeletonAnimation:registerRandomAnimation");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.DHSkeletonAnimation:registerRandomAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerRandomAnimation'", nullptr);
            return 0;
        }
        cobj->registerRandomAnimation(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:registerRandomAnimation",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerRandomAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSkin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSkin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:unregisterSkin"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSkin'", nullptr);
            return 0;
        }
        cobj->unregisterSkin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterSkin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSkin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_setPause(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setPause'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:setPause");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setPause'", nullptr);
            return 0;
        }
        cobj->setPause(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:setPause",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setPause'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoApply(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoApply'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:setAutoApply");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoApply'", nullptr);
            return 0;
        }
        cobj->setAutoApply(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:setAutoApply",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoApply'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_clearCascadeChildSet(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_clearCascadeChildSet'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_clearCascadeChildSet'", nullptr);
            return 0;
        }
        cobj->clearCascadeChildSet();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:clearCascadeChildSet",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_clearCascadeChildSet'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:getRegisteredAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredAnimation'", nullptr);
            return 0;
        }
        cocos2d::DHAnimationInfo* ret = cobj->getRegisteredAnimation(arg0);
        object_to_luaval<cocos2d::DHAnimationInfo>(tolua_S, "cc.DHAnimationInfo",(cocos2d::DHAnimationInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getRegisteredAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getEventTime(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getEventTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:getEventTime"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.DHSkeletonAnimation:getEventTime"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getEventTime'", nullptr);
            return 0;
        }
        double ret = cobj->getEventTime(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getEventTime",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getEventTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_stepAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_stepAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::ValueMap arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:stepAnimation");

        ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "cc.DHSkeletonAnimation:stepAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_stepAnimation'", nullptr);
            return 0;
        }
        cobj->stepAnimation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:stepAnimation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_stepAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdateAndDelayTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdateAndDelayTransform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:onUpdateAndDelayTransform");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdateAndDelayTransform'", nullptr);
            return 0;
        }
        bool ret = cobj->onUpdateAndDelayTransform(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:onUpdateAndDelayTransform",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdateAndDelayTransform'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_registerAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:registerAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerAnimation'", nullptr);
            return 0;
        }
        cobj->registerAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:registerAnimation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.DHSkeletonAnimation:registerAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerAnimation'", nullptr);
            return 0;
        }
        cobj->registerAnimation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        bool arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:registerAnimation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.DHSkeletonAnimation:registerAnimation");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "cc.DHSkeletonAnimation:registerAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerAnimation'", nullptr);
            return 0;
        }
        cobj->registerAnimation(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:registerAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_setDirty(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setDirty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:setDirty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setDirty'", nullptr);
            return 0;
        }
        cobj->setDirty(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:setDirty",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setDirty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_isComplete(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isComplete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isComplete'", nullptr);
            return 0;
        }
        bool ret = cobj->isComplete();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:isComplete",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isComplete'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_isUpdateFill(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isUpdateFill'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:isUpdateFill");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHSkeletonAnimation:isUpdateFill");

            if (!ok) { break; }
            bool ret = cobj->isUpdateFill(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:isUpdateFill");

            if (!ok) { break; }
            bool ret = cobj->isUpdateFill(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.DHSkeletonAnimation:isUpdateFill",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isUpdateFill'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_isPlayBackwardsEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isPlayBackwardsEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isPlayBackwardsEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlayBackwardsEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:isPlayBackwardsEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isPlayBackwardsEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllRandomAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllRandomAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllRandomAnimation'", nullptr);
            return 0;
        }
        cobj->unregisterAllRandomAnimation();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterAllRandomAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllRandomAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:unregisterAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAnimation'", nullptr);
            return 0;
        }
        cobj->unregisterAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getFrameSequenceInterval(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getFrameSequenceInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getFrameSequenceInterval'", nullptr);
            return 0;
        }
        double ret = cobj->getFrameSequenceInterval();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getFrameSequenceInterval",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getFrameSequenceInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationInfo(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationInfo'", nullptr);
            return 0;
        }
        cocos2d::DHAnimationInfo* ret = cobj->getAnimationInfo();
        object_to_luaval<cocos2d::DHAnimationInfo>(tolua_S, "cc.DHAnimationInfo",(cocos2d::DHAnimationInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getAnimationInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_clearNextAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_clearNextAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_clearNextAnimation'", nullptr);
            return 0;
        }
        cobj->clearNextAnimation();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:clearNextAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_clearNextAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_removeCascadeChildFromSet(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_removeCascadeChildFromSet'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DHSkeletonAnimation* arg0;

        ok &= luaval_to_object<cocos2d::DHSkeletonAnimation>(tolua_S, 2, "cc.DHSkeletonAnimation",&arg0, "cc.DHSkeletonAnimation:removeCascadeChildFromSet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_removeCascadeChildFromSet'", nullptr);
            return 0;
        }
        cobj->removeCascadeChildFromSet(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:removeCascadeChildFromSet",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_removeCascadeChildFromSet'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_update'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:update");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHSkeletonAnimation:update");

            if (!ok) { break; }
            cobj->update(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:update");

            if (!ok) { break; }
            cobj->update(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.DHSkeletonAnimation:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationData'", nullptr);
            return 0;
        }
        cocos2d::DHAnimationData* ret = cobj->getAnimationData();
        object_to_luaval<cocos2d::DHAnimationData>(tolua_S, "cc.DHAnimationData",(cocos2d::DHAnimationData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getAnimationData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_playAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_playAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:playAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_playAnimation'", nullptr);
            return 0;
        }
        cobj->playAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:playAnimation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.DHSkeletonAnimation:playAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_playAnimation'", nullptr);
            return 0;
        }
        cobj->playAnimation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:playAnimation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.DHSkeletonAnimation:playAnimation");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.DHSkeletonAnimation:playAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_playAnimation'", nullptr);
            return 0;
        }
        cobj->playAnimation(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:playAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_playAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdate'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:onUpdate");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.DHSkeletonAnimation:onUpdate");

            if (!ok) { break; }
            bool ret = cobj->onUpdate(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:onUpdate");

            if (!ok) { break; }
            bool ret = cobj->onUpdate(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.DHSkeletonAnimation:onUpdate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_addCascadeChildToSet(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_addCascadeChildToSet'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DHSkeletonAnimation* arg0;

        ok &= luaval_to_object<cocos2d::DHSkeletonAnimation>(tolua_S, 2, "cc.DHSkeletonAnimation",&arg0, "cc.DHSkeletonAnimation:addCascadeChildToSet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_addCascadeChildToSet'", nullptr);
            return 0;
        }
        cobj->addCascadeChildToSet(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:addCascadeChildToSet",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_addCascadeChildToSet'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_applyAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_applyAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:applyAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_applyAnimation'", nullptr);
            return 0;
        }
        cobj->applyAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:applyAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_applyAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllSkin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllSkin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllSkin'", nullptr);
            return 0;
        }
        cobj->unregisterAllSkin();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterAllSkin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllSkin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_isDirty(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isDirty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isDirty'", nullptr);
            return 0;
        }
        bool ret = cobj->isDirty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:isDirty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isDirty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_isActive(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isActive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isActive'", nullptr);
            return 0;
        }
        bool ret = cobj->isActive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:isActive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_isActive'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getTimeScale'", nullptr);
            return 0;
        }
        double ret = cobj->getTimeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getTimeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterEventsHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterEventsHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterEventsHandler'", nullptr);
            return 0;
        }
        cobj->unregisterEventsHandler();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterEventsHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterEventsHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSkin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSkin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:registerSkin"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSkin'", nullptr);
            return 0;
        }
        cobj->registerSkin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:registerSkin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSkin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredRandomAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredRandomAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:getRegisteredRandomAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredRandomAnimation'", nullptr);
            return 0;
        }
        cocos2d::DHAnimationInfo* ret = cobj->getRegisteredRandomAnimation(arg0);
        object_to_luaval<cocos2d::DHAnimationInfo>(tolua_S, "cc.DHAnimationInfo",(cocos2d::DHAnimationInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getRegisteredRandomAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredRandomAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_appendNextAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_appendNextAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:appendNextAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_appendNextAnimation'", nullptr);
            return 0;
        }
        cobj->appendNextAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:appendNextAnimation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.DHSkeletonAnimation:appendNextAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_appendNextAnimation'", nullptr);
            return 0;
        }
        cobj->appendNextAnimation(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:appendNextAnimation"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.DHSkeletonAnimation:appendNextAnimation");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.DHSkeletonAnimation:appendNextAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_appendNextAnimation'", nullptr);
            return 0;
        }
        cobj->appendNextAnimation(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:appendNextAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_appendNextAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllAnimation'", nullptr);
            return 0;
        }
        cobj->unregisterAllAnimation();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterAllAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_setFrameSequenceInterval(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setFrameSequenceInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:setFrameSequenceInterval");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setFrameSequenceInterval'", nullptr);
            return 0;
        }
        cobj->setFrameSequenceInterval(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:setFrameSequenceInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setFrameSequenceInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_handleEvents(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_handleEvents'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::DHEvent* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR DHEvent*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_handleEvents'", nullptr);
            return 0;
        }
        cobj->handleEvents(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:handleEvents",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_handleEvents'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_setPlayBackwardsEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setPlayBackwardsEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHSkeletonAnimation:setPlayBackwardsEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setPlayBackwardsEnabled'", nullptr);
            return 0;
        }
        cobj->setPlayBackwardsEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:setPlayBackwardsEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_setPlayBackwardsEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationTime(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:getAnimationTime"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationTime'", nullptr);
            return 0;
        }
        double ret = cobj->getAnimationTime(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:getAnimationTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_stopAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_stopAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_stopAnimation'", nullptr);
            return 0;
        }
        cobj->stopAnimation();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:stopAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_stopAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterRandomAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterRandomAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:unregisterRandomAnimation"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterRandomAnimation'", nullptr);
            return 0;
        }
        cobj->unregisterRandomAnimation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:unregisterRandomAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterRandomAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSenderEventsHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSenderEventsHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (cocos2d::DHSkeletonAnimation *, const cocos2d::DHEvent *)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSenderEventsHandler'", nullptr);
            return 0;
        }
        cobj->registerSenderEventsHandler(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:registerSenderEventsHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSenderEventsHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_scheduleUpdateLua(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_scheduleUpdateLua'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_scheduleUpdateLua'", nullptr);
            return 0;
        }
        cobj->scheduleUpdateLua();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:scheduleUpdateLua",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_scheduleUpdateLua'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:createWithFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithFile'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonAnimation* ret = cocos2d::DHSkeletonAnimation::createWithFile(arg0);
        object_to_luaval<cocos2d::DHSkeletonAnimation>(tolua_S, "cc.DHSkeletonAnimation",(cocos2d::DHSkeletonAnimation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeletonAnimation:createWithFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::DHSkeletonData* arg0;
        ok &= luaval_to_object<cocos2d::DHSkeletonData>(tolua_S, 2, "cc.DHSkeletonData",&arg0, "cc.DHSkeletonAnimation:createWithData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithData'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonAnimation* ret = cocos2d::DHSkeletonAnimation::createWithData(arg0);
        object_to_luaval<cocos2d::DHSkeletonAnimation>(tolua_S, "cc.DHSkeletonAnimation",(cocos2d::DHSkeletonAnimation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeletonAnimation:createWithData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeletonAnimation:createWithKey"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithKey'", nullptr);
            return 0;
        }
        cocos2d::DHSkeletonAnimation* ret = cocos2d::DHSkeletonAnimation::createWithKey(arg0);
        object_to_luaval<cocos2d::DHSkeletonAnimation>(tolua_S, "cc.DHSkeletonAnimation",(cocos2d::DHSkeletonAnimation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHSkeletonAnimation:createWithKey",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithKey'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHSkeletonAnimation_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DHSkeletonData* arg0;

        ok &= luaval_to_object<cocos2d::DHSkeletonData>(tolua_S, 2, "cc.DHSkeletonData",&arg0, "cc.DHSkeletonAnimation:DHSkeletonAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::DHSkeletonAnimation(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.DHSkeletonAnimation");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:DHSkeletonAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dhspine_DHSkeletonAnimation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHSkeletonAnimation)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHSkeletonAnimation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHSkeletonAnimation");
    tolua_cclass(tolua_S,"DHSkeletonAnimation","cc.DHSkeletonAnimation","cc.DHSkeleton",nullptr);

    tolua_beginmodule(tolua_S,"DHSkeletonAnimation");
        tolua_function(tolua_S,"new",lua_cocos2dx_dhspine_DHSkeletonAnimation_constructor);
        tolua_function(tolua_S,"registerEventsHandler",lua_cocos2dx_dhspine_DHSkeletonAnimation_registerEventsHandler);
        tolua_function(tolua_S,"setTimeScale",lua_cocos2dx_dhspine_DHSkeletonAnimation_setTimeScale);
        tolua_function(tolua_S,"setAutoRemove",lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoRemove);
        tolua_function(tolua_S,"unregisterSenderEventsHandler",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSenderEventsHandler);
        tolua_function(tolua_S,"registerRandomAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_registerRandomAnimation);
        tolua_function(tolua_S,"unregisterSkin",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterSkin);
        tolua_function(tolua_S,"setPause",lua_cocos2dx_dhspine_DHSkeletonAnimation_setPause);
        tolua_function(tolua_S,"setAutoApply",lua_cocos2dx_dhspine_DHSkeletonAnimation_setAutoApply);
        tolua_function(tolua_S,"clearCascadeChildSet",lua_cocos2dx_dhspine_DHSkeletonAnimation_clearCascadeChildSet);
        tolua_function(tolua_S,"getRegisteredAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredAnimation);
        tolua_function(tolua_S,"getEventTime",lua_cocos2dx_dhspine_DHSkeletonAnimation_getEventTime);
        tolua_function(tolua_S,"stepAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_stepAnimation);
        tolua_function(tolua_S,"onUpdateAndDelayTransform",lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdateAndDelayTransform);
        tolua_function(tolua_S,"registerAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_registerAnimation);
        tolua_function(tolua_S,"setDirty",lua_cocos2dx_dhspine_DHSkeletonAnimation_setDirty);
        tolua_function(tolua_S,"isComplete",lua_cocos2dx_dhspine_DHSkeletonAnimation_isComplete);
        tolua_function(tolua_S,"isUpdateFill",lua_cocos2dx_dhspine_DHSkeletonAnimation_isUpdateFill);
        tolua_function(tolua_S,"isPlayBackwardsEnabled",lua_cocos2dx_dhspine_DHSkeletonAnimation_isPlayBackwardsEnabled);
        tolua_function(tolua_S,"unregisterAllRandomAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllRandomAnimation);
        tolua_function(tolua_S,"unregisterAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAnimation);
        tolua_function(tolua_S,"getFrameSequenceInterval",lua_cocos2dx_dhspine_DHSkeletonAnimation_getFrameSequenceInterval);
        tolua_function(tolua_S,"getAnimationInfo",lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationInfo);
        tolua_function(tolua_S,"clearNextAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_clearNextAnimation);
        tolua_function(tolua_S,"removeCascadeChildFromSet",lua_cocos2dx_dhspine_DHSkeletonAnimation_removeCascadeChildFromSet);
        tolua_function(tolua_S,"update",lua_cocos2dx_dhspine_DHSkeletonAnimation_update);
        tolua_function(tolua_S,"getAnimationData",lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationData);
        tolua_function(tolua_S,"playAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_playAnimation);
        tolua_function(tolua_S,"onUpdate",lua_cocos2dx_dhspine_DHSkeletonAnimation_onUpdate);
        tolua_function(tolua_S,"addCascadeChildToSet",lua_cocos2dx_dhspine_DHSkeletonAnimation_addCascadeChildToSet);
        tolua_function(tolua_S,"applyAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_applyAnimation);
        tolua_function(tolua_S,"unregisterAllSkin",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllSkin);
        tolua_function(tolua_S,"isDirty",lua_cocos2dx_dhspine_DHSkeletonAnimation_isDirty);
        tolua_function(tolua_S,"isActive",lua_cocos2dx_dhspine_DHSkeletonAnimation_isActive);
        tolua_function(tolua_S,"getTimeScale",lua_cocos2dx_dhspine_DHSkeletonAnimation_getTimeScale);
        tolua_function(tolua_S,"unregisterEventsHandler",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterEventsHandler);
        tolua_function(tolua_S,"registerSkin",lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSkin);
        tolua_function(tolua_S,"getRegisteredRandomAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_getRegisteredRandomAnimation);
        tolua_function(tolua_S,"appendNextAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_appendNextAnimation);
        tolua_function(tolua_S,"unregisterAllAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterAllAnimation);
        tolua_function(tolua_S,"setFrameSequenceInterval",lua_cocos2dx_dhspine_DHSkeletonAnimation_setFrameSequenceInterval);
        tolua_function(tolua_S,"handleEvents",lua_cocos2dx_dhspine_DHSkeletonAnimation_handleEvents);
        tolua_function(tolua_S,"setPlayBackwardsEnabled",lua_cocos2dx_dhspine_DHSkeletonAnimation_setPlayBackwardsEnabled);
        tolua_function(tolua_S,"getAnimationTime",lua_cocos2dx_dhspine_DHSkeletonAnimation_getAnimationTime);
        tolua_function(tolua_S,"stopAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_stopAnimation);
        tolua_function(tolua_S,"unregisterRandomAnimation",lua_cocos2dx_dhspine_DHSkeletonAnimation_unregisterRandomAnimation);
        tolua_function(tolua_S,"registerSenderEventsHandler",lua_cocos2dx_dhspine_DHSkeletonAnimation_registerSenderEventsHandler);
        tolua_function(tolua_S,"scheduleUpdateLua",lua_cocos2dx_dhspine_DHSkeletonAnimation_scheduleUpdateLua);
        tolua_function(tolua_S,"createWithFile", lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithFile);
        tolua_function(tolua_S,"createWithData", lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithData);
        tolua_function(tolua_S,"createWithKey", lua_cocos2dx_dhspine_DHSkeletonAnimation_createWithKey);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHSkeletonAnimation).name();
    g_luaType[typeName] = "cc.DHSkeletonAnimation";
    g_typeCast["DHSkeletonAnimation"] = "cc.DHSkeletonAnimation";
    return 1;
}

int lua_cocos2dx_dhspine_DHActionAnimate_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHActionAnimate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::DHSkeletonAnimation* arg0;
        std::string arg1;
        ok &= luaval_to_object<cocos2d::DHSkeletonAnimation>(tolua_S, 2, "cc.DHSkeletonAnimation",&arg0, "cc.DHActionAnimate:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DHActionAnimate:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHActionAnimate_create'", nullptr);
            return 0;
        }
        cocos2d::DHActionAnimate* ret = cocos2d::DHActionAnimate::create(arg0, arg1);
        object_to_luaval<cocos2d::DHActionAnimate>(tolua_S, "cc.DHActionAnimate",(cocos2d::DHActionAnimate*)ret);
        return 1;
    }
    if (argc == 3)
    {
        cocos2d::DHSkeletonAnimation* arg0;
        std::string arg1;
        int arg2;
        ok &= luaval_to_object<cocos2d::DHSkeletonAnimation>(tolua_S, 2, "cc.DHSkeletonAnimation",&arg0, "cc.DHActionAnimate:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DHActionAnimate:create");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.DHActionAnimate:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHActionAnimate_create'", nullptr);
            return 0;
        }
        cocos2d::DHActionAnimate* ret = cocos2d::DHActionAnimate::create(arg0, arg1, arg2);
        object_to_luaval<cocos2d::DHActionAnimate>(tolua_S, "cc.DHActionAnimate",(cocos2d::DHActionAnimate*)ret);
        return 1;
    }
    if (argc == 4)
    {
        cocos2d::DHSkeletonAnimation* arg0;
        std::string arg1;
        int arg2;
        double arg3;
        ok &= luaval_to_object<cocos2d::DHSkeletonAnimation>(tolua_S, 2, "cc.DHSkeletonAnimation",&arg0, "cc.DHActionAnimate:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.DHActionAnimate:create");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.DHActionAnimate:create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "cc.DHActionAnimate:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHActionAnimate_create'", nullptr);
            return 0;
        }
        cocos2d::DHActionAnimate* ret = cocos2d::DHActionAnimate::create(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::DHActionAnimate>(tolua_S, "cc.DHActionAnimate",(cocos2d::DHActionAnimate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHActionAnimate:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHActionAnimate_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_dhspine_DHActionAnimate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHActionAnimate)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHActionAnimate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHActionAnimate");
    tolua_cclass(tolua_S,"DHActionAnimate","cc.DHActionAnimate","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"DHActionAnimate");
        tolua_function(tolua_S,"create", lua_cocos2dx_dhspine_DHActionAnimate_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHActionAnimate).name();
    g_luaType[typeName] = "cc.DHActionAnimate";
    g_typeCast["DHActionAnimate"] = "cc.DHActionAnimate";
    return 1;
}

int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStencil(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStencil'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cc.DHClippingSkeletonAnimation:setStencil");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStencil'", nullptr);
            return 0;
        }
        cobj->setStencil(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:setStencil",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStencil'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawBegin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawBegin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Mat4 arg0;
        unsigned int arg1;

        ok &= luaval_to_mat4(tolua_S, 2, &arg0, "cc.DHClippingSkeletonAnimation:drawBegin");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "cc.DHClippingSkeletonAnimation:drawBegin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawBegin'", nullptr);
            return 0;
        }
        cobj->drawBegin(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:drawBegin",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawBegin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getStencil(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getStencil'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getStencil'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getStencil();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:getStencil",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getStencil'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_isInverted(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_isInverted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_isInverted'", nullptr);
            return 0;
        }
        bool ret = cobj->isInverted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:isInverted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_isInverted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.DHClippingSkeletonAnimation:setStartBoundBySlotIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotIndex'", nullptr);
            return 0;
        }
        cobj->setStartBoundBySlotIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:setStartBoundBySlotIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_visit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "cc.DHClippingSkeletonAnimation:visit");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "cc.DHClippingSkeletonAnimation:visit");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "cc.DHClippingSkeletonAnimation:visit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_visit'", nullptr);
            return 0;
        }
        cobj->visit(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClippingBefore(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClippingBefore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClippingBefore'", nullptr);
            return 0;
        }
        cobj->drawClippingBefore();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:drawClippingBefore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClippingBefore'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClipping(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClipping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Mat4 arg0;
        unsigned int arg1;

        ok &= luaval_to_mat4(tolua_S, 2, &arg0, "cc.DHClippingSkeletonAnimation:drawClipping");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "cc.DHClippingSkeletonAnimation:drawClipping");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClipping'", nullptr);
            return 0;
        }
        cobj->drawClipping(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:drawClipping",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClipping'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "cc.DHClippingSkeletonAnimation:draw");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "cc.DHClippingSkeletonAnimation:draw");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "cc.DHClippingSkeletonAnimation:draw");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_draw'", nullptr);
            return 0;
        }
        cobj->draw(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.DHClippingSkeletonAnimation:setEndBoundBySlotIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotIndex'", nullptr);
            return 0;
        }
        cobj->setEndBoundBySlotIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:setEndBoundBySlotIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHClippingSkeletonAnimation:setEndBoundBySlotName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotName'", nullptr);
            return 0;
        }
        cobj->setEndBoundBySlotName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:setEndBoundBySlotName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExitTransitionDidStart(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExitTransitionDidStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExitTransitionDidStart'", nullptr);
            return 0;
        }
        cobj->onExitTransitionDidStart();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:onExitTransitionDidStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExitTransitionDidStart'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setAlphaThreshold(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setAlphaThreshold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.DHClippingSkeletonAnimation:setAlphaThreshold");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setAlphaThreshold'", nullptr);
            return 0;
        }
        cobj->setAlphaThreshold(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:setAlphaThreshold",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setAlphaThreshold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawEnd(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Mat4 arg0;
        unsigned int arg1;

        ok &= luaval_to_mat4(tolua_S, 2, &arg0, "cc.DHClippingSkeletonAnimation:drawEnd");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "cc.DHClippingSkeletonAnimation:drawEnd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawEnd'", nullptr);
            return 0;
        }
        cobj->drawEnd(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:drawEnd",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExit'", nullptr);
            return 0;
        }
        cobj->onExit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setInverted(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setInverted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.DHClippingSkeletonAnimation:setInverted");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setInverted'", nullptr);
            return 0;
        }
        cobj->setInverted(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:setInverted",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setInverted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHClippingSkeletonAnimation:setStartBoundBySlotName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotName'", nullptr);
            return 0;
        }
        cobj->setStartBoundBySlotName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:setStartBoundBySlotName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getAlphaThreshold(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getAlphaThreshold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getAlphaThreshold'", nullptr);
            return 0;
        }
        double ret = cobj->getAlphaThreshold();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:getAlphaThreshold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getAlphaThreshold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_initWithStencil(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_initWithStencil'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "cc.DHClippingSkeletonAnimation:initWithStencil");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_initWithStencil'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithStencil(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:initWithStencil",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_initWithStencil'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnterTransitionDidFinish(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::DHClippingSkeletonAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnterTransitionDidFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnterTransitionDidFinish'", nullptr);
            return 0;
        }
        cobj->onEnterTransitionDidFinish();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:onEnterTransitionDidFinish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnterTransitionDidFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        cocos2d::Node* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHClippingSkeletonAnimation:createWithFile"); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "cc.DHClippingSkeletonAnimation:createWithFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithFile'", nullptr);
            return 0;
        }
        cocos2d::DHClippingSkeletonAnimation* ret = cocos2d::DHClippingSkeletonAnimation::createWithFile(arg0, arg1);
        object_to_luaval<cocos2d::DHClippingSkeletonAnimation>(tolua_S, "cc.DHClippingSkeletonAnimation",(cocos2d::DHClippingSkeletonAnimation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHClippingSkeletonAnimation:createWithFile",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::DHSkeletonData* arg0;
        cocos2d::Node* arg1;
        ok &= luaval_to_object<cocos2d::DHSkeletonData>(tolua_S, 2, "cc.DHSkeletonData",&arg0, "cc.DHClippingSkeletonAnimation:createWithData");
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "cc.DHClippingSkeletonAnimation:createWithData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithData'", nullptr);
            return 0;
        }
        cocos2d::DHClippingSkeletonAnimation* ret = cocos2d::DHClippingSkeletonAnimation::createWithData(arg0, arg1);
        object_to_luaval<cocos2d::DHClippingSkeletonAnimation>(tolua_S, "cc.DHClippingSkeletonAnimation",(cocos2d::DHClippingSkeletonAnimation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHClippingSkeletonAnimation:createWithData",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.DHClippingSkeletonAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        cocos2d::Node* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHClippingSkeletonAnimation:createWithKey"); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "cc.DHClippingSkeletonAnimation:createWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithKey'", nullptr);
            return 0;
        }
        cocos2d::DHClippingSkeletonAnimation* ret = cocos2d::DHClippingSkeletonAnimation::createWithKey(arg0, arg1);
        object_to_luaval<cocos2d::DHClippingSkeletonAnimation>(tolua_S, "cc.DHClippingSkeletonAnimation",(cocos2d::DHClippingSkeletonAnimation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.DHClippingSkeletonAnimation:createWithKey",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithKey'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::DHClippingSkeletonAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DHSkeletonData* arg0;

        ok &= luaval_to_object<cocos2d::DHSkeletonData>(tolua_S, 2, "cc.DHSkeletonData",&arg0, "cc.DHClippingSkeletonAnimation:DHClippingSkeletonAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::DHClippingSkeletonAnimation(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.DHClippingSkeletonAnimation");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHClippingSkeletonAnimation:DHClippingSkeletonAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DHClippingSkeletonAnimation)");
    return 0;
}

int lua_register_cocos2dx_dhspine_DHClippingSkeletonAnimation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.DHClippingSkeletonAnimation");
    tolua_cclass(tolua_S,"DHClippingSkeletonAnimation","cc.DHClippingSkeletonAnimation","cc.DHSkeletonAnimation",nullptr);

    tolua_beginmodule(tolua_S,"DHClippingSkeletonAnimation");
        tolua_function(tolua_S,"new",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_constructor);
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnter);
        tolua_function(tolua_S,"setStencil",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStencil);
        tolua_function(tolua_S,"drawBegin",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawBegin);
        tolua_function(tolua_S,"getStencil",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getStencil);
        tolua_function(tolua_S,"isInverted",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_isInverted);
        tolua_function(tolua_S,"setStartBoundBySlotIndex",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotIndex);
        tolua_function(tolua_S,"visit",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_visit);
        tolua_function(tolua_S,"drawClippingBefore",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClippingBefore);
        tolua_function(tolua_S,"drawClipping",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawClipping);
        tolua_function(tolua_S,"draw",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_draw);
        tolua_function(tolua_S,"setEndBoundBySlotIndex",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotIndex);
        tolua_function(tolua_S,"setEndBoundBySlotName",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setEndBoundBySlotName);
        tolua_function(tolua_S,"onExitTransitionDidStart",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExitTransitionDidStart);
        tolua_function(tolua_S,"setAlphaThreshold",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setAlphaThreshold);
        tolua_function(tolua_S,"drawEnd",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_drawEnd);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onExit);
        tolua_function(tolua_S,"setInverted",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setInverted);
        tolua_function(tolua_S,"setStartBoundBySlotName",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_setStartBoundBySlotName);
        tolua_function(tolua_S,"getAlphaThreshold",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_getAlphaThreshold);
        tolua_function(tolua_S,"initWithStencil",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_initWithStencil);
        tolua_function(tolua_S,"onEnterTransitionDidFinish",lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_onEnterTransitionDidFinish);
        tolua_function(tolua_S,"createWithFile", lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithFile);
        tolua_function(tolua_S,"createWithData", lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithData);
        tolua_function(tolua_S,"createWithKey", lua_cocos2dx_dhspine_DHClippingSkeletonAnimation_createWithKey);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::DHClippingSkeletonAnimation).name();
    g_luaType[typeName] = "cc.DHClippingSkeletonAnimation";
    g_typeCast["DHClippingSkeletonAnimation"] = "cc.DHClippingSkeletonAnimation";
    return 1;
}
TOLUA_API int register_all_cocos2dx_dhspine(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_dhspine_DHBone(tolua_S);
	lua_register_cocos2dx_dhspine_DHSlot(tolua_S);
	lua_register_cocos2dx_dhspine_DHSkeletonData(tolua_S);
	lua_register_cocos2dx_dhspine_DHActionAnimate(tolua_S);
	lua_register_cocos2dx_dhspine_DHSkeleton(tolua_S);
	lua_register_cocos2dx_dhspine_DHSkeletonAnimation(tolua_S);
	lua_register_cocos2dx_dhspine_DHClippingSkeletonAnimation(tolua_S);
	lua_register_cocos2dx_dhspine_DHSkeletonDataCache(tolua_S);
	lua_register_cocos2dx_dhspine_DHAnimationInfo(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

