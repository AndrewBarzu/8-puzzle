#include "State.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

State::State(char init_state[10], int blank_space)
{
	strcpy(puzzle, init_state);
	blank = blank_space;
}

void State::copy(State new_state)
{
	strcpy(puzzle, new_state.puzzle);
	blank = new_state.blank;
}

bool State::goal_test()
{
	for (int i = 0; i < 9; i++)
	{
		if (puzzle[i] != '0' + i)
			return 0;
	}
	return 1;
}

void State::move_right()
{
	if (blank % 3 > 1 or blank < 0 or blank > 7)
	{
		return;
	}
	char aux = puzzle[blank];
	puzzle[blank] = puzzle[blank + 1];
	puzzle[blank + 1] = aux;
	blank += 1;
}

void State::move_left()
{
	if (blank % 3 < 1 or blank > 8)
	{
		return;
	}
	char aux = puzzle[blank];
	puzzle[blank] = puzzle[blank - 1];
	puzzle[blank - 1] = aux;
	blank -= 1;
}

void State::move_up()
{
	if (blank < 3 or blank > 8)
	{
		return;
	}
	char aux = puzzle[blank];
	puzzle[blank] = puzzle[blank - 3];
	puzzle[blank - 3] = aux;
	blank -= 3;
}

void State::move_down()
{
	if (blank < 0 or blank > 5)
	{
		return;
	}
	char aux = puzzle[blank];
	puzzle[blank] = puzzle[blank + 3];
	puzzle[blank + 3] = aux;
	blank += 3;
}

void State::print_state()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << puzzle[3 * i + j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}