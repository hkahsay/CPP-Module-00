/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:09 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:11:10 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm:: _fileName = 
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"    //// \\\\-\n";

ShrubberyCreationForm:: ShrubberyCreationForm(): AForm("ShrubberyCreation", 145, 137), _target("default")
{

}

ShrubberyCreationForm:: ShrubberyCreationForm(std::string target): AForm("ShrubberyCreation", 145, 137), _target(target)
{
    
}

ShrubberyCreationForm:: ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm(src.getTarget(), 145, 137)
{
    
}

std::string ShrubberyCreationForm:: getTarget()const
{
    return this->_target;
}

ShrubberyCreationForm& ShrubberyCreationForm:: operator= (ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
    {
        this->_target = rhs.getTarget();
    }
    return *this;
    
}