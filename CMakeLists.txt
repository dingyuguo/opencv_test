#cmake needs this line
cmake_minimum_required(VERSION 2.8)
#define project name 
project(opencv_test_project)

find_package(Opencv REQUIRED)

if(CMAKE_VERSION VERSION_LESS "2.8.11")
	include_directories(&{OpenCV_INCLUDE_DIRS})
endif()

set(ROOT_DIR ${opencv_test_project_SOURCE_DIR})
include_directories(${ROOT_DIR}/include)
add_subdirectory(${ROOT_DIR}/src)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXX_FLAGS} -O0 -Wall -g -ggdb")


