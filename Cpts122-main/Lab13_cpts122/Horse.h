#pragma once

#include "Mammal.h"

class Horse : public Mammal
{
public:

	void Speak() const override
	{
		cout << "Speak like a horse." << endl;
	}

	void Move() const override
	{
		cout << "Move like a horse!" << endl;
	}

};