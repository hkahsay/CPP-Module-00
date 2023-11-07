#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm:: ShrubberyCreationForm(): _grade_sign(145), _grade_exec(137)
{
    std::cout<<"default constructor called" << std::endl;
}

ShrubberyCreationForm:: ShrubberyCreationForm(std::string name, int grade): AForm(name, grade), _grade_sign(145), _grade_exec(137)
{
    std::cout<<"default constructor called" << std::endl;
}