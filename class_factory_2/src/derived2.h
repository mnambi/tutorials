#ifndef DERIVED2_H
#define DERIVED2_H

#include "base.h"

class Derived2 : public Base
{
public:

    virtual void name()
    {
        std::cout << "Class Derived 2" << std::endl;
    }
};



#endif // DERIVED2_H
