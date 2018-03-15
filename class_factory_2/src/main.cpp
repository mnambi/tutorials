#include <iostream>
#include "factory.h"
#include "base.h"
#include "derived1.h"

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
