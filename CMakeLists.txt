cmake_minimum_required(VERSION 3.17)
project(BigInt)

set(CMAKE_CXX_STANDARD 17)

enable_testing(true)

add_executable(BigInt main.cpp BigInt.h BigInt.cpp)


add_subdirectory(gtest)

add_subdirectory(test)