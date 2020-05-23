cmake_minimum_required(VERSION 3.17)
project (HelloProject)

set(PROJECT_BINARY_DIR build)

add_subdirectory(src)
add_subdirectory(test)
# ${PROJECT_SOURCE_DIR}