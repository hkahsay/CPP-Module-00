#include "GradeTooHighException.hpp"
#include "Bureaucrat.hpp"

GradeTooHighException:: GradeTooHighException(): _grade_high()
{
 
}
GradeTooHighException:: GradeTooHighException(int grade): _grade_high(grade)
{
  
}
//setters
void GradeTooHighException::setGradeHigh(int grade)
{
    Bureaucrat temp;
    grade = temp.getGrade();
    this->_grade_high = grade;
    
}
int GradeTooHighException::getGradeHigh(void) const
{
    return this->_grade_high;
}

char const * GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}


