本地模块调用C++编写的动态链接库（Mac OS X）

linux、unix、Mac：.so
windows：.dll

python、go、php、java


将Calc.cpp编译成Calc.so


g++ -dynamiclib Calc.cpp -o Calc.so


将TestCalc.cpp编译成可执行文件
g++ TestCalc.cpp -o TestCalc

编译可以调用动态链接库的本地模块

source activate python27
node-gyp rebuild

在Electron中编译本地模块

node-gyp rebuild --target=4.0.1 --arch=x64 --dist-url=https://atom.io、download/electron