#pragma once
#include "Mammal.h"

class Dog : public Mammal
{
public:

	void Speak() const override 
	{
		cout << "Bark" << endl;
	}

	void Move() const override 
	{
		cout << "Walk like a dog!" << endl;
	}

};