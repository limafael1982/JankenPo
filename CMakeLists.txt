cmake_minimum_required(VERSION 3.15)
project(JankenPo)

set(CMAKE_CXX_STANDARD 11)

set(SRC ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(JankenPo ${SRC})