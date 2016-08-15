local fightMainUI = class("fightMainUI", function() return cc.Layer:create() end)

function fightMainUI:ctor()
    --初始化监听数据，初始化数据


end

--该函数需要在setData完成后调用，生成界面
function fightMainUI:refreshUI()
    --创建生命图片
    local lifeSp = cc.Sprite:create("plist/fight/life.png")
    lifeSp:setPosition(cc.p(100,960))
    lifeSp:setAnchorPoint(cc.p(0,1))
    self:addChild(lifeSp )

    --创建金币图片
    local golbSp = cc.Sprite:create("plist/fight/golb.png")
    golbSp:setPosition(cc.p(400,960))
    golbSp:setAnchorPoint(cc.p(0,1))
    self:addChild(golbSp )

    --创建波次
    local waveSp = cc.Sprite:create("plist/fight/wave.png")
    waveSp:setPosition(cc.p(700,960))
    waveSp:setAnchorPoint(cc.p(0,1))
    self:addChild(waveSp )
end

--设定必要数据
function fightMainUI:setData(uiData)

end

return fightMainUI