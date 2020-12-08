#include "mazeGenerator.hpp"
#include "drawMazeASII.hpp"

int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(10,10);
    drawMazeASCII(maze);

    return 0;
}
