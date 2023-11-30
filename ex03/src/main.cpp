#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int	main(void)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		delete rrf;
	}
	return (0);
}