#include "header.h"

int main(void)
{
	Node* pMem = NULL, * pList = NULL;
	Contact newData;

	//makeNode(newData);

	strcpy(newData.name, "alice");
	strcpy(newData.phone, "0114");
	strcpy(newData.email, "wsu");
	strcpy(newData.title, "lab");
	// insertContactAtFront(&pList, newData);    //front
	insertContactInOrder(&pList, newData);      //order

	strcpy(newData.name, "ben");
	strcpy(newData.phone, "0115");
	strcpy(newData.email, "asu");
	strcpy(newData.title, "class");
	//insertContactAtFront(&pList, newData);    //front
	insertContactInOrder(&pList, newData);      //order

	makeNode(newData);

	printList(pList);




	return 0;
}