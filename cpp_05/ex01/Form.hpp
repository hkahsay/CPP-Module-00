/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:56 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/23 15:26:50 by hkahsay          ###   ########.fr       */
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

	std::string _name;
	bool _signed;
	int _grade_sign;
	int _grade_exec;

	public:

	Form(void);// Default constructor
	~Form(void);
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const & src);
	Form& operator = (const Form& rhs);
	std::string getName(void) const;
	void setName(std::string name);
	bool	getSigned(void) const;
	int getGrade_sign(void) const;
	int getGrade_exec(void) const;
	void setGrade_sign(int grade);
	void setGrade_exec(int grade);
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