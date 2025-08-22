#include "SimulationAndTest.h"

SimulationAndTest::SimulationAndTest()
{
	// Nothing
}

SimulationAndTest :: ~SimulationAndTest()
{
	// Nothing
}

void SimulationAndTest::runSimulation(int time)
{
	   //Queue queue1_express, queue2_normal;    // Use of two queues for simulation   // already called in the private
	int total_time = 0;    
	int cust_Num1 = 1, cust_Num2 = 1;    // The unique identifier number should start at 1


	//for (total_time; total_time < time; total_time++)
	while(total_time!=time)
	{
		             // Checking if someone enters
		                                                      
		if (rand () % 2 == 0)               // Express Lane
		{
			  // Adding someone to the express lane    // 1 represents the lane, which will refers to the service time (check Data.cpp)
			queue1_express.enqueue(cust_Num1, 1, total_time);
			cust_Num1++;     // Incrementing the customer ID for the next customers
			cout << " ****  *** Someone has joined the express line, Welcome!  ***  **** " << endl;
			//queue1_express.printQueue();    // Printing the Queue information
		}

			if (rand() % 2 == 0)              // Normal Lane
		 {
			// Adding someone to the express lane    // 2 represents the lane, which will refers to the service time (check Data.cpp)
			queue2_normal.enqueue(cust_Num2, 2, total_time);
			cust_Num2++;     // Incrementing the customer ID for the next customers
			cout << " *** **** Someone has joined the standard line, Welcome! **** *** " << endl;
			//queue2_normal.printQueue();    // Printing the Queue information
		  }
		 
		              // Processing the customers
		Queue pro;
		pro.processCust(&queue1_express, total_time, 1);      // Express line
		pro.processCust(&queue2_normal, total_time, 2);       // Standard line

		                                           
		      // Print the entire queue for each lane every 10 minutes    // 10 % 10 = 0, 20 % 20 = 0, etc.

		if (total_time != 0 && (total_time % 10) == 0)   
		{
			//system("cls");
			cout << "    The queue for the lane 1 (express lane) will be displayed below:     " << endl;  //express
			queue1_express.printQueue();
			cout << endl;

			cout << "   The queue for the lane 2 (normal lane) will be displayed below:      " << endl;   //normal
			queue2_normal.printQueue();
			cout << endl;

		}

		total_time++;
	}


}



void SimulationAndTest ::testRunSimilation()
{
	int time = 24*60;       // 24* 60 = 1440 which correspond to 24 hours of the simulation      
	runSimulation(time);
}

void SimulationAndTest :: testEnqueue_emptyQueue()
{
	Queue test;

	if (test.enqueue(3, 1, 6) == true)
	{
		cout << "Successfully Enqueued empty queue!" << endl;
	}

	else
	{
		cout << " Failed Enqueue empty node! " << endl;
	}
}


void SimulationAndTest :: testEnqueue_oneNode()
{
	Queue test;
	test.enqueue(3, 1, 6);

	if (test.enqueue(3, 1, 6) == true && test.enqueue(2, 6, 12) == true)
	{
		cout << "Successfully Enqueued one node!" << endl;
	}
	
	else
	{
		cout << " Failed Enqueue one node!" << endl;
	}

}

void SimulationAndTest::testDequeue_oneNode()
{
	Queue test;
	test.enqueue(3, 1, 6);   // By plugging the middle term (lane number) , it get assigned a service time 

	Data dq = test.dequeue();

	if (dq.getCustomerNumber() == 3 && dq.getServiceTime() == 1 && dq.getTotalTime() == 6)
	{
		cout << "Dequeue One Node failed, after dequeue, there should not be '3, 1, 6' " << endl;
	}
	else
	{
		cout << "Successfully dequeued one node!" << endl;
	}

}


void SimulationAndTest:: testDequeue_twoNodes()
{
	Queue test;
	test.enqueue(3, 1, 6);
	test.enqueue(2, 6, 12);

	Data dq = test.dequeue();


	if (dq.getCustomerNumber() == 3 && dq.getServiceTime() == 1 && dq.getTotalTime() == 6)
	{
		cout << "Dequeue failed, after dequeue, there should not be '3, 1, 6'" << endl;
	}
	else
	{
		cout << "Successfully dequeued two nodes!" << endl;
	}

	if (dq.getCustomerNumber() == 2 && dq.getServiceTime() == 6 && dq.getTotalTime() == 12)
	{
		cout << "Dequeue failed, after dequeue, there should not be '2, 8, 12'" << endl << endl;
		
	}
	else
	{
		cout << "Successfully dequeued two nodes." << endl << endl;
	}

}

void SimulationAndTest :: run_test_simulation()
{
	
	int choose = 0, min_simulate = 0;

	cout << "                 Welcome          " << endl << endl;
	cout << "     Pick an option from the menu:" << endl;
	cout << " 1)    Run the similation     " << endl;
	cout << " 2) Test Enqueue empty node and Test enqueue one node and Test dequeue one node and Test Dequeue two nodes." << endl;
	cout << " 3) Test similation for 24 hours" << endl;
	cout << " 4)  Exit " << endl << endl;
	
	cout << " Choice: ";
	cin >> choose;
	cout << endl << endl;

	
		switch (choose)
		{
		case 1:
			cout << " ------------- Welcome to the 2022 Grocery Store Simulation! --------------" << endl;
			cout << "How long would you like the simulation to last for in minutes? " << endl;     // How long should be good?> 10?
			cout << "    Please choose an integer (not decimal/ fraction) value > 10 " << endl;
			cout << "            Minutes: ";
			cin >> min_simulate;
			cout << endl;

			runSimulation(min_simulate);
			break;

		case 2:     // Testing enqueue and dequeue
			testEnqueue_emptyQueue();
			testEnqueue_oneNode();
			testDequeue_oneNode();
			testDequeue_twoNodes();

			break;

		case 3: testRunSimilation();
			break;

		case 4:
			cout << "-------------------- Goodbye! Thank you for passing by!  -------------------- " << endl;
			break;

		default: 
			system("cls");
			cout << "Choose a value within the indicated range (1-7) !" << endl << endl;
			run_test_simulation();
			break;
		}

}