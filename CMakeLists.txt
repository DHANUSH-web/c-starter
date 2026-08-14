cmake_minimum_required(VERSION 3.20)
project(cpp-codingbat LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(c-codingbat src/core.c src/main.c)
target_include_directories(c-codingbat PRIVATE include extras/unity/src)

add_executable(c-codingbat-tests tests/test_core.c src/core.c extras/unity/src/unity.c)
target_include_directories(c-codingbat-tests PRIVATE include extras/unity/src)
