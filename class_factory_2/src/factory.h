#ifndef FACTORY_H
#define FACTORY_H

#include "base.h"

class Factory
{
public:
    Factory();

    virtual Base *create() = 0;
};

#endif // FACTORY_H
