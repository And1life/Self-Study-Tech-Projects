cmake_minimum_required(VERSION 3.10)
project(Vector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Vector INTERFACE)
target_include_directories(Vector INTERFACE include)

add_subdirectory(tests)