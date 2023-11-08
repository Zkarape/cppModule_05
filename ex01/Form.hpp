#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
private:
    const std::string _name;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_execute;
public:
    Form();
    int getGradeToSign() const;
    int getGradeToExecute() const;
    std::string &getName() const;
    ~Form();
};

std::ostream &operator<<(std::ostream &in, Form &obj);

#endif