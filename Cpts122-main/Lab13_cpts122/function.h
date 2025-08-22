#pragma once
#include <iostream>

using std::cout;

using std::endl;


class Base
{
public:

    virtual void testFunction();
};

//class Base
//{
//
//public:
//    void testFunction();
//};



class Derived : public Base
{

public:
    void testFunction();

};

