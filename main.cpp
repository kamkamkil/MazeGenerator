#include "mazeGenerator.hpp"
#include "drawMaze.hpp"


int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(20, 10);
    drawMaze(maze);
    return 0;
}
