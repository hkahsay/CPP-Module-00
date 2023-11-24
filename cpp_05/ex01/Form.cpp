/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:52 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/23 17:04:22 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


Form:: Form(): _name("<unnammed>"), _signed(false), _grade_sign(150), _grade_exec(150)
{
  
}

Form:: Form(std::string name, int gradeSign, int gradeExec): _name(name), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
    try
    {
        if(gradeSign < 1 || gradeExec < 1)
            throw Form:: GradeTooHighException();
        else if(gradeSign > 150 || gradeExec > 150)
            throw Form:: GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

Form:: ~Form()
{
    
}

Form:: Form(Form const & src): _name(src.getName()), _signed(false), _grade_sign(src.getGrade_sign()), _grade_exec(src.getGrade_exec())
{
    return ;
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

char const*  Form:: GradeTooHighException::what() const throw()
{
    return "[Form]: Grade too high";
}

char const*  Form:: GradeTooLowException::what() const throw()
{
    return "[Form]: Grade too low";
}

std::ostream& operator<< (std:: ostream & o, Form const& rhs) {
    o << "Form name: " << rhs.getName()
		<< " Signed: " << (rhs.getSigned() ? "true" : "false") << std::endl;
    o << rhs.getName() << ", Form grade to sign " << rhs.getGrade_sign() << std::endl;
    o << rhs.getName() << ", Form grade to execute " << rhs.getGrade_exec() << std::endl;
    return o;
}

bool Form::beSigned(Bureaucrat &bureaucrat)
{
    if (_signed)
    {
        std::cout<< this->getName() << " is already signed the form"<<std::endl;
        return true;
    }
    if(this->_grade_sign < bureaucrat.getGrade())
        throw Form:: GradeTooLowException();
    _signed = true;
    return false;
}
