#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"

#define MAX_NUM 3
class AForm;

class Intern
{
    private:
        std::string _formNames;
    public:
        Intern();
        ~Intern();
        Intern(Intern const &src);
        Intern & operator = (Intern const &rhs);
        AForm   *makeForm(std::string nameForm, std::string targetForm);
};

#endif
