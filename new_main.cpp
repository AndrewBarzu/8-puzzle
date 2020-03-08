#include <iostream>
#include "Solver.h"

using namespace std;

int main()
{
	char initial[10] = "123045786";
	char goal[10] = "123456780";
	int blank = 0, inversions = 0;
	for (int i = 0; i < 9; i++)
		if (initial[i] == '0') {
			blank = i;
			break;
		}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (initial[j] > initial[i] && initial[j] != '0' && initial[i] != '0')
				inversions++;
		}
	}

	if (inversions % 2 == 1)
	{
		cout << "Puzzle is unsolvable!";
		return 0;
	}

	Solver solver = Solver(initial, goal);
	cout << "Depth-first search completed in " << solver.dfs(blank) << " steps." << endl;
	cout << "Breadth-first search completed in " << solver.bfs(blank) << " steps." << endl;
	cout << endl;

	return 0;
}