#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
	std::string _targetRobotomy;
	public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	std::string getTarget()const;
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm & operator = (RobotomyRequestForm const & rhs);
	bool	execute(Bureaucrat const &executor)const;

};

#endif