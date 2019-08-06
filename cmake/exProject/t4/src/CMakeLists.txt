INCLUDE_DIRECTORIES(BEFORE ${PROJECT_SOURCE_DIR}/../t3/lib)
MESSAGE(STATUS "This is INCLUDE_DIRECTORIES dir " ${PROJECT_SOURCE_DIR}/../t3/lib)

#INCLUDE_DIRECTORIES(/Users/kuro/Desktop/codeEX/cmake/exProject/t3/lib)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../t3/build/lib)
MESSAGE(STATUS "This is LINK_DIRECTORIES dir " ${PROJECT_SOURCE_DIR}/../t3/build/lib)

#LINK_DIRECTORIES(/Users/kuro/Desktop/codeEX/cmake/exProject/t3/build/lib)

ADD_EXECUTABLE(main main.c)

TARGET_LINK_LIBRARIES(main hello)

