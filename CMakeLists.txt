cmake_minimum_required(VERSION 3.0.0)
project(mazeGenerator CXX  )

include(CTest)
enable_testing()

add_subdirectory(SFML-2.5.1)

add_library(mazeGenerator STATIC mazeGenerator.hpp )
set_target_properties(mazeGenerator PROPERTIES LINKER_LANGUAGE CXX)

add_library(drawMaze STATIC drawMaze.hpp )
target_link_libraries(drawMaze  sfml-graphics mazeGenerator)
set_target_properties(drawMaze PROPERTIES LINKER_LANGUAGE CXX)

add_library(drawMazeASII drawMazeASII.hpp)
target_link_libraries(drawMazeASII mazeGenerator)
set_target_properties(drawMazeASII PROPERTIES LINKER_LANGUAGE CXX)

add_library(Dijkstra Dijkstra.hpp)
target_link_libraries(Dijkstra mazeGenerator)
set_target_properties(Dijkstra PROPERTIES LINKER_LANGUAGE CXX)

add_executable(mainascii mainascii.cpp)
target_link_libraries(mainascii Dijkstra  drawMazeASII mazeGenerator) #pamiętać usunąć tą bibliotekę

add_executable(main main.cpp )
target_link_libraries(main sfml-graphics Dijkstra mazeGenerator drawMaze)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
