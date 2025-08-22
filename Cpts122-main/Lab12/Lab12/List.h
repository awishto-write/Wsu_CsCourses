#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ostream;


                          // ListNode Elements

template< class NODETYPE > class List;  // forward declaration

template<class NODETYPE>

class ListNode
{

	friend class List < NODETYPE >; // make List a friend

public:

	ListNode(const NODETYPE& newData);  // copy constructor
	NODETYPE getData() const;      // return data in the node

private:

	NODETYPE data;                 // data
	ListNode< NODETYPE>* nextPtr; // next node in the list
};

template<class NODETYPE>
NODETYPE ListNode <NODETYPE> ::getData() const
{
	return data;
}


template<class NODETYPE>
ListNode <NODETYPE> ::ListNode(const NODETYPE& newData)
{
	this->data = newData;
	this->nextPtr = nullptr;
}


                               // List Elements 


template< class NODETYPE >

class List
{

public:

	List();      // constructor
	~List();     // destructor

	void insertAtFront(const NODETYPE& newData);
	void insertAtBack(const NODETYPE& newData);

	bool removeFromFront(NODETYPE& removedData);
	bool removeFromBack(NODETYPE& removedData);

	bool isEmpty() const;
	void print() const;

private:

	ListNode <NODETYPE>* firstPtr;  // pointer to first node
	ListNode <NODETYPE>* lastPtr;   // pointer to last node


	         // Utility function to allocate a new node
	ListNode <NODETYPE>* getNewNode(const NODETYPE& newData);

	//void destroyList()
	//{
	//	destroyList(this->firstPt);
	//}

	//void destroyList(ListNode < NODETYPE >* root)
	//{
	//	if (root->nextPtr)  // check if not null   / if I wanted the other way, I would write (!root->nextPtr)
	//	{
	//		  
	//	}
	//}

};


template< class NODETYPE >
List <NODETYPE>::List()
{
	firstPtr = nullptr;
	lastPtr = nullptr;
}

template< class NODETYPE >
List <NODETYPE>:: ~List()
{
	// destroyList();
}

template< class NODETYPE >
ListNode < NODETYPE >* List <NODETYPE> ::getNewNode(const NODETYPE& newData)
{
	ListNode < NODETYPE >* node = new  ListNode < NODETYPE > (newData );
	/*this->data = newData;
	this->nextPtr = nullptr;*/

	node->nextPtr = nullptr;
	return node;

}

template< class NODETYPE >
bool List <NODETYPE>::isEmpty() const
{


	if (firstPtr == nullptr)
	{
		return true;
	}
	return false;
}

template< class NODETYPE >
void List <NODETYPE>:: insertAtFront(const NODETYPE& newData)
{
	ListNode < NODETYPE >* node = getNewNode(newData);

	if (isEmpty())
	{
		node->nextPtr = nullptr;
		lastPtr = node;
	}

	else
	{
		node->nextPtr = firstPtr;
		firstPtr = node;
	}
}

template< class NODETYPE >
void List <NODETYPE>:: insertAtBack(const NODETYPE& newData)
{
	ListNode < NODETYPE >* node = getNewNode(newData);


	if (isEmpty())
	{
		insertAtFront(newData);
		return;
	}
    
	else
	{
		lastPtr->nextPtr = node;
		lastPtr = node;
	}

}

template< class NODETYPE >
bool List <NODETYPE>:: removeFromFront(NODETYPE& removedData)
{
	//bool success = true;

	if (isEmpty())
	{
		return false;
	}

	//removedData = firstPtr;
	removedData = firstPtr->getData();

	// ListNode < NODETYPE >* temp = getNewNode(removedData);
	auto temp = firstPtr;

	firstPtr = firstPtr->nextPtr;
	delete temp;

	return true;

}

template< class NODETYPE >
bool List <NODETYPE>:: removeFromBack(NODETYPE& removedData)
{
	//ListNode < NODETYPE >* node = *firstPtr;

	removedData = lastPtr->getData();
	//removedData = lastPtr;

	if (firstPtr == lastPtr)
	{
		//firstPtr = nullptr;
		delete firstPtr;
		delete lastPtr;
		return true;
	}

	else
	{
		ListNode < NODETYPE >* pCur = firstPtr;
		while (pCur->nextPtr != lastPtr)
		{
			pCur = pCur->nextPtr;
			lastPtr = pCur;
		}

		delete lastPtr->nextPtr;
		lastPtr->nextPtr = nullptr;
		return true;
	}
}


template< class NODETYPE >
void List <NODETYPE> :: print() const
{
	auto pCur = firstPtr;
	cout << pCur->data << " <-";
	
	while (pCur != lastPtr)
	{
		pCur = pCur->nextPtr;
		cout << pCur->data << "<-";
	}
}

         // Insertion Operator
//
//template < class NODETYPE >
//ostream& operator << (ostream& lhs, List<NODETYPE>& rhs)
//{
//	// lhs << rhs
//
//	 return lhs;
//}