#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm_default", 0, 72, 45), _target("Default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 0, 72, 45)
{
    _target = target;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy)
{
    this->_target = cpy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this != &obj)
    {
        _target = obj._target;
    }
    return (*this);
}

void RobotomyRequestForm::justDoAction() const
{
    std::srand(std::time(NULL));

    std::cout << "Drrrrrrrrrrrrrrrr" << "\n";
    int randomNumber = std::rand() % 100;
    if (randomNumber % 2 == 0)
    {
        std::cout << "Robotomy was successful for target " << _target << ".\n";
    }
    else
    {
        std::cout << "Robotomy failed for target " << _target << ".\n";
    }
}

RobotomyRequestForm::~RobotomyRequestForm() {}