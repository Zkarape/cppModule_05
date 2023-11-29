#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name)
{
    this->checkGrade(obj._grade);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    this->checkGrade(grade);
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

void Bureaucrat::setGrade(const int grade)
{
    _grade = grade;
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

void Bureaucrat::signForm(Form &form) const
{
    if (form.getSigned())
        std::cout << _name << " signed " << form.getName() << std::endl;
    else
    {
        std::cout << _name << " could not sign the form " << form.getName() << " because ";
        if (_grade > form.getGradeToSign())
            std::cout << "grade is low from sign grade" << std::endl;
        else if (_grade > form.getGradeToExecute()) //just to use this
            std::cout << "grade is low from execute grade" << std::endl;
    }
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