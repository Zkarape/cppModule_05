#include "Bureaucrat.h"

void Bureaucrat::checkGrade()
{
    try
    {
        if (this->_grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    this->checkGrade();
}

const std::string &Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    --_grade;
    checkGrade(_grade);
}

void Bureaucrat::decrementGrade()
{
    ++_grade;
    checkGrade(_grade);
}

std::istream &operator<<(std::istream &in, Bureaucrat &obj)
{
    in << obj.getName() << ",  bureaucrat grade " << obj.getGrade() << std::endl;
    return (in);
}

Bureaucrat::~Bureaucrat() {}