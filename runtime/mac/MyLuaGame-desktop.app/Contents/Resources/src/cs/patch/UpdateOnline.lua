module('cs.patch.UpdateOnline',package.seeall)

----------------------------------------------------
-- 存放补丁临时文件的根目录
----------------------------------------------------
local C_PATCH_ROOT = _G.C_PATCH_ROOT

----------------------------------------------------
-- 存放补丁信息的文件名
----------------------------------------------------
local C_PATCH_INFO_FILENAME = "_actcli_patch_list_.json"
----------------------------------------------------

--------------------------------------------------
-- 前置申明
----------------------------------------------------
local _getLocalVersion                  --获取本地版本号等
local _readAssetPathInfo                --读取之前网络数据保存在本地文件的版本号，不存在返回空（无更新版本时候进入游戏会不存在）
local _RequestToSrvForUpdate            --从服务器抓取更新数据底层
local Ok_ProcessUpdateReplyFromSrv      --服务器正确返回数据
local Err_ProcessUpdateReplyFromSrv     --服务器错误返回数据
local httpDowndFile                     --从服务器下载最近数据包
local _downloadPatchDelegate            --下载代理
local _addSearchPath                    --添加搜索路径
local _landSelf                         --外部传入指针用于界面的回调


--------------------------------------------------
-- 变量
----------------------------------------------------
local request = nil --网络数据

------------------------------------------------------------------------------------------------------------------------
function Ok_ProcessUpdateReplyFromSrv(strJson)
    local CODE_CHANNEL_EXSISTS   = -200;                -- 渠道不存存在
    local CODE_APPVER_EXSISTS    = -201;                -- 程序版本号错误
    local CODE_PATCHVER_EXSISTS  = -202;                -- 补丁版本号错误
    local CODE_PATCHVER_ISNEW    = -203;                -- 补丁版本不需要更新
    local CODE_CLIENT_NEEDUPDATE = -204;                -- 客户端需要更新

    local rep = json.decode(strJson)

    if rep.code==CODE_CHANNEL_EXSISTS or rep.code==CODE_APPVER_EXSISTS then
        cg.prompt.tip(45201)  --游戏版本已过期，请下载最新版本的游戏，重新登录。

    elseif rep.code==CODE_PATCHVER_EXSISTS or rep.code==CODE_CLIENT_NEEDUPDATE then
        --界面打开进度条
        _landSelf:inLoading()
        --开始下载
        httpDowndFile(rep)
        --iRetCode = 1;                                   -- 更新游戏，退出后重新启动程序

    elseif rep.code == CODE_CHANNEL_EXSISTS then
        cg.prompt.tip(45200)                            --渠道不存存在

    elseif rep.code == CODE_PATCHVER_ISNEW then
        _landSelf:inLand()
    else
        cg.prompt.tip(45202) -- 游戏更新出现未知错误,请重试或安装最新游戏版本

    end
end

function httpDowndFile(rep)

    local addressUrl = cg.base64.ZZBase64.decode(rep["address"])
    local zipPureFilename = rep.mainver .. "_"..rep.subver
    local zipPath = cs.util.combine_writable_path(C_PATCH_ROOT)
    local zipFilename = zipPath .. "/" .. zipPureFilename

    -- 创建zip存放目录
    if not cc.FileUtils:getInstance():isFileExist(zipPath) then
        Util:makeDirectory(zipPath,true)
    end

        local context = {
        ["callback"] = function(event,...) _installPatch(zipFilename,zipPath)  end,
        ["zipFileUrl"] = addressUrl,
        ["zipFilename"] = zipFilename,
        ["assetVersion"] = rep["mainver"],
        }

    -- 下载补丁
    local zipFileUrl = context["zipFileUrl"]
    local zipFilename = context["zipFilename"]
    if request ~= nil then 
        request:cancel()
        request = nil
        cclog('request:cancel()')    
    end

    print("--zipFileUrl--"..zipFileUrl)
    print("--zipFilename--"..zipFilename)
    request = HTTPRequest:create(function(...) _downloadPatchDelegate(context,...) end,zipFileUrl,"GET")

    request:retain()
    request:setRequestUrl(zipFileUrl)
    request:setTimeout(0)
    request:setEnableResponseBuffer(false)
    request:setEnableResponseFile(true, zipFilename)
    request:start()
end

