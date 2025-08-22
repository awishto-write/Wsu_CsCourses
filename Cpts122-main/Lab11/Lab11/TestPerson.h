#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;

using std::istream;
using std::ostream;

using std::string;


class TestPerson : public Person
{
public:

	TestPerson() : Person("Alan", 20, "M", 175.0) 
	{
		 //noop
	}
	 
	    // Test Getter Functions
	void TestGetName();
	void TestGetAge();
	void TestGetHeight();
	void TestGetGender();
	
	   // Test Setter Functions
	void TestSetName();
	void TestSetAge();
	void TestSetHeight();
	void TestSetGender();

	void Run_AllTestFunctions();

};