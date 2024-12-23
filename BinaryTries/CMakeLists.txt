cmake_minimum_required(VERSION 3.26)
project(BinaryTries C)

set(CMAKE_C_STANDARD 11)

add_executable(BinaryTries main.c
        BinaryTree.c
        BinaryTree.h)
