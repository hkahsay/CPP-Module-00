/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:59 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/27 12:20:08 by hkahsay          ###   ########.fr       */
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


// int	main( void )
// {
	
// 	Bureaucrat bur("Bob", 149);

// 	Bureaucrat bur1("Tom", 1);
// 	Bureaucrat bur2("Robert", 50);
// 	Bureaucrat bur4(bur);
// 	std::cout << bur4 << std::endl;

// 	Form obj("Objet", 50, 0);
// 	Form service("Service", 151, 140);

// 	Form com("commande", 50, 30);
// 	Form nett("Nettoyage", 150, 51);
// 	bur.signForm(com);
// 	std::cout << com  << std::endl;
// 	bur1.signForm(com);
// 	bur2.signForm(com);

// 	bur.signForm(nett);
// 	bur2.signForm(nett);

// 	Form my_copy(com);
// 	std::cout << my_copy << std::endl;
// 	return 0;
// }


int main( void ) {

		Bureaucrat b("Bob", 10);
		Bureaucrat c("paul", 150);
		Bureaucrat bf("paul", 151);
		Bureaucrat d("lucas", 0);
		Bureaucrat e("hann", 20);


		Form f("f", 100, 0);
		Form f1("f1", 151, 50);
		Form f2("f2", 150, 50);
		Form f3("f3", 10, 50);


		b.signForm(f);
		e.signForm(f);
		e.signForm(f3);
		b.signForm(f3);
		c.signForm(f2);
		std::cout << b << std::endl;
		std::cout << e << std::endl;
		std::cout << f << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
	
	return 0;
}