
-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 2

-- use framework, will disable all deprecated API, false - use legacy API
CC_USE_FRAMEWORK = true

-- show FPS on screen
CC_SHOW_FPS = true

-- disable create unexpected global variable
CC_DISABLE_GLOBAL = true

-- for module display
CC_DESIGN_RESOLUTION = {
    width = 640,
    height = 1138,
    autoscale = "SHOW_ALL",
    callback = function(framesize)
        local ratio = framesize.width / framesize.height
        if ratio <= 1.34 then
            -- iPad 768*1024(1536*2048) is 4:3 screen
            return {autoscale = "SHOW_ALL"}
        end
    end
}

--配置预加载
CC_CONFIG = 
{
    { src = 'conf/tower.conf', name = 'tower' },              --塔的配置
    { src = 'conf/bullet.conf', name = 'bullet' },            --子弹的配置
}

--是否显示DEBUG编辑器模式下的圈绘图
CC_IS_SHOW_DEBUG = true

-----------------------------------------------------
-----界面方面的枚举标记
-----------------------------------------------------

--界面名称标记
CC_UI_TAG = 
{
    UI_SignIn   = "signIn",         --登录界面
    UI_Register = "register",       --注册界面
    UI_MainHall = "mainHall"        --游戏主大厅
}

--界面跳转的方式
CC_UI_GOTO_TPYE = 
{
    UI_Add_Layer = 1,           --层直接覆盖跳转
    UI_Add_Bomb  = 2,           --弹框覆盖跳转
    UI_Rep_Scene = 3            --场景切换
}

CC_UI_DATA_TPYE = 
{
    UI_PlayName    = "PlayName",           --玩家数据
    UI_Wallet      = "Wallet",             --钱包数据
    UI_Level       = "Level"               --等级信息
}

-----------------------------------------------------
-----核心战斗方面的枚举标记
-----------------------------------------------------
--战斗中的层级关系
CC_GAME_LAYER_LEVEL = 
{
    Layer_scene = 10,    --最底层的地形层 
    Layer_scene_debug = 11,    --最底层的地形层上的debug模式绘制层
    
    Layer_scene_space = 50,     --空地所在层
    Layer_scene_enemy = 100,   --怪物所在层级
    Layer_scene_top = 150,      --上层地形
    Layer_scene_tower = 180,    --塔所在层
    Layer_scene_bullet = 190,    --子弹所在的层


    Layer_scene_sky =  400,   --云层

    Layer_fight_main_ui = 500,   --主操作层所在层级
    Layer_max = 9999     --最高层地形
}

--参与者的阵营属性
CC_CAMP = 
{
    Camp_Own        = 1,        --己方阵营，可以操作的英雄，士兵，防御塔
    Camp_Friend     = 2,        --友军，无法操作，但可以帮助你攻击敌方的士兵，防御塔，等单位  
    Camp_Enemy      = 3,        --敌军，无法操作，会攻击己方，友放英雄，士兵单位。
    Camp_Other      = 4,        --第三方阵营，可能存在不分敌我的攻击单位。
    Camp_Non        = 5,        --无阵营者，参与游戏演出，如会动的螃蟹，会动的树木。等视为无阵营者，或许可以被攻击产生金币
    Camp_All        = 6         --所有
}

--演员类的类型，该类型主要为塔升级作为标示，如果标记为Type_Actor
--说明作者并不在意这个类的类型的运算
CC_ACTOR_TYPE =
{
    Type_Actor          =  1,       --普通演员类型,
    Type_Space          =  2,       --空地类型
    Type_Tower_Arrow    =  3        --箭塔
} 

--战斗缓存plist组
CC_PLIST = 
{
    "plist/enemy/babyspirit.plist",
    "plist/enemy/devilobserver.plist",
    "plist/enemy/goblin.plist",
    "plist/enemy/orcgeneral.plist",
    "plist/enemy/babyspirit.plist",
    "plist/towers/tower.plist",
    "plist/bullet/bullet1.plist",
}

--敌人状态标记
CC_ENEMY_STATE = 
{
    State_Ready= 1,             -- 准备状态，还没有到出生的时候
    State_Born = 2,             -- 出生状态
    State_Walk = 3,             -- 行走状态
    State_Hit  = 4,             -- 被击状态
    State_Die  = 5              -- 死亡状态
}

--生命体的移动方向模式记录
CC_LIFT_WALK_DIR = 
{
    Walk_Left  = 1,          --左移动
    Walk_Right = 2,          --右移动
    Walk_Up    = 3,          --上移动
    Walk_Down  = 4,          --下移动
    Walk_All   = 5             
}

CC_GAME_EVENT = 
{
    GameEvent_EnemyGoOver = 1,      -- 怪物走到了最后的出口
    GameEvent_LifeDie = 2,          -- 生命体被击杀
    GameEvent_WaveDataReady = 50,   -- 当前波次信息准备Ok,附带波次数据
    GameEvent_NextWaveNeed  = 51,    -- 请求下一个波次的怪物，

    GameEvent_MainUIDataChange = 100,     --游戏场景数据变化
    GameEvent_GoldChange    =   101,     --金币数据变更      

    GameEvent_BuildTower    =   150,     --建造防御塔
    GameEvent_BuildBullet   =   151,      --请求创建子弹
    GameEvent_BulletCollision =  153        --子弹碰撞检测请求

}

CC_TIME_SCALE = 1