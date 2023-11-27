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

bool	RobotomyRequestForm:: execute(Bureaucrat const & executor) const
{
	try
	{
		if (this->getSigned() == true)
		{
			if (executor.getGrade() <= this->getGrade_exec())
			{
				srand(time(NULL));
				int random = rand()%2;
				if(random != 0)
				{
					std::cout<< "vouvouuuuuuu"<<std::endl;
					std::cout<< this->_targetRobotomy<< " has been robotomized "<<
					"successfully"
					<<std::endl;

				}
				else
					std::cout <<"Robotomized is failed"<<std::endl;
				return true;
			}
			else
				throw AForm ::GradeTooLowException();

		}
		else
			throw	AForm:: NotSignedException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return false;
	
}

