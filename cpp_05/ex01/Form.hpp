/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/27 12:22:17 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {

	private:

	const std::string _name;
	bool _signed;
	const int _grade_sign;
	const int _grade_exec;

	public:

	Form(void);// Default constructor
	~Form(void);
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const & src);
	Form& operator = (const Form& rhs);
	std::string getName(void) const;
	bool	getSigned(void) const;
	int getGrade_sign(void) const;
	int getGrade_exec(void) const;
	bool beSigned(Bureaucrat &bureaucrat);
	class GradeTooHighException: public std::exception {
		public:

		virtual char const * what() const throw();
	

	};
	class GradeTooLowException: public std::exception {
		public:
		char const * what() const throw();
	};
};

std::ostream& operator<< (std:: ostream & o, Form const & rhs);


#endif