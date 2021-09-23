cmake_minimum_required(VERSION 3.13)
project(redis_findere)

set(CMAKE_CXX_STANDARD 11)

add_library(redis_findere SHARED library.cpp redismodule.h)

add_subdirectory(findere)
