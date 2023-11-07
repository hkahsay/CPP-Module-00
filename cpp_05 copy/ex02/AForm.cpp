#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "AForm.hpp"

AForm:: AForm(): _name("<unnammed>")
{
    Bureaucrat temp;
    this->_grade_sign = temp.getGrade();
    this->_grade_exec = temp.getGrade();
    std::cout<<"default constructor called" << std::endl;
}

AForm:: AForm(std::string name, int grade): _name(name), _grade_sign(grade), _grade_exec(grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
}

AForm:: ~AForm()
{
    
}

AForm:: AForm(AForm const & src)
{
    std::cout<<"copy constructor called" << std::endl;
    *this = src;
}

AForm& AForm::operator = (const AForm& rhs)
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

std::string AForm::getName(void) const
{
    return this->_name;
}

int AForm::getGrade_sign(void) const
{
    return this->_grade_sign;
}

int AForm::getGrade_exec(void) const
{
    return this->_grade_exec;
}

void AForm::setName(std::string name)
{
    this->_name = name;
}

void AForm::setGrade_sign(int grade)
{
    this->_grade_sign = grade;
}

void AForm::setGrade_exec(int grade)
{
    this->_grade_exec = grade;
}

std::ostream& operator<< (std:: ostream & o, AForm const& rhs) {
    o << rhs.getName() << ", AForm grade to sign " << rhs.getGrade_sign() << std::endl;
    o << rhs.getName() << ", AForm grade to execute " << rhs.getGrade_exec() << std::endl;
    return o;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->_grade_sign)
        throw GradeTooLowException();
    else
        this->_signed = true;
}

void    excute(Bureaucrat const & executor) const
{
    if(executor.getGrade() > this->_grade_exec)
        throw GradeTooLowException();
    else
        std::cout << "Form " << this->_name << " is executed" << std::endl;
}