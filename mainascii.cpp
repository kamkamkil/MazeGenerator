#include "mazeGenerator.hpp"
#include "drawMazeASII.hpp"

int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(4, 4);
    drawMazeASCII(maze);

    return 0;
}
