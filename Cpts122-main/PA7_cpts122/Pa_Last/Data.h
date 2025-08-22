#pragma once
#include "Stack.h"

class Data
{
public:

	   // Constructor
   Data(int newRecord = 0, int newID = 0, string newName = " ", string newEmail = " ", string newUnits = " ",
	string newMajor = " ", string newYearLevel = " ", int newAbsence = 0);


		  // Setters

	void setRecord_num(int newRecord);
	void setID_number(int newID);
	void setName(string& newName);
	void setEmail(string& newEmail);
	void setUnits(string& newUnits);
	void setMajor(string& newMajor);
	void setYearLevel(string& newYearLevel);
	void setNumAbsences(int newAbsence);
	void setAbsenceDate(Stack newDateAbsences);


	// Getters 

	int getRecord_num();
	int getID_number();
	string getName();
	string getEmail();
	string getUnits();
	string getMajor();
	string getYearLevel();
	int getNumAbsences();
	Stack get_Absence_Dates();

private:

	int record_number;
	int ID_number;
	string name;
	string email;
	string units;
	string major;
	string year_level;
	int num_absences;
	Stack date_absences;
};

// Non-Member Functions of Data       

ifstream& operator >> (ifstream& lhs, Data& rhs);   // This functions read from the file and extracts data from the list
ofstream& operator << (ofstream& lhs, Data& rhs);   // This function writes into the file


