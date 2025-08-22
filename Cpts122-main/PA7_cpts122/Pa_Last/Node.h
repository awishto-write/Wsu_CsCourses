#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::to_string;

template <class T>

class Node
{
public:

	// Constructor 
	Node(T newData);

	// Copy constructor
	Node(Node& copy);

	// Destructor
	~Node();

	// Setters
	void setData(T newData);
	void setNextPtr(Node* newNextPtr);

	// Getters
	T& getData();
	Node* getNextPtr();

private:

	T data;
	Node* nextPtr;
};

template <class T>
Node <T>::Node(T newData)
{
	data = newData;
	this->nextPtr = nullptr;
}

template <class T>
Node <T> :: Node(Node& copy)
{
	data = copy.getData();
	nextPtr = copy.getNextPtr();
}

template <class T>
Node <T>:: ~Node()
{
	// It does nothing
}

template <class T>
void Node <T> ::setData(T newData)
{
	data = newData;
}

template <class T>
void Node <T> ::setNextPtr(Node* newNextPtr)
{
	nextPtr = newNextPtr;
}

template <class T>
T& Node <T>::getData()
{
	return data;
}

template <class T>
Node <T>* Node <T>::getNextPtr()
{
	return nextPtr;
}


