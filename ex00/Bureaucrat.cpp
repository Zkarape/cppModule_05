#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade()
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    this->checkGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this == &obj)
        return (*this);
    this->_grade = obj._grade;
    return (*this);
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
    checkGrade();
}

void Bureaucrat::decrementGrade()
{
    ++_grade;
    checkGrade();
}

std::ostream &operator<<(std::ostream &in, Bureaucrat &obj)
{
    in << obj.getName() << ",  bureaucrat grade " << obj.getGrade() << std::endl;
    return (in);
}

Bureaucrat::~Bureaucrat() {}