#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    this->checkGrade(_grade);
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
    this->checkGrade(_grade - 1);
    --_grade;
}

void Bureaucrat::decrementGrade()
{
    this->checkGrade(_grade + 1);
    ++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high.\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low.\n";
}

std::ostream &operator<<(std::ostream &in, Bureaucrat &obj)
{
    in << obj.getName() << ",  bureaucrat grade " << obj.getGrade() << std::endl;
    return (in);
}

Bureaucrat::~Bureaucrat() {}