
-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 2

-- use framework, will disable all deprecated API, false - use legacy API
CC_USE_FRAMEWORK = true

-- show FPS on screen
CC_SHOW_FPS = true

-- disable create unexpected global variable
CC_DISABLE_GLOBAL = true

-- for module display
CC_DESIGN_RESOLUTION = 
{
    width = 1280,
    height = 960,
    autoscale = "SHOW_ALL",
    callback = function(framesize)
        local ratio = framesize.width / framesize.height
        if ratio <= 1.34 then
            -- iPad 768*1024(1334x750 1536*2048) is 4:3 screen
            return {autoscale = "SHOW_ALL"}
        end
    end
}

--层级关系
CC_LAYER_LEVEL = 
{
    Layer_scene = 10,    --最底层的地形层 
    Layer_scene_debug = 11,    --最底层的地形层上的debug模式绘制层
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
