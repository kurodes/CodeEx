set(EXECUTABLE_OUTPUT_PATH ../bin)

include_directories(../include)

add_compile_options(-std=c++11 -Wall)
add_executable(P1 process1.cpp component.cpp)
add_executable(P2 process2.cpp component.cpp)
