# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class   ShrubberyCreationForm : public AForm {

    private:
  
    std::string _target_shrubbery;
    static const std::string _fileName;

    public:
    ShrubberyCreationForm(void);// Default constructor
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    std::string getTarget(void) const;
    void setTarget(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ShrubberyCreationForm& operator = (const ShrubberyCreationForm& rhs);
    void execute(Bureaucrat const & executor) const;
};
#endif