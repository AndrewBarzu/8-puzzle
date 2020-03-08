#pragma once
#include "SimplyLinkedNode.h"
#include "State.h"
class Stack
{
private:
	SimplyLinkedNode* Tail;
	int len;
public:
	Stack();
	void push(State);
	State pop();
	int size();
};

