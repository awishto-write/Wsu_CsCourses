#pragma once
#include "Mammal.h"

class GuineaPig : public Mammal
{
public:

	void Speak() const override
	{
		cout << "weep weep" << endl;
	}

	void Move() const override
	{
		cout << "Walk like a GuineaPig!" << endl;
	}

};