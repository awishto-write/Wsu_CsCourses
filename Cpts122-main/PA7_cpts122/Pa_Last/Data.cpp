#include "Data.h"

Data::Data(int newRecord, int newID, string newName, string newEmail, string newUnits,
	string newMajor, string newYearLevel, int newAbsence)
{
	record_number = newRecord;
	ID_number = newID;
	name = newName;
	email = newEmail;
	units = newUnits;
	major = newMajor;
	year_level = newYearLevel;
	num_absences = newAbsence;
	//date_absences = newDateAbsences;
}


void Data::setRecord_num(int newRecord)
{
	record_number = newRecord;
}

void Data::setID_number(int newID)
{
	ID_number = newID;
}

void Data::setName(string& newName)
{
	name = newName;
}

void Data::setEmail(string& newEmail)
{
	email = newEmail;
}

void Data::setUnits(string& newUnits)
{
	units = newUnits;
}

void Data::setMajor(string& newMajor)
{
	major = newMajor;
}

void Data::setYearLevel(string& newYearLevel)
{
	year_level = newYearLevel;
}

void Data::setNumAbsences(int newAbsence)
{
	num_absences += newAbsence;  // Sum of absence dates
}


void Data::setAbsenceDate(Stack newDateAbsences)
{
	date_absences = newDateAbsences;
}


int Data::getRecord_num()
{
	return record_number;
}

int Data::getID_number()
{
	return ID_number;
}

string Data::getName()
{
	return name;
}

string Data::getEmail()
{
	return email;
}

string Data::getUnits()
{
	return units;
}

string Data::getMajor()
{
	return major;
}

string Data::getYearLevel()
{
	return year_level;
}


int Data::getNumAbsences()
{
	return num_absences;
}


Stack Data::get_Absence_Dates()
{
	return date_absences;
}


ifstream& operator >> (ifstream& lhs, Data& rhs)
{
	string name = " ", email = " ", major = " ", level = " ", units = " ";
	int record = 0, id = 0;

	string date;
	Stack dates;

	lhs >> record;
	getline(lhs, name, ',');
	lhs >> id;
	getline(lhs, name, '\"');
	getline(lhs, name, '\"');
	getline(lhs, email, ',');
	getline(lhs, email, ',');
	getline(lhs, units, ',');
	getline(lhs, major, ',');
	getline(lhs, level, '\n');


	rhs.setRecord_num(record);
	rhs.setID_number(id);
	rhs.setName(name);
	rhs.setEmail(email);
	rhs.setUnits(units);
	rhs.setMajor(major);
	rhs.setYearLevel(level);


	return lhs;
}

ofstream& operator << (ofstream& lhs, Data& rhs)
{

	lhs << rhs.getRecord_num() << ", " << rhs.getID_number() << ", " << rhs.getName() << " ," << rhs.getEmail() << " ,";
	lhs << rhs.getUnits() << " ," << rhs.getMajor() << " ," << rhs.getYearLevel() << " ," << rhs.getNumAbsences() << " ,";
	lhs << rhs.get_Absence_Dates().peek() << endl;

	return lhs;
}

