#pragma once
#include "State.h"
#include "SimplyLinkedNode.h"

class Queue
{
private:
	int len;
	SimplyLinkedNode* last;
	SimplyLinkedNode* first;
public:
	Queue();
	void push(State);
	State pop();
	int size();
};

