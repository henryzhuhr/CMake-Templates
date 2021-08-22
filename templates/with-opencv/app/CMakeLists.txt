
# -------- 3rd-party lib --------
# -- Opencv4
set(OpenCV_DIR "C:/Users/Henryzhu/Programs/opencv/")
find_package( OpenCV 4 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories(${OpenCV_LIB_DIRS})
message(STATUS "OpenCV status:")
message(STATUS "    Opencv version: ${OpenCV_VERSION}")   
message(STATUS "    Opencv include: ${OpenCV_INCLUDE_DIRS}")

# include_directories(${PROJECT_SOURCE_DIR}/src/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("CMAKE_BINARY_DIR:" ${PROJECT_SOURCE_DIR}/bin)

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

add_executable(${PROJECT_NAME} 
    app-match-sift.cpp
    )
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    )

