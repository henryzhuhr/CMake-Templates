aux_source_directory(./  myClass_src)
message(STATUS "[INFO] compile by: ${myClass_src}")
include_directories(${PROJECT_SOURCE_DIR}/include)



add_library(myClass STATIC ${myClass_src})          # ------ static ------
add_library(myClass_shared SHARED ${myClass_src})   # ------ shared ------
# rename dynamic_link_library file / set dynamic_link_library output name
SET_TARGET_PROPERTIES(myClass_shared PROPERTIES OUTPUT_NAME "myClass")

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist)


FILE(GLOB_RECURSE myclass_LIB_HEADERS ${PROJECT_SOURCE_DIR}/include/*)
INSTALL(FILES ${myclass_LIB_HEADERS} DESTINATION Release/include)

INSTALL(TARGETS myClass_shared myClass ${myclass_LIB_HEADERS}
    CONFIGURATIONS Release
    RUNTIME DESTINATION Release/bin
    LIBRARY DESTINATION Release/bin
    ARCHIVE DESTINATION Release/lib
    PUBLIC_HEADER DESTINATION Release/include
)

message(STATUS "[INFO] header file: ${PROJECT_SOURCE_DIR}/include")
message(STATUS "[INFO] header file: ${myclass_LIB_HEADERS}")