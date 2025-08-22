#pragma once
#pragma warning(disable : 4996)       // To be able to use localtime without having that warning
#include "List.h"

class Menu
{
public:

	// Constructor
	Menu();

	// Destructor
	~Menu();

	// This function displays the menu to the screen
	void display_menu();

	// This function allows the user to pick its option from the menu
	void performUserSelection(const int& option);

	// This function runs the program and the choices picked by the user
	void RunApp();

	// This function reads the .csv course file and overwrites the master list.
	void import_courseList(List<Data>& File);

	// This function populates the master list with previous nodes from master.txt.
	void load_masterList(List<Data>& File);

	// This function stores the contents of the master list’s nodes to master.txt.
	void store_masterList(List<Data>& File);

	// This function runs through the master list, displays each student’s name,
	//and prompts if he/she was absent for the current day.
    void mark_absences(List<Data>& File);


	  // This function generates the report for all students (showing only the most recent absence for each student) and
			// generates the report for students with absences that match or exceed (the number entered by the user).
      void generateReport(List<Data>& File);
	
     // Prompts for an ID number or name of student to edit.Prompts for the date of absence to edit.
	    void editAbsences(List<Data>& File);


private:

	List<Data> master_file;
	ifstream extraction;
	ofstream insertion;

};

