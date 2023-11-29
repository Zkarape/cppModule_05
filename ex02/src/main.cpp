#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
   Bureaucrat b("haha", 2);
   ShrubberyCreationForm s;
   RobotomyRequestForm r;
   PresidentialPardonForm p;

   try
   {
      s.justDoAction();
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
}