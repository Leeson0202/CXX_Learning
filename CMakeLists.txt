cmake_minimum_required(VERSION 3.26)
project(CXXLearning)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(operator)
add_subdirectory(STL)
add_subdirectory(Design_Pattern)


add_executable(participant STL/participant/participant.cpp
        template/templateTest.cpp
        template/templateTest.h)

