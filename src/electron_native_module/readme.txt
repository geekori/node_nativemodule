在Electron中使用Node.js本地模块

在Electron中编译本地模块有两种方法：

1. node-gyp rebuild --target=3.0.2 --arch=x64 --dist-url=https://atom.io/download/electron

2. ./node_modules/.bin/electron-rebuild -v 3.0.2

windows
 ./node_modules/.bin/electron-rebuild.cmd -v 3.0.2