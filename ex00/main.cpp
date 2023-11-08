#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("hahaha", 3);
    std::cout << b;
    try
    {
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        std::cout << b;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

}