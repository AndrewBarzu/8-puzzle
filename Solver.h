#pragma once
#include <unordered_set>
#include <stdlib.h>
#include "State.h"
#include "Stack.h"
#include "Queue.h"
#include <string.h>
#include <unordered_set>
#include <iostream>
#include "PriorityQueue.h"

class Solver
{
public:
	char initial_state_string[10];
	char goal_state_string[10] = "123456780";
	int initial_state, goal_state;
	std::unordered_set<int>* visited;

	int hamming_distance(char*, char*);

	Solver(char[10], char[10]);
	bool is_visited(int);
	int dfs(int);
	int bfs(int);
	int dijkstra(int);
	int Astar(int);
};

