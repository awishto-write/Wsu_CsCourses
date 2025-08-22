#include "header.h"

Node* makeNode(Contact newData)
{
	Node* pMem = NULL;
	pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->data = newData;
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
	}

	return pMem;
}

Boolean insertContactAtFront(Node** pList, Contact newData)
{
	Node* pMem = makeNode(newData);

	         // we are not able to allocate enough memory
	if (pMem == NULL)             // Or the other one: if (pMem == NULL && pMem->data.name == NULL )
		return FALSE;

	if (*pList != NULL)
	{
		pMem->pNext = *pList;
		(*pList)->pPrev = pMem;
	}
	  *pList = pMem;
	  return TRUE;
}

Boolean insertContactInOrder(Node** pList, Contact newData)
{
	Node* pMem = makeNode(newData);
	Node *pCur = *pList, *pPrev = NULL;

	if (pMem == NULL)         
		return FALSE;

	if (pMem != NULL)
	{
		// allocated a Node successfully
		while (pCur != NULL && strcmp(pCur->data.name, pMem->data.name) < 0)
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		pMem->pNext = pCur; // this case is common to all cases of inserting

		if (pPrev != NULL)
		{
			// we're inserting somewhere after first node, middle, or at end
			pPrev->pNext = pMem;
		}
		else
		{
			// inserting at front
			*pList = pMem;
		}
	    
		return TRUE;
	}
	
}

void printList(Node* pList)
{
	if (pList != NULL)
	{
		// recursive step
		printf(" %s, %s, %s, %s ", pList->data.name, pList->data.phone, pList->data.email, pList->data.title);
		printList(pList->pNext);
	}
	else
	{
		// base case
		printf("-->\n");
	}

}

//Boolean deleteContact(Node** pList, Contact searchContact)
//{
//	Node* pCur = *pList;
//
//	if(strcmp(pCur->data.name, pCur->searchContact.name) == 0)
//	{
//		//pCur = pCur;
//		//pCur = pCur->pNext;
//	}
//}