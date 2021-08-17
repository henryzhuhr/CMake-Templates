# CMake
CMake is good
- [CMake](#cmake)
- [Compile the project](#compile-the-project)
- [Directory Structure](#directory-structure)
- [CMake](#cmake-1)
  - [global configuration](#global-configuration)
  - [compile executable file](#compile-executable-file)
  - [compile dynamic link library](#compile-dynamic-link-library)
  - [compile static link library](#compile-static-link-library)
- [Clang-Format](#clang-format)
  - [Download](#download)
  - [Usage](#usage)
- [git](#git)

# Compile the project
- build && compile
```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make -j8
```
- run the executable file
```bash
cd ../bin
./<your_program>
```


# Directory Structure
``` bash
.
├─app               # test file
├─bin               # binary output
├─build             # cmake build and make output
├─include           # head file
|   ├─LinkedList.hpp
|   └─...
├─src               # source file
├─tools             # compile tools chain
├─.clang-format     # clang-format custom file
├─build.ps1         # build script in powershell
├─build.sh          # build script in bash
├─CMakeLists.txt    # CMake configuration
└─README.md
```


# CMake
## global configuration
## compile executable file
[app/CMakeLists.txt](app/CMakeLists.txt) configurate how to compile an executable file
```cmake
include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)

# add executable file
add_executable(test-linkedlist test-linkedlist.cpp)
```

```cmake
file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libstdc++-6.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libwinpthread-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libgcc_s_seh-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
```

## compile dynamic link library
## compile static link library


# Clang-Format
## Download
In [LLVM](https://llvm.org/builds/) official website, 
choose corresponding **Clang-Format** [Release](https://releases.llvm.org/) for your OS in **Other builds**. 

Then, you can download LLVM in this [page](https://releases.llvm.org/download.html) or in [Github Release](https://github.com/llvm/llvm-project.git)

when installing LLVM, 
in page `Install Options`, select if add LLVM to the system
- [ ] Do not add LLVM to the system PATH
- [x] Add LLVM to the system PATH for all user
- [ ] Add LLVM to the system PATH for current user

## Usage
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

# git
in file `.git/config`
```bash
[remote "origin"]
	url = https://gitee.com/<用户名>/<仓库名字>.git
	url = https://github.com/<用户名>/<仓库名字>.git
	fetch = +refs/heads/*:refs/remotes/origin/*
```