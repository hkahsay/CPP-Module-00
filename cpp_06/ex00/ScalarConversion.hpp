#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP


#include <cstdlib>
#include<cstdio>
#include <iostream>
#include <string>
#include <limits>
#include<cassert>

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


        int   isChar(std::string input);
        int    isInt(std::string input);
        int    isFloat(std::string input);
        int    isDouble(std::string input);

        void convert(std::string input);
        void identify_convert(std::string input_type);
        void convert_char(std:: string charToConvert);
        void    print_char(char pChar);
        void   print_int(int integer);
        void    convert_int(std::string toBeConvert);
        // class UnrecognizedTypeException : public std::exception
        // {
        //     public:
        //         virtual const char* what() const throw();
        // };

};

#endif