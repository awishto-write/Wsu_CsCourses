//
// Created by sherryl Dion-Gokan on 09/30/22.
//

#include "testQueue.h"

// This function checks if the function for to determine the size of the queue works properly
void testQueue :: test_queueSize()
{
    queue* test = new queue(3);
    test->enqueue(3);
    test->enqueue(5);
    test->enqueue(7);

    int size_test = test->size();

    if(size_test == 3)
        cout << "Successful use of size() function because, the size is 3" << endl;
    else
        cout << "Failed using size() function because the size is not 3" << endl;
}

// This function checks if the function to determine if the queue is empty or not works properly
void testQueue :: test_isEmpty()
{
    queue* test = new queue(1);
    bool empty = test->isEmpty();

    if(empty == true)
    cout << "Successful use of isEmpty() the queue is empty, we di not insert anything" << endl;

    else   // empty == false
        cout << " Failed isEmpty() because the queue is not empty" << endl;
}

// This function checks if the function to determine if the queue is full or not works properly
void testQueue :: test_isFull()
{
    queue* test = new queue(1);
   test->enqueue(100);
    cout << "We choose the queue to be full at 100" << endl;
    bool full = test->isFull();

    if(full == true)
        cout << "isEmpty() succeed because we inserted 100 and max size is 1" << endl;

    else   // full == false
        cout << " Failed isEmpty() because we inserted 100 and max size is 1" << endl;

}

// This function checks if the function to dequeue(remove front element from the queue) 1 node works properly
void testQueue :: test1_dequeue()
{
    queue* test1 = new queue(2);
    test1->enqueue(1);
    test1->enqueue(2);

    int dequeue1 = test1->dequeue();

    if (dequeue1 == 1)
        cout << "Successfully Dequeue, the dequeued value is '1' " << endl;
    else
        cout << " Failed dequeued one node!" << endl;
}

// This function checks if the function to dequeue (remove front element from the queue) an empty queue properly
void testQueue :: test2_dequeue()
{
    queue* test2 = new queue(0);
    int dequeue2 = test2->dequeue();

    if (dequeue2 == -999)
        cout << "Successfully Dequeue an empty node, underflow because nothing has been enqueued " << endl;
    else
        cout << " Failed, dequeued empty node!" << endl;

}

// This function checks if the function to enqueue (add an item to the queue) an empty node works properly
void testQueue :: test1_enqueue()
{
    queue* test1 = new queue(0);
    int enqueue1 = test1->enqueue(1);

    if (enqueue1 == +999)
        cout << "Successfully Enqueued empty node! Overflow because the size"
                " is 0 and one element has been enqueued!" << endl;
    else
        cout << " Failed Enqueue one node!" << endl;

    queue* test2 = new queue(1);
    int enqueue2 = test2->enqueue(1);
}

// This function checks if the function to enqueue (add an item to the queue) 1 node works properly
void testQueue :: test2_enqueue()
{
    queue* test2 = new queue(1);

    int enqueue2 = test2->enqueue(1);

    if (enqueue2 == 1)
        cout << "Successfully Enqueued one node!" << endl;
    else
        cout << " Failed Enqueue empty queue!" << endl;

}

// This function checks if the function to peek (return front element in the queue) 1 node works properly
void testQueue :: test1_peek()
{
    queue* test1 = new queue(3);
    test1->enqueue(7);
    test1->enqueue(5);
    test1->enqueue(2);

    int peek1 = test1->peek();

    if (peek1 == 7)
        cout << "Successfully peek() function for one node!" << endl;
    else
        cout << "Failed peek() function for one node!" << endl;
}

// This function checks if the function to peek (return front element in the queue) an empty queue works properly
void testQueue :: test2_peek()
{
    queue* test2 = new queue(1);

    int peek2 = test2->peek();

    if (peek2 == -999)
        cout << "Successfully peek() function, underflow, empty queue(nothing has been enqueued)!" << endl;
    else
        cout << "Failed peek() function for empty queue!" << endl;
}
