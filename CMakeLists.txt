cmake_minimum_required(VERSION 3.23)
project(jolt)

set(CMAKE_CXX_STANDARD 14)

add_executable(jolt main.cpp parser.cpp parser.h debug.h constantpool.cpp constantpool.h constant.cpp constant.h)
