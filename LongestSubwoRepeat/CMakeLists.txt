cmake_minimum_required(VERSION 2.6)
project(main)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
SET(SRCS ./cpp/find_sub.cpp main.cpp)

include_directories(SRCS PUBLIC ./hpp)

ADD_EXECUTABLE (main ${SRCS})

target_compile_options (main PRIVATE -std=c++17)