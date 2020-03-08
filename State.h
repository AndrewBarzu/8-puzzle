#pragma once

class State
{
public:
	char puzzle[10];
	int blank;

	State(char[10], int);
	State() = default;

	void copy(State);
	bool goal_test();

	void move_right();
	void move_left();
	void move_up();
	void move_down();

	void print_state();
};

