/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:09:53 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:09:54 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class MyException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "My exception happened";
		}
};

class DivisionByZeroException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Division by zero exception happened";
		}
};

int f(bool throw_exception = true) {
	if (throw_exception) throw MyException();
	else return 42;
}

double division(double a, double b) {
	if (b == 0.0) {
		throw DivisionByZeroException();
	}
	return (a/b);
}

double plusOne(double a) {
	std::cout << "plusOne called" << std::endl;
	return a + 1;
}

// int main( void ) {
// 	try {
// 		// Bureaucrat b("Bob", 0);
// 		Bureaucrat b("Bob", -76);
// 		// Bureaucrat c("Bob", -100);
// 		// c.incrementGrade();
// 		// b.decrementGrade();
// 		std::cout << b << std::endl;
// 		// std::cout << c << std::endl;
// 	} catch (const GradeTooHighException & e) {
// 		// error mesage and grade that cosed the error
// 		std:: cerr << "Grade too high: " << e.getGradeHigh() << std::endl;
// 	}
// 	catch (const GradeTooLowException & e) {
// 		// error mesage and grade that cosed the error
// 		std:: cerr << "Grade too low: " << e.getGradeLow() << std::endl;
// 	}
// 	/* double res = 0.0;
// 	try {
// 		res = plusOne(division(5.0, 2.0));
// 	} catch (DivisionByZeroException & e) {
// 		std::cout << e.what() << std::endl;
// 		res = -1.0;
// 	}
// 	std::cout << res << std::endl; */
// 	return 0;
// }

int main() {
    // try {
    //     Bureaucrat c("Bob", 100);
    //     Bureaucrat b("han", 170);

    //     std::cout << "Bureaucrat name: " << c.getName() << std::endl;
    //     std::cout << "Bureaucrat grade: " << c.getGrade() << std::endl;
    //     std::cout << "Bureaucrat name: " << b.getName() << std::endl;
    //     std::cout << "Bureaucrat name: " << b.getGrade() << std::endl;
    // } catch (const GradeTooHighException& e) {
    //     std::cerr << "Grade too high: " << e.getGradeHigh() << std::endl;
    // } catch (const GradeTooLowException& e) {
    //     std::cerr << "Grade too low: " << e.getGradeLow() << std::endl;
    // }
	try
	{
		Bureaucrat d("hann", 100);
		Bureaucrat f("hadu", -120);

		d.incrementGrade();
		f.decrementGrade();
		std::cout << d << std::endl;
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}