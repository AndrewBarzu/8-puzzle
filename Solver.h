#pragma once
#include <unordered_set>

class Solver
{
public:
	char initial_state_string[10];
	int initial_state, goal_state;
	std::unordered_set<int>* visited;

	Solver(char*, char*);
	bool is_visited(int);
	int dfs(int);
	int bfs(int);
	int dijkstra();
	int Astar();
};

