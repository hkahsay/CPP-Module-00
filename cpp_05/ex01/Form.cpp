#include "Bureaucrat.hpp"
#include "Form.hpp"


Form:: Form(): _name("<unnammed>"), _signed(false), _grade_sign(150), _grade_exec(150)
{
  
}

Form:: Form(std::string name, int gradeSign, int gradeExec): _name(name), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
    if(_grade_sign < 1 || _grade_exec < 1)
        throw Form:: GradeTooHighException();
    else if(_grade_sign > 150 || _grade_exec > 150)
        throw Form:: GradeTooLowException();
}

Form:: ~Form()
{
    
}

Form:: Form(Form const & src): _name(src.getName()), _signed(false), _grade_sign(src.getGrade_sign()), _grade_exec(src.getGrade_exec())
{
    if (this->_grade_sign < 1 || this->_grade_exec < 1)
    {
        throw Form:: GradeTooHighException();
    }
    else if (this->_grade_sign > 150 || this->_grade_exec > 150)
    {
        throw Form:: GradeTooLowException();
    }
}

Form& Form::operator = (const Form& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_grade_sign = rhs.getGrade_sign();
        this->_grade_exec = rhs.getGrade_exec();
        this->_signed = rhs.getSigned();
    }
    return *this;
}

std::string Form::getName(void) const
{
    return this->_name;
}

bool Form::getSigned(void) const
{
    return this->_signed;
}

int Form::getGrade_sign(void) const
{
    return this->_grade_sign;
}

int Form::getGrade_exec(void) const
{
    return this->_grade_exec;
}

void Form::setName(std::string name)
{
    this->_name = name;
}

void Form::setGrade_sign(int grade)
{
    this->_grade_sign = grade;
}

void Form::setGrade_exec(int grade)
{
    this->_grade_exec = grade;
}

char const*  Form:: GradeTooHighException:: what() const throw()
{
    return "[Form]: Grade too high";
}

char const*  Form:: GradeTooLowException:: what() const throw()
{
    return "[Form]: Grade too low";
}

std::ostream& operator<< (std:: ostream & o, Form const& rhs) {
    o << rhs.getName() << ", Form grade to sign " << rhs.getGrade_sign() << std::endl;
    o << rhs.getName() << ", Form grade to execute " << rhs.getGrade_exec() << std::endl;
    return o;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->_grade_sign)
        throw Bureaucrat:: GradeTooLowException();
    else
        this->_signed = true;
}

