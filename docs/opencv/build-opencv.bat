set OPENCV_VERSION=4.5.1

cd opencv-%OPENCV_VERSION%

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
    -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-%OPENCV_VERSION%/modules ^
    -D OPENCV_GENERATE_PKGCONFIG=ON ^
    -D CMAKE_BUILD_TYPE=Release ^
    -DBUILD_opencv_python2=OFF ^
    -DBUILD_opencv_python3=OFF ^
    -D BUILD_SHARED_LIBS=ON^
    -D WITH_CUDA=ON ^
    -D OPENCV_DNN_CUDA=ON ^
    -D WITH_ONNX=ON ^
    -D WITH_1394=OFF
make -j8
make install
