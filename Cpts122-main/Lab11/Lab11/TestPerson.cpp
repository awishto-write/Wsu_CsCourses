#include "TestPerson.h"

void TestPerson:: TestGetName()
{
	if (this->getName() == "Alan")
	{
		cout << "The getName test function succeed!" << endl;
	}

	/*if (this->_name == "Alan")
	{
		cout << "The getName test function succeed!" << endl;
	}*/

	else
	{
		cout << "The getName test function failed" << endl;
	}
}

void TestPerson::TestGetAge()
{
	if (this->getAge() == 20)
	{
		cout << "The getAge test function succeed!" << endl;
	}

	/*if (this->_age == 20)
	{
		cout << "The getAge test function succeed!" << endl;
	}*/

	else
	{
		cout << "The getAge test function failed" << endl;
	}
}

void TestPerson::TestGetHeight()
{
	if (this->getHeight() == 175.0)
	{
		cout << "The getHeight test function succeed!" << endl;
	}

	//if (this->_height == 175.0)
	//{
	   //cout << "The getHeight test function succeed!" << endl;
	//}

	else
	{
		cout << "The getHeight test function failed" << endl;
	}
}

void TestPerson:: TestGetGender()
{
	if (this->getGender() == "M")
	{
		cout << "The getGender test function succeed!" << endl;
	}

	/*if (this->_gender == "M")
	{
		cout << "The getGender test function succeed!" << endl;
	}*/

	else
	{
		cout << "The getGender test function failed" << endl;
	}

}

void TestPerson :: TestSetName()
{
	this->setName("Allen");

	/*if (this->getName() == "Allen")
	{
		cout << "The setName test function succeed!" << endl;
	}*/

	if (this->_name == "Allen")
	{
		cout << "The setName test function succeed!" << endl;
	}


	else
		cout << "The setName test function failed!" << endl;
}

void TestPerson::TestSetAge()
{
	this->setAge(21);

	/*if (this->getAge() == 21)
	{
		cout << "The setAge test function succeed!" << endl;
	}*/

	if (this->_age == 21)
	{
		cout << "The setAge test function succeed!" << endl;
	}

	else
		cout << "The setAge test function failed!" << endl;
}

void TestPerson::TestSetGender()
{
	this->setGender("F");

	/*if (this->getGender() == "F")
	{
		cout << "The setGender test function succeed!" << endl;
	}*/

	if (this-> _gender== "F")
	{
		cout << "The setGender test function succeed!" << endl;
	}

	else
		cout << "The setGender test function failed!" << endl;
}

void TestPerson::TestSetHeight()
{
	this->setHeight(180.0);

	/*if (this->getHeight() == 180.0)
	{
		cout << "The setHeight test function succeed!" << endl;
	}*/

	if (this->_height == 180.0)
	{
		cout << "The setHeight test function succeed!" << endl;
	}

	else
		cout << "The setHeight test function failed!" << endl;
}

void TestPerson :: Run_AllTestFunctions()
{
      TestGetName();
	  TestGetAge();
	  TestGetHeight();
	  TestGetGender();
	  TestSetName();
	  TestSetAge();
	  TestSetHeight();
	  TestSetGender();
}