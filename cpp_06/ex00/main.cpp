#include "ScalarConversion.hpp"


// cases to handele
// check and identify what the input type is
// convert into the scalar types
// convert parameter will take the identified input
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::cout<<"arv value in char, integer, float and double " <<std::endl;
        std::string userInput = argv[1];
        ScalarConverter SConvert(userInput);
        std::cout <<"userInput "<<userInput<<std::endl;
        long long nbr = atoll(userInput.c_str());
        if (nbr < INT_MIN && nbr > INT_MAX)
        {
            std::cerr << "Value is out of the range of INT_MIN to INT_MAX" << std::endl;
            exit(EXIT_FAILURE);
        }
        SConvert.identify_convert(userInput);
        // try
        // {
        //     SConvert.identify_convert(userInput);
        // }
        // catch(const std::exception& e)
        // {
        //     std::cerr << e.what() << '\n';
        // }
        

       
    }
    else
    {
        std::cout <<"error number of arguments"<<std::endl;
        return 0;

    }
    
    // ScalarConverter:: convert(argv[1]);
}