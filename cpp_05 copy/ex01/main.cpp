#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

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

int main( void ) {
	try {
		Bureaucrat b("Bob", 76);
		// Bureaucrat c("Bob", -100);
		Form f("Bob from form", -100);
		// f.beSigned(b);
		b.signForm(f);
		// c.incrementGrade();
		b.decrementGrade();
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		// std::cout << c << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	/* double res = 0.0;
	try {
		res = plusOne(division(5.0, 2.0));
	} catch (DivisionByZeroException & e) {
		std::cout << e.what() << std::endl;
		res = -1.0;
	}
	std::cout << res << std::endl; */
	
	return 0;
}
