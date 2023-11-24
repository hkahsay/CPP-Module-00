#include "PresidentialPardonForm.hpp"

PresidentialPardonForm:: PresidentialPardonForm()
: AForm("Presidential target", 25, 5), _target("default")
{

}


PresidentialPardonForm:: PresidentialPardonForm(std::string target)
: AForm("Presidential target", 25, 5), _target(target)
{

}

PresidentialPardonForm:: ~PresidentialPardonForm()
{

}
PresidentialPardonForm:: PresidentialPardonForm(PresidentialPardonForm const &src)
: AForm(src.getName(), src.getGrade_sign(), src.getGrade_exec())
{

}

std::string PresidentialPardonForm:: getTarget()const
{
    return this->_target;
}

PresidentialPardonForm& PresidentialPardonForm:: operator = (PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
    {
        this->_target = rhs.getTarget();
    }
    return *this;
}

void	PresidentialPardonForm:: execute(Bureaucrat const & executor) const
{
	try
	{
		if (getSigned() == false)
			throw	AForm::NotSignedException();
		else if (executor.getGrade() <= this->getGrade_exec())
		{
			std::cout<< this->_target<< " has been pardoned by Zaphod Beeblebrox "
				<<std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}