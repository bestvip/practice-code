cmake_minimum_required(VERSION 2.8)
project(MedianFilter)
find_package(OpenCV REQUIRED)
add_executable(MedianFilter.out MedianFilter.cpp)
target_link_libraries(MedianFilter.out ${OpenCV_LIBS})
