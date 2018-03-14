#include <iostream>
#include "factory.h"

int main(int argc, char** argv)
{
    std::string name = "Derived1";
    auto one = Factory::Instance()->Create(name);
    name = "Derived2";
    auto two = Factory::Instance()->Create(name);

    one->name();
    two->name();

    return 0;
}
