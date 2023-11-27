/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:29:33 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/27 13:45:12 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"

#define MAX_NUM 3
class AForm;

class Intern
{

    public:
        Intern();
        ~Intern();
        Intern(Intern const &src);
        Intern & operator = (Intern const &rhs);
        AForm   *makeForm(const std::string nameForm, const std::string targetForm);
        class FormDoesnotExist : public std::exception
        {
            public:
            
            virtual char const * what()const throw();
        };
        class FormIsEmpty : public std::exception
        {
            public:
            
            virtual char const * what()const throw();
        };
};

#endif
