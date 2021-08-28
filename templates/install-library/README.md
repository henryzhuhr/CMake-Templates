# 安装库
- [安装库](#安装库)
- [项目结构](#项目结构)
- [使用](#使用)
- [工作原理](#工作原理)


# 项目结构
```bash
.
├─include
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
cmake .. -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX="../dist"
make
```
编译完成后，执行安装
```bash
make install
```
在 `CMAKE_INSTALL_PREFIX` 指定的目录 `dist` 下会生成
```bash
.
├─bin
|  └─libmyLib.dll
├─include
|  └─myClass.h
└─lib
   ├─libmyLib.a
   └─libmyLib.dll.a
```


# 工作原理
首先将源码编译成库，并且同时编译静态库(`myLib`)和动态库(`myLib_shared`)
```cmake
aux_source_directory(./  myLib_src)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(myLib STATIC ${myLib_src})          # static  link library
add_library(myLib_shared SHARED ${myLib_src})   # dynamic link library
```

如果直接编译上述库，那么将会生成静态库文件 `libmyLib.a` 和动态库文件 `libmyLib_shared.dll` ，这是由库的变量名决定的，我们也可以通过 `set_target_properties` 规定其输出名
```cmake
set_target_properties(myLib_shared PROPERTIES OUTPUT_NAME "myLib")
```
这时候动态库的输出文件就是 `libmyLib.dll`

```cmake
set_target_properties(myLib_shared PROPERTIES VERSION 1.2 SEVERSION 1)
```

配置完编译环境后，需要配置安装 (install) 目录

首先将头文件 `*.h` 加入到变量 `INSTALL_HEAD_FILES` 中，并且指定安装目录 `DESTINATION` 为 `${CMAKE_INSTALL_PREFIX}/include` 
```cmake
set(INSTALL_HEAD_FILES 
    ${PROJECT_SOURCE_DIR}/include/myClass.h
)
install(
    FILES ${INSTALL_HEAD_FILES} 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    )
```
`CMAKE_INSTALL_PREFIX` 是一个CMake预置的常量，用于指定项目的安装目录，例如 `${PROJECT_SOURCE_DIR}/dist`
```cmake
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(
        CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist
        CACHE PATH "Installation Directory" FORCE
        )
endif()
```
也可以写到一行内
```cmake
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist CACHE PATH "Installation Directory" FORCE)
endif()
```
设定 `CMAKE_INSTALL_PREFIX` 的操作放在了根目录的 [`CMakeLists.txt`](CMakeLists.txt) 下，是将该设置当成一个全局配置来看待的

然后就是将库文件安装
```cmake
install(TARGETS myLib_shared myLib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION lib
    )
```

| 目标文件       | 内容                    | 安装目录变量                | 默认安装目录 |
| -------------- | ----------------------- | --------------------------- | -------------- |
| RUNTIME        | 可执行二进制文件        | ${CMAKE_INSTALL_BINDIR}     | bin            |
| ARCHIVE        | 静态库                  | ${CMAKE_INSTALL_LIBDIR}     | lib            |
| LIBRARY        | 动态库                  | ${CMAKE_INSTALL_LIBDIR}     | lib            |
| PUBLIC_HEADER  | 与库关联的PUBLIC头文件  | ${CMAKE_INSTALL_INCLUDEDIR} | include        |
| PRIVATE_HEADER | 与库关联的PRIVATE头文件 | ${CMAKE_INSTALL_INCLUDEDIR} | include        |
