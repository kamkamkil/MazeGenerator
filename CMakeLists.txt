cmake_minimum_required(VERSION 3.0.0)
project(mazeGenerator VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(SFML-2.5.1)

add_library(mazeGenerator STATIC mazeGenerator.cpp )

add_library(drawMaze STATIC drawMaze.cpp )
target_link_libraries(drawMaze  sfml-graphics mazeGenerator)

add_executable(main main.cpp drawMaze.cpp mazeGenerator.cpp)
target_link_libraries(main mazeGenerator drawMaze)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
