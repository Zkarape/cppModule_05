#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_execute;

public:
    AForm();
    AForm(const AForm &);
    AForm(const std::string &, bool, const int, const int);
    AForm &operator=(const AForm &);
    int getGradeToSign() const;
    int getGradeToExecute() const;
    int getSigned() const;
    const std::string &getName() const;
    void beSigned(Bureaucrat &);
    virtual void justDoIt() = 0;
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream &in, AForm &obj);

#endif