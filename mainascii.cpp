#include "mazeGenerator.hpp"
#include "drawMazeASII.hpp"
#include "dijkstra.hpp"
int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(4,4);
    drawMazeASCII(maze);
    dijkstra({0,0},{3,3},maze);

    return 0;
}
