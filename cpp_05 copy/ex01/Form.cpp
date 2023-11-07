#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"

Form:: Form(): _name("<unnammed>")
{
    Bureaucrat temp;
    this->_grade_sign = temp.getGrade();
    this->_grade_exec = temp.getGrade();
    std::cout<<"default constructor called" << std::endl;
}

Form:: Form(std::string name, int grade): _name(name), _grade_sign(grade), _grade_exec(grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
}

Form:: ~Form()
{
    
}

Form:: Form(Form const & src)
{
    std::cout<<"copy constructor called" << std::endl;
    *this = src;
}

Form& Form::operator = (const Form& rhs)
{
    std::cout<<"Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_grade_sign = rhs._grade_sign;
        this->_grade_exec = rhs._grade_exec;
    }
    return *this;
}

std::string Form::getName(void) const
{
    return this->_name;
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

std::ostream& operator<< (std:: ostream & o, Form const& rhs) {
    o << rhs.getName() << ", Form grade to sign " << rhs.getGrade_sign() << std::endl;
    o << rhs.getName() << ", Form grade to execute " << rhs.getGrade_exec() << std::endl;
    return o;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->_grade_sign)
        throw GradeTooLowException();
    else
        this->_signed = true;
}

