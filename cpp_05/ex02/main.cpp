/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:29 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 17:14:48 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
	try {
		Bureaucrat b("Bob",6);
		// Bureaucrat c("Bob",36);

		ShrubberyCreationForm f2("home");
		RobotomyRequestForm f3("home");
		RobotomyRequestForm f4(f3);
		PresidentialPardonForm f6("home");
		// ShrubberyCreationForm f(b.getName());
		// f2.beSigned(b);
		f3.beSigned(b);
		f4.beSigned(b);
		f6.beSigned(b);

	
		b.signForm(f2);
		b.signForm(f3);
		b.signForm(f4);

		
		// std::cout <<"f2 \n"<< f2 << std::endl;
		std::cout << b << std::endl;

		f2.execute(b);
		f3.execute(b);
		f4.execute(b);
		f6.execute(b);

		std::cout <<"f2 :"<< f2 << std::endl;

		std::cout <<"f4 :"<< f4 << std::endl;
		std::cout <<"f3 :"<< f3 << std::endl;
		


		b.executeForm(f2);
		b.executeForm(f3);
		
		// std::cout <<"f3"<< f3 << std::endl;

		// c.incrementGrade();
		// b.decrementGrade();
		// std::cout << c << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
