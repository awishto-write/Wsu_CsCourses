#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

#include "QueueNode.h"

class Queue
{
private:
	QueueNode* _pHead;
	QueueNode* _pTail;

	void printQueueRecursive(QueueNode* node) const;    // Definitvely to redo
	void deleteQueueRecursive(QueueNode* node);

public:
	Queue();
	~Queue();

	bool isEmpty() const;
	bool enqueue(const std::string data);

	std::string dequeue();

	void printQueueRecursive() const;       //public
	//void deleteQueueRecursive()const;


};