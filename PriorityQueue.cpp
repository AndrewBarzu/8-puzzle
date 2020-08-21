#include "PriorityQueue.h"
#include <iostream>

#define INF 2147483647

PriorityQueue::PriorityQueue()
{
	capacity = 10;
	states = new std::pair<State, int> [capacity];
	len = 0;
}

int PriorityQueue::push(State new_element, int cost)
{
	if (len == capacity)
	{
		capacity *= 1.5;
		std::pair<State, int>* new_states = new std::pair<State, int> [capacity];
		for (int i = 0; i < len; i++)
		{
			new_states[i] = states[i];
		}

		delete[] states;
		states = new_states;
	}

	states[len] = std::pair<State, int>(new_element, cost);
	int index = len;
	
	while (index - 1 >= 0 && states[index].second < states[(index - 1) / 2].second)
	{
		//std::pair<State, int> aux = std::pair<State, int>(states[index].first, states[index].second);
		//states[index] = states[(index - 1) / 2];
		//states[(index - 1) / 2] = aux;
		swap(states[index], states[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
	len++;
	return 0;
}

State PriorityQueue::pop()
{
	State return_value = states[0].first;
	states[0] = states[len];
	int index = 0;
	int son1 = 0, son2 = 0;
	while (1)
	{
		son1 = index * 2 + 1;
		son2 = index * 2 + 2;

		if (son1 < len && son2 < len)
		{
			if (states[son1].second < states[son2].second)
			{
				states[index] = states[son1];
				index = son1;
			}
			else
			{
				states[index] = states[son2];
				index = son2;
			}
			continue;
		}
		else if (son1 < len)
		{
			states[index] = states[son1];
			index = son1;
			continue;
		}
		else
		{
			break;
		}
	}
	len--;
	return return_value;
}

int PriorityQueue::size()
{
	return len;
}