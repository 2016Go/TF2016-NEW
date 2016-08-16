--战斗场景单键类
if cc.exports.singleLoadData == nil then
    cc.exports.singleLoadData = {} 
end

function singleLoadData:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleLoadData:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
        self.mapData = {}
        self.enemyData = {}
        self.enemyLevelData = {}
    end  
    return self.instance  
end 

--读取地图xml信息
function singleLoadData:loadMap(namePath)
    cs.logger.d("loadMap",namePath)

    if cc.FileUtils:getInstance():isFileExist(namePath) then

        --打开整个文件
        local fullPath = cc.FileUtils:getInstance():fullPathForFilename(namePath)
        local strJson = cc.FileUtils:getInstance():getStringFromFile(fullPath);

        --开始解析
        self.mapData = json.decode(strJson)
    end

    return self.mapData
end

function singleLoadData:getTestWave()
    return self.enemyLevelData["level"]["waves"]["wave"][1]
end

--读取敌人表格信息
function singleLoadData:loadEnemy(namePath)
    cs.logger.d("loadEnemy",namePath)
    local enemyData = {}
    if cc.FileUtils:getInstance():isFileExist(namePath) then

        --打开整个文件
        local fullPath = cc.FileUtils:getInstance():fullPathForFilename(namePath)
        local strJson = cc.FileUtils:getInstance():getStringFromFile(fullPath);
        --开始解析
        local allData = json.decode(strJson)
        local enemyData1 = allData["enemies"]
        enemyData = enemyData1["e"]
    else
        cs.logger.d("can not find",namePath)
    end

    --二次解析
    for k,v in pairs(enemyData) do
        local enemyName = v["-name"]
        self.enemyData[enemyName] = v
    end

    return self.enemyData
end

--读取当前关卡刷怪的表格信息
function singleLoadData:loadLevelEnemy(namePath)
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

--获取场景界面所需要的主要数据
function singleLoadData:getStageData()
    local mainUIData = {}
    mainUIData.life = tonumber(self.enemyLevelData["level"]["hpBonus"])
    mainUIData.gold = tonumber(self.enemyLevelData["level"]["initgold"])
    mainUIData.exp  = tonumber(self.enemyLevelData["level"]["expStoneBonus"])
    mainUIData.towersindex = tonumber(self.enemyLevelData["level"]["towersindex"])
    mainUIData.bgm = self.enemyLevelData["level"]["bgm"]
    mainUIData.wave = 0
    mainUIData.waveLimit = #(self.enemyLevelData["level"]["waves"]["wave"])    --波次上限

    return mainUIData
end

--传入一个波次的数据，和波次中的怪物id，获取这个怪物Item的所有出生的数据
function singleLoadData:getEnemyItemBornData(waveData , itemID)
    return waveData["e"][itemID]
end

--传入波次数据，和波次中怪物的ID，获取这个怪物出场延迟时间
function singleLoadData:getEnemyItemBornTime(waveData , itemID)
    return tonumber((self:getEnemyItemBornData(waveData , itemID))["-d"]) / 1000
end

--传入波次数据，和波次中怪物的ID，获取这个怪物个体的数据
function singleLoadData:getEnemyItem(waveData , itemID)
    local data = self:getEnemyItemBornData(waveData , itemID)
    if data == nil then
        cs.logger.i("getEnemyItem is nil for itemID = "..itemID)
        return nil
    end
    
    local enemyName = data["-n"]
    if self.enemyData[enemyName] == nil then
        cs.logger.w("can not find enemyName in data = "..enemyName)
        return nil
    end

    return self.enemyData[enemyName]
end

--传入一个波次ID，获取本关卡本波次的所有数据
function singleLoadData:getLevelWavaData(wavaID)
    return self.enemyLevelData["level"]["waves"]["wave"][wavaID]
end

--传入一个波次，获取本关卡本波次的的等待时间
function singleLoadData:getLevelWavaDataTime(wavaID)
    return (self.enemyLevelData["level"]["waves"]["wave"][wavaID]["-d"])/1000
end

