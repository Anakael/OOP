cmake_minimum_required(VERSION 3.15)
project(OOP)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_NAME ${PROJECT_NAME})

include_directories(.)

file(GLOB_RECURSE SOURCE *.cpp)
list(FILTER SOURCE EXCLUDE REGEX ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${EXECUTABLE_NAME} ${SOURCE} commands/attack_command.cpp commands/attack_command.h commands/pick_up_neutral_object_command.cpp commands/pick_up_neutral_object_command.h commands/object_die_command.cpp commands/object_die_command.h commands/create_object_command.cpp commands/create_object_command.h common/coordinates.h)
