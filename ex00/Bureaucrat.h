#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    int               _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    GradeTooHighException();
    GradeTooLowException();
    void incrementGrade();
    void decrementGrade();
    void checkGrade();
    const std::string &getName() const;
    int getGrade() const;
    ~Bureaucrat();
};

std::istream &operator<<(std::istream &in, Bureaucrat &obj);

#endif