/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:29 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 13:28:40 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"

int main( void ) {
	try {
		Bureaucrat b("Bob", 6);
		// RobotomyRequestForm f3("home");
		ShrubberyCreationForm f(b.getName());
		ShrubberyCreationForm f2("home");
		f2.beSigned(b);
		// f3.beSigned(b);
		b.signForm(f2);
		// std::cout <<"f2 \n"<< f2 << std::endl;
		std::cout << b << std::endl;
		f2.execute(b);
		// std::cout <<"f3"<< f3 << std::endl;

		// c.incrementGrade();
		// b.decrementGrade();
		// std::cout << c << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
