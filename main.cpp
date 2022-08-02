#include <destern/creation/singleton.h>
#include <iostream>
#include <thread>
#include <future>
#include <type_traits>

#include "include/destern/utils/remove-duplicates.h"
#include "include/destern/creation/factory-method.h"

struct Base
{
    virtual void f() const
    {
        std::cout << "Base\n";
    }
};

struct A : public Base
{
    virtual void f() const override
    {
        std::cout << "A\n";
    }
};

struct B : public Base
{
    virtual void f() const override
    {
        std::cout << "B\n";
    }
};


int main()
{
    auto * fct = new dst::FactoryMethod<Base>();
    auto x = fct->Create<B>();
    x->f();
    delete fct;

    return 0;
}