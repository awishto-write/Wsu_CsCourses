// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

// Poor attributes to the code (start)
// 1. File structure; The classes were not inserted into different files(header and sources).
      // So, to solve this issue, each class should have its own header and source file
// 2. Comments; There were only few comments, however it would be better to have more detailed
     // comments for every function and every intermediate step of a function.
// 3. The name of the variables could be more related to their attributes/qualifications
      // in order that by looking at their names, we know why they have been created for.
// 4. The presentation, the layer, the space between each line of code would be better, in
     // a more appealing, readable way and easy to understand
// 5. Testing; The test cases of those functions coule be done more in-depth, by covering element
    // of the function and also in a more efficient way
// End of Poor attributes to the code

#include <iostream>
#include "testQueue.h"

// main function
int main()
{
    testQueue q;

           // call your test functions here!

    cout << "The test case for the size of the queue" << endl;
    q.test_queueSize();

    cout << "The test case to know if the queue is empty" << endl;
    q.test_isEmpty();

    cout << "The test case to know if the queue is full" << endl;
    q.test_isFull();

    cout << "The test cases to dequeue" << endl;
    q.test1_dequeue();
    q.test2_dequeue();

    cout << "The test cases to enqueue" << endl;
    q.test1_enqueue();
    q.test2_enqueue();

    cout << "The test cases to peek" << endl;
    q.test1_peek();
    q.test2_peek();

    return 0;
}


