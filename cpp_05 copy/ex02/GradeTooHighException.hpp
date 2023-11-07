#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP

#include<string>
#include<iostream>
#include <iomanip>

class GradeTooHighException: public std::exception {

	private:
		int _grade_high;
	public:

	// default constructor
	GradeTooHighException(void);
	GradeTooHighException(int grade);
	int getGradeHigh(void) const;
	void setGradeHigh(int grade);
	virtual char const * what() const throw();

};

std:: ostream & operator<<(std::ostream & o, GradeTooHighException const & rhs);


#endif