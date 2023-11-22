#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_default", 1, 145, 137), _target("Default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 1, 145, 137)
{
    _target = target;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy)
{
    this->_target = cpy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
        _target = obj._target;
    }
    return (*this);
}

void ShrubberyCreationForm::justDoAction() const
{
    std::ofstream oFile((_target + "_shrubbery").c_str());
    if (oFile.is_open())
    {
        oFile << "          ||          " << std::endl;
        oFile << "        ||| ||         " << std::endl;
        oFile << "     ||  |||  | ||        " << std::endl;
        oFile << "    |||   ||  |||||       " << std::endl;
        oFile << "     || ||  |  | ||    " << std::endl;
        oFile << "    | | ||  || |  ||  " << std::endl;
        oFile << "   ||  | | ||||  |||  " << std::endl;
        oFile << "     ||||||  |||||| " << std::endl;
        oFile << "      || || | |||" << std::endl;
        oFile << "          |||     " << std::endl;
        oFile << "          |||        " << std::endl;
        oFile.close();
    }
    else
    {
        std::cerr << "Error opening file" << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}