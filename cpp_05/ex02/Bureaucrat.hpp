/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:25 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 15:11:58 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<string>
#include<iostream>
#include <iomanip>
// #include "GradeTooHighException.hpp"
// #include "GradeTooLowException.hpp"
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat {

	private:

	std::string _name;
	int _grade;

	public:

	Bureaucrat(void);// Default constructor
	~Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat& operator = (const Bureaucrat& rhs);
	std::string getName(void) const;
	void setName(std::string name);
	int getGrade(void) const;
	void setGrade(int grade);
	void incrementGrade(void);
	void decrementGrade(void);
	void executeForm(AForm const & form);
	class GradeTooHighException: public std::exception {
		public:

		virtual char const * what() const throw();
	

	};

	class GradeTooLowException: public std::exception {
		public:
		char const * what() const throw();
		
	
	};
	void signForm(AForm &form);
};

std::ostream& operator<< (std:: ostream & o, Bureaucrat const & rhs);


#endif