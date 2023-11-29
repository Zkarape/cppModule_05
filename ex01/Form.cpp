#include "Form.hpp"

int Form::checkGradeToSign(const int i)
{
    if (i > 150)
        throw(Form::GradeTooLowException());
    else if (i < 1)
        throw(Form::GradeTooHighException());
    return (i);
}

int Form::checkGradeToExecute(const int i)
{
    if (i > 150)
        throw(Form::GradeTooLowException());
    else if (i < 1)
        throw(Form::GradeTooHighException());
    return (i);
}


Form::Form() : _name("default"), _signed(0), _grade_to_sign(1), _grade_to_execute(1) {}

Form::Form(const std::string &name, bool sign, const int grSign, const int grExec) : _name(name),  _signed(sign), _grade_to_sign(checkGradeToSign(grSign)), _grade_to_execute(checkGradeToExecute(grExec)) {}

Form::Form(const Form &f) : _name(f._name), _signed(f._signed), _grade_to_sign(checkGradeToSign(f._grade_to_sign)), _grade_to_execute(checkGradeToExecute(f._grade_to_execute))
{}

Form &Form::operator=(const Form &obj)
{
    (void)obj;
    return (*this);
}

int Form::getGradeToSign() const
{
    return (_grade_to_sign);
}

int Form::getGradeToExecute() const
{
    return (_grade_to_execute);
}

int Form::getSigned() const
{
    return (_signed);
}

const std::string &Form::getName() const
{
    return (_name);
}

void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->getGradeToSign())
        throw(Form::GradeTooLowException());
    else if (_signed == 0)
    {
        _signed = 1;
        std::cout << this->getName() << " Form was signed by " << obj.getName() << std::endl;
    }
    else
        std::cout << "The Form is already signed" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("The grade of form is too high.\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("The grade of form is too low.\n");
}

std::ostream &operator<<(std::ostream &out, Form &obj)
{
    out << "Name is: " << obj.getName() << "\n"
        << "Form is " << (obj.getSigned() ? "signed\n" : "not signed\n")
        << "Grade to Sign is: " << obj.getGradeToSign() << "\n"
        << "Grade to Execute is: " << obj.getGradeToExecute() << std::endl;
    return (out);
}

Form::~Form() {}
