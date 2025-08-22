//
// Created by sherryl Dion-Gokan on 9/9/22.


#ifndef PA1_CPTS223_LIST_H
#define PA1_CPTS223_LIST_H

#include "node.h"

//template < class command_Type, class description_Type>
template <class A, class B>
class List
{

public:

       // Constructor
    List();

        // Destructor
    ~List();

    // This function checks if the list is empty or not  // check for command and description: separate functions?
    bool isEmpty();

    // Setter
   void set_pHead(Node<A,B>* newpHead);

    // Getter
   Node<A,B>* get_pHead();

       // This function inserts/ adds item in order in the list
    void InsertAtFront(A& newCommand, B& newDescription);
    //void InsertAtFront(A& newData);

    // This function deletes each node in the list and is called by the function help_destructor()
    void destroy_List();

    // This function is called from the destructor to delete each node in the list
    void help_destroy(Node<A,B>* pTemp);

    int getList_size();

protected:

    Node<A,B>* pHead;
    int size;

    // This function is called from the destructor to delete each node in the list
   // void help_destroy(Node<A,B>* pTemp);
};

template < class A, class B>
List <A,B> :: List()
{
    this->pHead = nullptr;
    size = 0;
}

template < class A, class B>
List <A,B> :: ~List()
{
    this->destroy_List();
}

template < class A, class B>
int List<A,B> :: getList_size()
{
    return size;
}

template < class A, class B>
void List<A,B> :: InsertAtFront(A& newCommand, B& newDescription)
//void List<A,B> :: InsertAtFront(A& newData)
{
    //Node<A,B>* pTemp = new Node<A,B>(newData);   // Make a new node
    Node<A,B>* pTemp = new Node<A,B>(newCommand, newDescription);   // Make a new node

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


template < class A, class B>
void List <A,B> :: help_destroy(Node<A,B>* pTemp)
{
    if (pTemp != nullptr)
    {
        help_destroy(pTemp->getNextPtr());
        delete pTemp;    // delete from the back of list to the front!
    }
}

template < class A, class B>
void List <A,B> :: destroy_List()
{
    help_destroy(pHead);
    pHead = nullptr;
}

template <class A, class B>
bool List <A,B> :: isEmpty()
{
    bool success = false;

    if (this->pHead == nullptr)
    {
        success = true;
    }

    return success;
}

template <class A, class B>
void List <A,B> :: set_pHead(Node<A,B>* newpHead)
{
    this->pHead = newpHead;
}

template <class A, class B>
Node<A,B>* List <A,B> :: get_pHead()
{
    return pHead;
}

// (Read data from the list of command.csv, having access, getting and use it) - insertion of the data

template <class A, class B>
ofstream& operator << (ofstream& lhs, List<A,B>& rhs)
{
    Node<A,B>* pMem = rhs.get_pHead();

    while (pMem != nullptr)
    {
        lhs << pMem->getCommand();
        lhs << pMem->getDescription();
        pMem = pMem->getNextPtr();
    }

    return lhs;
}

#endif //PA1_CPTS223_LIST_H