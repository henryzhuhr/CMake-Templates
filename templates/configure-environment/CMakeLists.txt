cmake_minimum_required(VERSION 3.10 FATAL_ERROR)


# =================================
#   C/CXX configuration: must before `project()`
# =================================
# CMAKE_C_COMPILER
message(STATUS "[INFO] C compiler: ${CMAKE_C_COMPILER}(default)")
if(NOT CMAKE_C_COMPILER)
    message(WARNING "not specify C compiler")
    set(CMAKE_C_COMPILER "~/Programs/mingw64/bin/gcc.exe")
endif()
get_filename_component(CMAKE_C_COMPILER ${CMAKE_C_COMPILER} ABSOLUTE)
message(STATUS "[INFO] C compiler: ${CMAKE_C_COMPILER}")
message(STATUS)

# CMAKE_CXX_COMPILER
message(STATUS "[INFO] CXX compiler: ${CMAKE_CXX_COMPILER}(default)")
if(NOT CMAKE_CXX_COMPILER)
    message(WARNING "not specify C++ compiler")
    set(CMAKE_CXX_COMPILER "~/Programs/mingw64/bin/g++.exe")
endif()
get_filename_component(CMAKE_CXX_COMPILER ${CMAKE_CXX_COMPILER} ABSOLUTE)
message(STATUS "[INFO] CXX compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS)

message(STATUS "[INFO] CXX standard: ${CMAKE_CXX_STANDARD}(default)")
set(CMAKE_CXX_STANDARD 14)
message(STATUS "[INFO] CXX standard: ${CMAKE_CXX_STANDARD}")
message(STATUS)


add_compile_options(-std=c++11 -Wall -Werror)
message(STATUS "[INFO] CXX standard: ${CMAKE_CXX_STANDARD}")


project(configure_project LANGUAGES CXX)


add_subdirectory(app)


