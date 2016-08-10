local Enemy = class("Enemy")
cs.class.setFather(Enemy,"gameFight.Actor.Life")

function Enemy:create()
    --设定怪物类型
    self:setActorCamp( CC_CAMP.Camp_Enemy)
    self.NowPosID = 1 --当前行动节点ID

    
    --创建怪物蹄片
    self.mainSprite = cc.Sprite:create()
    self.mainSprite:setAnchorPoint(cc.p(0,0))
    self.LifeLayer:addChild(self.mainSprite , 10)

    return Enemy
end

function Enemy:setData(ActorData)


    self.ActorData = {}
    self.ActorData.name         = ActorData.name            -- 怪物名字
    self.ActorData.life         = ActorData.life            -- 生命值
    self.ActorData.speed        = ActorData.speed           -- 速度值
    self.ActorData.mainRes      = ActorData.mainRes         -- 资源（前缀资源，要求最后一位加/ 如babyspirit/walk/）
    self.ActorData.stand        = ActorData.stand           -- 站立动作名字
    self.ActorData.walk         = ActorData.walk            -- 位移动作名字
    self.ActorData.road         = ActorData.road            -- 行走道路ID
end

function Enemy:stand()
    
end

function Enemy:walk()
    print("Enemy:setLifeData()")
    cs.logger.i("self.ActorData.mainRes",self.ActorData.mainRes)
    cs.logger.i("self.ActorData.walk",self.ActorData.walk)

    local fristFrame , animation = singleUtil:getInstance():createFrameCache(self.ActorData.mainRes ,self.ActorData.walk, 0.25,7)
    self.mainSprite:setSpriteFrame(fristFrame)
    self.mainSprite:runAction(cc.RepeatForever:create(cc.Animate:create(animation)))
    --self.mainSprite:setPosition(cc.p(200,200))
end

function Enemy:bigen()
    local myTestData = singleLoadMap:getInstance().mapData["map"]["roads"]["road"][self.ActorData.road]
    local pos = loadstring("return "..myTestData["p"][self.NowPosID])();
    print(myTestData["p"][self.NowPosID])


    cc.RepeatForever:create(cc.Animate:create(animation))


    self.RootLayer:setPosition(cc.p(pos[1],pos[2]))
end

return Enemy
