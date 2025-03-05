#include <iostream>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <array>
#include <unordered_set>
#include "bfs_algo.h"
#include "macros.h"


static inline bool is_visited(const BFSAlgo::Position& pos, const bitset<MAP_WIDTH*MAP_HEIGHT>& visited)
{
    return visited[pos.first * MAP_WIDTH + pos.second];
}

static inline void set_visited(const BFSAlgo::Position& pos, bitset<MAP_WIDTH*MAP_HEIGHT>& visited)
{
    visited.set(pos.first * MAP_WIDTH + pos.second);
}

static array<BFSAlgo::Position, 4> get_neighbors(const BFSAlgo::Position& pos)
{
    return {BFSAlgo::Position{pos.first - 1, pos.second},
            {pos.first, pos.second + 1},
            {pos.first + 1, pos.second},
            {pos.first, pos.second - 1}};
}

BFSAlgo::PositionSet BFSAlgo::find_path(const Position& src, const Position& dest, const vector<Position>& obstacles) const
{
    queue<Position> que;
    unordered_map<Position, Position, PositionHash> parent; // Parent map used for backtrace
    bitset<MAP_WIDTH*MAP_HEIGHT> visited{};
    const PositionSet obstacles_set(obstacles.begin(), obstacles.end());

    que.push(src);
    while (!que.empty())
    {
        auto cur_pos = que.front();
        que.pop();
        if (cur_pos == dest) // Path is found
        {
            PositionSet path;
            while (cur_pos != src)
            {
                path.emplace(cur_pos);
                cur_pos = parent[cur_pos];
            }
            path.emplace(src);
            return path;
        }

        // Path not found. Add all neighbors of current position to the queue, only if valid and not visited yet:
        for (const auto& pos : get_neighbors(cur_pos))
        {
            if (pos.first >= 0 && pos.first < MAP_HEIGHT && pos.second >= 0 && pos.second < MAP_WIDTH &&
                (obstacles_set.find(pos) == obstacles_set.end()) &&
                !is_visited(pos, visited))
            {
                que.emplace(pos);
                parent.emplace(pos, cur_pos);
                set_visited(pos, visited);
            }
        }
    }
    return {}; // No valid path found
}


/*
* A main function used to tests this algorithm as a seperate unit
*/
/*
int main()
{
    BFSAlgo bfs;
    cout << "start \n"; 

    const auto& path = bfs.find_path({0,19}, {19,0}, {{3,3}, {2,3}, {3,2}});
    for (const auto& pos : path)
    {
        cout << pos.first << "," << pos.second << "\n"; 
    }
    return 0;
}
*/