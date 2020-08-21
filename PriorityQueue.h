#pragma once
#include "State.h"
#include <utility>

class PriorityQueue
{
private:

	std::pair<State, int>* states;
	int len;
	int capacity;

public:

	PriorityQueue();
	int push(State, int);
	State pop();
	int size();
};