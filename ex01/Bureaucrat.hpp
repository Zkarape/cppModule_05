#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &);
    Bureaucrat &operator=(const Bureaucrat &);
    const std::string &getName() const;
    int getGrade() const;
    void setGrade(const int grade);
    void incrementGrade();
    void decrementGrade();
    void checkGrade(int);
    void signForm(Form &) const;
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
    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &in, Bureaucrat &obj);

#endif