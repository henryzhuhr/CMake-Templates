aux_source_directory(.  myLib)
message(STATUS "[INFO] compile by: ${myLib}")
include_directories(${PROJECT_SOURCE_DIR}/include)

# ------ dynamic-link-library ------
add_library(myLib_shared SHARED ${myLib})
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "[INFO] dynamic link library compiled by : " ${myLib})

# ------ static-link-library ------
add_library(myLib STATIC ${myLib})
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
message(STATUS "[INFO] static link library compiled by : " ${myLib})

# -- link other 3rd-party lib to this lib
# target_link_libraries(myLib <>)