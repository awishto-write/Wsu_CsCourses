#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <time.h>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ostream;
using std::stoi;

class Stack
{
public:

	// Constructor
	Stack();

	// Destructor
	~Stack();

	// This function checks if stack is empty or not
	bool isEmpty();

	  // The function adds items in the list
	void push(string& newDate);

	  // This function removes items from the list
	string pop();

	string peek() const;


public:

	string date[50];
	int pTop;
};
