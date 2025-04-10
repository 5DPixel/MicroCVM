cmake_minimum_required(VERSION 3.12)

project(MicroCVM
    VERSION 0.1
    DESCRIPTION "A portable virtual CPU and memory system written in C"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(microcvm ${SOURCES})

enable_testing()
add_subdirectory(tests)

target_include_directories(microcvm PRIVATE include)