aux_source_directory(./  myClass_src)
message(STATUS "[INFO] compile by: ${myClass_src}")
include_directories(${PROJECT_SOURCE_DIR}/include)

# ------ shared ------
add_library(myClass SHARED ${myClass_src})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "[INFO] SHARED linked library compiled by : " ${myClass_src})

# -- link other 3rd-party
# target_link_libraries(myClass)