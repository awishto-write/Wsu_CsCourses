//
// Created by sherryl Dion-Gokan on 9/9/22.
//

#ifndef PA1_CPTS223_NODE_H
#define PA1_CPTS223_NODE_H

#include "data.h"

//template < class command_Type, class description_Type>
template <class A, class B>
class Node
{
public:
         // Constructor
    //Node(string New_command_Type = "", string New_description_Type= "");
   Node(A New_command_Type, B New_description_Type);    // Put the values as strings?

    Node();
    //Node(A New_command_Type);

    // Copy constructor
    Node(Node& copy);

    // Destructor
    ~Node();

     // Setters
    void setCommand(A New_command_Type);
    void setDescription(B New_description_Type);
    void setNextPtr(Node* newNextPtr);

    // Getters
    A& getCommand();
    B& getDescription();
    Node* getNextPtr();

    bool operator==(Node<A,B> &side) const;

//private:
//protected:

    A command_Type;
    B description_Type;
    Node* nextPtr;
   // Node* Ptr;
    Node<A,B>* Ptr;
};

template <class A, class B>
bool Node<A,B>::operator==(Node<A,B> &side) const {
    if (command_Type == side.description_Type)
        return true;
    else
        return false;
}

template <class A, class B>
Node<A,B>:: Node(A New_command_Type, B New_description_Type)
//Node<A,B>::Node(string New_command_Type, string New_description_Type)
{
     command_Type = New_command_Type;
     description_Type = New_description_Type;
     this->nextPtr = nullptr;
    this->Ptr = nullptr;
}

template <class A, class B>
Node<A,B>:: Node()
{
    this->Ptr = nullptr;
    string New_command_Type, New_description_Type;
    //string New_description_Type;
    command_Type = New_command_Type;
    description_Type = New_description_Type;
    this->nextPtr = nullptr;
}

template <class A, class B>
Node<A,B>:: ~Node()
{
    // It does nothing
}

        // Setters
template <class A, class B>
void Node<A,B>::setCommand(A New_command_Type)
{
    command_Type = New_command_Type;
}

template <class A, class B>
void Node<A,B>:: setDescription(B New_description_Type)
{
   description_Type = New_description_Type;
}

template <class A, class B>
void Node<A,B>::setNextPtr(Node* newNextPtr)
{
    nextPtr = newNextPtr;
}

template <class A, class B>
A& Node<A,B>:: getCommand()
{
   return description_Type;
}

template <class A, class B>
B& Node<A,B>:: getDescription()
{
   return command_Type;
}

template <class A, class B>
Node<A,B>* Node<A,B>::getNextPtr()
{
  return nextPtr;
}

template <class A, class B>
Node<A,B> :: Node(Node& copy)
{
   command_Type = copy.getCommand();
   description_Type = copy.getDescription();
   nextPtr = copy.getNextPtr();
}


#endif //PA1_CPTS223_NODE_H