/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:23:19 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:23:19 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"


// cases to handele
// check and identify what the input type is
// convert into the scalar types
// convert parameter will take the identified input
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string userInput = argv[1];
        ScalarConverter SConvert(userInput);
        long long nbr = atoll(userInput.c_str());
        
        if (nbr < INT_MIN && nbr > INT_MAX)
        {
            std::cerr << "Value is out of the range of INT_MIN to INT_MAX" << std::endl;
            exit(EXIT_FAILURE);
        }
        SConvert.identify_convert(userInput);  
    }
    else
    {
        std::cout <<"error number of arguments"<<std::endl;

    }
    return 0;
}