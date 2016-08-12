--战斗场景单键类
if cc.exports.singleLoadMap == nil then
    cc.exports.singleLoadMap = {} 
end

function singleLoadMap:new(o)  
    o = o or {}  
    setmetatable(o,self)  
    self.__index = self  
    return o  
end  
  
function singleLoadMap:getInstance()  
    if self.instance == nil then  
        self.instance = self:new()  
        self.mapData = {}
    end  
    return self.instance  
end 

--读取地图xml信息
function singleLoadMap:loadMap(namePath)
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