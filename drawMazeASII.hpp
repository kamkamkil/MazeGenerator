#pragma once
#include <iostream>
#include "mazeGenerator.hpp"

void drawMazeASCII(MyTable table)
{
    bool drawResult[table.hight * 2 + 1][table.width * 2 + 1];
    for (int y = 0; y < table.hight * 2 + 2; y++)
    {
        for (int x = 0; x < table.width * 2 + 2; x++)
        {
            drawResult[y][x] = false;
            std::cout << drawResult[y][x] ;
        }
            std::cout  << std::endl;
    }
    for (int a = 0; a <= table.hight; a++)
    {
        for (int b = 0; b <= table.width; b++)
        {
            auto node = table(a, b);

        }
    }
}