----------------------------------------------------
-- 安装补丁
----------------------------------------------------
--补丁路径
--
_installPatch = function(zipFilename,installPath,callback)
    -- 路径与文件
     local WritablePath = cs.util.combine_writable_path(C_PATCH_ROOT) --该处路径定义在UpdateOnline中，如果有变更请修改
                           
    
    -- 补丁不存在则不能安装
    if not cc.FileUtils:getInstance():isFileExist(zipFilename) then
        cs.util.call(callback,C_PATCH_EVT_INSTALL_FAIL)
        return
    end

    -- 创建解压目录
    if not cc.FileUtils:getInstance():isFileExist(installPath) then
        Util:makeDirectory(installPath,true)
    end

    -- 解压补丁
    Util:unzip(zipFilename,installPath,false,function(event,now,total)
        if event == "done" then
            -- 创建安装目录
            Util:makeDirectory(installPath,true)

            -- 删除补丁包
            Util:removeFile(zipFilename,true)
            local readData = _readAssetPathInfo()

            if readData.filelist ~= nli then
                for _,v in pairs(readData.filelist) do
                    if v.flag == "DEL" then
                        local pathData = cs.util.combine_writable_path(C_PATCH_ROOT,v.fileName)
                        Util:removeFile(pathData,true)
                    end
                end
            end

            --打开登陆器
            _landSelf:inLand()

            
            local ver = readData.verinfo
            --显示版本号
            _landSelf.banBenText:setText(ver.mainVer .. "."..ver.subVer)

            if ver.restart == 0 then
                --打开登陆器
                _landSelf:inLand()
            else
                --要求重启
                _landSelf:isReBegin()
            end


        elseif event == "progress" then
            if total ~= 0 then
                _landSelf:setInstallBarData(now,total)
             end
        elseif event == "fail" then
            cs.util.call(callback,C_PATCH_EVT_INSTALL_FAIL)
        end
    end)
end
------------------------------------------------------------------------------------------------------------------------
function Err_ProcessUpdateReplyFromSrv(status)

    cg.prompt.tip(45203)  --网络通讯异常：连接更新服务器失败！请重试
    --local iRetCode = -1;                                -- 显示“重新连接”按钮
    --return iRetCode

end

------------------------------------------------------------------------------------------------------------------------
function _RequestToSrvForUpdate(Channel, ProgramVer, PatchVer, funcOk, funcErr)

    local url = cs.conf.g('operator-zytx-update-url')
    local timeout = cs.conf.g('operator-zytx-http-timeout')
    local Params = {
        channel = Channel,
        mainver = ProgramVer,
        subver  = PatchVer,
    }

    cs.http.get(url, timeout, Params, funcOk, funcErr)
end

------------------------------------------------------------------------------------------------------------------------
function RequestToSrvForUpdate(Channel, ProgramVer, PatchVer)
        _RequestToSrvForUpdate(Channel,ProgramVer,PatchVer,Ok_ProcessUpdateReplyFromSrv,Err_ProcessUpdateReplyFromSrv)
end

----------------------------------------------------
-- 读取资产补丁信息
----------------------------------------------------
_readAssetPathInfo = function()  
    local filename = cs.util.combine_writable_path(C_PATCH_ROOT,C_PATCH_INFO_FILENAME)
    local data = cc.FileUtils:getInstance():getStringFromFile(filename)
    local assetInfo = (data == "" and {} or cs.util.json_decode(data))
    return assetInfo
end                       

----------------------------------------------------
-- 写入资产补丁信息
----------------------------------------------------
function _flushAssetPatchInfo(info)
    local filename = cs.util.combine_writable_path(C_PATCH_ROOT,C_PATCH_INFO_FILENAME)
    local data = json.encode(info)
    Util:flushFile("w",filename,data)
end

----------------------------------------------------
-- 下载补丁代理
----------------------------------------------------
_downloadPatchDelegate = function(context,event)
    if event.name == "complete" then
        local status = event.request:getResponseStatusCode()
        event.request:release()
        if status >= 200 and status < 300 then
            print("--C_PATCH_EVT_DOWNLOAD_COMPLETE--")
            context["callback"]()
        else
            print("--C_PATCH_EVT_DOWNLOAD_FAIL--")
            --cs.util.call(context["callback"],C_PATCH_EVT_DOWNLOAD_FAIL,status)
        end      
    elseif event.name == "fail" then
        event.request:autorelease()
        print("--event.request:autorelease--")
        --cs.util.call(context["callback"],C_PATCH_EVT_DOWNLOAD_FAIL)
    elseif event.name == "progress" then
        if event.dltotal ~= 0 then
             _landSelf:setDownBarData(event.dlnow,event.dltotal)
        end

        --cs.util.call(context["callback"],C_PATCH_EVT_DOWNLOAD_PROGRESS,event.dltotal,event.dlnow,event.ultotal,event.ulnow)
    end
end

----------------------------------------------------
-- 检查版本并且准备更新
----------------------------------------------------
function checkVer(landSelf)
    _landSelf = landSelf
    return _getLocalVersion()
end


----------------------------------------------------
-- 获取本地当前版本
----------------------------------------------------
_getLocalVersion = function()
    --读取本地原始版本号    
    local VersionData = {}
    VersionData.channel = cs.conf.g('operator-channel')
    VersionData.mainVer = cs.conf.g('operator-mainver')
    VersionData.subVer  = cs.conf.g('operator-subver')

    --如果有网络数据包,读取数据包最新版本号
    local data = _readAssetPathInfo().verinfo
    
    if data == nil then
        return VersionData
    end

    if data == "" then
        return VersionData
    end

    if next(data) == nil then
        return VersionData
    end

    return data
end
