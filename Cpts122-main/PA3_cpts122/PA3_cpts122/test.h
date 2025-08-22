#ifndef TEST_H
#define TEST_H

#include "header.h"

typedef struct test
{
	int num;
	struct test* pNext;
	struct test* pPrev;

}Test;

void InsertTest(void);
void DeleteTest(void);
Test* makeNode_test(int num);
bool InsertNodeTest(Test** pList, int num);
int num_test(Test* pList);
void ShuffleTest(void);

#endif

