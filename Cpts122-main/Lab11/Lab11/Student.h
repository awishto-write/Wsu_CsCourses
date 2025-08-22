#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Person.h"
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

using std::string;
using std::vector;


struct Course
{
	string courseName;
	int credits;
	char currentGrade;
};


class Student : public Person
{
public:

	Student(string name, int age, string gender, double height, const vector<Course>& courses) : Person(name, age, gender, height)
	{
		this->_courses = courses;
		this->_numberOfCoursesTaken = courses.size();
		//this->_numberOfCoursesTaken = courses.size();

		/*int num = 0;
		for (int i = 0; i< num; i++)
		{
			num = courses. credits<i>;
		}*/
		this->_totalNumberOfCredits = 0;
		for (int i = 0; i < courses.size(); i++)
		{
			this->_totalNumberOfCredits += courses[i].credits;
		}

		//this->_totalNumberOfCredits = courses.size();
		
		// ...
	}

private:

	vector <Course> _courses;
	int _numberOfCoursesTaken;
	int _totalNumberOfCredits;

};
