#include <iostream>
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"


int main() {
    try {
        Bureaucrat c("Bob", 100);
        Bureaucrat b("han", 170);

        std::cout << "Bureaucrat name: " << c.getName() << std::endl;
        std::cout << "Bureaucrat grade: " << c.getGrade() << std::endl;
        std::cout << "Bureaucrat name: " << b.getName() << std::endl;
        std::cout << "Bureaucrat name: " << b.getGrade() << std::endl;
    } catch (const GradeTooHighException& e) {
        std::cerr << "Grade too high: " << e.getGradeHigh() << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cerr << "Grade too low: " << e.getGradeLow() << std::endl;
    }
	try
	{
		Bureaucrat d("hann", 100);
		Bureaucrat f("hadu", 120);

		d.incrementGrade();
		f.decrementGrade();
		std::cout << d << std::endl;
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
    return 0;
}