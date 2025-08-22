////////////////////////////////////////////////////////////////////////////////
/// \file         FitnessAppWrapper.h
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;   //for scanning
using std::endl;    //For new line?

using std::fstream;                                 // For both writing and reading?
using std::ostream;   //for file writing

using std::istream;   //for file reading 
using std::string;


#include "DietPlan.h"
#include "ExercisePlan.h"

     // at least two file stream objects (input / output file streams) : one for each file.

class FitnessAppWrapper
{
private:                               // Also another private with one of those operators?
	DietPlan plan_for_diet[7];
	ExercisePlan plan_for_exercise[7];
	fstream infile_diet;
	fstream outfile_diet;
	fstream infile_exercise;
	fstream outfile_exercise;

public:

	    //Constructor
	FitnessAppWrapper();

	 // This function displays the menu of the Application with 9 options
	void displayMenu();

	// This function prompts the user to pick an option from the menu
	int getMenuOption() const;

	// This function starts the main application.
	void runApp(void); 

	                            //Precondition : file is already open!

	       // Edit daily plan functions
	      // They are overloaded Functions.
		 // The first one deals with the Dietplan class and the second one with ExercisePlan class.
	void editDailyPlan(DietPlan &cplan);   // We pass it by reference to be able to retain the change
	void editDailyPlan(ExercisePlan &cplan);

	     // Edit daily plan functions
		  // They are overloaded Functions.
		 // The first one deals with the Dietplan class and the second one with ExercisePlan class.
	     // Those functions choose a specific day to edit.
	void editDailyPlan_Diet(DietPlan cplan[]);
	void editDailyPlan_Exercise(ExercisePlan cplan[]);


		 // These functions read one record from the given stream.
		 // They are overloaded Functions.
	     // The first one deals with the Dietplan class and the second one with ExercisePlan class.
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);                                                                           
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);


	  // These functions read in all seven daily plans from the given stream.    
     // These functions call loadDailyPlan() directly. They are overloaded functions.
	 // The first one deals with the Dietplan class and the second one with ExercisePlan class.
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);     
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);


	   // These functions write a daily plan to the screen and apply the overloaded stream insertion operator.
	   // They are overloaded Functions.
	  // The first one deals with the Dietplan class and the second one with ExercisePlan class.
	void displayDailyPlan(DietPlan cplan);                                       
	void displayDailyPlan(ExercisePlan cplan);


	    // These functions write a weekly plan to the screen. 
		// These functions call displayDailyPlan(). They are overloaded Functions.
	   // The first one deals with the Dietplan class and the second one with ExercisePlan class.
	void displayWeeklyPlan(DietPlan cplan[]);
	void displayWeeklyPlan(ExercisePlan cplan[]);

	   // These functions write a daily plan to a file and apply the overloaded stream insertion operator.
	   // They are overloaded Functions.
	  // The first one deals with the Dietplan class and the second one with ExercisePlan class.
	void storeDailyPlan(fstream& fileStream, DietPlan cplan);
	void storeDailyPlan(fstream& fileStream, ExercisePlan cplan);


	  // These functions write a weekly plan to a file. 
	  //  They are overloaded Functions.
	  // These functions call storeDailyPlan().
	void storeWeeklyPlan(fstream& fileStream, DietPlan cplan[]);
	void storeWeeklyPlan(fstream& fileStream, ExercisePlan cplan[]);


};

