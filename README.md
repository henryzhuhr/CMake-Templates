# CMake-Templates
[![简体中文](https://img.shields.io/badge/说明文档-简体中文-blue)](README.md)
<!-- [![Englis](https://img.shields.io/badge/README-English-red)](README_en.md) -->


这是一个 CMake 模板库

- [CMake-Templates](#cmake-templates)
- [CMake](#cmake)
- [CMake模板的结构](#cmake模板的结构)
- [CMake模板列表](#cmake模板列表)
- [编译一些有用的第三方库](#编译一些有用的第三方库)
  - [gflags](#gflags)
- [常见的工具](#常见的工具)
  - [CMake](#cmake-1)
  - [Clang](#clang)
    - [Download](#download)
    - [Usage](#usage)
  - [git](#git)
  - [Wget](#wget)

# CMake
你可以在[CMake官方网站](https://cmake.org/)找到[下载链接](https://cmake.org/download/)、[官方文档](https://cmake.org/documentation/)以及一份简单的[官方教程](https://cmake.org/cmake/help/v3.21/guide/tutorial/index.html#adding-system-introspection-step-5)

# CMake模板的结构
Cmake模板都是基于此目录进行的，具体每个项目的目录可能由于其需求不同而不同
``` bash
.
├─.vscode           # VSCode 配置文件
|   ├─c_cpp_properties.json #
|   ├─launch.json           #
|   └─setting.json          #
├─app               # 测试文件目录
├─bin               # 二进制输出（编译后产生）
├─build             # cmake 构建和 make 编译输出文件目录
├─include           # 头文件
|   ├─<file>.hpp
|   └─...
├─src               # 源文件
├─tools             # 编译工具链（也可以将工具链添加到系统环境变量中）
├─.clang-format     # clang-format 文件（代码自动格式化工具）
├─build.bat         # bat 编译脚本
├─build.sh          # shell 编译脚本
├─CMakeLists.txt    # 根目录的CMake配置文件
└─README.md
```
# CMake模板列表
- [x] [编译可执行文件 (compile executable file)](templates\compile-executable_file\README.md)
- [x] [编译库文件 (compile library)](templates\compile-library\README.md)
- [x] [安装库文件 (install library)](templates\install-library\README.md)
- [x] [第三方库的使用 (link 3rd-party))](templates\link-3rd_party\README.md)




# 编译一些有用的第三方库
## gflags
download gflags in [GitHub](https://github.com/gflags/gflags), see ["Installing a binary distribution package"](https://github.com/gflags/gflags/blob/master/INSTALL.md)



# 常见的工具
## CMake
添加环境变量 `CMAKE_GENERATOR` 到系统中，值为 `MinGW Makefiles` 


## Clang
### Download
In [LLVM](https://llvm.org/builds/) official website, 
choose corresponding **Clang-Format** [Release](https://releases.llvm.org/) for your OS in **Other builds**. 

Then, you can download LLVM in this [page](https://releases.llvm.org/download.html) or in [Github Release](https://github.com/llvm/llvm-project.git)

when installing LLVM, 
in page `Install Options`, select if add LLVM to the system
- [ ] Do not add LLVM to the system PATH
- [x] Add LLVM to the system PATH for all user
- [ ] Add LLVM to the system PATH for current user

### Usage
use `clang-format ` with parameter `-style` and `-i`
- `-style` LLVM、Google、Chromium、Mozilla、WebKit or file(.clang-format)
- `-i`
```
clang-format -style=LLVM -i test.c
```

or you can edit your custom format file [`.clang-format`](.clang-format), 
```
clang-format -i test.c
```

see [Clang documentation](https://clang.llvm.org/docs/ClangFormat.html) for more detail of using Clang-Format
- [Clang Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)



## git
in file `.git/config`
```bash
[remote "origin"]
	url = https://gitee.com/<user_name>/<repo_name>.git
	url = https://github.com/<user_name>/<repo_name>.git
	fetch = +refs/heads/*:refs/remotes/origin/*
```

## Wget

A command-line utility for retrieving files using HTTP, HTTPS and FTP protocols.

Download:
- [Windows binaries of GNU Wget](https://eternallybored.org/misc/wget/) (Downloading ZIP and add to system PATH is recommended.)
