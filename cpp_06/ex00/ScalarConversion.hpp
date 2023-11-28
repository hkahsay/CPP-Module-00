/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:23:31 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:23:31 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP


#include <cstdlib>
#include<cstdio>
#include <iostream>
#include <string>
#include <climits>
#include<cassert>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <exception>

class ScalarConverter
{
    private:
        std::string _input;
        std::string _type;
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(std::string input);
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator = (ScalarConverter const &rhs);

        bool    isInt(std::string input);
        bool    isChar(std::string input);
        bool    isFloat(std::string input);
        bool    isDouble(std::string input);

        void    convertChar(std::string input);
        void    convertInt(std::string toBeConvert);
        void    convertFloat(std::string input);
        void    convertDouble(std::string input);

        void    identify_convert(std::string input_type);
        void    print_float(float value);
        void    print_double(double value);


};

#endif