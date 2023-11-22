/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:11:12 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 13:03:43 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include<string>
#include<iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
    private:
        static const std::string _fileName;
        std::string _target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ShrubberyCreationForm& operator = (ShrubberyCreationForm const &rhs);
        std::string getTarget()const;
        void execute(Bureaucrat const & executor) const;

};
#endif