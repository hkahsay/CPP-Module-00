/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:29:28 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/23 13:11:10 by hkahsay          ###   ########.fr       */
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
	int i;
	std::string formNames[MAX_NUM] = 
	{"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	AForm* form = NULL;
	if (nameForm.empty() || targetForm.empty())
	{
		throw Intern::FormDoesnotExist();
	}
	for (i = 0; i < MAX_NUM; i++)
	{
		if (nameForm == formNames[i])
		{
			break;
		}
	}

	if(i == 3)
	{
		std::cout << "Intern did'nt find this type of form: "
		   << nameForm	<< std::endl;
		return form;
		
	}
	try
	{	
		switch (i)
		{
			case (0):
				form = new ShrubberyCreationForm(targetForm);
				break;
			case(1):
				form = new RobotomyRequestForm(targetForm);
				break;
			case (2):
				form = new PresidentialPardonForm(targetForm);
				break;
			default:
				break;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std:: cout << "Intern is creating " << formNames[i] << std::endl;
	return form;
}

char const * Intern:: FormDoesnotExist:: what()const throw()
{
	return ("Form doesnot exist\n");
}