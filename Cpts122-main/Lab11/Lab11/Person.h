#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

//using std::istream;
//using std::ostream;

using std::string;

class Person
{
protected:
	string _name;
	int _age;
	string _gender;
	double _height;

public:
	    // Constructor
	Person(string name, int age, string gender, double height);

	    // Destructor
	~Person() = default;

	    // Copy Constructor
	Person(const Person& copy);

	       // Setters
	string getName() const;
	int getAge() const;
	string getGender() const;
	double getHeight() const;

	        // Setters
	void setName(const string& newName);  // We want to have the &: reference for string because it is an object
	                                  // Without reference, it is like we make 2 copies.
	void setAge(int newAge);   // int is passed by value
	void setGender(const string& newGender);
	void setHeight(double newHeight);

	     // Overloaded Assignment Operator
	Person& operator=(const Person& person);

	friend std::ostream& operator << (std:: ostream& in, const Person& person)
	{
		in << person._name << endl;
		in << person._age << endl;
		in << person._gender << endl;
		in << person._height << endl;

		return in;
	}

	friend std::istream& operator >> (std::istream& ext, Person& person)
	{
		ext >> person._name;
		ext >> person._age;
		ext >> person._gender;
		ext >> person._height;

		return ext;
	}
};

     