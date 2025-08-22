#include <iostream>
#include <cstdlib>     // For srand
#include <string>
#include <ctime>

#include "Queue.h"

class SimulationAndTest
{

private:

	    // Express
	Queue queue1_express;

	// Regular 
	    Queue queue2_normal;

public: 

	    //Constructor
	SimulationAndTest();

	     // Destructor
	~SimulationAndTest();
	  
	//One test case that executes your enqueue() operation on an empty queue
	void testEnqueue_emptyQueue();

	//One test case that executes your enqueue() operation with one node in the queue
	void testEnqueue_oneNode();

	//One test case that executes your dequeue() operation on a queue with one node
	void testDequeue_oneNode();
	
	//One test case that executes your dequeue() operation on a queue with two nodes
	void testDequeue_twoNodes();

	   // Running the simulation with the time indicated by the user
	void runSimulation(int time);

	   // One test case that runs the simulation for 24 hours
	void testRunSimilation();

	    // Print the menu and ask the user to select the test cases he/she wants to execute and ability to run the simulation
	void run_test_simulation();
};
