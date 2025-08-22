#include "Queue.h"

Queue::Queue(QueueNode* newpHead, QueueNode* newpTail)
{
	this->pHead = newpHead; // pointer assignment
	this->pTail = newpTail;
}


bool Queue::isEmpty() const
{
	return this->pHead == nullptr;
}

Queue:: ~Queue()
{
	deleteQueueRecursive(this->pHead);
}

QueueNode* Queue :: getHead(void)
{
	return pHead;
}

QueueNode* Queue::getTail(void)
{
	return pTail;
}


bool Queue :: enqueue(int CusNum, int Lane_ServTime, int TotTime)
{
	QueueNode* newNode = new QueueNode (CusNum, Lane_ServTime, TotTime);

	//Check if memory was allocated
	bool success = false;                  // The memory was not allocated

	if (newNode != nullptr)
	{
		// The memory was allocated
		success = true;

		//change pointers, as needed
	   //if the list is empty, then set head and tail to new
	  //node otherwise, change ----(head or tail) pointer

		if (isEmpty())
		{
			this->pHead = newNode;
			this->pTail = newNode;
		}

		else
		{
			// not empty queue
			this->pTail->setNextPtr(newNode);
			this->pTail = newNode;
		}

	}

	return success;
}

void Queue::deleteQueueRecursive(QueueNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	
	else
	{
		deleteQueueRecursive(node->getNextPtr());
		delete node;
	}

}

Data Queue :: dequeue()
{
	QueueNode* node_to_delete = this->pHead;
	Data* data_to_return = node_to_delete->getData();

	                                   
	if (node_to_delete->getNextPtr() == nullptr)    // one node in queue
	{
		this->pHead = nullptr;
		this->pTail = nullptr;
	}
	else  // more than one node
	{
		this->pHead = this->pHead->getNextPtr();
		            
	}
	       //Node to delete
	delete node_to_delete;

	return *data_to_return;
}

void Queue::processCust(Queue* node, int time, int lane)
{
	if (node->pHead != nullptr)
	{
		QueueNode* pMem = node->pHead;
		 
		     // At arrival time, generate a service time
		int temp = node->pHead->getData()->getServiceTime();

		if (pMem->getData()->getServiceTime() != 0)
		{
			 // Setting new arrival time for  next customer, 
			node->pHead->getData()->setServiceTime(temp - 1);
		}

		else
		{ 
			     // Removing a customer from the line
			node->dequeue();
			if (lane == 1)
			{
				cout << " A customer from the express lane left!" << endl;
			}
			
			if (lane == 2)
			{
				cout << " A customer from the standard lane left!" << endl;
			}
		}
	}
}


void Queue :: printQueue(void)
{
	QueueNode* node = pHead;

	if (node == nullptr)
	{
		cout << "There is no customer in the line!" << endl;
	}

	else
	{

		while (node != nullptr)
		{
			Data* temp = node->getData();

			                           
			cout << "Customer Number: " << temp->getCustomerNumber() << ";" << " Service Time: " << temp->getServiceTime()
				<< ";" << " Total Time: " << temp->getTotalTime() << endl;

			node = node->getNextPtr();
		}
	}
}


