/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:29 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/24 11:37:18 by hkahsay          ###   ########.fr       */
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

		Bureaucrat b("Bob",4);
		Bureaucrat c("lucas",3);
		Bureaucrat d("tom", 140);


		ShrubberyCreationForm f2("home");
		RobotomyRequestForm f3("office");
		RobotomyRequestForm f4(f3);
		PresidentialPardonForm f6("work");
		PresidentialPardonForm f7("home");

		b.signForm(f2);
		b.signForm(f2);
		b.signForm(f3);
		b.signForm(f4);
		b.signForm(f6);
		b.signForm(f7);


		// std::cout <<"f2 :"<< f2 << std::endl;
		// std::cout <<"f4 :"<< f4 << std::endl;
		// std::cout <<"f3 :"<< f3 << std::endl;
		// std::cout <<"f6 :"<< f6 << std::endl;
		// std::cout <<"f7 :"<< f7 << std::endl;

		b.executeForm(f2);
		b.executeForm(f3);
		b.executeForm(f4);
		b.executeForm(f6);
		c.executeForm(f7);

		// b.executeForm(f3);
	
	
	return 0;
}
	