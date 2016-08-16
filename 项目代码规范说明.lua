
                                    TF2016-new项目编码规范 1.0   by   youwei


1.函数，变量名称 文件夹 尽量用英文命名，非特殊情况不要用拼音

2.函数，变量名称 文件夹 用骆驼命名法，首字母小写，中间首字母大写  如   local  gameEnemyWalk = {}

3.创建任何table的时候，一定要初始化  
                     如 local  gameEnemyWalk = {}
                     如 local  gameEnemyWalk = 0   
                     如 local  gameEnemyWalk = self:testGame()
                     --以下为错误演示
                     如 local  gameEnemyWalk   --此做法不可取，除非是非常特殊的情况需要、

4.项目中不得随意创建全局的标记，枚举。所有此类的创建生成，请全部放于 config.lua (后期可能会考虑移动位置，但必须在统一的一个文件lua内)

5.项目的全局标记，枚举。类型全部大写，里面的值前半段统一，且首字母大写，后半段各不相同，首字母大写，用_连接
                    如
                        --敌人状态标记
                        CC_ENEMY_STATE = 
                        {
                            State_Ready= 1,             -- 准备状态，还没有到出生的时候
                            State_Born = 2,             -- 出生状态
                            State_Walk = 3,             -- 行走状态
                            State_Hit  = 4,             -- 被击状态
                            State_Die  = 5              -- 死亡状态
                        }

6.类中的函数，如果是对外开放调用的函数（公用，保护），可以随意命名，但请遵循第 1，2 条进行

7.类中的函数，如果是对内开放调用的函数（私用），需要在函数名前面加入_标记，作一个人为的区分
                    如 
                    --公用函数
                    function enemy:setActor()

                    end
                    --私用函数
                    function enemy:_setActorTime(actorTime)

                    end

8.类中的函数，对外开放函数，写于lua的上方部分，对内开放的函数，写于lua的下部分。

9.每个函数的函数起始处，强制要求有一行注释。说明该函数的作用( 常规，可自解释的函数可以不用注释)
                    如
                    --可以不需要注释的函数
                    function enemy:create()
                    function enemy:init()
                    function enemy:getEnemy()

                    --需要注释的函数
                    --根据ID的编号，查找到当前的敌人坐标，并返回坐标值cc.p
                    function enemy:autoFind(id)
                    --敌人因为buff效果而进入被击状态的情况处理，返回一个处理结果
                    function enemy:hitWithBuff()


10.函数内部，建议在复杂逻辑的地方加入注释，且控制函数长度，不要有太复杂逻辑的函数，尽量进行拆分

11.创建类的时候,lua文件名要和类名保持一致，且如果类是单键类的话。名字前缀一定是single 
                                    如  singleGameData

12.游戏战斗的主要逻辑lua全部写于gameFight

13.游戏UI的主要逻辑lua全部写于gameUI，只提供部分接口供相互调用

14.项目以后可以共用的公共库。可以进过抽象后，放于cs文件夹。






-----------------SVN
svn root:
http://10.0.0.212/svn/droidhang/android/dhArt/TF2016
svn user:
wei_you
密码就是你刚才设置的
—————————程序员请忽略以下内容————————
baidu搜TortoiseSVN  下载安装
svn 客户端安装完要重启下电脑
使用教程参考：
http://jingyan.baidu.com/article/358570f6638aa4ce4724fcf7.html

svn checkout http://10.0.0.212/svn/droidhang/android/dhArt/TF2016 --username=wei_you --password= /Users/apple/Documents/work/TF2016-SVN