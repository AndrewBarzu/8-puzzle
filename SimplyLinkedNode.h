#pragma once
#include "State.h"
#include "SimplyLinkedNode.h"

class SimplyLinkedNode
{
public:
	State value;
	SimplyLinkedNode* next;

	SimplyLinkedNode(State, SimplyLinkedNode*);
};

