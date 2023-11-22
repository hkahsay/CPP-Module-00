/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:29 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/22 16:28:40 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) {
	try {
		Bureaucrat b("Bob",6);
		Bureaucrat	b1("hanniel", 4);
		// Bureaucrat	b2("hadriel", 3);
		// Bureaucrat	b3("heaven", 2);

	
		Intern		hur;
		
		std::cout<< "--------------test shrubbery----------\n\n";
		AForm*	shrubbyery = hur.makeForm("Shrubbery Creation Form", "home");
		std::cout << *shrubbyery << std::endl;
		b1.signForm(*shrubbyery);
		b1.executeForm(*shrubbyery);
		std::cout << *shrubbyery << std::endl;
		delete shrubbyery;

		std::cout<< "--------------test Robotomy----------\n\n";
		AForm*	robotomy = hur.makeForm("Robotomy Request Form", "home");
		std::cout << *robotomy << std::endl;
		b1.signForm(*robotomy);
		b1.executeForm(*robotomy);
		std::cout << *robotomy << std::endl;
		delete robotomy;

		std::cout<< "--------------test presidential----------\n\n";
		AForm*	presidential = hur.makeForm("Presidential Pardon Form", "office");
		std::cout << *presidential << std::endl;
		b1.signForm(*presidential);
		b1.executeForm(*presidential);
		std::cout << *presidential << std::endl;
		delete presidential;
		
		std::cout<< "--------------test desnot exist----------\n\n";
		AForm*	none = hur.makeForm("Robotomy", "work");
		std::cout << *none << std::endl;
		b1.signForm(*none);
		b1.executeForm(*none);
		std::cout << *none << std::endl;
		delete none;
		
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
