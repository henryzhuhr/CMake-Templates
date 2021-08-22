aux_source_directory(./  myClass_src)
message(STATUS "[INFO] compile by: ${myClass_src}")
include_directories(${PROJECT_SOURCE_DIR}/include)

# ------ static ------
add_library(myClass STATIC ${myClass_src})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
message(STATUS "[INFO] STATIC linked library compiled by : " ${myClass_src})
