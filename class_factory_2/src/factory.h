#ifndef FACTORY_H
#define FACTORY_H

#include "base.h"
#include <memory>
#include <string>
#include <map>
#include <functional>

class Factory
{
public:
    static std::shared_ptr<Base> CreateInstance(std::string& name)
    {
        return std::shared_ptr<Base>();
    }

    static Factory* Instance()
    {
        static Factory factory;
        return& factory;
    }

    std::map<std::string, std::function<Base*(void)>> factoryFunctionRegistry;

    void registerFactoryFunction(std::string& name, std::function<Base* (void)> factoryFunction)
    {
        factoryFunctionRegistry[name] = factoryFunction;
    }

    std::shared_ptr<Base> Create(std::string& name)
    {
        Base * instance = nullptr;

        // find name in the registry and call factory method.
        auto it = factoryFunctionRegistry.find(name);
        if(it != factoryFunctionRegistry.end())
            instance = it->second();

        // wrap instance in a shared ptr and return
        if(instance != nullptr)
            return std::shared_ptr<Base>(instance);
        else
            return nullptr;
    }


};

template<class T>
class Registrar {
public:
    Registrar(std::string className)
    {
        // register the class factory function
        Factory::Instance()->registerFactoryFunction(className,
                [](void) -> Base * { return new T();});
    }
};

#endif // FACTORY_H
