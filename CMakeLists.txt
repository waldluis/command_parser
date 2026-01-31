cmake_minimum_required(VERSION 3.15)
project(command_parser LANGUAGES CXX)

option(ENABLE_TESTS "Build unit tests" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(src)

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()