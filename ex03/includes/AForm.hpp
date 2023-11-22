#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <fstream>
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
    AForm(const std::string &name);
    AForm(const std::string &, bool, const int, const int);
    AForm &operator=(const AForm &);
    int getGradeToSign() const;
    int getGradeToExecute() const;
    int getSigned() const;
    const std::string &getName() const;
    void beSigned(Bureaucrat &);
    virtual void justDoAction() const = 0;
    void execute(Bureaucrat const &executor) const;
    class GradeException : public std::exception
    {
    private:
        std::string _errorMessage;
    public:
        GradeException(const std::string& message);
        // ~GradeException(); ??????????????????
        virtual ~GradeException() throw();
        const char *what() const throw();
    };
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream &in, AForm &obj);

#endif