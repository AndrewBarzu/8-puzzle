# 8-puzzle

This is my first try at a bigger C++ project, in which I tried to use mostly self made data structures (with exceptions for the
unordered set)
This was just made for fun to check which of the searches finds a solution faster.

## Types of searches used: 

**_Depth first search:_**
Very unoptimal, finds a solution in a very long time, and using many steps

**_Breadth first search:_**
A good improvement sometimes over DFS but can still be unlucky and take a while to find a solution

**_A* search:_**
Uses as heuristic the hamming distance for each square. It's very fast compared to the other 2 approaches


## Implemented data structures: 

**_Stack_**
Implemented using a list of singly linked nodes, with constant time for every operation

**_Queue_**
Same as the stack, but updated to work as it should

**_Priority Queue_**
Created using a heap

An image where you can see the difference in steps taken:
![Outputs](https://github.com/AndrewBarzu/8-puzzle/blob/master/Outputs.png)
