#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP


#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		std::string getTarget()const;
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm& operator = (PresidentialPardonForm const &rhs);
		bool	execute(Bureaucrat const &executor) const;
};
#endif