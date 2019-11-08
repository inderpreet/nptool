## @file    CMakeLists.txt
## @brief   Cmake File for VIDS Project
## @author  Inderpreet Singh

## For the uninitiated, create a folder named build and run the 
## command cmake .. && make 
## to make and build the executable

cmake_minimum_required(VERSION 2.8)

# Project Name
project( nptool )

set( CMAKE_C_COMPILER "gcc" )
# set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS "-Wall -m64 -O3 -std=c++14 -pedantic -v -pthread " ) 
# -fno-omit-frame-pointer -g -v -finstrument-functions -DWITH_OPENCL=OFF" )
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# The version number
set (APP_VERSION_MAJOR 1)
set (APP_VERSION_MINOR 0)

## configure to pass cmake settings INTO the source CMAKE_SOURCE_DIR
configure_file(
    "${PROJECT_SOURCE_DIR}/include/app_config.h.in"
    "${PROJECT_BINARY_DIR}/app_config.h"
)
## use #define APP_VERSION_MAJOR @APP_VERSION_MAJOR@ in the app_config.h.in file


SET(OpenCV_DIR /usr/local/Cellar/opencv/4.0.1/)

## Find package OpenCV
# find_package( OpenCV REQUIRED )

## Include directories for the headers etc
include_directories( 
    # ${OpenCV_INCLUDE_DIRS} 
    ${PROJECT_SOURCE_DIR}/include 
    "." 
    ${PROJECT_BINARY_DIR}
)

## Source Files
file(GLOB SOURCES "./*.cpp" "./src/*.cpp")

## Create Binary Named demo_linux_x64 and link OpenCV Libraries
add_executable( nptool ${SOURCES})
target_link_libraries( nptool  ${OpenCV_LIBS} )

## Copy assets to build folder
#add_custom_command(TARGET ${PROJECT_NAME}
#    POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/assets
#
#    COMMAND ${CMAKE_COMMAND} -E copy 
#    ${CMAKE_SOURCE_DIR}/assets/*.*
#    ${CMAKE_BINARY_DIR}/assets/
#    )