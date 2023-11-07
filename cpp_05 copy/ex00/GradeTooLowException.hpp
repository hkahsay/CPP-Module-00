#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include <exception>
#include "Bureaucrat.hpp"

class GradeTooLowException: public std::exception {

	private:
		int _grade;
	public:
	GradeTooLowException(void);// Default constructor
	GradeTooLowException(int grade);// Default constructor

	char const * what() const throw();
	int getGradeLow(void) const;
	void setGradeLow(int grade);
};



#endif