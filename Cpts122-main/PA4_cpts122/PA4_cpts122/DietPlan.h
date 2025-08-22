//////////////////////////////////////////////////////////////////////////////
/// \file         DietPlan.h
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;   
using std::endl;

using std::fstream;
using std::ostream;
using std::string;      // includes getline()
using std::istream;   //for file reading 

                            // Member Functions

class DietPlan
{
private:

	string _planName;
	int _goalCalories;
	string _date;

public:

	// We set the element of the private to default values
	//Constructor
	DietPlan(string newPlanName = " ", int newGoalCalories = 0, string newDate = " ");

	// Copy constructor
	DietPlan(const DietPlan& copyDiet);

	// Destructor
	~DietPlan();

	// Setters
	void setGoalCalories(int newGoalCalories);      
	void setPlanName(string newPlanName);
	void setDate(string newDate);

	// Getters
	int getGoalCalories() const;
	string getPlanName() const;
	string getDate() const;

	         // Functions for the edit of the plan

	// This function edits a goal from the plan
	void editGoal_Diet(); 

	//This function edits a plan name from the plan
	void editName_Diet();

	// This function edits a date from the plan
	void editDate_Diet();
};

              // Non-Member Functions: overloaded streams          

    // This function helps to read, technically to display the data 
ostream& operator << (ostream& ins, const DietPlan& diet_plan);         // Insertion

    // This function helps extracting information from the data, to be able to read it later and set it to the exact format of the data
istream& operator >> (istream& ext, DietPlan& diet_plan);     // Extraction