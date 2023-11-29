#include "../includes/AForm.hpp"

int AForm::checkGradeToSign(const int i)
{
    if (i > 150)
        throw(AForm::GradeException("Grade is too low"));
    else if (i < 1)
        throw(AForm::GradeException("Grade is too high"));
    return (i);
}

int AForm::checkGradeToExecute(const int i)
{
    if (i > 150)
        throw(AForm::GradeException("Grade is too low"));
    else if (i < 1)
        throw(AForm::GradeException("Grade is too high"));
    return (i);
}

AForm::AForm() : _name("default"), _signed(0), _grade_to_sign(1), _grade_to_execute(1) {}

AForm::AForm(const std::string &name, bool sign, const int grSign, const int grExec) : _name(name),  _signed(sign), _grade_to_sign(checkGradeToSign(grSign)), _grade_to_execute(checkGradeToExecute(grExec)) {}

AForm::AForm(const AForm &f) : _name(f._name), _signed(f._signed), _grade_to_sign(checkGradeToSign(f._grade_to_sign)), _grade_to_execute(checkGradeToExecute(f._grade_to_execute)) {}

AForm::GradeException::GradeException(const std::string& message) : _errorMessage(message) {}


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
        throw(GradeException("Grade too high exception\n"));
    else if (_signed == 0)
    {
        _signed = 1;
        std::cout << this->getName() << " AForm was signed by " << obj.getName() << std::endl;
    }
    else
        std::cout << "The AForm is already signed" << std::endl;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (this->_signed == 0)
        throw(GradeException("Form is not signed\n"));
    else if (executor.getGrade() < this->_grade_to_execute)
        throw(GradeException("Bureaucrat's grade is not high enough\n"));
    this->justDoAction();
}

const char *AForm::GradeException::what() const throw()
{
    return (_errorMessage.c_str());
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
