aux_source_directory(.  myClass_src)
message(STATUS "[INFO] compile by: ${myClass_src}")
include_directories(${PROJECT_SOURCE_DIR}/include)

# ------ dynamic-link-library ------
add_library(myClass_shared SHARED ${myClass_src})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "[INFO] dynamic link library compiled by : " ${myClass_src})

# ------ static-link-library ------
add_library(myClass STATIC ${myClass_src})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
message(STATUS "[INFO] static link library compiled by : " ${myClass_src})

# -- link other 3rd-party lib to this lib
# target_link_libraries(myClass <>)