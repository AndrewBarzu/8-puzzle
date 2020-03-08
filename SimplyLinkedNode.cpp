#include "SimplyLinkedNode.h"

SimplyLinkedNode::SimplyLinkedNode(State value, SimplyLinkedNode* next)
{
	this->value = State(value.puzzle, value.blank);
	this->next = next;
}