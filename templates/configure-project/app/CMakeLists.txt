set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

message(STATUS "[INFO] CMAKE_CURRENT_SOURCE_DIR in ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt is: ${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(compile-executable_file main.cpp)