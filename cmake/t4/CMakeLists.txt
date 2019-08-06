cmake_minimum_required(VERSION 3.11)
project (HelloProject)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_compile_options(-std=c++11 -stdlib=libc++ -Wall)

add_subdirectory(src)
