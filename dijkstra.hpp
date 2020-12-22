#pragma once
#include <vector>
#include <utility>
#include <unordered_set>
#include <set>
#include <climits>
#include <algorithm>
#include "mazeGenerator.hpp"
//@TODO zmienić tak aby z tablic odczytywać za pomocą par i funkcji lambda
/**
 * @brief funkcja wykonuje algorytm dijkstry na labiryncie 
 * 
 * @param start pole startowe 
 * @param end pole końcowe 
 * @param table labirynt 
 * @return std::pair<std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>> pierwszy wektor to najkrótsza droga, drugi to kolejność przeszukiwania  
 */
std::pair<std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>> dijkstra(std::pair<int, int> start, std::pair<int, int> end, MyTable table)
{
    std::vector<std::pair<int, int>> visited;
    std::set<std::pair<int, int>> unVisited;
    std::vector<std::vector<int>> dys(table.hight, std::vector<int>(table.width, INT_MAX));
    std::vector<std::vector<std::pair<int, int>>> prec(table.hight, std::vector<std::pair<int, int>>(table.width, {-1, -1}));
    for (int y = 0; y < table.hight; y++)
        for (int x = 0; x < table.width; x++)
            unVisited.insert({y, x});
    dys[start.first][start.second] = 0;
    while (!unVisited.empty())
    {
        int smallestDis = INT_MAX;
        std::pair<int, int> smallestDisPair;
        for (auto it : unVisited)
        {
            if (dys[it.first][it.second] < smallestDis)
            {
                smallestDis = dys[it.first][it.second];
                smallestDisPair = it;
            }
        }
        if (table(smallestDisPair).up)
        {
            if (unVisited.find({smallestDisPair.first - 1, smallestDisPair.second}) != unVisited.end())
            {
                if (dys[smallestDisPair.first - 1][smallestDisPair.second] > dys[smallestDisPair.first][smallestDisPair.second] + 1)
                {
                    dys[smallestDisPair.first - 1][smallestDisPair.second] = dys[smallestDisPair.first][smallestDisPair.second] + 1;
                    prec[smallestDisPair.first - 1][smallestDisPair.second] = smallestDisPair;
                }
            }
        }
        if (table(smallestDisPair).down)
        {
            if (unVisited.find({smallestDisPair.first + 1, smallestDisPair.second}) != unVisited.end())
            {
                if (dys[smallestDisPair.first + 1][smallestDisPair.second] > dys[smallestDisPair.first][smallestDisPair.second] + 1)
                {
                    dys[smallestDisPair.first + 1][smallestDisPair.second] = dys[smallestDisPair.first][smallestDisPair.second] + 1;
                    prec[smallestDisPair.first + 1][smallestDisPair.second] = smallestDisPair;
                }
            }
        }
        if (table(smallestDisPair).right)
        {
            if (unVisited.find({smallestDisPair.first , smallestDisPair.second+ 1}) != unVisited.end())
            {
                if (dys[smallestDisPair.first][smallestDisPair.second + 1] > dys[smallestDisPair.first][smallestDisPair.second] + 1)
                {
                    dys[smallestDisPair.first][smallestDisPair.second + 1] = dys[smallestDisPair.first][smallestDisPair.second] + 1;
                    prec[smallestDisPair.first][smallestDisPair.second + 1] = smallestDisPair;
                }
            }
        }
        if (table(smallestDisPair).left)
        {
            if (unVisited.find({smallestDisPair.first , smallestDisPair.second- 1}) != unVisited.end())
            {
                if (dys[smallestDisPair.first][smallestDisPair.second - 1] > dys[smallestDisPair.first][smallestDisPair.second] + 1)
                {
                    dys[smallestDisPair.first][smallestDisPair.second - 1] = dys[smallestDisPair.first][smallestDisPair.second] + 1;
                    prec[smallestDisPair.first][smallestDisPair.second - 1] = smallestDisPair;
                }
            }
        }
        unVisited.erase(smallestDisPair);
        visited.push_back(smallestDisPair); 
    }
        std::vector<std::pair<int,int>> path;
        auto temp = end;
        while (temp != start)
        {
            path.push_back(temp);
            temp = prec[temp.first][temp.second];
        }
        path.push_back(start);
        return {path,visited};
}
