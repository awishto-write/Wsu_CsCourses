#include "Person.h"

string Person :: getName() const
{
	return this-> _name;
}

int Person :: getAge() const
{
	return this-> _age;
}

string Person :: getGender() const
{
	return this->_gender;
}

double Person:: getHeight() const
{
	return this->_height;
}

Person :: Person (string name, int age, string gender, double height)
{
	_name = name;
	_age = age;
	_gender = gender;
	_height = height;
}

Person :: Person (const Person& copy)
{
	_name = copy.getName();
	_age= copy.getAge();
	_gender = copy.getGender();
	_height = copy.getHeight();
}

void Person:: setName(const string& newName)
{
	_name = newName;
}
									  
void Person:: setAge(int newAge)
{
	_age = newAge;
}

void Person:: setGender(const string& newGender)
{
	_gender = newGender;
}
void Person:: setHeight(double newHeight)
{
	_height = newHeight;
}

Person& Person :: operator=(const Person& person)
{
	this->_name = person._name;
	this->_age = person._age;
	this->_gender = person._gender;
	this->_height = person._height;

	return *this;
}