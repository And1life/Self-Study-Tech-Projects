cmake_minimum_required(VERSION 3.10)

project(VectorTests)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(VectorTests

    Vector_Tests.cpp
)

target_link_libraries(VectorTests
    PRIVATE
    GTest::GTest
    GTest::Main
    Vector
)

target_include_directories(VectorTests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
enable_testing()
gtest_discover_tests(VectorTests)
