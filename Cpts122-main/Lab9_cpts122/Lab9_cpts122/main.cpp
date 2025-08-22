// This example illustrates how to define a Stack class template.

#include "TestStack.h"

//#include <vector>

int main(void)
{
	int item1 = -89, item2 = 104;     //given
	//int item1 = 80, item2 = 104;

	//	vector<int> my_vector; // vector<> is from the Standard Template Library (STL)

	TestStack<int> tester;

	tester.Test(item1, item2);

	return 0;
}

int postFix(string input)
{
	int newItem1, newItem2, i;
	int size, element;
	Stack <char> tried;

	/*theStack.push(newItem1);
	peek(item2);*/

	for (int i = 0; i < size; i++)
	{
	     switch(element)
		 {
		  case '+':
			  tried = newItem1 + newItem2;
			  break;
		
		  case '-':
			  tried = newItem1 - newItem2;
			  break;

		  case '*':
			  tried = newItem1 * newItem2;
			  break;

		  case '/':
			  tried = newItem1 / newItem2;
			  break;
		 }
	}
}