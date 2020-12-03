cmake_minimum_required(VERSION 3.0.0)
project(mazeGenerator VERSION 0.1.0)

include(CTest)
enable_testing()
add_executable(mazeGenerator mazegenerator.cpp)


# add_subdirectory("sfml")

# add_executable(temp temp.cpp)




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
