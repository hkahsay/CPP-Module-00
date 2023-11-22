/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:29:28 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/22 16:29:29 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern:: Intern()
{

}

Intern:: ~Intern()
{

}
Intern:: Intern(Intern const & src)
{
	*this = src;
}

Intern & Intern:: operator= (Intern const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
	
}

AForm* Intern:: makeForm(const std::string nameForm, const std::string targetForm)
{
	std::string formNames[MAX_NUM] = 
	{"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};

	if (nameForm.empty() || targetForm.empty())
	{
		throw Intern::FormDoesnotExist();
	}
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (formNames[i] == nameForm)
		{
			switch (i)
			{
				case (0):
				{
					std:: cout << "Intern is creating " << formNames[i] << std::endl;
					return new ShrubberyCreationForm(targetForm);
					break;
				}
				case(1):
				{
					std:: cout << "Intern is creating " << formNames[i] << std::endl;
					return new RobotomyRequestForm(targetForm);
					break;
				}
				case (2):
				{

					std:: cout << "Intern is creating " << formNames[i] << std::endl;
					return new PresidentialPardonForm(targetForm);
					break;
				}
				default:
					break;
			}
		}
	
	}
	throw Intern::FormDoesnotExist();
	return NULL;
}

char const * Intern:: FormDoesnotExist:: what()const throw()
{
	return ("Form doesnot exsist\n");
}