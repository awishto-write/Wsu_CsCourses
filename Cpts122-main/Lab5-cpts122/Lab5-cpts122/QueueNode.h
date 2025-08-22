#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class QueueNode
{
private:
	std::string _data;
	QueueNode* _pNext;

public:

	// Constructor
	QueueNode(const std::string data);

	// Destructor
	~QueueNode();

	std::string getData()const
	{
		return this->_data;
	}

	QueueNode* getNext() const
	{
		return this->_pNext;

	}

	void setData(const std::string newValue)
	{
		this->_data = newValue;
	}

	void setNext(QueueNode* newValue)
	{
		this->_pNext = newValue;
	}
};