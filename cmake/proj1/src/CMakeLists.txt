include_directories(../include)

set(EXECUTABLE_OUTPUT_PATH ../bin)

add_compile_options(-std=c++11 -Wall)
add_executable(Hello HW.cpp)
add_executable(Fuck FU.cpp)
