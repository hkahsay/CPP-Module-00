/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:09:44 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:09:45 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"


int main() {
    try {
        Bureaucrat c("Bob", 100);
        Bureaucrat b("han", 0);

        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    try {
    Bureaucrat bureaucrat("Alice", -100);
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade(); // Incrementing grade from 100 to 99
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade(); // Decrementing grade from 99 to 100
    std::cout << bureaucrat << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	
    return 0;
}


// int main() {
//     try {
//         Bureaucrat c("Bob", 100);
//         Bureaucrat b("han", 170);

//         std::cout << "Bureaucrat name: " << c.getName() << std::endl;
//         std::cout << "Bureaucrat grade: " << c.getGrade() << std::endl;
//         std::cout << "Bureaucrat name: " << b.getName() << std::endl;
//         std::cout << "Bureaucrat name: " << b.getGrade() << std::endl;
//     } catch (const GradeTooHighException& e) {
//         std::cerr << "Grade too high: " << e.getGradeHigh() << std::endl;
//     } catch (const GradeTooLowException& e) {
//         std::cerr << "Grade too low: " << e.getGradeLow() << std::endl;
//     }
// 	try
// 	{
// 		Bureaucrat d("hann", 100);
// 		Bureaucrat f("hadu", 120);

// 		d.incrementGrade();
// 		f.decrementGrade();
// 		std::cout << d << std::endl;
// 		std::cout << f << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
	
//     return 0;
// }