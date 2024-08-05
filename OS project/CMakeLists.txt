cmake_minimum_required(VERSION 3.26)
project(OS_project C)

set(CMAKE_C_STANDARD 11)

add_executable(OS_project main.c
        dataset.h
        dataset.c
        bruh.cpp
)
