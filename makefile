all:
	g++ -std=c++11 main.cpp snake.cpp input.cpp snake_map.cpp bfs_algo.cpp -o snake -lpthread