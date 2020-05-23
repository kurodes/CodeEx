include_directories(../include)
add_compile_options(
    -std=c++11
    -Wall
)

add_executable(Gtest
    gtest.cpp 
    ../src/component.cpp
)

target_link_libraries(Gtest
    gtest
)

# enable_testing()
# add_test(NAME my_component_test COMMAND my_component_test)