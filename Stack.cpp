#include "Stack.h"
#include <exception>

Stack::Stack()
{
	len = 0;
	Tail = 0;
}

void Stack::push(State value)
{
	SimplyLinkedNode* node;
	if (len == 0)
	{
		node = new SimplyLinkedNode(value, 0);
	}
	else
	{
		node = new SimplyLinkedNode(value, Tail);
	}
	Tail = node;
	len++;
}

State Stack::pop()
{
	if (len <= 0)
	{
		throw std::exception("Pop from empty stack!");
	}
	State value = Tail->value;
	SimplyLinkedNode* deletable = Tail;
	Tail = Tail->next;
	delete deletable;
	len--;
	return value;
}

int Stack::size()
{
	return len;
}