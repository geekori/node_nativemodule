将用C++编写的静态库编译进本地模块

静态库：Linux、Unix、Mac OS X：.a  abc.a   Windows：.lib  abc.lib
动态库：Linux、Unix、Mac OS X：.so  abc.so  Windows：.dll  abc.dll

可执行文件：Linux、Unix、Mac OS X：可以是任意文件    Windows：.exe  abc.exe

why 静态库

1. 想将自己编写的程序给另外的开发者，但又不想给源代码
2. 想让对方编译后的程序没有那么多的依赖

C++程序的组成
1. 头文件（.h）
2. 源代码文件（.cpp、.cc）

生成静态库的步骤
1.  将.cpp文件编译成.o文件

g++ -c Calc.cpp


2.  将.o文件编译成.a文件
ar -crv libCalc.a Calc.o

在linux、mac下，静态库文件必须以lib开头，以.a作为扩展名

3. 将.a文件编译进可执行程序
g++ TestCalc.cpp -o TestCalc -L . -lCalc

binding.gyp（1）
{
    "targets" :[
    {
        "target_name":"Calc_N",
        "sources":["Calc.cc"],
        "libraries":["../cpp/libCalc.a"]
    }
    ]
}

binding.gyp(2)
{
    "targets" :[
    {
        "target_name":"Calc_N",
        "sources":["Calc.cc"],
        "libraries":["-L../cpp","-lCalc"]
    }
    ]
}


编译electron的本地模块

node-gyp rebuild --target=4.0.1 --arch=x64 --dist-url=https://atom.io/download/electron



