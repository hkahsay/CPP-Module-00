/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:15 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/27 12:30:25 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


AForm:: AForm(): _name("<unnammed>"), _signed(false), _grade_sign(150), _grade_exec(150)
{
  
}

AForm:: AForm(std::string name, int gradeSign, int gradeExec): _name(name), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
    try
    {
        if(gradeSign < 1 || gradeExec < 1)
            throw AForm:: GradeTooHighException();
        else if(gradeSign > 150 || gradeExec > 150)
            throw AForm:: GradeTooLowException();  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

AForm:: ~AForm()
{
    
}

AForm:: AForm(AForm const & src): _name(src._name), _signed(src.getSigned()), _grade_sign(src.getGrade_sign()), _grade_exec(src.getGrade_exec())
{
    return ;
    
}

AForm& AForm::operator = (const AForm& rhs)
{
    if (this != &rhs)
        this->_signed = rhs.getSigned();
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

char const*  AForm:: GradeTooHighException:: what() const throw()
{
    return "[AForm]: Grade too high";
}

char const*  AForm:: GradeTooLowException:: what() const throw()
{
    return "[AForm]: Grade too low";
}

std::ostream& operator<< (std:: ostream & o, AForm const& rhs) {
    o << "Form name: " << rhs.getName()
    << "Signed: " << (rhs.getSigned() ? "true" : "false") << std::endl;
    o << rhs.getName() << ", AForm grade to sign " << rhs.getGrade_sign() << std::endl;
    o << rhs.getName() << ", AForm grade to execute " << rhs.getGrade_exec() << std::endl;
    return o;
}

bool AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (_signed)
    {
        std::cout<< this->getName() << " is already signed the form"<<std::endl;
        return true;
    }
    if(this->_grade_sign < bureaucrat.getGrade())
    {
        throw AForm:: GradeTooLowException();

    }
    _signed = true;
    return false;
}

char const*  AForm:: NotSignedException:: what() const throw()
{
    return "[AForm]: Form is not signed";
}