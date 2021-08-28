# 编译和链接静态库和动态库
- [编译和链接静态库和动态库](#编译和链接静态库和动态库)
- [项目结构](#项目结构)
- [工作原理](#工作原理)
  - [编译库](#编译库)
# 项目结构
```bash
.
├─include
│  └─myClass.h
├─src
│  ├─CMakeLists.txt
│  └─myClass.cpp
└─CMakeLists.txt
```

# 工作原理
## 编译库
命令 `add_library(<lib_name> STATIC <file>.h <file>.cpp)` 用于将指定的源码编译成库
- `<lib_name>` 是生成的库名，该库名可以看成一个变量，可以在其他地方通过库名进行引用
- 第二个参数 `STATIC` 可以设置生成的库的类型
  - **动态库**为 `SHARED`
  - **静态库**为 `STATIC`
- 剩下的参数是需要编译进库的源码

在[src/CMakeLists.txt](src/CMakeLists.txt)中我们可以看到编译 `myClass` 为一个库

当代码有多个源代码之后，为了方便，我们将全部源代码添加到一个变量下。例如将 [`src`](src) 目录下的全部源码添加到变量 `myClass_src`内 
```cmake
aux_source_directory(.  myClass_src)
```
我们可以输出被包含在这个变量内的文件，以查看哪些文件会被编译成库（非必要）
```cmake
message(STATUS "[INFO] compile by: ${myClass_src}")
```
同时设置源码所对应的头文件所在目录，使得编译的时候可以正确地找到头文件
```cmake
include_directories(${PROJECT_SOURCE_DIR}/include)
```

接下来就可以编译库了，我们以编译动态库为例
```cmake
add_library(myClass_shared SHARED ${myClass_src})
```
并且我们设置库的输出目录
```cmake
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
```
我们也可以打印库是由哪些文件编译而成的（非必要）
```cmake
message(STATUS "[INFO] library compiled by : " ${myClass_src})
```
如果当前的库还使用了一些第三方库，需要链接到当前的库，那么可以通过 `target_link_libraries` 链接；如果链接多个库，以空格分开即可
```cmake
target_link_libraries(myClass <other_libaray> [<other_libaray_2>])
```
