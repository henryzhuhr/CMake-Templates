# CMake-Templates!
[![简体中文](https://img.shields.io/badge/说明文档-简体中文-blue)](README.md)
[![Englis](https://img.shields.io/badge/README-English-red)](README_en.md)

CMake is good
- [CMake-Templates!](#cmake-templates)
- [Compile the project](#compile-the-project)
- [Directory Structure](#directory-structure)
- [CMake](#cmake)
  - [global configuration](#global-configuration)
  - [compile executable file](#compile-executable-file)
  - [compile dynamic link library](#compile-dynamic-link-library)
  - [compile static link library](#compile-static-link-library)
  - [build some useful 3rd-party](#build-some-useful-3rd-party)
    - [gflags](#gflags)
    - [Opencv](#opencv)
- [Clang-Format](#clang-format)
  - [Download](#download)
  - [Usage](#usage)
- [git](#git)
- [Wget](#wget)

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

## build some useful 3rd-party
### gflags
download gflags in [GitHub](https://github.com/gflags/gflags), see ["Installing a binary distribution package"](https://github.com/gflags/gflags/blob/master/INSTALL.md)
### Opencv
Download the same version of [opencv](https://github.com/opencv/opencv) and [opencv_contrib](https://github.com/opencv/opencv_contrib) in Releases or[Mirrors](https://www.bzblog.online/opencv/)

Compile from source:
- [OpenCV compile configuration options reference](https://docs.opencv.org/4.5.2/db/d05/tutorial_config_reference.html)
- [Compile by Cmake](https://docs.opencv.org/4.5.2/d7/d9f/tutorial_linux_install.html)

In Windows cmd:
```bat
cd opencv-4.5.2

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
    -D CMAKE_INSTALL_PREFIX=C:/Users/Henryzhu/Programs/opencv ^
    -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.5.2/modules ^
    -D CMAKE_BUILD_TYPE=Release ^
    -DBUILD_opencv_python2=OFF ^
    -DBUILD_opencv_python3=OFF ^
    -D OPENCV_GENERATE_PKGCONFIG=ON ^
    -D BUILD_SHARED_LIBS=OFF^
    -D WITH_CUDA=ON ^
    -D OPENCV_DNN_CUDA=ON ^
    -D WITH_ONNX=ON ^
    -D WITH_1394=OFF
make -j8
make install
```

Some file must be downloaded for OpenCV compiled. After `cmake` command, see `build/CMakeDownloadLog.txt` to get the files need to be downloaded, then download and put them to the corresponded folder:
- [v0.1.1f.zip](https://github.com/opencv/ade/archive/v0.1.1f.zip): `build/3rdparty/ade/v0.1.1f`
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

# Wget

A command-line utility for retrieving files using HTTP, HTTPS and FTP protocols.

Download:
- [Windows binaries of GNU Wget](https://eternallybored.org/misc/wget/) (Downloading ZIP and add to system PATH is recommended.)
