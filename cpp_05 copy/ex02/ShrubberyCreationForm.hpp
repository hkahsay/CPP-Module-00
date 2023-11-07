# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   ShrubberyCreationForm : public AForm {

    private:
    int _grade_sign;
    int _grade_exec;
    public:

    ShrubberyCreationForm(void);// Default constructor
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string name, int grade);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ShrubberyCreationForm& operator = (const ShrubberyCreationForm& rhs);
    void execute(Bureaucrat const & executor) const;
};
#endif