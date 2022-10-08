cmake_minimum_required(VERSION 3.17)
project(leetcode_solver)

set(CMAKE_CXX_STANDARD 14)

configure_file(
    "${PROJECT_SOURCE_DIR}/solves/config.h.in"
    "${PROJECT_BINARY_DIR}/solves/config.h"
)

include(ExternalProject)
include("${CMAKE_SOURCE_DIR}/deps/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

file(GLOB_RECURSE SRC_CC "solves/*.cc")
add_executable(main ${SRC_CC})
add_dependencies(main rapidjson)