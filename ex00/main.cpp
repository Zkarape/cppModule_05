#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("hahaha", 150);
    std::cout << b;
    try
    {
        b.incrementGrade();
        b.incrementGrade();
        b.decrementGrade();
        b.incrementGrade();
        std::cout << b;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}