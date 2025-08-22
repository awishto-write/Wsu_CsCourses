
#include "QueueNode.h"

QueueNode :: QueueNode(const std::string data)
{
   this->_data = data;
   this->_pNext = nullptr;
}

QueueNode:: ~QueueNode()
{
	// nothing
}
