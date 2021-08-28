# 安装库
- [安装库](#安装库)
- [项目结构](#项目结构)
- [使用](#使用)
- [工作原理](#工作原理)


# 项目结构
```bash
|  └─myClass.h
├─src
│  ├─CMakeLists.txt
|  └─myClass.cpp
└─CMakeLists.txt
```

# 使用
```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=./dist
make
make install

```

# 工作原理

