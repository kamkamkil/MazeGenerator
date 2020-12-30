#include "mazeGenerator.hpp"
#include "drawMazeASII.hpp"
#include "dijkstra.hpp"
int main(int argc, char const *argv[])
{
    auto maze = mazeGenerator(4,4);
    drawMazeASCII(maze);
        auto k = dijkstra({0, 0}, {3, 3}, maze);
    for (auto var : k.first)
    {
        std::cout << var.first << "  " << var.second << std::endl;
    }

    return 0;
}
