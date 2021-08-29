
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(compile-platform main.cpp)


if (UNIX AND NOT APPLE) # Linux
    target_compile_definitions(compile-platform PUBLIC "IS_LINUX")
elseif (APPLE)          # MacOS
    target_compile_definitions(compile-platform PUBLIC "IS_MACOS")
elseif (WIN32)          # Windows
    target_compile_definitions(compile-platform PUBLIC "IS_WINDOWS")
endif ()

