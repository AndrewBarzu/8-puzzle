#include "Queue.h"
#include <exception>

Queue::Queue()
{
	len = 0;
	last = 0;
	first = 0;
}

void Queue::push(State value)
{
	SimplyLinkedNode* node = new SimplyLinkedNode(value, 0);;
	if (len == 0)
	{
		first = node;
		last = node;
	}
	else if (len == 1)
	{
		last = node;
		first->next = last;
	}
	else
	{
		SimplyLinkedNode* aux = last;
		last = node;
		aux->next = last;
	}
	len++;
}

State Queue::pop()
{
	State value;
	if (len <= 0)
	{
		throw std::exception("Pop from empty queue!");
	}
	
	else if (len == 1)
	{
		value = first->value;
		delete first;
		first = 0;
		last = 0;
	}

	else if (len >= 2)
	{
		value = first->value;
		SimplyLinkedNode* deletable = first;
		first = first->next;
		delete deletable;
	}

	len--;
	return value;
}

int Queue::size()
{
	return len;
}