cmake_minimum_required(VERSION 3.16)
project(leetcode_solver)

set(CMAKE_CXX_STANDARD 14)
add_compile_definitions(PROBLEM_NUM=${PROBLEM_NUM})

configure_file(
    "${PROJECT_SOURCE_DIR}/solves/config.h.in"
    "${PROJECT_BINARY_DIR}/solves/config.h"
)

include(ExternalProject)
include("${CMAKE_SOURCE_DIR}/deps/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

# file(GLOB_RECURSE SRC_CC "solves/*.cc")
file(GLOB SRC_CC "solves/*.cc")
file(GLOB PROBLEM_CC "solves/impl/p${PROBLEM_NUM}.cc")
add_executable(main ${SRC_CC} ${PROBLEM_CC})
add_dependencies(main rapidjson)