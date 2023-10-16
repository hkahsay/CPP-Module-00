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
// }
std::string pseudoLiterals[6] = {"-inff","+inff", "nanf", "-inf", "+inf", "nan"};

ScalarConverter:: ScalarConverter(): _input(0)
{
    

}
ScalarConverter:: ScalarConverter(std::string input):_input(input)
{

}
ScalarConverter:: ~ScalarConverter(){

}

ScalarConverter:: ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter& ScalarConverter:: operator = (ScalarConverter const &rhs)
{
   (void)rhs;
    return(*this);
    
}




int    ScalarConverter:: isChar(std::string str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
    {
        if(!isprint(str[1]))
        {
            std::cout<< "char is not displayable"<<std::endl;
            return 0;
        }
       return 1;
    }
    return 0;

}





void ScalarConverter:: identify_convert(std::string input_type)
{
    std::cout<< "identify the input: "<<input_type<<std::endl;
    size_t  input_len = input_type.length();
    //if the input has negative sign as the first character remove 
    if (input_type[0] == '-' && input_len > 1)
    {
        input_type.substr(1, input_len);
    }
    
    if(isChar(input_type))
        convert_char(input_type);
    else if(isInt(input_type))
        convert_int(input_type);
    // else if(isFloat())
    //     return("FLOAT");
    // else if (isDouble())
    //     return("DOUBLE");
    else
        std::cout << "unknown literal"<<std::endl;
}

int ScalarConverter:: isInt(std::string input)
{
    int nbr = atoi(input.c_str());

    std:: size_t pos;
 
   
    
    if (isdigit(input[0]) && i)
    {
        return 1;
    }
    else
    
}
// int ScalarConverter:: isFloat()
// {

// }
// int ScalarConverter:: isDouble()
// {

// }
void ScalarConverter::convert_char(std:: string charToConvert)
{
    assert (isChar(charToConvert));
    
    char convertedChar = charToConvert[1];
    print_char(convertedChar);
    int convertedInt = static_cast<int>(convertedChar);//convert into int
    int temp = convertedInt - '0';
    print_int(temp); // Print the integer
}

// void    ScalarConverter:: convert_int(std::string toBeConvert)
// {
//     const char *copy = toBeConvert.c_str();
//     int nbr = atoi(copy);
//     char char_int = static_cast<char>(nbr);
//     print_char(char_int);
//     print_int(nbr);

// }


void ScalarConverter::convert_int(std::string toBeConvert) {
    const char *copy = toBeConvert.c_str();
    int nbr = atoi(copy);

    if (nbr >= 0 && nbr <= 127) {
        char char_int = static_cast<char>(nbr);
        print_char(char_int);
        print_int(nbr);
    } else {
        std::cout << "Conversion to character is not meaningful for this integer." << std::endl;
    }
}


void    ScalarConverter::print_char(char pChar)
{
    std::cout<<"char: "<<"'"<< pChar<< "'"<<std::endl;
}

void   ScalarConverter:: print_int(int integer)
{
    std::cout << "converted int "<< integer<<std::endl;
}

// const char* ScalarConverter::UnrecognizedTypeException::what() const throw()
// {
// 	return "User input error : type unrecognized";
// }

