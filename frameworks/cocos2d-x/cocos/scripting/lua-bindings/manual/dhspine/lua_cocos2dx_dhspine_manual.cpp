/****************************************************************************
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "scripting/lua-bindings/manual/dhspine/lua_cocos2dx_dhspine_manual.hpp"
#include "scripting/lua-bindings/auto/lua_cocos2dx_dhspine.hpp"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "scripting/lua-bindings/manual/dhspine/DHSkeletonAnimation.h"
#include "scripting/lua-bindings/manual/dhspine/DHSkeleton.h"

int lua_cocos2dx_dhspine_DHSkeletonAnimation_registerLuaHandler(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerLuaHandler'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        ok &= toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err);
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_custom_DHSkeletonAnimation_registerLuaHandler'", &tolua_err);
            return 0;
        }
#endif
        
        LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
        cobj->registerLuaHandler(nHandler);
        
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeletonAnimation:registerLuaHandler",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeletonAnimation_registerLuaHandler'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_dhspine_DHSkeleton_getIntersectionBySlot(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_dhspine_DHSkeleton_getIntersectionBySlot'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3)
    {
        const char* arg0;
        cocos2d::Point arg1;
        cocos2d::Point arg2;
        
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.DHSkeleton:getIntersectionBySlot"); arg0 = arg0_tmp.c_str();
        
        ok &= luaval_to_point(tolua_S, 3, &arg1, "cc.DHSkeleton:getIntersectionBySlot");
        
        ok &= luaval_to_point(tolua_S, 4, &arg2, "cc.DHSkeleton:getIntersectionBySlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_dhspine_DHSkeleton_getIntersectionBySlot'", nullptr);
            return 0;
        }
        std::pair<bool, cocos2d::Vec2> ret = cobj->getIntersectionBySlot(arg0, arg1, arg2);
        
        lua_newtable(tolua_S);
        lua_pushstring(tolua_S, "intersect");
        tolua_pushboolean(tolua_S, ret.first);
        lua_rawset(tolua_S, -3);
        lua_pushstring(tolua_S, "pointX");
        lua_pushnumber(tolua_S, (lua_Number) ret.second.x);
        lua_rawset(tolua_S, -3);
        lua_pushstring(tolua_S, "pointY");
        lua_pushnumber(tolua_S, (lua_Number) ret.second.y);
        lua_rawset(tolua_S, -3);
        
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.DHSkeleton:getIntersectionBySlot",argc, 3);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_dhspine_DHSkeleton_getIntersectionBySlot'.",&tolua_err);
#endif
    
    return 0;
}

static void extendDHSkeleton(lua_State* tolua_S)
{
    lua_pushstring(tolua_S, "cc.DHSkeleton");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S,"getIntersectionBySlot",lua_cocos2dx_dhspine_DHSkeleton_getIntersectionBySlot);
    }
    lua_pop(tolua_S, 1);
}

static void extendDHSkeletonAnimation(lua_State* tolua_S)
{
    lua_pushstring(tolua_S, "cc.DHSkeletonAnimation");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S,"registerLuaHandler",lua_cocos2dx_dhspine_DHSkeletonAnimation_registerLuaHandler);
    }
    lua_pop(tolua_S, 1);
}

int register_all_cocos2dx_dhspine_manual(lua_State* L)
{
    if (nullptr == L)
        return 0;

    extendDHSkeleton(L);
    extendDHSkeletonAnimation(L);
    
    return 0;
}

int register_dhspine_module(lua_State* L)
{
    lua_getglobal(L, "_G");
    if (lua_istable(L,-1))//stack:...,_G,
    {
        register_all_cocos2dx_dhspine(L);
        register_all_cocos2dx_dhspine_manual(L);
    }
    lua_pop(L, 1);

    return 1;
}
