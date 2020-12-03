#include "mazeGenerator.cpp"
#include "drawMaze.cpp"


int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(30, 25);
    drawMaze(maze);
    return 0;
}
