#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include <utility>
#include "macros.h"
#include "bfs_algo.h"

using namespace std;

Snake snake;
BFSAlgo bfs_algo;
SnakeMap snake_map(&snake, &bfs_algo);
bool is_help_me_mode = false;

void initialize()
{
    input_init();
    input_enter_off();
}

bool is_game_end()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
    if (snake_head.first < 0 || snake_head.first >= MAP_HEIGHT || snake_head.second < 0 || snake_head.second >= MAP_WIDTH)
    {
        result = true;
    }
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

void game_over()
{
    cout << "GAME IS OVER" << endl;
}

void start_game()
{
    while (true)
    {
        snake.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }

        snake_map.redraw(is_help_me_mode);

        usleep(PAUSE_LENGTH);

        snake.validate_direction();
    }
}

int main(int argc, char* argv[])
{
    // Initialize is_help_me_mode from argv
    if (argc > 1)
    {
        int arg = std::atoi(argv[1]);
        if (arg == 1) {
            is_help_me_mode = true;
        } else if (arg == 0) {
            is_help_me_mode = false;
        } else {
            std::cerr << "Invalid argument, \"help me\" mode expect 1 or 0.\n";
            return 1;
        }
    }
    initialize();
    start_game();
    return 0;
}
