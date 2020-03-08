#include <iostream>
#include <cstring>
#include <unordered_set> 
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class State {
public:
	//myState - Object's state
	char* myState;
	//blank_space - the index of the empty space
	int blank_space;

	State(char* state, int blankSpot)
	{
		myState = new char[10];
		for (int i = 0; i < 10; i++)
			myState[i] = 0;
		strcpy(myState, state);
		blank_space = blankSpot;
	}
};

void move_up(char* state, char* new_state, int blank_spot)
{
	//move the blank space up
	strcpy(new_state, state);
	char aux = new_state[blank_spot];
	new_state[blank_spot] = new_state[blank_spot - 3];
	new_state[blank_spot - 3] = aux;
}

void move_down(char* state, char* new_state, int blank_spot)
{
	//move the blank space down
	strcpy(new_state, state);
	char aux = new_state[blank_spot];
	new_state[blank_spot] = new_state[blank_spot + 3];
	new_state[blank_spot + 3] = aux;
}

void move_left(char* state, char* new_state, int blank_spot)
{
	//move the blank space left
	strcpy(new_state, state);
	char aux = new_state[blank_spot];
	new_state[blank_spot] = new_state[blank_spot - 1];
	new_state[blank_spot - 1] = aux;
}

void move_right(char* state, char* new_state, int blank_spot)
{
	//move the blank space right
	strcpy(new_state, state);
	char aux = new_state[blank_spot];
	new_state[blank_spot] = new_state[blank_spot + 1];
	new_state[blank_spot + 1] = aux;
}

bool is_visited(unordered_set<int> &list, char* state)
{
	//checks if the given state was already visited (inserted in the list)
	if (list.find(atoi(state)) != list.end())
	{
		return 1;
	}
	return 0;
}

void print(char* state)
{
	//prints a given puzzle state
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << state[3 * i + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

auto dfs(char* init_state, int blank_spot, char* end_state)
{
	/// converting it so that i don't do it repeatedly
	int end = atoi(end_state);
	int step = 0;
	stack<State> myStack;
	State initialState = State(init_state, blank_spot);
	myStack.push(initialState);

	unordered_set<int> visited;

	while (myStack.size() > 0)
	{

		/// extract the last state added on the stack
		State current_state = myStack.top();
		myStack.pop();
		char* state = current_state.myState;
		// !!! DEBUG PRINTS
		//print(state);
		cout << step << endl;

		if (is_visited(visited, state))
			continue;

		/// insert the current state on the visited list
		visited.insert(atoi(state));

		// check the end condition
		if (atoi(state) == end)
		{
			break;
		}
		step++;
		int blank_spot = current_state.blank_space;
		int up = blank_spot - 3;
		int down = blank_spot + 3;
		int left = blank_spot - 1;
		int right = blank_spot + 1;

		/// check if a right move is possible
		if (blank_spot % 3 <= 1 && blank_spot >= 0 && blank_spot <= 8)
		{
			char* new_state = new char[10];
			move_right(state, new_state, blank_spot);
			myStack.push(State(new_state, right));
		}

		/// check if an up move is possible
		if (blank_spot >= 3 && blank_spot <= 8)
		{
			char* new_state = new char[10];
			move_up(state, new_state, blank_spot);
			myStack.push(State(new_state, up));
		}

		/// check if a left move is possible
		if (blank_spot % 3 >= 1 && blank_spot >= 0 && blank_spot <= 8)
		{
			char* new_state = new char[10];
			move_left(state, new_state, blank_spot);
			myStack.push(State(new_state, left));
		}

		/// check if a down move is possible
		if (blank_spot >=0 && blank_spot <= 5)
		{
			char* new_state = new char[10];
			move_down(state, new_state, blank_spot);
			myStack.push(State(new_state, down));
		}
	}
	return step;
}

/*
int main()
{
	char initialState[10] = "147598263";
	//char initialState[10] = "123945786";
	char endState[10] = "123456789";
	int blank = 4;

	cout << dfs(initialState, blank, endState);
	return 0;
}
*/