cmake_minimum_required(VERSION 3.7)
project(LineDrawing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(LineDrawing ${SOURCE_FILES})
target_link_libraries(LineDrawing graph)