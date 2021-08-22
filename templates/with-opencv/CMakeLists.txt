cmake_minimum_required(VERSION 3.0)
project( project )

# C-CXX-standard
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "-g -fexec-charset=GBK")

# -------- Debug config --------
# -- dubug 模式------------------这个非常重要，否则无法进入断点
# add_definitions("-Wall -g")
# set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_subdirectory(app)
