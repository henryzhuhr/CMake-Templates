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
  - [compile 3rd-party](#compile-3rd-party)
    - [Opencv](#opencv)
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
see directory [`exe`](exe) for detail that how to compile an **executable file**


## compile dynamic link library
see directory [`dynamic-library`](dynamic-library) for details that how to compile **dynamic link library**
## compile static link library
see directory [`static-library`](static-library) for detail that how to compile **static link library**

## compile 3rd-party
### Opencv
Download the same version of [opencv](https://github.com/opencv/opencv) and [opencv_contrib](https://github.com/opencv/opencv_contrib) in Releases or[Mirrors](https://www.bzblog.online/opencv/)

Compile from source:
- [OpenCV compile configuration options reference](https://docs.opencv.org/4.5.2/db/d05/tutorial_config_reference.html)
- [Compile by Cmake](https://docs.opencv.org/4.5.2/d7/d9f/tutorial_linux_install.html)
```bash
cd opencv-4.5.2
mkdir build
cd build
cmake .. ^
    -G "MinGW Makefiles" ^
    -DCMAKE_INSTALL_PREFX=C:/Users/Henryzhu/Programs/opencv ^
    -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.5.2/modules ^
    -DCMAKE_BUILD_TYPE=Release ^
    -DOPENCV_GENERATE_PKGCONFIG=ON ^
    -DBUILD_SHARED_LIBS=OFF^
    -DWITH_CUDA=OFF ^
    -DOPENCV_DNN_CUDA=OFF ^
    -DWITH_ONNX=ON ^
    -DWITH_1394=OFF

make -j8
```
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
	url = https://gitee.com/<user_name>/<repo_name>.git
	url = https://github.com/<user_name>/<repo_name>.git
	fetch = +refs/heads/*:refs/remotes/origin/*
```