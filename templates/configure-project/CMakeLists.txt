cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(configure_project LANGUAGES CXX)


# PROJECT_SOURCE_DIR
message(STATUS "[INFO] project source dir: ${PROJECT_SOURCE_DIR}(default)")
message(STATUS)


# PROJECT_BINARY_DIR
message(STATUS "[INFO] project binary dir: ${PROJECT_BINARY_DIR}(default)")
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "[INFO] project binary dir: ${PROJECT_BINARY_DIR}")
message(STATUS)


# LIBRARY_OUTPUT_PATH
message(STATUS "[INFO] library output dir: ${LIBRARY_OUTPUT_PATH}(default)")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
message(STATUS "[INFO] library output dir: ${LIBRARY_OUTPUT_PATH}")
message(STATUS)


# EXCUTABLE_OUTPUT_PATH
message(STATUS "[INFO] executable output path: ${EXCUTABLE_OUTPUT_PATH}(default)")
set(EXCUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "[INFO] executable output path: ${EXCUTABLE_OUTPUT_PATH}")
message(STATUS)


# CMAKE_BUILD_TYPE
message(STATUS "[INFO] cmake build type: ${CMAKE_BUILD_TYPE}(default)")
set(CMAKE_BUILD_TYPE RELEASE CACHE STRING "builde type" FORCE)
message(STATUS "[INFO] cmake build type: ${CMAKE_BUILD_TYPE}")
message(STATUS)




if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 8->x64 4->x86
    set(ADDRESS_MODEL 64)
    set(NODE_TARGET x64)
else()
    set(ADDRESS_MODEL 32)
    set(NODE_TARGET x86)
endif()
message(STATUS "[Address] ${ADDRESS_MODEL}-bit")


add_subdirectory(app)


