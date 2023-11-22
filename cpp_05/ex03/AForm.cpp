/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:15 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 14:46:58 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


AForm:: AForm(): _name("<unnammed>")
{
    Bureaucrat temp;
    this->_grade_sign = temp.getGrade();
    this->_grade_exec = temp.getGrade();
    std::cout<<"default constructor called" << std::endl;
}

AForm:: AForm(std::string name, int gradeSign, int gradeExec): _name(name), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
    if(gradeSign < 1 || gradeExec < 1)
        throw AForm:: GradeTooHighException();
    else if(gradeSign > 150 || gradeExec > 150)
        throw AForm:: GradeTooLowException();
}

AForm:: ~AForm()
{
    
}

AForm:: AForm(AForm const & src): _name(src._name), _signed(src.getSigned()), _grade_sign(src.getGrade_sign()), _grade_exec(src.getGrade_exec())
{
    if (this->_grade_sign < 1 || this->_grade_exec < 1)
    {
        throw AForm:: GradeTooHighException();
    }
    else if (this->_grade_sign > 150 || this->_grade_exec > 150)
    {
        throw AForm:: GradeTooLowException();
    }
}

AForm& AForm::operator = (const AForm& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_signed = rhs.getSigned();
        this->_grade_sign = rhs.getGrade_sign();
        this->_grade_exec = rhs.getGrade_exec();
    }
    return *this;
}

std::string AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getSigned(void) const
{
    return this->_signed;
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

char const*  AForm:: GradeTooHighException:: what() const throw()
{
    return "[AForm]: Grade too high";
}

char const*  AForm:: GradeTooLowException:: what() const throw()
{
    return "[AForm]: Grade too low";
}

std::ostream& operator<< (std:: ostream & o, AForm const& rhs) {
    o << rhs.getName() << ", AForm grade to sign " << rhs.getGrade_sign() << std::endl;
    o << rhs.getName() << ", AForm grade to execute " << rhs.getGrade_exec() << std::endl;
    return o;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->_grade_sign)
    {
        std::cout<<" this->_grade_sign "<<this->_grade_sign<<std::endl;
        throw AForm:: GradeTooLowException();
    }
    else
    {
        std::cout<<" this->_grade_sign true: "<<this->_grade_sign<<std::endl;
        
        this->_signed = true;
    }
}

char const*  AForm:: NotSignedException:: what() const throw()
{
    return "[AForm]: Form is not signed";
}