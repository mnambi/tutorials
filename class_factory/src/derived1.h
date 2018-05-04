#ifndef DERIVED1_H
#define DERIVED1_H

#include "base.h"

class Derived1 : public Base
{
public:
    virtual void name()
    {
        std::cout << "Class Derived 1" << std::endl;
    }
};



#endif // DERIVED1_H
