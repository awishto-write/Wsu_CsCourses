#include "Node.h"

Node::~Node()
{
	// Nothing 
}
 
   
Node:: Node (const string& newData)
{
	this->pLeft = this->pRight = nullptr;
	this->data = newData; 
}

Node* Node::getRightPtr() const
{
	return this->pRight;
}

Node* Node  :: getLeftPtr() const
{
	return this->pLeft;
}

void Node :: setRightPtr(Node* const newRightPtr)
{
	this->pRight = newRightPtr;
}

void  Node :: setLeftPtr(Node* const newLeftPtr)
{
	this->pLeft = newLeftPtr;
}

void  Node :: setData(const string& newData) //Passing by reference 
{
	this->data = newData;
}

string  Node::getData() const
{
	return this->data;
}