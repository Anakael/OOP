cmake_minimum_required(VERSION 3.15)
project(OOP)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_NAME ${PROJECT_NAME})

include_directories(.)

file(GLOB_RECURSE SOURCE *.cpp)
list(FILTER SOURCE EXCLUDE REGEX ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${EXECUTABLE_NAME} ${SOURCE})
