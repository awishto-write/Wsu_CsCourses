//
// Created by sherryl Dion-Gokan on 09/29/22.
//

#include "queue.h"

// Constructor to initialize queue
queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
    delete arr; // you are not required to test this function;
    // however, are there issues with it?
}

// Utility function to remove front element from the queue
int queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return -999;
    }
    cout << "Removing " << arr[front] << '\n';   // The second "<" of "<<" was not added after cout
    front = (front + 1) % capacity;
    count--;
    return arr[front - 1];
}

// Utility function to add an item to the queue
int queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())  // The function was not called properly, it was "isFul" instead of "isFull"
    {
        cout << "OverFlow\nProgram Terminated\n";
        return +999;
    }
    cout << "Inserting " << item << '\n';
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
    return arr[rear];
}

// Utility function to return front element in the queue
int queue::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        //return numeric_limits<int>::min();
        return -999;
    }
    return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
    return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
    return (size() == 0);
}
// Utility function to check if the queue is full or not
bool queue::isFull()
{
    return (capacity == size());  // It was only one "=" instead of 2
}
