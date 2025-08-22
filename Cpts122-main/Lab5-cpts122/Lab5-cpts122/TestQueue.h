
#include "Queue.h"

class TestQueue
{
private:

	Queue _queue;

	void testIsEmpty();
	void testEnquingDequeuing();

public:

	TestQueue();
	void runTests();

};