#include "Form.hpp"

Form::Form() : _name("default"), _grade_to_execute(0), _grade_to_sign(0) {}

int Form::getGradeToSign() const
{
    return (_grade_to_sign);
}

int Form::getGradeToExecute() const
{
    return (_grade_to_execute);
}

bool Form::getSigned() const
{
    return (_signed);
}

const std::string &Form::getName() const
{
    return (_name);
}

const char *Form::what() throw()
{
    return ("The grade of form is too ");
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
