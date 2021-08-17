HOME=$(pwd)

CMAKE_BIN=${HOME}/tools/cmake-3.20.1-windows-x86_64/bin/
export PATH=$PATH:${CMAKE_BIN}

MinGW64_BIN=${HOME}/tools/mingw64/bin/
export PATH=$PATH:${MinGW64_BIN}

rm -rf bin
rm -rf build

mkdir build
cd build

cmake .. \
    -G "MinGW Makefiles" \
    -DCMAKE_BUILD_TYPE=Release
make -j8

# rm -rf build

cd bin
test_linkedlist.exe
