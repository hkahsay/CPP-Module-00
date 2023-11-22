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
// bool    isChar(std::string input)
// {
//     if (input[0] == '\'' && input[2] == '\'')
//     {
//         std::cout<<"char: " << input <<std::endl;
//     }
// // }
// std::string pseudoLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

// int isliterals(std::string input)
// {
//     for (size_t i = 0; i < 6; i++)
//     {
//         /* code */
//     }
    
// }

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

bool ScalarConverter::isChar(std::string input)
{
    if (input.length() == 1 && isalpha(input[0]))
    {
        if (isprint(input[0]))
        {
            return true;
        }
        else
            std::cout << "char is not displayable" << std::endl;
    }
    // else
    // {
    //     std::cerr<< "char must only have one character"<<std::endl;
    //     exit(EXIT_FAILURE);
    // }
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
    std::cout << "double: " << d << std::endl;
    // std::cout<<"double: "<< std::fixed << std::setprecision(10) << d <<std::endl;
}

void ScalarConverter::identify_convert(std::string input_type)
{
    std::cout << "identify the input: " << input_type << std::endl;
    if (isChar(input_type))
        convertChar(input_type);
    else if (isFloat(input_type))
        convertFloat(input_type);
    else if (isInt(input_type))
        convertInt(input_type);
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
//  inff", "+inff", "nanf", "-inf", "+inf", "nan
bool ScalarConverter::isInt(std::string input)
{
    std::cout << "display input: " << input << std::endl;
//std::numeric_limits<int>(input);
    size_t len = input.length();
    if (input.empty())
    {
        std::cout << "the string is empty" << std::endl;
        return false;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (input[i] == '-' || input[i] == '+')
        {
            continue;
        }

        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    // int nbr = std::atoi(input.c_str());
    long long nbr = atoll(input.c_str());
    std::cout << "display number: " << nbr << std::endl;
    if (nbr >= INT_MIN && nbr <= INT_MAX)
    {
        std::cout <<INT_MAX<<std::endl;
        return true;
    }
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

    std::cout << "char int: '" << static_cast<char>(nbr) << "'" << std::endl;
    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: ";
    print_float(f);
    std::cout << std::endl;
    std::cout << "double: ";
    print_double(d);
    std::cout << std::endl;
}

// bool ScalarConverter::isFloat(std::string input)
// {
//     std::cout << "from isfloat" << std::endl;
//     size_t len = input.length();
//     bool    hasDecimal = false;

//     for (size_t i = 0; i < len; i++)
//     {
//         if (i == 0 && (input[i] == '-' || input[i] == '+'))
//             continue;
//         if (isdigit(input[i]) )//&& !hasDecimal
//         {
//             std:: cout << input[i] << " ";
//             if (i == 1 && input[i] == '0' && !hasDecimal) {
//                 return false;  // Leading zeros are not allowed unless there's a decimal
//             }
//         }
//         else if(input[i] == '.' && !hasDecimal)
//         {
//             hasDecimal = true;
//         } 
//         else if (input[i] == 'f' && i == len - 1)
//         {
//             std::cout << "from isfloat2" << std::endl;
//             return true;
//         }
//         else
//             return false;
//     }
//     return false;
// }

bool ScalarConverter::isFloat(std::string input) {
    size_t len = input.length();
    bool hasDecimal = false;
    bool numericLimit = false;
    for (size_t i = 0; i < len; i++) {
        long long nbr = atoll(input.c_str());
        if (nbr >= INT_MIN && nbr <= INT_MAX)
        {
            numericLimit = true;
        }
        else
        {
            std::cerr << "Value is out of the range of INT_MIN to INT_MAX" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (i == 0 && (input[i] == '-' || input[i] == '+')) {
            continue; // Optional sign character
        }
        if (isdigit(input[i])) {
            if (i == 1 && input[0] == '0' && !hasDecimal) {
                printf("0\n");
                return false; // Leading zeros are not allowed unless there's a decimal
            }
                printf("6\n");
        } else if (input[i] == '.' && !hasDecimal && numericLimit) {
            printf("1\n");
            hasDecimal = true; // One decimal point allowed
        } else if (input[i] == 'f' && i == len - 1 && numericLimit) {
                printf("4\n");
            return true; // 'f' character found at the end
        } else {
                printf("5\n");
            return false; // Invalid character
        }
    }

    return false; // No 'f' character found at the end
}

void ScalarConverter::convertFloat(std::string input)
{

    float fnbr = std::atof(input.c_str());
    double d = static_cast<double>(fnbr);
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
    {
        std::cout << value << ".0f";
    }
    else
    {
        std::cout << value << "f";
    }
}

bool ScalarConverter::isDouble(std::string input)
{
    size_t len = input.length();
    bool hasDecimal = false;
    bool numericLimit = false;
    long long nbr = atoll(input.c_str());
    if (nbr >= INT_MIN && nbr <= INT_MAX)
    {
        numericLimit = true;
    }
    else
    {
        std::cerr << "Value is out of the range of INT_MIN to INT_MAX" << std::endl;
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < len; i++)
    {
        if (i == 0 && (input[i] == '-' || input[i] == '+')) {
            continue; // Optional sign character
        }

        if (isdigit(input[i])) {
            if (i == 1 && input[0] == '0' && !hasDecimal) {
                printf("10\n");
                return false; // Leading zeros are not allowed unless there's a decimal
            }
                printf("16\n");
        } else if (input[i] == '.' && !hasDecimal && numericLimit) {
            printf("19\n");
            hasDecimal = true; // One decimal point allowed
            if (isdigit(input[i]) && numericLimit)
                return true;
        } else {
                printf("20\n");
            return false; // Invalid character
        }
    }
    return false;
}


void ScalarConverter::convertDouble(std::string input)
{

    double dnbr = std::atof(input.c_str());
    float f = static_cast<float>(dnbr);
    std::cout << "char d: '" << static_cast<char>(dnbr) << "'" << std::endl;
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
    {
        std::cout << value << ".0";
    }
    else
    {
        std::cout << value;
    }
}

const char *ScalarConverter::UnrecognizedTypeException::what() const throw()
{
    return "User input error : type unrecognized";
}
