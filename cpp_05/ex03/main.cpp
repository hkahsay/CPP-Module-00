/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:29 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/27 14:31:08 by hkahsay          ###   ########.fr       */
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
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	
		Intern		hur;
		Intern		hur1;

		
		
		std::cout<< "--------------test shrubbery----------\n\n";
		AForm*	shrubbyery = hur.makeForm("Robotomy Request Form", "home");

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
		std::cout<< "--------------test desnot exist----------\n\n";
		AForm*	none = hur.makeForm("Robotomy", "work");

		delete none;

		std::cout<< "--------------test presidential----------\n\n";
		AForm*	presidential = hur.makeForm("presidential", "office");
		AForm*	pform = hur.makeForm("Presidential Pardon Form", "office");
		delete pform;
		if (presidential)
		{
			std::cout << *presidential << std::endl;
			b1.signForm(*presidential);
			b1.executeForm(*presidential);
			std::cout << *presidential << std::endl;
			delete presidential;
		}
		
		
		std::cout<< "--------------test emptyform----------\n\n";

		AForm*	emptyForm = hur1.makeForm("", "home");
		delete emptyForm;

		if(emptyForm)
		{
			b1.signForm(*emptyForm);
			b1.executeForm(*emptyForm);
			
		}

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
