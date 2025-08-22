#include "Data.h"

    // Constructor

Data :: Data (int Cust_num, int lane, int sum_Serv_time)
{
	customerNumber = Cust_num;               //  Reset to 1 ? Starting at 1 for Customer ID?
	
	// Service Time
	           srand(time(NULL));
	if (lane == 1)
		serviceTime = rand() % 5 + 1;      // 5 random numbers from 1 to 5      // Express Lane
	if (lane == 2)
		serviceTime = rand() % 6 + 3;      // 6 random numbers from 3 to 8      // Normal Lane

	sum_Serv_time += serviceTime;    
	//serviceTime += sum_Serv_time;

	totalTime = serviceTime + sum_Serv_time;              // Set to 0 ?
} 


    // Destructor 
Data :: ~Data()
{
	// Nothing
}

       // Setters

void Data :: setCustomerNumber(int Cust_num)
{
	customerNumber = Cust_num;
}

void Data :: setServiceTime(int Serv_time)
{
	serviceTime = Serv_time;
}

void Data::setTotalTime(int tot_time)
{
	totalTime = tot_time;
}

      // Getters

int Data :: getCustomerNumber() const
{
	return customerNumber;
}

int Data :: getServiceTime()  const
{
	return serviceTime;
}

int Data :: getTotalTime() const 
{
	return totalTime;
}

    // Copy Constructor

Data :: Data (const Data& copy)
{
	customerNumber = copy.getCustomerNumber();
	serviceTime= copy.getServiceTime();
	totalTime = copy.getTotalTime();
}
