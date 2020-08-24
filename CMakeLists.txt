cmake_minimum_required(VERSION 3.17)
project(TaskManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(TaskManager main.cpp Process.h Process.cpp)