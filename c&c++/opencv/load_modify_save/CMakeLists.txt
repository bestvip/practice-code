cmake_minimum_required(VERSION 2.8)
project(LoadModifySave)
find_package(OpenCV REQUIRED)
add_executable(LoadModifySave.out LoadModifySave.cpp LoadModifySave.cpp)
target_link_libraries(LoadModifySave.out ${OpenCV_LIBS})
