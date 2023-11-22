#include "RobotomyRequestForm.hpp"

RobotomyRequestForm:: RobotomyRequestForm(): AForm("_targetRobotomy",72, 45), _targetRobotomy("default")
{
	srand(time(NULL));

}

RobotomyRequestForm:: RobotomyRequestForm(std::string target): AForm("_targetRobotomy",72, 45),_targetRobotomy(target)
{
	srand(time(NULL));
}

RobotomyRequestForm:: RobotomyRequestForm(RobotomyRequestForm const &src)
: AForm(src.getName(), src.getGrade_sign(), src.getGrade_exec())
{

}

RobotomyRequestForm:: ~RobotomyRequestForm()
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

void	RobotomyRequestForm:: execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw	AForm:: NotSignedException();
	else if (executor.getGrade() <= this->getGrade_exec())
	{
		std::cout<< "vouvouuuuuuu"<<std::endl;
		srand(time(NULL));
		int random = rand()%2;
		if(random != 0)
		{
			std::cout<< this->_targetRobotomy<< " has been robotomized "<<
			"successfully"
			<<std::endl;

		}
		else
			std::cout <<"Robotomized is failed"<<std::endl;
	}
	else
		throw AForm ::GradeTooLowException();
	
	
}

