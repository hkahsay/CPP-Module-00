#ifndef AFORM_HPP
#define AFORM_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {

	private:

	std::string _name;
	bool _signed;
	int _grade_sign;
	int _grade_exec;

	public:

	AForm(void);// Default constructor
	~AForm(void);
	AForm(std::string name, int grade);
	AForm(AForm const & src);
	AForm& operator = (const AForm& rhs);
	std::string getName(void) const;
	void setName(std::string name);
	int getGrade_sign(void) const;
	int getGrade_exec(void) const;
	void setGrade_sign(int grade);
	void setGrade_exec(int grade);
	//Abstruct function
	virtual void execute(Bureaucrat const & executor) const = 0;
	void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<< (std:: ostream & o, AForm const & rhs);


#endif