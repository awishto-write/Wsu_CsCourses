#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct object
{
	//int num_dics;
	//int num_pegs;
	int stack_a;
	int stack_b;
	int stack_c;

} Object;

typedef enum boolean
{
	FALSE, TRUE

}Boolean;

int solve_tower(int num_discs, int num_pegs);

int solve_tower(Object* stack_a, Object* stack_b, Object* stack_c);
