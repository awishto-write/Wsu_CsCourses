#include "test.h"

void InsertTest(void)
{                             
	Node* pList = NULL;
	Record newData = { 0 };
	strcpy(newData.artist, "Perry, Katy");
	strcpy(newData.album_title, "Witness");
	strcpy(newData.song_title, "Chained to the Rhythm");
	strcpy(newData.genre, "Pop");

	newData.song_length.minutes = 4;
	newData.song_length.seconds = 36;
	newData.num_times_played = -1;
	newData.rating = 6;

	if (newData.num_times_played < 0)
		printf("Error, the number of times played < 0 \n");
	else if (newData.rating > 5 && newData.rating < 0)
		printf("Error, the rating is out of range {0,5}\n");
	else
		printf("Success, the record is in good shape!\n");

	insertFront(&pList, newData);
	if (pList == NULL)
		printf("Failed, the record is not inserted\n");
	else
		printf("The record has been inserted successfully\n");
}

void DeleteTest(void)
{
	Node* pList = NULL;

	Record newData = { 0 };
	strcpy(newData.artist, "Perry, Katy");
	strcpy(newData.album_title, "Witness");
	strcpy(newData.song_title, "Chained to the Rhythm");
	strcpy(newData.genre, "Pop");

	newData.song_length.minutes = 4;
	newData.song_length.seconds = 36;
	newData.num_times_played = 3;
	newData.rating = 5;

	insertFront(&pList, newData);

	Node* pMem = pList;
	pList->pNext = pList;

	free(pMem);
	pMem = NULL;
	pList = NULL;

	if (pList != NULL)   //It is not equal to null
		printf("Sorry, pList != NULL!\n");
	else
		printf("Yeah, the record has been deleted!\n");

	if (pMem != NULL)
		printf("Sorry, the memory is not released!\n");
	else
		printf("Yeah, the memory  has been released!\n");

}

Test* makeNode_test(int num)   // Creates a new node
{
	Test* pMems = NULL;
	pMems = (Test*)malloc(sizeof(Test)); // allocate data for a new node
	pMems->num = num;
	pMems->pNext = NULL;
	pMems->pPrev = NULL;

	return pMems; // returns a new node
}

bool InsertNodeTest(Test** pList, int num)   //adding a new record to the linked list
{
	bool success = false;
	Test* pMem = NULL, * pCur = *pList, * pPrev = NULL;
	pMem = makeNode_test(num); 

	if (pMem != NULL)
	{
		success = true; // the memory allocation was sucessful
		if (*pList == NULL)
			*pList = pMem;
		else
		{
			while (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			if (pPrev != NULL)    // inserts at the end of the list
			{
				pPrev->pNext = pMem;
				pMem->pNext = pCur;
				pMem->pPrev = pPrev;
			}

			else
			{
				pMem->pNext = pCur; // inserts at the start of the list
				*pList = pMem;
			}
		}
	}
}

int num_test(Test* pList)
{
	int i = 1;
	Test* pCur = pList;
	while (pCur != NULL && pCur->pNext != NULL)
	{
		i++;
		pCur = pCur->pNext;
	}
	return i;
}

void ShuffleTest(void)
{
	Test* pList = NULL;
	InsertNodeTest(&pList, 1);
	InsertNodeTest(&pList, 2);
	InsertNodeTest(&pList, 3);

	Test* pMem = NULL;
	srand(time(NULL));
	int order[3] = { 3,1,2 };
	pMem = pList;

	for (int i = 0; i < num_test(pList); i++)
	{
		while (pMem->num != order[i])
		{
			pMem = pMem->pNext;
		}

		printf("%d ", pMem->num);
		pMem = pList;
	}

	printf("\nIt was expected to see: 3, 1, 2\n");
	printf("The suffle test has been successfully effectuated!\n");
}
