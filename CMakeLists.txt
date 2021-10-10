cmake_minimum_required(VERSION 3.15)
project(JankenPo)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin)

set(SRC
        ${CMAKE_SOURCE_DIR}/src/WeaponEnum.h
        ${CMAKE_SOURCE_DIR}/src/Player.h
        ${CMAKE_SOURCE_DIR}/src/Player.cpp
        ${CMAKE_SOURCE_DIR}/src/Game.h
        ${CMAKE_SOURCE_DIR}/src/Game.cpp
        ${CMAKE_SOURCE_DIR}/src/main.cpp
)

set(SRC ${SRC})

add_executable(JankenPo ${SRC})