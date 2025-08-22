#pragma once
#include "Node.h"

template <class T>

class List
{

public:
	// Constructor
	List();

	// Destructor
	~List();

	// This function checks if the list is empty or not
	bool isEmpty();

	// Setter
	void set_pHead(Node<T>* newpHead);

	// Getter
	Node<T>* get_pHead();

	// This function inserts/ adds item in order in the list
	void InsertAtFront(T& newData);

	// This function deletes each node in the list and is called by the function help_destructor()
	void destroy_List();


private:

	Node<T>* pHead;

	// This function is called from the destructor to delete each node in the list
	void help_destroy(Node<T>* pTemp);
	 
};


template <class T>
List <T> ::List()
{
	this->pHead = nullptr;
}


template < class T>
bool List <T> ::isEmpty()
{
	bool success = false;

	if (this->pHead == nullptr)
	{
		success = true;
	}

	return success;
}


template <class T>
void List <T> ::set_pHead(Node<T>* newpHead)
{
	this->pHead = newpHead;
}

template < class T>
Node<T>* List < T> ::get_pHead()
{
	return pHead;
}

template<class T>
void List<T>::InsertAtFront(T& newData)
{
	Node<T>* pTemp = new Node<T>(newData);   // Make a new node

	if (this->pHead == nullptr)
	{
		pHead = pTemp;
	}
	else
	{
		pTemp->setNextPtr(pHead);
		pHead = pTemp;
	}
}


template < class T>
List <T> :: ~List()
{
	this->destroy_List();
}

template<class T>
void List<T>::help_destroy(Node<T>* pTemp)
{
	if (pTemp != nullptr)
	{
		help_destroy(pTemp->getNextPtr());
		delete pTemp;    // delete from the back of list to the front!
	}
}

template<class T>
void List <T> ::destroy_List()
{
	help_destroy(pHead);
	pHead = nullptr;
}

       // Non-member functions

// Read data/ information from the list of classList.csv- extraction of the data

template <class T>
ifstream& operator >> (ifstream& lhs, List<T>& rhs)
{
	Data master_list;
	int record_num, Id, absences_num;
	string name, email, major, year_level, date;    
	string units;
	Stack dates;

	lhs >> record_num >> Id;
	getline(lhs, name, '\"');
	getline(lhs, name, '\"');
	getline(lhs, email, ',');
	lhs >> units;
	getline(lhs, major, ',');
	getline(lhs, year_level, ',');

	lhs >> absences_num;
	getline(lhs, date, '\n');

	master_list.setRecord_num(record_num);
	master_list.setID_number(Id);
	master_list.setName(name);
	master_list.setEmail(email);
	master_list.setUnits(units);
	master_list.setMajor(major);
	master_list.setYearLevel(year_level);

	master_list.setNumAbsences(absences_num);
	master_list.setAbsenceDate(dates);


	return lhs;
}


    // Read data/ information from the list of classList.csv, having access, getting and use it- insertion of the data 

template <class T>
ofstream& operator << (ofstream& lhs, List<T>& rhs)
{
	Node<T>* pMem = rhs.get_pHead();

	while (pMem != nullptr)
	{
		lhs << pMem->getData();
		pMem = pMem->getNextPtr();
	}

	return lhs;
}
