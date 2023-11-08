#include <iostream>

class base
{
public:
    virtual void function() throw()
    {
        std::cout << "Base's function()\n";
    }
    void function(int a)
    {
    }
};

class derived
{
public:
    void function() noexcept
    {
        std::cout << "Derived's function()\n";
    }
    void function() const
    {
        std::cout << "Derived's function()2\n";
    }
    void function()
    {
        std::cout << "Derived's function()2\n";
    }
};

int main()
{
    // base *b;
    // derived d;
    // // b = &d;
    // // b->function();
    // d.function();
}