#include "Stack.h"

Stack::Stack()
{
	this->pTop = -1;
}


Stack :: ~Stack()
{
	// It does nothing
}

bool Stack::isEmpty()
{

	if (pTop == -1)
	{
		return true;
	}

	return false;
}


void Stack::push(string& newDate)
{
	if (!isEmpty())
	{
		pTop++;
		date[pTop] = newDate;
	}

	else    // The stack is empty
	{

		this->date[0] = newDate;
		pTop++;
	}

}

//void Stack::pop(string newDate)
//{
//	if (!isEmpty())
//	{
//		newDate = date[pTop];
//		pTop--;
//	}
//
//}

string Stack::pop()
{
	string again;

	if (!isEmpty())
	{
		again = date[pTop];
		date[pTop] = " ";
		pTop--;
	}

	return again;

}

string Stack::peek() const
{
	return date[pTop];
}