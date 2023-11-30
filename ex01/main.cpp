#include "Bureaucrat.hpp"

int main()
{
   Bureaucrat b("haha", 2);
   Form f("yey", 0, 4, 500);

   try
   {
        f.beSigned(b);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
}