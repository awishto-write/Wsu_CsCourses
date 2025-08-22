#pragma once

#include "Mammal.h"

class Cat : public Mammal
{
public:

	void Speak() const override
	{
		cout << "Meow" << endl;
	}

	void Move() const override
	{
		cout << "Walk like a cat!" << endl;
	}

};