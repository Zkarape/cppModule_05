#include "../includes/Intern.hpp"

Intern::Intern() {};

AForm *makePresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *makeRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *makeShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
    AForm *(*formsObjs[])(const std::string &formTarget) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
    std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << " now" << std::endl;
			return (formsObjs[i](formTarget));
		}
	}
	std::cout << "Intern cannot create a form called " << formName << std::endl;
	return (NULL);
}

Intern::~Intern() {}