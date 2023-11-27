/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:09:44 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/27 11:32:04 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"


int main() {
   
    Bureaucrat b("han", 1);
    Bureaucrat c("Bob", 160);
    Bureaucrat d("mehari", 0);
    Bureaucrat bureaucrat("Alice", 100);
    // Bureaucrat bur1("han", 150);
    Bureaucrat bur2("her", 1);
    
    
    
    std::cout << b << std::endl;    
    std::cout << c << std::endl;
    std::cout << d << std::endl;    
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade(); // Incrementing grade from 100 to 99
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade(); // Decrementing grade from 99 to 100
    std::cout << bureaucrat << std::endl;
    // bur1.incrementGrade(); 
    // std::cout << bur1 << std::endl;
    bur2.incrementGrade(); 
    std::cout << bur2 << std::endl;
    // bur1.decrementGrade(); 
    // std::cout << bur1 << std::endl;
    bur2.decrementGrade(); 
    std::cout << bur2 << std::endl;
    
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