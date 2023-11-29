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
    Bureaucrat(const Bureaucrat &);
    Bureaucrat &operator=(const Bureaucrat &);
    void incrementGrade();
    void decrementGrade();
    void checkGrade(int);
    const std::string &getName() const;
    int getGrade() const;
    void setGrade(const int grade);
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