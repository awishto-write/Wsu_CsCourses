#include <iostream>
#include <cstdlib>     // For srand
#include <string>
#include <ctime>

#include "QueueNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Queue
{

public: // Member functions

        // Constructor
    Queue(QueueNode* newpHead = nullptr, QueueNode* newpTail = nullptr);

         // Destructor    // It calls deleteQueueRecursive()
    ~Queue();

          //Getters
    QueueNode* getHead(void);        // Get the head
    QueueNode* getTail(void);        // Get the tail

         // This function checks if the queue is empty, when empty it sets the head pointer to null
    bool isEmpty() const; 
   
         // This function checks for empty queue, enqueue new nodes, which helps enqueueing customers to the lanes
    bool enqueue(int CusNum, int Lane_ServTime, int TotTime);
        
         // This function dequeues, it dequeues one or more nodes, which helps dequeueing customers from the nodes
    Data dequeue();
        
        // This function prints the queue to the screen
    void printQueue(void);

         // This function proccess the customers, it generates a service time at arrival, generate a service time for the 
                    //next customer and remove a customer to the lane when he/she is done
    void processCust(Queue* node, int time, int lane);


private:

    QueueNode* pHead;
    QueueNode* pTail;

       // This function deletes a node and calls itself recursively
    void deleteQueueRecursive(QueueNode* node);   
};