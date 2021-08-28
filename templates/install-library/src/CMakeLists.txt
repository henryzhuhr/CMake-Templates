aux_source_directory(./  myLib_src)
message(STATUS "[INFO] compile by: ${myLib_src}")
include_directories(${PROJECT_SOURCE_DIR}/include)



add_library(myLib STATIC ${myLib_src})          # static  link library
add_library(myLib_shared SHARED ${myLib_src})   # dynamic link library

SET_TARGET_PROPERTIES(myLib_shared PROPERTIES OUTPUT_NAME "myLib")
SET_TARGET_PROPERTIES(myLib_shared PROPERTIES VERSION 1.2 SEVERSION 1)

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist)
message(STATUS "[INFO] library install to: ${CMAKE_INSTALL_PREFIX}")
file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX})

# FILE(GLOB_RECURSE myLib_LIB_HEADERS ${PROJECT_SOURCE_DIR}/include/*)
# INSTALL(FILES ${myLib_LIB_HEADERS} DESTINATION Release/include)

INSTALL(TARGETS myLib_shared myLib
    CONFIGURATIONS Release
    RUNTIME DESTINATION Release/bin
    LIBRARY DESTINATION Release/bin
    ARCHIVE DESTINATION Release/lib
)

# message(STATUS "[INFO] header file: ${PROJECT_SOURCE_DIR}/include")
# message(STATUS "[INFO] header file: ${myLib_LIB_HEADERS}")