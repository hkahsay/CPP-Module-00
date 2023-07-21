#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


#include <iostream>

Cat::Cat(){

	std::cout << "Cat Default constructor called" << std::endl;
	_type = "Cat";
	return;
 
}

Cat::Cat(const Cat& src)  : Animal() {
    std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
}

Cat:: Cat(const std:: string & name) {
	std:: cout << "Cat name constructor called"<< std:: endl;
	_type = name;

}

Cat &	Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}


void Cat::makeSound()const {
	
	std::cout << this->_type << " says meaw meaw... " << std::endl;

	return;
}


