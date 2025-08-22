using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ostream;

#include "List.h"

template< class NODETYPE >

// It takes everything in Queue and makes it private. You can use everything in List 
  // But you can use those elements of List outside of Queue // wHA

class Stack :  List < NODETYPE >
{
    // First In - First Out

public:

   void push (const NODETYPE& newData);

   bool pop(const NODETYPE& removedData);

 
private:

    int pTop;

};

template < class NODETYPE >
void Stack < NODETYPE> :: push (const NODETYPE& newData)
{
    this->insertAtFront(newData);
}

template < class NODETYPE >
bool Stack < NODETYPE> :: pop(const NODETYPE& removedData)
{
    this->removeFromBack(removedData);
}
