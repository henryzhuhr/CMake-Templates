# CMake-Templates
这是一个 CMake 模板库

- [CMake-Templates](#cmake-templates)
- [CMake](#cmake)
- [CMake模板](#cmake模板)
  - [全局配置](#全局配置)
  - [编译可执行文件](#编译可执行文件)
  - [编译动态链接库](#编译动态链接库)
  - [编译静态链接库](#编译静态链接库)
  - [编译一些有用的第三方库](#编译一些有用的第三方库)
    - [gflags](#gflags)
    - [Opencv](#opencv)
      - [为 Linux 编译 Opencv](#为-linux-编译-opencv)
      - [为 MacOS 编译 Opencv](#为-macos-编译-opencv)
      - [为 Windows 编译 Opencv](#为-windows-编译-opencv)
- [常见的工具](#常见的工具)
  - [Clang-Format](#clang-format)
    - [Download](#download)
    - [Usage](#usage)
  - [git](#git)
  - [Wget](#wget)

# CMake
你可以在[CMake官方网站](https://cmake.org/)找到[下载链接](https://cmake.org/download/)、[官方文档](https://cmake.org/documentation/)以及一份简单的[官方教程](https://cmake.org/cmake/help/v3.21/guide/tutorial/index.html#adding-system-introspection-step-5)

# CMake模板
每一个Cmake模板都是基于此目录进行的，具体每个项目可能由于其
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

## 全局配置
在 Cmake 项目的根目录下
```cmake
cmake_minimum_required(VERSION 3.10)

project(dataStructure)

# ==================================
#   C/CXX  standard
# ==================================
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "-g -fexec-charset=utf-8 -m64 ")
# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


add_subdirectory(src)
add_subdirectory(app)
```
## 编译可执行文件
see directory [`exe`](exe) for detail that how to compile an **executable file**


## 编译动态链接库
see directory [`dynamic-library`](dynamic-library) for details that how to compile **dynamic link library**

## 编译静态链接库
see directory [`static-library`](static-library) for detail that how to compile **static link library**

## 编译一些有用的第三方库
### gflags
download gflags in [GitHub](https://github.com/gflags/gflags), see ["Installing a binary distribution package"](https://github.com/gflags/gflags/blob/master/INSTALL.md)

### Opencv
对于OpenCV，我们选择从源码编译的方式。源码编译采用CMake，确保设备上安装了下面依赖：
- [CMake](https://cmake.org/download/)
- g++
- wget


在 [Github](https://github.com/opencv) 上下载相同版本的 [opencv](https://github.com/opencv/opencv) 和 [opencv_contrib](https://github.com/opencv/opencv_contrib) 源码的**Release版本**

> OpenCV下载较慢，可以选择在国内[镜像](https://www.bzblog.online/opencv/)里面下载（版本并不一定是最新的）

下面是基于Opencv 4.5.3版本进行的。

已经测试过可以编译的版本:
![Opencv-v4.5.1](https://img.shields.io/badge/Opencv-v4.5.1-blue)
![Opencv-v4.5.3](https://img.shields.io/badge/Opencv-v4.5.3-blue)



**源码编译可以参考官方的编译教程 [Installation in Linux](https://docs.opencv.org/4.5.2/d7/d9f/tutorial_linux_install.html)。**

在用CMake构建项目时，需要进行编译选项的配置，这些配置可以参考 [OpenCV compile configuration options reference](https://docs.opencv.org/4.5.2/db/d05/tutorial_config_reference.html) 。有一些编译选项在官方也并没有列举出来，那么这时候，为了查看完整的编译选项，可以使用`cmake-gui`来构建项目，并且可以查看当前版本下全部编译选项。

下载完成后，请将 [opencv](https://github.com/opencv/opencv) 和 [opencv_contrib](https://github.com/opencv/opencv_contrib) 解压放置到同一目录下，并且新建一个`download`目录，然后将 [docs/opencv](docs/opencv) 下的脚本文件，复制到相同目录下

例如在当前项目中的 [3rd-party](3rd-party) 目录下创建 [opencv](3rd-party/opencv) 目录（使用powershell脚本）
```bash
mkdir 3rd-party/opencv
cd 3rd-party/opencv
```
那么 [`3rd-party/opencv`](3rd-party/opencv) 的目录结构为，`<OpenCV_VERSION>`需要修改为需要编译的opencv的版本
```bash
.
├─download
├─opencv_contrib-<OpenCV_VERSION>
├─opencv-<OpenCV_VERSION>
├─build-opencv.bat    # script for windows 
├─build-opencv.sh     # script for linux/macOS
└─...
```

之后就可以根据系统来开始编译Opencv
- [ ] [为 Linux 编译 Opencv](#为-linux-编译-opencv)
- [ ] [为 MacOS 编译 Opencv](#为-macos-编译-opencv)
- [x] [为 Windows 编译 Opencv](#为-windows-编译-opencv)

#### 为 Linux 编译 Opencv
#### 为 MacOS 编译 Opencv
#### 为 Windows 编译 Opencv





准备好上述文件后，我们开始进行“尝试”编译
```bat
cd opencv-<OpenCV_VERSION>
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
```

在上述cmake构建项目的过程中，你会在终端看到一些“不和谐”的输出：
```bat
-- FFMPEG: Download: ffmpeg_version.cmake
-- Try 1 failed
--
=======================================================================
  Couldn't download files from the Internet.
  Please check the Internet access on this host.
=======================================================================

CMake Warning at cmake/OpenCVDownload.cmake:202 (message):
  FFMPEG: Download failed: 6;"Couldn't resolve host name"

  For details please refer to the download log file:


  .../CMake/3rd-party/opencv/opencv-4.5.3/build/CMakeDownloadLog.txt
```
这表示有一些文件没有被下载，这是由于“网速”原因。为了解决这个问题，你可以在 [build/CMakeDownloadLog.txt](build/CMakeDownloadLog.txt) 文件中查看哪些文件需要被下载、下载链接以及放置目录，例如
```txt
#do_copy "ffmpeg_version.cmake" "8862c87496e2e8c375965e1277dee1c7" "https://raw.githubusercontent.com/opencv/opencv_3rdparty/213fcd5d4897319a83207406036c4a5957fba010/ffmpeg/ffmpeg_version.cmake" ".../CMake/3rd-party/opencv/opencv-4.5.3/build/3rdparty/ffmpeg"
#check_md5 ".../CMake/3rd-party/opencv/opencv-4.5.3/build/3rdparty/ffmpeg/ffmpeg_version.cmake"
#mismatch_md5 ".../CMake/3rd-party/opencv/opencv-4.5.3/build/3rdparty/ffmpeg/ffmpeg_version.cmake" "f8e65dbe4a3b4eedc0d2997e07c3f3fd"
...
```
找到 `#do_copy` 一行，会看到需要下载的文件`ffmpeg_version.cmake`，以及下载链接`https://raw.githubusercontent.com/.../ffmpeg_version.cmake`，并且可以看到需要将该文件放置到目录下`.../build/3rdparty/ffmpeg`

通常会有如下文件需要下载：
| 需要下载的文件及其链接                                                                                                                                                | 放置的位置                                             |
| :-------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------- |
| [v0.1.1f.zip](https://github.com/opencv/ade/archive/v0.1.1f.zip)                                                                                                      | build/3rdparty/ade/v0.1.1f                             |
| [opencv_videoio_ffmpeg.dll](https://raw.githubusercontent.com/opencv/opencv_3rdparty/629590c3ba09fb0c8eaa9ab858ff13d3a84ca1aa/ffmpeg/opencv_videoio_ffmpeg.dll)       | `build/3rdparty/ffmpeg/opencv_videoio_ffmpeg.dll`      |
| [opencv_videoio_ffmpeg_64.dll](https://raw.githubusercontent.com/opencv/opencv_3rdparty/629590c3ba09fb0c8eaa9ab858ff13d3a84ca1aa/ffmpeg/opencv_videoio_ffmpeg_64.dll) | `build/3rdparty/ffmpeg/opencv_videoio_ffmpeg_64.dll`   |
| [ffmpeg_version.cmake](https://raw.githubusercontent.com/opencv/opencv_3rdparty/629590c3ba09fb0c8eaa9ab858ff13d3a84ca1aa/ffmpeg/ffmpeg_version.cmake)                 | `build/3rdparty/ffmpeg/ffmpeg_version.cmake`           |
| [detect.caffemodel](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/detect.caffemodel)                            | `build/downloads/wechat_qrcode/detect.caffemodel`      |
| [detect.prototxt](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/detect.prototxt)                                | `build/downloads/wechat_qrcode/detect.prototxt`        |
| [sr.caffemodel](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/sr.caffemodel)                                    | `build/downloads/wechat_qrcode/sr.caffemodel`          |
| [sr.prototxt](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/sr.prototxt)                                        | `build/downloads/wechat_qrcode`                        |
| [boostdesc_bgm.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm.i)                                  | `build/downloads/xfeatures2d/boostdesc_bgm.i`          |
| [boostdesc_bgm_bi.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm_bi.i)                            | `build/downloads/xfeatures2d/boostdesc_bgm_bi.i`       |
| [boostdesc_bgm_hd.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm_hd.i)                            | `build/downloads/xfeatures2d/boostdesc_bgm_hd.i`       |
| [boostdesc_binboost_064.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_binboost_064.i)                | `build/downloads/xfeatures2d/boostdesc_binboost_064.i` |
| [boostdesc_binboost_128.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_binboost_128.i)                | `build/downloads/xfeatures2d/boostdesc_binboost_128.i` |
| [boostdesc_binboost_256.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_binboost_256.i)                | `build/downloads/xfeatures2d/boostdesc_binboost_256.i` |
| [boostdesc_lbgm.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_lbgm.i)                                | `build/downloads/xfeatures2d/boostdesc_lbgm.i`         |
| [vgg_generated_48.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_48.i)                            | `build/downloads/xfeatures2d/vgg_generated_48.i`       |
| [vgg_generated_64.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_64.i)                            | `build/downloads/xfeatures2d/vgg_generated_64.i`       |
| [vgg_generated_80.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_80.i)                            | `build/downloads/xfeatures2d/vgg_generated_80.i`       |
| [vgg_generated_120.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_120.i)                          | `build/downloads/xfeatures2d/vgg_generated_120.i`      |
| [face_landmark_model.dat](https://raw.githubusercontent.com/opencv/opencv_3rdparty/8afa57abc8229d611c4937165d20e2a2d9fc5a12/face_landmark_model.dat)                  | `build/testdata/cv/face//face_landmark_model.dat`      |

<!-- 
- [v0.1.1f.zip](https://github.com/opencv/ade/archive/v0.1.1f.zip): 解压到 `build/3rdparty/ade/v0.1.1f`
- [opencv_videoio_ffmpeg.dll](https://raw.githubusercontent.com/opencv/opencv_3rdparty/629590c3ba09fb0c8eaa9ab858ff13d3a84ca1aa/ffmpeg/opencv_videoio_ffmpeg.dll): `build/3rdparty/ffmpeg/opencv_videoio_ffmpeg.dll`
- [opencv_videoio_ffmpeg_64.dll](https://raw.githubusercontent.com/opencv/opencv_3rdparty/629590c3ba09fb0c8eaa9ab858ff13d3a84ca1aa/ffmpeg/opencv_videoio_ffmpeg_64.dll): `build/3rdparty/ffmpeg/opencv_videoio_ffmpeg_64.dll`
- [ffmpeg_version.cmake](https://raw.githubusercontent.com/opencv/opencv_3rdparty/629590c3ba09fb0c8eaa9ab858ff13d3a84ca1aa/ffmpeg/ffmpeg_version.cmake): `build/3rdparty/ffmpeg/ffmpeg_version.cmake`
- [detect.caffemodel](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/detect.caffemodel): `build/downloads/wechat_qrcode/detect.caffemodel`
- [detect.prototxt](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/detect.prototxt): `build/downloads/wechat_qrcode/detect.prototxt`
- [sr.caffemodel](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/sr.caffemodel): `build/downloads/wechat_qrcode/sr.caffemodel`
- [sr.prototxt](https://raw.githubusercontent.com/WeChatCV/opencv_3rdparty/a8b69ccc738421293254aec5ddb38bd523503252/sr.prototxt): `build/downloads/wechat_qrcode`
- [boostdesc_bgm.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm.i): `build/downloads/xfeatures2d/boostdesc_bgm.i`
- [boostdesc_bgm_bi.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm_bi.i): `build/downloads/xfeatures2d/boostdesc_bgm_bi.i`
- [boostdesc_bgm_hd.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm_hd.i): `build/downloads/xfeatures2d/boostdesc_bgm_hd.i`
- [boostdesc_binboost_064.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_binboost_064.i): `build/downloads/xfeatures2d/boostdesc_binboost_064.i`
- [boostdesc_binboost_128.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_binboost_128.i): `build/downloads/xfeatures2d/boostdesc_binboost_128.i`
- [boostdesc_binboost_256.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_binboost_256.i): `build/downloads/xfeatures2d/boostdesc_binboost_256.i`
- [boostdesc_lbgm.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_lbgm.i): `build/downloads/xfeatures2d/boostdesc_lbgm.i`
- [vgg_generated_48.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_48.i): `build/downloads/xfeatures2d/vgg_generated_48.i`
- [vgg_generated_64.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_64.i): `build/downloads/xfeatures2d/vgg_generated_64.i`
- [vgg_generated_80.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_80.i): `build/downloads/xfeatures2d/vgg_generated_80.i`
- [vgg_generated_120.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d/vgg_generated_120.i): `build/downloads/xfeatures2d/vgg_generated_120.i`
- [face_landmark_model.dat](https://raw.githubusercontent.com/opencv/opencv_3rdparty/8afa57abc8229d611c4937165d20e2a2d9fc5a12/face_landmark_model.dat): `build/testdata/cv/face//face_landmark_model.dat` 
 -->

如果将上述文件下载后，放置到与编译脚本 `build-opencv.*` 同级的目录 `download` 下，就可以很方便的用脚本进行编译

编译前请仔细查看[编译脚本`opencv/build-opencv.*`](docs/opencv/build-opencv.sh)，需要修改：
- OpenCV的版本 `OPENCV_VERSION`
- **CMake的编译选项 `-D`，可以参考 [OpenCV compile configuration options reference](https://docs.opencv.org/4.5.2/db/d05/tutorial_config_reference.html) 。**   
  有一些编译选项在官方也并没有列举出来，那么这时候，为了查看完整的编译选项，可以使用`cmake-gui`来构建项目，并且可以通过UI界面来查看当前版本下全部编译选项。     
  比较重要的几个编译选项，例如：
  - `-D CMAKE_INSTALL_PREFIX=~/Programs/opencv`: **Opencv需要安装的位置**（这里推荐安装到用户目录下），便于之后CMake项目链接OpenCV库
  - `-D BUILD_opencv_python2=OFF`,`-D BUILD_opencv_python3=OFF`: 该项目不编译python版本的opencv，如果需要为python安装opencv，建议`pip3 install opencv-python`，如果需要处理与视频相关的操作，那么才需要用该项目编译python版本的opencv
- **编译使用的线程数`-j`**，默认是8线程编译`make -j8`，根据电脑配置进行修改，单线程则是`make`，十六线程则是`make -j16`。**当出现编译错误的时候，首先考虑修改编译线程数为单线程编译，重新进行编译，有概率能够解决问题。**


```bat
set CV_VERSION=4.5.3

cd opencv-%CV_VERSION%

md build

md build\3rdparty\ffmpeg
copy ..\download\*.cmake build\3rdparty\ffmpeg\
copy ..\download\*.dll  build\3rdparty\ffmpeg\

md build\downloads\wechat_qrcode
copy ..\download\*.caffemodel   build\downloads\wechat_qrcode
copy ..\download\*.prototxt     build\downloads\wechat_qrcode

md build\downloads\xfeatures2d\
copy ..\download\*.i build\downloads\xfeatures2d\

md build\testdata\cv\face\
copy ..\download\face_landmark_model.dat build\testdata\cv\face\

cd build

cmake .. ^
    -G "MinGW Makefiles" ^
    -D CMAKE_INSTALL_PREFIX=~/Programs/opencv ^
    -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-%CV_VERSION%/modules ^
    -D OPENCV_GENERATE_PKGCONFIG=ON ^
    -D CMAKE_BUILD_TYPE=Release ^
    -DBUILD_opencv_python2=OFF ^
    -DBUILD_opencv_python3=OFF ^
    -D BUILD_SHARED_LIBS=ON^
    -D WITH_CUDA=OFF ^
    -D OPENCV_DNN_CUDA=OFF ^
    -D WITH_ONNX=OFF ^
    -D WITH_1394=OFF
make -j8
make install
```

修改脚本以适配你的设备，随后可以简单的用脚本进行编译：
```bat
./build-opencv.bat
```

编译完成之后需要检查安装目录，也就是编译选项中的`CMAKE_INSTALL_PREFIX` (`~/Programs/opencv`)，安装目录应该如下：
```bat
.
├─bin
├─etc
├─include
├─x64
├─LICENSE
├─OpenCVConfig.cmake
├─OpenCVConfig-version.cmake
└─setup_vars_opencv4.cmd
```
其中`OpenCVConfig.cmake`和`OpenCVConfig-version.cmake`是非常重要的两个文件，CMake能够链接到OpenCV库就是寻找这两个文件。`setup_vars_opencv4.cmd`是设置OpenCV环境变量的脚本

在CＭake项目中使用参考 [Cmake+OpenCV 模板](templates/with-opencv)

# 常见的工具
## Clang-Format
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
