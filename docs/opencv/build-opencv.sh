CV_VERSION=4.5.1

cd opencv-${CV_VERSION}

mkdir build

mkdir build/3rdparty/ffmpeg
cp ../download/*.cmake build/3rdparty/ffmpeg/
cp ../download/*.dll  build/3rdparty/ffmpeg/

mkdir build/downloads/wechat_qrcode
cp ../download/*.caffemodel   build/downloads/wechat_qrcode
cp ../download/*.prototxt     build/downloads/wechat_qrcode

mkdir build/downloads/xfeatures2d/
cp ../download/*.i build/downloads/xfeatures2d/

mkdir build/testdata/cv/face/
cp ../download/face_landmark_model.dat build/testdata/cv/face/

cd build

cmake .. \
    -D CMAKE_INSTALL_PREFIX=~/Programs/opencv \
    -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-${CV_VERSION}/modules \
    -D OPENCV_GENERATE_PKGCONFIG=ON \
    -D CMAKE_BUILD_TYPE=Release \
    -DBUILD_opencv_python2=OFF \
    -DBUILD_opencv_python3=OFF \
    -D BUILD_SHARED_LIBS=ON\
    -D WITH_CUDA=OFF \
    -D OPENCV_DNN_CUDA=OFF \
    -D WITH_ONNX=OFF \
    -D WITH_1394=OFF
make -j8
make install
