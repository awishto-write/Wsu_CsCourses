//
// Created by sherryl Dion-Gokan on 9/29/22.
//

#ifndef MA1_QUEUE_H
#define MA1_QUEUE_H

#include <iostream>
#include <iostream>
#include <cstdlib>

using namespace std;

// define default capacity of the queue
#define SIZE 10

// Class for queue
class queue
{
    int* arr;// array to store queue elements
    int capacity; // maximum capacity of the queue
    int front;// front points to front element in the queue (if any)
    int rear;// rear points to last element in the queue
    int count;// current size of the queue
public:
    queue(int size = SIZE);  // constructor
    ~queue();    // destructor
    int dequeue();
    int enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();

};         // Semi-Colon was missing at the end od the declaration

#endif //MA1_QUEUE_H
