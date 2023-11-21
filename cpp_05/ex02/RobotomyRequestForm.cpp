#include "RobotomyRequestForm.hpp"

RobotomyRequestForm:: RobotomyRequestForm(): AForm("_targetRobotomy",72, 45), _targetRobotomy("default")
{
	srand(time(NULL));

}

RobotomyRequestForm:: RobotomyRequestForm(std::string target): AForm("_targetRobotomy",72, 45),_targetRobotomy(target)
{
	srand(time(NULL));
}

RobotomyRequestForm:: RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src.getTarget(),72, 45)
{

}

std::string RobotomyRequestForm:: getTarget()const
{
    return this->_targetRobotomy;
}

RobotomyRequestForm& RobotomyRequestForm:: operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		this->_targetRobotomy = rhs.getTarget();
	}
	return *this;
}