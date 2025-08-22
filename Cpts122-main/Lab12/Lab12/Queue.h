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

#include "List.h"

template< class NODETYPE > 

      // It takes everything in Queue and makes it private. You can use everything in List 
        // But you can use those elements of List outside of Queue // wHA

class Queue: private List < NODETYPE >   
{
      // First In - First Out

public:

   void enqueue(const NODETYPE& newData );
   bool dequeue(const NODETYPE& removedData);

};

template < class NODETYPE >
void Queue < NODETYPE> :: enqueue (const NODETYPE& newData )
{
    this->insertAtFront(newData);
}

template< class NODETYPE >
bool Queue < NODETYPE> :: dequeue(const NODETYPE& removedData)
{
    this->removeFromBack(removedData);
}

