#include "../includes/AForm.hpp"

AForm::AForm() : _name("default"), _signed(0), _grade_to_sign(0), _grade_to_execute(0) {}

AForm::AForm(const std::string &name, bool sign, const int grSign, const int grExec) : _name(name),  _signed(sign), _grade_to_sign(grSign), _grade_to_execute(grExec)
{}

AForm::AForm(const AForm &f) : _name(f._name), _signed(f._signed), _grade_to_sign(f._grade_to_sign), _grade_to_execute(f._grade_to_execute)
{
    const int i = this->getGradeToSign();
    const int j = this->getGradeToExecute();
    if (i > 150 || j > 150)
        throw(AForm::GradeTooLowException());
    else if (i < 1 || j < 1)
        throw(AForm::GradeTooHighException());
}

AForm &AForm::operator=(const AForm &obj)
{
    (void)obj;
    return (*this);
}

int AForm::getGradeToSign() const
{
    return (_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
    return (_grade_to_execute);
}

int AForm::getSigned() const
{
    return (_signed);
}

const std::string &AForm::getName() const
{
    return (_name);
}

void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->getGradeToSign())
        throw(AForm::GradeTooLowException());
    else if (_signed == 0)
    {
        _signed = 1;
        std::cout << this->getName() << " AForm was signed by " << obj.getName() << std::endl;
    }
    else
        std::cout << "The AForm is already signed" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("The grade of AForm is too high.\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("The grade of AForm is too low.\n");
}

std::ostream &operator<<(std::ostream &out, AForm &obj)
{
    out << "Name is: " << obj.getName() << "\n"
        << "AForm is " << (obj.getSigned() ? "signed\n" : "not signed\n")
        << "Grade to Sign is: " << obj.getGradeToSign() << "\n"
        << "Grade to Execute is: " << obj.getGradeToExecute() << std::endl;
    return (out);
}

AForm::~AForm() {}
