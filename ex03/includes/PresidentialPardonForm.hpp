#ifndef PresidentialPardonForm_hpp
#define PresidentialPardonForm_hpp

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &);
    PresidentialPardonForm(const PresidentialPardonForm &);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &);
    void justDoAction() const;
    ~PresidentialPardonForm();
};

#endif