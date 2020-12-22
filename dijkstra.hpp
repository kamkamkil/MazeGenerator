#pragma once 
#include <vector>
#include <utility>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include "mazeGenerator.hpp"
/**
 * @brief 
 * 
 * @param start 
 * @param end 
 * @param table 
 * @return std::pair<std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>> 
 */
std::pair<std::vector<std::pair<int,int>>,std::vector<std::pair<int,int>>> dijkstra(std::pair<int, int> start,std::pair<int, int> end,MyTable table)
{
    struct Node_info //@FIXME zmiana nazwy 
    {
        Node_info(std::pair<int,int> position_,std::pair<int,int> predecessor_,int dis_) : position(position_), predecessor(predecessor_), dis(dis_){};
        Node_info(std::pair<int,int> position_,std::pair<int,int> predecessor_) : position(position_), predecessor(predecessor_), dis(INT_MAX){};
        Node_info(std::pair<int,int> position_) : position(position_), predecessor(position_), dis(INT_MAX){};
        Node_info(std::pair<int,int> position_,int dis_) : position(position_), predecessor(position_), dis(dis_){};
        const std::pair<int,int> position;
        std::pair<int,int> predecessor;
        int dis;
    };
    std::vector<Node_info> unvisited;
    for (int x = 0; x < table.width; x++)
    {
        for (int y = 0; y < table.hight; y++)
        {
            if(start == std::pair<int,int>(y,x))
                continue;
            unvisited.push_back(Node_info({y,x}));
        }
    }
    std::vector<Node_info> visited;
    visited.push_back(Node_info(start,0));
    auto node = start;
    if (table(node).up)
    {
        auto new_node = std::find_if(visited.begin(),visited.end(),[node](Node_info n){n.position == std::pair<int,int>(node.first - 1,node.second);});
        if()
    }
}