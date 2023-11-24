/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:59 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/23 17:32:51 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

// class MyException: public std::exception {
// 	public:
// 		virtual const char* what() const throw() {
// 			return "My exception happened";
// 		}
// };

// class DivisionByZeroException: public std::exception {
// 	public:
// 		virtual const char* what() const throw() {
// 			return "Division by zero exception happened";
// 		}
// };

// int f(bool throw_exception = true) {
// 	if (throw_exception) throw MyException();
// 	else return 42;
// }

// double division(double a, double b) {
// 	if (b == 0.0) {
// 		throw DivisionByZeroException();
// 	}
// 	return (a/b);
// }

// double plusOne(double a) {
// 	std::cout << "plusOne called" << std::endl;
// 	return a + 1;
// }

int main( void ) {

		Bureaucrat b("Bob", 10);
		Bureaucrat c("paul", 100);
		Form f("Form 1", 100, 50);
		Form f1("Form 2", 100, 50);

		// Form g("Bob from form", -100, 50);

		// f.beSigned(b);
		b.decrementGrade();
		c.incrementGrade();
		b.signForm(f);
		b.signForm(f1);

		c.signForm(f);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		std::cout << c << std::endl;
		std::cout << f << std::endl;
	
	
	return 0;
}
