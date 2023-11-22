#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
   Bureaucrat b("haha", 2);
   ShrubberyCreationForm s;

   try
   {
        s.justDoAction();
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
}