cmake_minimum_required(VERSION 3.20)

# project
project(c-starter VERSION 0.1.0 LANGUAGES C)

# config
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# build type compiler flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -g)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O2 -DNDEBUG)
endif()

# testing
enable_testing()

# include libraries
add_subdirectory(lib/logger)
add_subdirectory(lib/unity)

# main target
add_executable(main main.c)
target_include_directories(main PRIVATE lib)
target_link_libraries(main m)

# test target
add_executable(test_main tests/test_main.c main.c)
target_compile_definitions(test_main PRIVATE UNIT_TEST)
target_include_directories(test_main PRIVATE lib/logger lib lib/unity/src)
target_link_libraries(test_main unity m)

add_test(NAME UnitTests COMMAND test_main)
