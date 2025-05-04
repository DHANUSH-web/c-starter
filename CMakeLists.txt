cmake_minimum_required(VERSION 3.20)
project(c-starter VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
include_directories(lib)
add_executable(main main.c
    lib/main.h
)