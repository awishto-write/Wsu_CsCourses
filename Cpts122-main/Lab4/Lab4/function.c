#include"header.h"

int isEmpty(Stack* stack) 
{
	if (stack->top == NULL)
		return 1;	//empty

	return 0;		//not empty
}


Stack* makeNode(double newData) 
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));

	newNode->pNext = NULL;
	newNode->data = newData;

	return newNode;
}

double peek(Stack* stack)
{
	return stack->top->data;
}

int push(Stack* stack, double data)
{
	Stack* pMem = makeNode(data);

	if (pMem == NULL)
		return 0;

	//pMem->pNext = stack->top;
	stack->top = pMem;

	return 1;

}

double pop(Stack* stack) 
{
	double ok;
	Stack* pFree = NULL;

	if (isEmpty(stack) == 0)
	{
		ok = stack->top->data;
		Stack* pFree = stack->top;
		stack->top = stack->top->pNext;
		free(pFree);
	}
	return ok;
}

 solveTower()
{
	StackNode * tower[3];
  int option1 = -1, option2 = -1, success = 0, validOption = 0;
  printf("Which tower do you want to move from (1,2,3)?: ");
  scanf("%d", &option1);

    while (option1 < 1 || option1 > 3)
    {
	  printf("That's an invalid input, please input a number between 1- 3!\n");
	  scanf("%d", &option1);
    }

	option1 = -1;
	if (isEmpty(tower[option1]) == 0)
	{
		printf("Invalid input: This tower is currently empty!\n");
		option1 = -1;
	}
	else
	{
		printf("Which tower do you want to move to? ");
		scanf("%d", &option2);

		while (option2 < 1 || option2 > 3)
		{
			printf("That's an invalid input, please input a number between 1- 3!\n");
			scanf("%d", &option1);
		}

		if (peek(tower[option2]) < peek(tower[option1]))
		{
			printf("This is an invalid input, please choose a different tower\n");
		}
	}
}