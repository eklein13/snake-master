#ifndef _snake_map_h
#define _snake_map_h

#include "snake.h"
#include "i_path_finder.h"
#include "macros.h"

class SnakeMap
{
public:
  SnakeMap(Snake *snake, const IPathFinder* path_finder);
  void redraw(bool draw_path = false);
  
private:
  void update_snake_food(bool force_update);
  void update_path();
  void update_score();

  pair<int, int> snake_food;
  char map_array[MAP_HEIGHT][MAP_WIDTH];
  Snake *snake;
  // Path finder is used to find a valid path. The found path is saved until next call to update_path()
  const IPathFinder *path_finder;
  IPathFinder::PositionSet path;
};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);
void update_snake_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Snake *snake);

#endif