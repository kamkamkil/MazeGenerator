#include "mazeGenerator.hpp"
#include "drawMazeASII.hpp"

int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(10,10);
    auto maze1 = mazeGenerator(10,10);
    auto maze2 = mazeGenerator(10,10);
    auto maze3 = mazeGenerator(10,10);
    // drawMazeASCII(maze);

    return 0;
}
