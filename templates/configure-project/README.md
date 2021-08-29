# 配置项目
- [配置项目](#配置项目)
  - [项目结构](#项目结构)
  - [打印信息](#打印信息)
  - [内置常量](#内置常量)

## 项目结构
```bash
.
├─app
│  ├─CMakeLists.txt
|  └─main.cpp
└─CMakeLists.txt
```

## 打印信息
```cmake
message([<mode>] "message to display" ...)
```

- **FATAL_ERROR**: cmake出错，停止编译和生成(信息红色)
- **SEND_ERROR**: cmake出错，继续编译，但是停止生成(信息红色)
- **WARNING**: cmake警告，继续编译(信息红色)
- **AUTHOR_WARNING**: 开发者警告，继续编译(信息红色)
- **DEPRECATION**: 如果使用set方法设置CMAKE_ERROR_DEPRECATED为true(不区分大小写)，编译出错，否则继续编译
- (none) or **NOTICE**: 不设置mode，默认是NOTICE模式，不影响编译和生成，用于打印消息(信息白色)
- **STATUS**: 编译时状态信息，左边以--开头(信息白色)
- **DEBUG**: 针对开发人员的调试信息(信息白色)
- **TRACE**: 日志级别的临时信息(信息白色)


## 内置常量
- `PROJECT_SOURCE_DIR`: 项目所在路径。与用`project()`指定项目名的`CMakeLists.txt`目录保持一致。
- `PROJECT_BINARY_DIR`: 编译路径。默认为执行cmake命令时所在目录
- `LIBRARY_OUTPUT_PATH`: 库的安装位置。
- `EXCUTABLE_OUTPUT_PATH`: 用于指定执行文件的安装位置。
- `CMAKE_BUILD_TYPE`: 编译类型 `DEBUG`,`RELEASE`,`RELWITHDEBINFO`,`MINSIZEREL`。
- `CMAKE_CXX_FLAGES `: C++编译标识符。
- `CMAKE_BUILD_TYPE`: 

