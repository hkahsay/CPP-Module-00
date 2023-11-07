#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

GradeTooLowException:: GradeTooLowException(): _grade(0)
{
    
}

GradeTooLowException:: GradeTooLowException(int grade): _grade(grade)
{
  
}

void GradeTooLowException::setGradeLow(int grade)
{
    Bureaucrat temp;
    grade = temp.getGrade();
    this->_grade = grade;
    
}

char const * GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

int GradeTooLowException::getGradeLow(void) const
{
    return this->_grade;
}