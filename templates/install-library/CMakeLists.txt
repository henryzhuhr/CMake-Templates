cmake_minimum_required(VERSION 3.10)

project(DYNAMIC_LIBRARY)

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


# cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=C:/Users/Henryzhu/project/CMake/install-library/dist
