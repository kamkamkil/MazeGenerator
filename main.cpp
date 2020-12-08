#include "mazeGenerator.hpp"
#include "drawMaze.hpp"


int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(5, 5);
    drawMaze(maze);
    return 0;
}
