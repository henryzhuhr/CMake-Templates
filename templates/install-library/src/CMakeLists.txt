aux_source_directory(./  myLib_src)
message(STATUS "[INFO] compile by: ${myLib_src}")
include_directories(${PROJECT_SOURCE_DIR}/include)


add_library(myLib STATIC ${myLib_src})          # static  link library
add_library(myLib_shared SHARED ${myLib_src})   # dynamic link library

set_target_properties(myLib_shared PROPERTIES OUTPUT_NAME "myLib")
set_target_properties(myLib_shared PROPERTIES VERSION 1.2 SEVERSION 1)



set(INSTALL_HEAD_FILES 
    ${PROJECT_SOURCE_DIR}/include/myClass.h
)
install(
    FILES ${INSTALL_HEAD_FILES} 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    )

install(TARGETS myLib_shared myLib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION lib
    )

