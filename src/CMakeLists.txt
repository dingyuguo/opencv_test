#cmake needs this line
cmake_minimum_required(VERSION 2.8)

#define project name 
project(test)

find_package(Opencv REQUIRED)

if(CMAKE_VERSION VERSION_LESS "2.8.11")
	include_directories(&{OpenCV_INCLUDE_DIRS})
endif()

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXX_FLAGS} -O0 -Wall -g -ggdb")


add_executable(draw_circle draw_circle.cpp)

message(  " opencv_libes"  ${OpenCV_LIBS})
target_link_libraries(draw_circle ${OpenCV_LIBS})

