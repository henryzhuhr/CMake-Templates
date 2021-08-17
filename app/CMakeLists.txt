include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)

# 添加可执行文件
add_executable(test-linkedlist test-linkedlist.cpp)

add_executable(test-myclass test-myclass.cpp)
target_link_libraries(test-myclass myClass)



file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libstdc++-6.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libwinpthread-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libgcc_s_seh-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)