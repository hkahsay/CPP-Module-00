#include "RobotomyRequestForm.hpp"

RobotomyRequestForm:: RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target_Robotomy("default")
{
    srand(time(NULL));
}

RobotomyRequestForm:: RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target_Robotomy(target)
{
    srand(time(NULL));
}

RobotomyRequestForm:: RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src)
{
    *this = src;
}

RobotomyRequestForm:: ~RobotomyRequestForm()
{
    
}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
    {
        this->_target_Robotomy = rhs.getTarget();
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return this->_target_Robotomy;
}

void    RobotomyRequestForm::setTarget(std::string target)
{
    this->_target_Robotomy = target;
}

char const* RobotomyRequestForm::RobotomyException::what() const throw()
{
    return "Robotomy failed!";
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
    if(getSigned() == false)
        throw AForm::NotSignedException(); 
    else if (executor.getGrade() <= this->getGrade_exec())
    {
        std::cout << "Drilling noises..." << std::endl;
        //has been robotomized successfully 50% of the time
        if (rand() % 2 == 0)
            std::cout << this->_target_Robotomy << " has been robotomized successfully!" << std::endl;
        else
            throw RobotomyException();
    }
    else
        throw AForm::GradeTooLowException(
                AZXDFCGHJ,NK.M/LP';YTRE