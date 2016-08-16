--战斗场景单键类
if cc.exports.singleUIData == nil then
    cc.exports.singleUIData = {} 
end

function singleUIData:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleUIData:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()
        self.instance:_init()  
    end  
    return self.instance  
end

function singleUIData:setData(key, v)
    if self[key] == nil then
        cs.logger.w("singleUIData this key is error")
        return
    end

    self[key] = v
    singleUIEvent:getInstance():SendEventForListener(key , self , v)
    --发送数据变更消息
    self:_saveData(key,v)
end

function singleUIData:_init() 
    cs.logger.i("_init")

    local PlayName = cs.util.readUD(CC_UI_DATA_TPYE.UI_PlayName)
    cs.util.flushUD()
    
    --如果是新玩家，先测试的给他添加基础函数
    if walletData == "" then
        self:_setNewPlayerData()
    end

    for k,v in pairs(CC_UI_DATA_TPYE) do
        self[v] = cs.util.readUD(v)
        print(self[v])
    end
end

function singleUIData:_setNewPlayerData()
    cs.util.writeUD( CC_UI_DATA_TPYE.UI_PlayName , "游客" )
    cs.util.writeUD( CC_UI_DATA_TPYE.UI_Wallet , 300 )
    cs.util.writeUD( CC_UI_DATA_TPYE.UI_Level , 0 )
    cs.util.flushUD()
end 

function singleUIData:_saveData(key , data)
    cs.util.writeUD( key , data )
    cs.util.flushUD()
end 