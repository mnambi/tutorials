#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <string>
#include <map>
#include <functional>

template<class T>
class Factory
{
public:
    static Factory* Instance()
    {
        static Factory factory;
        return& factory;
    }

    void registerFactory(std::string& name, std::function<T* (void)> factoryFunction)
    {
        factoryMap[name] = factoryFunction;
    }

    std::shared_ptr<T> Create(std::string& name)
    {
        T * instance = nullptr;

        // find name in the registry and call factory method.
        auto it = factoryMap.find(name);
        if(it != factoryMap.end())
            instance = it->second();

        // wrap instance in a shared ptr and return
        if(instance != nullptr)
            return std::shared_ptr<T>(instance);
        else
            return nullptr;
    }


private:
    std::map<std::string, std::function<T*(void)>> factoryMap;
};

template<class T1, class T2>
class Registrar {
public:
    Registrar(std::string className)
    {
        // register the class factory function
        Factory<T1>::Instance()->registerFactory(className,
                [](void) -> T1 * { return new T2();});
    }
};

#endif // FACTORY_H
