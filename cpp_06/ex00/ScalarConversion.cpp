/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:23:27 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:23:27 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <iostream>
#include <string>
#include <limits>


ScalarConverter::ScalarConverter() : _input(0)
{
}
ScalarConverter::ScalarConverter(std::string input) : _input(input)
{
}
ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    (void)rhs;
    return (*this);
}

void ScalarConverter::identify_convert(std::string input_type)
{
    if (isChar(input_type))
        convertChar(input_type);
    else if (isInt(input_type))
        convertInt(input_type);
    else if (isFloat(input_type))
        convertFloat(input_type);
    else if (isDouble(input_type))
        convertDouble(input_type);
    else if (input_type == "nan" || input_type == "nanf")
    {
        std::cout << "char \t: impossible\n" << "integer\t: impossible\n"
            << "float\t: nanf\n"<<"double\t: nan"<< std::endl;
    }
     else if (input_type == "nan" || input_type == "nanf")
    {
        std::cout << "char \t: impossible\n" << "integer\t: impossible\n"
            << "float\t: nanf\n"<<"double\t: nan"<< std::endl;
    }
    else if (input_type == "+inf" || input_type == "+inff")
    {
        std::cout << "char \t: impossible\n" << "integer\t: impossible\n"
            << "float\t: +inff\n"<<"double\t: +inf"<< std::endl;
    }
    else if (input_type == "-inf" || input_type == "-inff")
    {
        std::cout << "char \t: impossible\n" << "integer\t: impossible\n"
            << "float\t: -inff\n"<<"double\t: -inf"<< std::endl;
    }
    else
        std::cout << "unknown literal"<<std::endl;
}

bool ScalarConverter::isChar(std::string input)
{
    if (input.length() == 1 && isalpha(input[0]))
    {
        if (isprint(input[0]))
        {
            return true;
        }
    }   
    return false;
}


void ScalarConverter::convertChar(std::string str)
{
    double d = static_cast<double>(str[0]);
    std::cout << "char: '" << str[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: ";
    print_float(str[0]);
    std::cout << std::endl;
    std::cout << "double: ";
    print_double(d);
    std::cout<< std::endl;
}


bool ScalarConverter::isInt(std::string input)
{
    size_t len = input.length();
    if (input.empty())
    {
        std::cout << "the string is empty" << std::endl;
        return false;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (input[i] == '-' || input[i] == '+')
            continue;
        if (!isdigit(input[i]))
            return false;
    }
    long long nbr = atoll(input.c_str());
    if (nbr >= INT_MIN && nbr <= INT_MAX)
        return true;
    else
    {
        std::cerr << "Value is out of the range of INT_MIN to INT_MAX" << std::endl;
        exit(EXIT_FAILURE);
    }
    return false;
}

void ScalarConverter::convertInt(std::string toBeConvert)
{
    const char *copy = toBeConvert.c_str();
    int nbr = atoi(copy);
    float f = static_cast<float>(nbr);
    double d = static_cast<double>(nbr);

    if ((nbr >= 0 && nbr < 32) || nbr == 127)
        std::cout << "char : " <<"Non displayable"<< std::endl;
    else if (nbr < 0 || nbr > 127)
        std::cout << "char : " <<"impossible"<< std::endl;
    else
        std::cout << "char : '" << static_cast<char>(nbr) << "'" << std::endl;
    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: ";
    print_float(f);
    std::cout << std::endl;
    std::cout << "double: ";
    print_double(d);
    std::cout << std::endl;
}

bool ScalarConverter::isFloat(std::string input)
{
    size_t len = input.length();
    bool hasDecimal = false;
    bool numericLimit = false;
    for (size_t i = 0; i < len; i++)
    {
        long long nbr = atoll(input.c_str());
        if (nbr >= INT_MIN && nbr <= INT_MAX)
            numericLimit = true;
        else
        {
            std::cerr << "Value is out of the range of INT_MIN to INT_MAX" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (i == 0 && (input[i] == '-' || input[i] == '+'))
            continue; // Optional sign character
        if (isdigit(input[i]))
        {
            if (i == 1 && input[0] == '0' && !hasDecimal) 
                return false; // Leading zeros are not allowed unless there's a decimal
        } 
        else if (input[i] == '.' && !hasDecimal && numericLimit)
            hasDecimal = true; // One decimal point allowed
        else if (input[i] == 'f' && i == len - 1 && numericLimit)
            return true; // 'f' character found at the end
         else 
            return false; // Invalid character
    }

    return false; // No 'f' character found at the end
}

void ScalarConverter::convertFloat(std::string input)
{

    float fnbr = std::atof(input.c_str());
    double d = static_cast<double>(fnbr);
    if ((fnbr >= 0 && fnbr < 32) || fnbr == 127)
        std::cout << "char : " <<"Non displayable"<< std::endl;
    else if (fnbr < 0 || fnbr > 127)
        std::cout << "char : " <<"impossible"<< std::endl;
    else
        std::cout << "char f: '" << static_cast<char>(fnbr) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(fnbr) << std::endl;
    std::cout << "float: ";
    print_float(fnbr);
    std::cout << std::endl;
    std::cout << "double: ";
    print_double(d);
    std::cout << std::endl;
}

void ScalarConverter::print_float(float value)
{
    // Add a trailing '.0' if the value has no decimal part using modf
    // Source: https://stackoverflow.com/a/47245857
    double integral;
    if (std::modf(value, &integral) == 0)
        std::cout << value << ".0f";
    else
        std::cout << value << "f";
}

bool ScalarConverter::isDouble(std::string input)
{
    size_t len = input.length();
    bool hasDecimal = false;
    bool numericLimit = false;
    long long nbr = atoll(input.c_str());
    if (nbr >= INT_MIN && nbr <= INT_MAX)
        numericLimit = true;
    else
    {
        std::cerr << "Value is out of the range of INT_MIN to INT_MAX" << std::endl;
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < len; i++)
    {
        if (i == 0 && (input[i] == '-' || input[i] == '+'))
            continue; // Optional sign character
        if (isdigit(input[i]))
        {
            if (i == 1 && input[0] == '0' && !hasDecimal)
                return false; // Leading zeros are not allowed unless there's a decimal
        }
        else if (input[i] == '.' && !hasDecimal && numericLimit)
            hasDecimal = true; // One decimal point allowed
        else 
            return false; // Invalid character
    }
    return true;
}


void ScalarConverter::convertDouble(std::string input)
{

    double dnbr = std::atof(input.c_str());
    float f = static_cast<float>(dnbr);
    if ((dnbr >= 0 && dnbr < 32) || dnbr == 127)
        std::cout << "char : " <<"Non displayable"<< std::endl;
    else if (dnbr < 0 || dnbr > 127)
        std::cout << "char : " <<"impossible"<< std::endl;
    else
        std::cout << "char : '" << static_cast<char>(dnbr) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(dnbr) << std::endl;
    std::cout << "float: ";
    print_float(f);
    std::cout << std::endl;
    std::cout << "double: ";
    print_double(dnbr);
    std::cout<< std::endl;
    
}

void   ScalarConverter:: print_double(double value)
{
   
    double integral;
    if (std::modf(value, &integral) == 0)
        std::cout << value << ".0";
    else
        std::cout << value;
}
