cmake_minimum_required(VERSION 2.8)

PROJECT(fizz_buzz)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
endif()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_fizz_buzz test_fizz_buzz.cpp)
target_link_libraries(test_fizz_buzz ${GTEST_LIBRARIES} pthread)
