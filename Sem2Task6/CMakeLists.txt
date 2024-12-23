cmake_minimum_required(VERSION 3.26)
project(Sem2Task6)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sem2Task6 main.cpp
        Queue.h
        "RequestQueue.h"
        RequestQueue.cpp
)
