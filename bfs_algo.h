#ifndef _bfs_algo_h
#define _bfs_algo_h

#include "i_path_finder.h"

using namespace std;

/*
* BFS algorithm implementation, for path findinig between 2 dots on a grid.
* Inherint IPathFinder interface.
*/
class BFSAlgo : public IPathFinder
{
public:
  virtual PositionSet find_path(const Position& src, const Position& dest, const vector<Position>& obstacles) const override;
};

#endif