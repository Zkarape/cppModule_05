#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_execute; // for what????

public:
    Form();
    Form(const Form &);
    Form(const std::string &, bool, const int, const int);
    Form &operator=(const Form &);
    int getGradeToSign() const;
    int getGradeToExecute() const;
    int getSigned() const;
    const std::string &getName() const;
    void beSigned(Bureaucrat &);
    int checkGradeToSign(const int i);
    int checkGradeToExecute(const int i);
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
    ~Form();
};

std::ostream &operator<<(std::ostream &in, Form &obj);

#endif