local TestFa = class("TestFa")

--创建函数
function TestFa:ctor()  
    print("TestFa:ctor()")
    self.aaa = 3
end  


function TestFa:youwei()
    print("TestFa:youwei()"..self.aaa)
end

return TestFa