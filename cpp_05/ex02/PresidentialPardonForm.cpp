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

bool	PresidentialPardonForm:: execute(Bureaucrat const & executor) const
{
	// if ( _signGrade < executor.getGrade())
	try
	{
		if (getSigned() == true)
		{
			if (executor.getGrade() <= this->getGrade_exec())
			{
				std::cout<< this->_target<< " has been pardoned by Zaphod Beeblebrox "
					<<std::endl;
					return true;
			}
			else
				throw AForm::GradeTooLowException();
		}
		else
			throw	AForm::NotSignedException();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return false;
}
