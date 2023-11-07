# ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;
class RobotomyRequestForm : public AForm 
{
    private:
    std::string _target_Robotomy;
    public:
    RobotomyRequestForm(void);// Default constructor
    ~RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const & src);
    std::string getTarget(void) const;
    void setTarget(std::string target);
    RobotomyRequestForm& operator = (const RobotomyRequestForm& rhs);

    void execute(Bureaucrat const & executor) const;
    class RobotomyException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };  
};

#endif