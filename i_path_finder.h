#ifndef _i_path_finder_h
#define _i_path_finder_h

#include <unordered_set>
#include "macros.h"

using namespace std;

/*
* An interface for path finding algorithms between dots on a grid.
* The grid size is MAP_HEIGHT * MAP_WIDTH (from macro.h)
*/
class IPathFinder
{
public:
    using Position = pair<int, int>;   
    
    struct PositionHash {
        std::size_t operator()(const Position& p) const {
            return std::hash<int>()(p.first * MAP_WIDTH + p.second); // Hash algorithm use differen sid for each position
        }
    };
    using PositionSet = unordered_set<Position, IPathFinder::PositionHash>;

    virtual PositionSet find_path(const Position& src, const Position& dest, const vector<Position>& obstacles) const = 0;
};

#endif