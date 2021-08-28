include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)

# add executable file
add_executable(test-dl test-dl.cpp)

target_link_libraries(test-dl myClass)