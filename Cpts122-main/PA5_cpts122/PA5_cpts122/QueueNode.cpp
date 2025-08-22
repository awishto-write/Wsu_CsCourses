#include "QueueNode.h"

QueueNode :: QueueNode(int CusNum, int Lane_ServTime, int TotTime)
{
	Data* ptr = new Data(CusNum, Lane_ServTime, TotTime); // Allocating memory on the heap
	this->pData = ptr;
	this->pNext = nullptr;
}

QueueNode:: ~QueueNode()
{
	//cout << "Node destructor" << endl;

	// I need to deleallocate QueueNode data:   delete [] Data;
}

void QueueNode::setNextPtr(QueueNode* newNextPtr)
{
	this->pNext = newNextPtr;
}

void QueueNode::setData(Data* newData)
{
	this->pData = newData;
}

QueueNode* QueueNode::getNextPtr() const
{
	return this->pNext;
}

Data* QueueNode::getData() const
{
	return this->pData;
}

