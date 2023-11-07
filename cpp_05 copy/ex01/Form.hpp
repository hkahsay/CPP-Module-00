#ifndef FORM_HPP
#define FORM_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {

	private:

	std::string _name;
	bool _signed;
	int _grade_sign;
	int _grade_exec;

	public:

	Form(void);// Default constructor
	~Form(void);
	Form(std::string name, int grade);
	Form(Form const & src);
	Form& operator = (const Form& rhs);
	std::string getName(void) const;
	void setName(std::string name);
	int getGrade_sign(void) const;
	int getGrade_exec(void) const;
	void setGrade_sign(int grade);
	void setGrade_exec(int grade);
	void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<< (std:: ostream & o, Form const & rhs);


#endif