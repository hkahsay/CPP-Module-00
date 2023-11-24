/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:21 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/23 17:22:46 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat:: Bureaucrat(): _name("<unnammed>"), _grade(150)
{
    std::cout<<"default constructor called" << std::endl;
}

Bureaucrat:: Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    try 
    {
        if(grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if(grade > 150)
            throw Bureaucrat::GradeTooLowException();
        
    }
    catch(const std::exception& e)
    {
		std::cerr << e.what() << std::endl;
    
    }
}

Bureaucrat:: Bureaucrat(Bureaucrat const & src)
{
    std::cout<<"copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& rhs)
{
    std::cout<<"Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_grade = rhs._grade;
    }
    return *this;
}

Bureaucrat:: ~Bureaucrat()
{
    
}

std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::setName(std::string name)
{
    this->_name = name;
}

void Bureaucrat::setGrade(int grade)
{
    this->_grade = grade;
}

std::ostream& operator<< (std:: ostream & o, Bureaucrat const& rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return o;
}

	//increment grade
void Bureaucrat::incrementGrade(void)
{
    try
    {
        if(this->_grade < 1 || this->_grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->_grade--;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
}

//decrement grade
void Bureaucrat::decrementGrade(void)
{
    try
    {
        if(this->_grade > 150 || this->_grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->_grade++;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
}

char const * Bureaucrat:: GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

char const * Bureaucrat:: GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}


void    Bureaucrat:: signForm(AForm &form)
{
   try
    {
        if(!form.beSigned(*this))
            std::cout << this->getName() << " signs " << form.getName() << std::endl;
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cout << this->getName() << " cannot sign " << form.getName() 
        << " because " << e.what() << std::endl;
    } 
}

void    Bureaucrat:: executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout<<this->getName()
        <<" excuted " << form.getName()
        <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout<<this->getName()
        <<" can not excuted " << form.getName()
        <<std::endl;
    }
    
}