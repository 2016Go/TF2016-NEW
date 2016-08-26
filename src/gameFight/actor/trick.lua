local trick = class("trick", function() return cc.Node:create() end)

--初始化函数
function trick:ctor()
	local m_pDrawNode = cc.DrawNode:create(1)
    m_pDrawNode:setAnchorPoint(cc.p(0,0))
    m_pDrawNode:setPosition(cc.p(0,0))
    self:addChild(m_pDrawNode, 99)
    m_pDrawNode:drawCircle(cc.p(0,0), 25, 0, 9, false, 1, 1, cc.c4b(1,0,1,1))
end  

--设置阵营
function trick:setData(trick, tag)
	self.trickData = trick
	self.tag = tag
end

--当怪物死亡，或消失的时候调用
function trick:clear()
	self:removeFromParent()
end

--机关更新运算
function trick:UpData(dt)
    --检查范围内是否有怪物存在
    local  myPos = cc.p( self:getPosition() )

    --获取所有怪物
    local  allEnemy = singleEnemyManager:getInstance():getAllEnemy()
    
    --计算怪物距离塔的直线距离
    for i,v in pairs(allEnemy) do
        local d = cc.pGetDistance( myPos, cc.p(v:getPosition()) )

        --范围内怪物
        if d < 25 then
        	self:doTrick(v)
        end
    end
end

function trick:doTrick(enemy)
	--如果该怪物已经带有这个机关的ID，说明这个怪物已经触发过这个机关1次
    if enemy.trickTag ~= nil then
       	if enemy.trickTag == self.tag then
        	return
        end
    end 

    --如果是BUFF机关
    if self.trickData['trickType'] == 1 then
    	enemy:addBuffDataForID(self.trickData['buffID'])
    end
end

return trick
