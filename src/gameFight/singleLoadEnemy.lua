--战斗场景单键类
if cc.exports.singleLoadEnemy == nil then
    cc.exports.singleLoadEnemy = {} 
end

function singleLoadEnemy:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleLoadEnemy:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
        self.instance:_init()
    end  
    return self.instance  
end 

function singleLoadEnemy:_init()
    self.enemyData = {}
    self.enemyLevelData = {}
end  

function singleLoadEnemy:getTestWave()
    return self.enemyLevelData["level"]["waves"]["wave"][1]
end

--读取敌人表格信息
function singleLoadEnemy:loadEnemy(namePath)
    cs.logger.d("loadEnemy",namePath)

    if cc.FileUtils:getInstance():isFileExist(namePath) then

        --打开整个文件
        local fullPath = cc.FileUtils:getInstance():fullPathForFilename(namePath)
        local strJson = cc.FileUtils:getInstance():getStringFromFile(fullPath);

        --开始解析
        self.enemyData = json.decode(strJson)
    else
        cs.logger.d("can not find",namePath)
    end
    return self.enemyData
end

--读取当前关卡刷怪的表格信息
function singleLoadEnemy:LoadLevelEnemy(namePath)
    cs.logger.d("enemyLevelData",namePath)

    if cc.FileUtils:getInstance():isFileExist(namePath) then
        --打开整个文件
        local fullPath = cc.FileUtils:getInstance():fullPathForFilename(namePath)
        local strJson = cc.FileUtils:getInstance():getStringFromFile(fullPath);

        --开始解析
        self.enemyLevelData = json.decode(strJson)
    else
        cs.logger.d("can not find",namePath)
    end

    return self.enemyLevelData
end