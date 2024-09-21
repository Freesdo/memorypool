cmake_minimum_required(VERSION 3.10)

project(Arena)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(arena src/main.cpp)

set_target_properties(arena PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
