local tower = class("tower",require("gameFight.actor.life"))

function tower:ctor()
    --self:setData()
    tower.super.ctor(self)
    self:setActorCamp( CC_CAMP.Camp_Own)
    self:setAnchorPoint(cc.p(0.5,0.5))  --设定根节点的锚点

    --创建一个塔的造型空图片
    self.mainSprite = cc.Sprite:create()
    self.mainSprite:setAnchorPoint(cc.p(0.5,0.3))
    self.mainSprite:setPosition(cc.p(0,0))

	--singleManagerUI:getInstance():bindListener(self.lifeLayer,self,"towerImage")
end

--存储数据
function tower:setTowerData(data)
    self.towerData = data 
end

function tower:createTowerWithData()

    print("createTowerWithData = "..self.towerData['png'])
    local fristFrame , animation = singleUtil:getInstance():createFrameCache(self.towerData['png'] ,"/standby/", 0.25, 9, 20, "%02d.png")
    
    if fristFrame == nil then
        print(" fristFrame == nil "..self.towerData['png'])
    end

    if animation == nil then
        print(" animation == nil "..self.towerData['png'])
    end

    
    self.mainSprite:setSpriteFrame(fristFrame)
    self.mainSprite:runAction(cc.RepeatForever:create(cc.Animate:create(animation)))
    self.lifeLayer:addChild(self.mainSprite , 10)
end

function tower:towerImageTouchEnded()

end

return tower