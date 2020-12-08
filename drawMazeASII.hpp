#pragma once
#include <iostream>
#include "mazeGenerator.hpp"

void drawMazeASCII(MyTable table)
{
    bool drawResult[table.hight * 2 + 1][table.width * 2 + 1];
    for (int y = 0; y < table.hight * 2 + 1; y++)
    {
        for (int x = 0; x < table.width * 2 + 1; x++)
        {
            drawResult[y][x] = false;
        }
    }
    for (int a = 0; a < table.hight; a++)
    {
        for (int b = 0; b < table.width; b++)
        {
            int x = b * 2 + 1;
            int y = a * 2 + 1;
            auto node = table(a, b);
            if (node.up || node.right || node.down || node.left)
                drawResult[y][x] = true;
            if (node.up)
            {
                drawResult[y - 1][x] = true;
            };
            if (node.left)
            {
                drawResult[y][x - 1] = true;
            };
            if (node.down)
            {
                drawResult[y + 1][x] = true;
            };
            if (node.right)
            {
                drawResult[y][x + 1] = true;
            };
        }
    }
    for (int y = 0; y < table.hight * 2 + 1; y++)
    {
        for (int x = 0; x < table.width * 2 + 1; x++)
        {
            std::cout << (drawResult[y][x] ? " " : "x");
        }
        std::cout << std::endl;
    }
}