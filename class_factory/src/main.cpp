#include <iostream>
#include "factory.h"
#include "base.h"

/**
* @file main.cpp 
* @author mnambi
*/

int main(int argc, char** argv)
{
    std::string name = "Derived1";
    auto one = Factory<Base>::Instance()->Create(name);
    name = "Derived2";
    auto two = Factory<Base>::Instance()->Create(name);

    one->name();
    two->name();

    return 0;
}
