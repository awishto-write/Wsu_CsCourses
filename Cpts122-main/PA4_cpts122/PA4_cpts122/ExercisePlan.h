#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::endl;

using std::fstream;
using std::ostream;
using std::string;    // includes getline(), stoi
using std::istream;  //for file reading 


                        // Member Functions

class ExercisePlan
{
private:

	string _planName;
	int _goalSteps;
	string _date;

public:

	//Constructor
	// We set the element of the private to default values
	ExercisePlan(string newPlanName = " ", int newGoalSteps = 0, string newDate = " ");

	// Copy constructor
	ExercisePlan(const ExercisePlan& copyExercise);

	// Destructor
	~ExercisePlan();

	// Setters
	void setGoalSteps(int newGoalSteps);      
	void setPlanName(string newPlanName);
	void setDate(string newDate);

	// Getters
	int getGoalSteps() const;
	string getPlanName() const;
	string getDate() const;

						
	        // Functions for the edit of the plan

	// This function edits a goal from the plan
	void editGoal_Ex();

	//This function edits a plan name from the plan
	void editName_Ex();

	// This function edits a date from the plan
	void editDate_Ex();
};


                 // Non-Member Functions: overloaded streams           

 // This function helps to read, technically to display the data 
ostream& operator<< (ostream& ins, const ExercisePlan& ex_plan);        // Insertion 
                              
 // This function helps extracting information from the data, to be able to read it later and set it to the exact format of the data
istream& operator>> (istream& ext, ExercisePlan& ex_plan);     // Extraction

