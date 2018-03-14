#ifndef BASE_H
#define BASE_H

#include "factory.h"

#include <iostream>
#include <map>

class Base
{
public:
    Base();

    virtual void name()
    {
        std::cout << "Base" << std::endl;
    }

    static void registerType(const string& name, Factory *factory)
    {
        factories[name] = factory;
    }

    Base* Base::create(const std::string& name)
    {
        return factories[name]->create();
    }

private:
    static std::map<std::string, Factory*> factories;
};

#endif // BASE_H
