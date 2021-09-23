cmake_minimum_required(VERSION 3.13)
project(redis_findere C)

set(CMAKE_C_STANDARD 99)

add_library(redis_findere SHARED library.c redismodule.h)
