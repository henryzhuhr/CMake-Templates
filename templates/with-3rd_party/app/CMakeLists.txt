# =========================================
#       3rd-party lib
# =========================================
# -- Boost
set(BOOST_ROOT "~/Programs/boost")
get_filename_component(BOOST_ROOT ${BOOST_ROOT} ABSOLUTE)
find_package(Boost 1.36.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
message(STATUS "Boost status:")
message(STATUS "    Opencv version: ${Boost_VERSION}")   
message(STATUS "    Opencv include: ${Boost_INCLUDE_DIRS}")

# include_directories(${PROJECT_SOURCE_DIR}/src/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("CMAKE_BINARY_DIR:" ${PROJECT_SOURCE_DIR}/bin)

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

add_executable(${PROJECT_NAME} 
    test.cpp
    )
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    )

