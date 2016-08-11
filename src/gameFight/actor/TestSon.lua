local TestSon = class("TestSon",require("gameFight.Actor.TestFa"))


--创建函数

function TestSon:ctor()
    self.super:ctor()
    print("TestSon:ctor()")
end


return TestSon