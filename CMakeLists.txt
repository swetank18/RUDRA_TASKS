cmake_minimum_required(VERSION 3.10)
project(HoughCircles)

find_package(OpenCV REQUIRED)

add_executable(hough main.cpp)
target_link_libraries(hough ${OpenCV_LIBS})

