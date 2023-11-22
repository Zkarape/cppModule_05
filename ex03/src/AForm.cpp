#include "../includes/AForm.hpp"

AForm::AForm(const std::string &n) : _name(n), _grade_to_sign(0), _grade_to_execute(0) {}

AForm::AForm() : _name("default"), _signed(0), _grade_to_sign(0), _grade_to_execute(0) {}

AForm::AForm(const std::string &name, bool sign, const int grSign, const int grExec) : _name(name),  _signed(sign), _grade_to_sign(grSign), _grade_to_execute(grExec)
{}

AForm::GradeException::GradeException(const std::string& message) : _errorMessage(message) {}

AForm::AForm(const AForm &f) : _name(f._name), _signed(f._signed), _grade_to_sign(f._grade_to_sign), _grade_to_execute(f._grade_to_execute)
{
    const int i = this->getGradeToSign();
    const int j = this->getGradeToExecute();
    if (i > 150 || j > 150)
        throw(GradeException("Grade too low exception\n"));
    else if (i < 1 || j < 1)
        throw(GradeException("Grade too high exception\n"));
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

AForm::GradeException::~GradeException() throw() {}