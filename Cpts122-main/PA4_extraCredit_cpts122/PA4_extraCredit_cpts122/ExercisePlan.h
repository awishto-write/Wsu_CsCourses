///////////////////////////////////////////////////////////////////////////////
/// \file         ExercisePlan.h
/// \author       AO
/// \date         03/19/2022
/// \brief        The class ExercisePlan and its memeber and non-memeber fucntions
///           
///       
/// REVISION HISTORY:  03/22/2022
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExercisePlan
{

public:
	
	ExercisePlan(const string& newPlanName = "", const string& newDate = "", const int& newGoalCalories = 0);

	ExercisePlan(const ExercisePlan& copy);

	~ExercisePlan();

	// overloaded assignment - always a member function
	ExercisePlan& operator= (const ExercisePlan& rhs);

	// getters - allows us to return a copy of the private data members to outside the object
	string getPlanName() const; // const member function - should not modify data in object - 
								// if try to, compiler will provide error!
	string getDate() const;
	int getGoalSteps() const;

	// setters - allows us to modify the private data members with values from 
	// outside the object
	void setPlanName(const string& newPlanName);
	void setDate(const string& newDate);
	void setGoalSteps(const int& newGoalSteps);

	void editGoal(); // prompt the user for a different goal - display plan with 
					 // changes to screen


private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};

// nonmember functions
ostream& operator<< (ostream& lhs, const ExercisePlan& rhs); // will allow cout << ExercisePlan object1 << ExercisePlan object2...
// write a complete ExercisePlan to a file
fstream& operator<< (fstream& lhs, const ExercisePlan& rhs); // will allow fstr << ExercisePlan object1 << ExercisePlan object2... 
// read a complete ExercisePlan from a file
fstream& operator>> (fstream& lhs, ExercisePlan& rhs); // will allow fstr >> ExercisePlan object1 >> ExercisePlan object2...
