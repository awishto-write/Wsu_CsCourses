#include <iostream>
#include <cstdlib>    // For srand
#include <string>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Data
{

public: // Member functions

            // Constructor
    Data(int Cust_num, int lane, int sum_Serv_time);

          // Copy Constructor
    Data(const Data& copy);

         // Destructor
    ~Data();

         // Setters
    void setCustomerNumber(int Cust_num);      // Set customer number 
    void setServiceTime(int Serv_time);       //  Set service time
    void setTotalTime(int tot_time);         // Set total time 

         // Getters    
    int getCustomerNumber() const ;        // Get customer number
    int getServiceTime() const ;          // Get service time
    int getTotalTime() const;             // Gte total time


private:

    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!