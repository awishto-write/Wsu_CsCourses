#include "Queue.h"

Queue::Queue()
{
	this->_pHead = nullptr;
	this->_pTail = nullptr;
}

Queue :: ~Queue()
{
	deleteQueueRecursive (this->_pHead);
}

void Queue :: deleteQueueRecursive (QueueNode* node) 
{
	if (node == nullptr)
		return;

	deleteQueueRecursive(node->getNext());

		delete node;

}

bool Queue::enqueue (const std::string data)
{
	QueueNode* newNode = new QueueNode(data) ;

	bool success = false;

	if (newNode != nullptr)
	{
		success = true;

		if (isEmpty ())
		{
			 this->_pHead = newNode;
		     this->_pTail = newNode;
		}
		
		else
		{
			this->_pTail->setNext(newNode);
			this->_pTail = newNode;
		}

	}

	return success;
}

std::string Queue::dequeue()
{
	QueueNode* nodetodelete = this->_pHead;
	std::string data = nodetodelete->getData();

	    //to do...                                nodetodelete->getNext() = this-> _pHead
	if ( nodetodelete->getNext() == nullptr)    // one node in queue
	{
		this->_pHead = nullptr;
		this->_pTail = nullptr;
	}
	else  // more than one node
	{
		this->_pHead = this->_pHead->getNext();
		             // = node->getNext(); 
	}
	        //Node to delete
	delete nodetodelete;

	return data;
}

bool Queue :: isEmpty() const
{
	return this->_pHead == nullptr;
}

void Queue:: printQueueRecursive(QueueNode* node) const
{
	if (node == nullptr)
	{
		return;
	}
		

	else 
	{
		cout << node->getData() << endl;
		printQueueRecursive(node->getNext());
	 }

}

void Queue :: printQueueRecursive() const        //public
{
	this->printQueueRecursive(this->_pHead);
}
