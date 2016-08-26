local life = class("life",require("gameFight.actor.actor"))

function life:ctor()
    --self:setData()
    life.super.ctor(self)

    --自身根节点，用于怪物移动
    self:setAnchorPoint(cc.p(0.5,0.5))	--设定根节点的锚点

    --生命值的数据结构，用于后面子类使用
    self.actorData = {}
    self.actorData.life         = 10            -- 生命初始值
    self.actorData.speed        = 10            -- 速度初始值
    self.actorData.immine       = 1             -- 初始被击打优先级
    self.actorData.speedBuff    = 0             -- buff影响的速度值 
    self.actorData.direction    = CC_LIFT_WALK_DIR.Walk_All --移动方向初始化
    
    self.lifeLayer = cc.Layer:create() 			--生命节点，用于怪物的翻转已经特效等
    self.lifeLayer:setAnchorPoint(cc.p(0.5,0.5))	--设定节点的锚点
    self:addChild(self.lifeLayer,10)            --加入根节点

    self.buffLayer = cc.Layer:create()          --生命节点，用于怪物的翻转已经特效等
    self.buffLayer:setAnchorPoint(cc.p(0.5,0.5))    --设定节点的锚点
    self:addChild(self.buffLayer,11)            --加入根节点

    self.buffData = {}
    self.buffNextAdd = {}
    self.buffNextRemove = {}
end

function life:_checklife()
    if self.actorData.life  <= 0 then      
        singleGameEventPool:getInstance():SendEventForListener(CC_GAME_EVENT.GameEvent_LifeDie, self, self.actorData)
        return false
    end
    return true
end

function life:addBuffDataForID(buffID)
    --判断BUFF是否存在，暂时考虑不能叠加BUFF
    for k,v in pairs(self.buffData) do
        if v["id"] == buffID then
            return
        end
    end
    --驱散BUFF
    local buffDataItem = cs.util.tablecpy(cs.conf.a("buff",buffID))

    if buffDataItem["dispelCode"] ~= nil then
        for k,v in pairs(buffDataItem["dispelCode"]) do
            self:removeBuffDataForID(v)
        end
    end
    --加入这个buff
    
    table.insert(self.buffNextAdd , buffDataItem)
end

function life:removeBuffDataForID(buffID)
    for k,v in pairs(self.buffData) do
        if v["id"] == buffID then
            table.insert(self.buffNextRemove , buffID)
            return
        end
    end
end

--被击事件处理
function life:Hit(parameter)
    if self.actorData.immine > parameter.attType then
        return
    end

    --buff方面
    if parameter.buffId ~= 0 then
        parameter.targetEnemy:addBuffDataForID(parameter.buffId)
    end

    self.actorData.life = self.actorData.life - parameter.att

    --判断有没有攻击消失的BUFF
    for k,v in pairs(self.buffData) do
        --如果是被击打消失
        if v['loseType'] == "Hit" then
            print("loseType = hit")
            table.insert(self.buffNextRemove,v["id"])
        end
    end
end

function life:_upDataBuff(dt)
    --处理buff主要逻辑
    for k,v in pairs(self.buffData) do
        --如果是时间结束
        if v['loseType'] == "Countdown" then
            v['duration'] = v['duration'] - dt

            if v['duration'] <= 0 then
                table.insert(self.buffNextRemove,v)
            end
        end
    end

    --删除等待中的buff
    for k,v in pairs(self.buffNextRemove) do

        if v == 1003 then
            print("loseType = hit22")
        end
        self:_removeBuff(v)
    end
    self.buffNextRemove = {}

    --加入等待中的buff
    for k,v in pairs(self.buffNextAdd) do
        --增加buff表现，和buff效果
        self:_firstBuff(v)
        --插入
        table.insert(self.buffData , v)
    end
    self.buffNextAdd = {}
end

function life:_removeBuff(buffID)
    for k,v in pairs(self.buffData) do
        if v["id"] == buffID then
            --删除buff表现 todo youwei
            self:_resetBuff(buffID)
            --end
            table.remove( self.buffData, k)
            return
        end
    end
end

function life:_firstBuff(data)
    local buffSp = cc.Sprite:create(data['animationName'])
    buffSp:setName(""..data["id"])
    buffSp:setAnchorPoint(cc.p(0.5,0.3))
    self.buffLayer:addChild(buffSp , 10)

    --状态增加的影响
    if data['operationType'] == 'AddDelt' then
        self.actorData[data['property']] = self.actorData[data['property']] + data['value']
        self.actorData[data['property']..'Buff'] = self.actorData[data['property']..'Buff']  + data['value'] 
    end

    --状态固定增加的影响
    if data['operationType'] == 'Const' then
        self.actorData[data['property']..'Buff'] = self.actorData[data['property']]
        print("self.actorData[buffData befor= "..self.actorData[data['property']..'Buff'] )
        self.actorData[data['property']] = data['value']
        print("property = "..self.actorData[data['property']] )
        print("self.actorData[buffData after= "..self.actorData[data['property']..'Buff'] )
    end    
end

function life:_resetBuff(buffID)
    --删除buff特效
    local buffData = cs.util.tablecpy(cs.conf.a("buff",buffID))
    local buffSp = self.buffLayer:getChildByName(""..buffData["id"])
    buffSp:removeFromParent()

    --恢复之前的属性
    if buffData['operationType'] == 'AddDelt' then
        self.actorData[buffData['property']] = self.actorData[buffData['property']] - buffData['value']
        self.actorData[buffData['property']..'Buff'] = self.actorData[buffData['property']..'Buff']  - buffData['value'] 
    end

    if buffData['operationType'] == 'Const' then
        print("self.actorData[buffData goBack= "..self.actorData[buffData['property']..'Buff'] )
        self.actorData[buffData['property']] = self.actorData[buffData['property']..'Buff']
    end 
end

return life