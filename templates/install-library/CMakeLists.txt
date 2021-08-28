cmake_minimum_required(VERSION 3.10)
project(INSTALL_LIBRARY)


if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(
        CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist 
        CACHE PATH "Installation Directory" FORCE
        )
endif()
message(STATUS "[Install Path] ${CMAKE_INSTALL_PREFIX}")

message(STATUS "[Build Type] ${CMAKE_BUILD_TYPE}")

add_subdirectory(src)
