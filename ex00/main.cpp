#include "Bureaucrat.h"

int main()
{
    Bureaucrat b("hahaha", 3);
    std::cout << b;
    catch (const std::exception &e)
    {
        std::cerr << "Exception " << e.what() << '\n';
    }
}