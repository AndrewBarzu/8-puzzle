#include "Solver.h"
#include <stdlib.h>
#include "State.h"
#include "Stack.h"
#include "Queue.h"
#include <string.h>
#include <unordered_set>
#include <iostream>

Solver::Solver(char initial[10], char goal[10])
{
	strcpy(initial_state_string, initial);
	initial_state = atoi(initial);
	goal_state = atoi(goal);
	visited = 0;
}

bool Solver::is_visited(int current_state)
{
	if (visited->find(current_state) != visited->end())
	{
		return 1;
	}
	return 0;
}

int Solver::dfs(int blank_spot)
{
	if (visited != 0)
		delete visited;

	visited = new std::unordered_set<int>;
	/// converting it so that i don't do it repeatedly
	int step = 0;
	Stack stack = Stack();
	State initialState = State(initial_state_string, blank_spot);
	stack.push(initialState);

	while (stack.size() > 0)
	{

		/// extract the last state added on the stack
		State current_state = stack.pop();
		char* state = current_state.puzzle;
		// !!! DEBUG PRINTS
		//print(state);

		if (is_visited(atoi(state)))
			continue;

		/// insert the current state on the visited list
		visited->insert(atoi(state));

		//current_state.print_state();

		// check the end condition
		if (atoi(state) == goal_state)
		{
			break;
		}
		step++;
		//std::cout << step << std::endl;

		State new_state = current_state;
		new_state.move_up();
		stack.push(new_state);

		new_state = current_state;
		new_state.move_down();
		stack.push(new_state);

		new_state = current_state;
		new_state.move_left();
		stack.push(new_state);

		new_state = current_state;
		new_state.move_right();
		stack.push(new_state);
	}
	return step;
}

int Solver::bfs(int blank_spot)
{
	if (visited != 0)
		delete visited;

	visited = new std::unordered_set<int>;

	int step = 0;
	Queue queue = Queue();
	State initialState = State(initial_state_string, blank_spot);
	queue.push(initialState);

	while (queue.size() > 0)
	{
		State current_state = queue.pop();
		char* state = current_state.puzzle;
		int int_state = atoi(state);

		if (is_visited(int_state))

			continue;

		//current_state.print_state();

		if (goal_state == int_state)
			break;
		
		visited->insert(int_state);
		step++;
		//std::cout << step << std::endl;
		int blank = current_state.blank;

		State new_state = current_state;
		new_state.move_up();
		queue.push(new_state);

		new_state = current_state;
		new_state.move_down();
		queue.push(new_state);

		new_state = current_state;
		new_state.move_left();
		queue.push(new_state);

		new_state = current_state;
		new_state.move_right();
		queue.push(new_state);
	}
	return step;
}