#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	Bureaucrat *b = new Bureaucrat("Bureaucrat_b", 130);
	ShrubberyCreationForm sh = ShrubberyCreationForm();
	PresidentialPardonForm *pr = new PresidentialPardonForm();

	sh.justDoAction();
	pr->execute(*b);
	return (0);
}