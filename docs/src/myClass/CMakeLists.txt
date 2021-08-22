aux_source_directory(./  myClass_src)
message(STATUS "[INFO] compile by: ${myClass_src}")
include_directories(${PROJECT_SOURCE_DIR}/include)

# ------ static
# add_library(src STATIC ${myClass_src})
# SET_TARGET_PROPERTIES (src PROPERTIES OUTPUT_NAME "src")


# ------ shared
add_library(myClass SHARED ${myClass_src})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "[INFO] SHARED linked library compiled by : " ${myClass_src})

# target_link_libraries(myClass)