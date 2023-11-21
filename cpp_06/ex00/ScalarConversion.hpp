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


        void   convertChar(std::string input);
        bool    isInt(std::string input);
        bool    isChar(std::string input);
        void    convertFloat(std::string input);
        bool    isFloat(std::string input);
        bool    isDouble(std::string input);
        void    convertDouble(std::string input);
        void convert(std::string input);
        void identify_convert(std::string input_type);
        void convert_char(std:: string charToConvert);
        void print_float(float value);
       void  print_double(double value);

        void    convertInt(std::string toBeConvert);
        class UnrecognizedTypeException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

#endif