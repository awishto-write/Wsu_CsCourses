#include <iostream>
#include <cstdlib>       // For srand
#include <string>
#include <ctime>

#include "Data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class QueueNode
{

public:    // Member functions

        //  Constructor?
    QueueNode(int CusNum, int Lane_ServTime, int TotTime);

       // Destructor
    ~QueueNode();

          // Setters 
    void setNextPtr(QueueNode* newNextPtr);          // Setter for QueueNode
    void setData(Data* newData);                   // Setter for Data

          // Getters
    QueueNode* getNextPtr() const;        // Getter for QueueNode
    Data* getData() const;             // Getter for Data

private:

    Data* pData;    // The memory for Data will need to be allocated on the heap as well!
    QueueNode* pNext;

};
