#ifndef DERIVED1_H
#define DERIVED1_H


class Derived1
{
public:
    Derived1();

    virtual void name()
    {
        std::cout << "Derived 1" << std::endl;
    }
};

#endif // DERIVED1_H
