
#include "TestQueue.h"

TestQueue::TestQueue()
{
	//noop
}

void TestQueue::testIsEmpty()
{
	           //test isEmpty.
	
	// Test Case: Testing queue is empty.

	if (_queue.isEmpty() == false)
	{
		std::cout << "isEmpty failed. Expected true, but got false." << std::endl;
	}

	else 
	{
		std::cout << "isEmpty Success" << std::endl;
	}

	_queue.enqueue("asf");

	if (_queue.isEmpty() == true)
	{
		std::cout << "isEmpty failed. After enqueuing data, the queue should not be empty." << std::endl;
	}

	else
	{
		std::cout << "isEmpty Success" << std::endl;
	}


	_queue.dequeue();

	if (_queue.isEmpty() == false)
	{
		std::cout << "isEmpty failed. After dequeueing the last data, the queue should be empty." << std::endl;
	}

	else 
	{
		std::cout << "isEmpty Success" << std::endl;
	}

}

void TestQueue::runTests() 
{
	testIsEmpty();
	testEnquingDequeuing();
	//test is empty
}

void TestQueue::testEnquingDequeuing()
{
	// Enqueue some stuff
	// Dequeue one by one, and make sure the returned value is as expected.
	// "a", "b", "c".
	// dequeue() == "a";
	// dequeue() == "b";
	// ....

	_queue.enqueue("a");
	_queue.enqueue("b");
	_queue.enqueue("c");
	_queue.enqueue("d");

	    //Test Case: Dequeuing
	if (_queue.dequeue() == "a")
	{
		std::cout << "Successfully dequeued." << std::endl;
	}
	else
	{
		std::cout << "dequeue failed, after dequeue head, there should not be 'a'" << std::endl;
	}

	if (_queue.dequeue() == "b")
	{
		std::cout << "Successfully dequeued." << std::endl;
	}
	else
	{
		std::cout << "dequeue failed, after dequeue head, there should not be 'b'" << std::endl;
	}

	if (_queue.dequeue() == "c")
	{
		std::cout << "Successfully dequeued." << std::endl;
	}
	else
	{
		std::cout << "dequeue failed, after dequeue head, there should not be 'c'" << std::endl;
	}

	if (_queue.dequeue() == "d")
	{
		std::cout << "Successfully dequeued." << std::endl;
	}
	else
	{
		std::cout << "dequeue failed, after dequeue head, there should not be 'd'" << std::endl;
	}

}


