#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>

typedef struct stacknode
{
	double data;
	struct stacknode* pNext;

}StackNode;

typedef struct stack
{
	StackNode* top;

}Stack;

int isEmpty(Stack* stack);
Stack* makeNode(double newData);

int push(Stack* stack, double data);

double pop(Stack* stack);
double peek(Stack* stack);


