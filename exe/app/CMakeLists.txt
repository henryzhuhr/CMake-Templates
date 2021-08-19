include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

# add executable file
add_executable(main main.cpp)