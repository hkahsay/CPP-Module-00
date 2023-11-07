#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"

class Bureaucrat {

	private:

	std::string _name;
	int _grade;

	public:

	Bureaucrat(void);// Default constructor
	~Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat& operator = (const Bureaucrat& rhs);
	std::string getName(void) const;
	void setName(std::string name);
	int getGrade(void) const;
	void setGrade(int grade);
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form &form);
};

std::ostream& operator<< (std:: ostream & o, Bureaucrat const & rhs);


#endif