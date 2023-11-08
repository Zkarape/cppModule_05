#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    void incrementGrade();
    void decrementGrade();
    void checkGrade();
    const std::string &getName() const;
    int getGrade() const;
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        { 
            return "Grade is too high.\n";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        { 
            return "Grade is too low.\n";
        }
    };
    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &in, Bureaucrat &obj);

#endif