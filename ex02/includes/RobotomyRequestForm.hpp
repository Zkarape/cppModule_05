#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &);
    RobotomyRequestForm(const RobotomyRequestForm &);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &);
    void justDoAction() const;
    ~RobotomyRequestForm();
};

#endif