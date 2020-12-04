#include "mazeGenerator.hpp"
#include "drawMaze.hpp"


int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(30, 25);
    drawMaze(maze);
    return 0;
}
