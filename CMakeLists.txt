cmake_minimum_required(VERSION 3.26)
project(game)

set(CMAKE_CXX_STANDARD 23)

add_executable(game main.cpp
        Unit.cpp
        Unit.h
        Transport.cpp
        Transport.h
)
