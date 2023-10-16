#include "Dog.hpp"
#include "Animal.hpp"
// #include <iostream>

Dog::Dog() {

	std::cout << "Dog Default constructor called" << std::endl;
	_type = "Dog";
 
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog:: Dog(const std:: string & name) {
	std:: cout << "Dog name constructor called"<< std:: endl;
	_type = name;

}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}


void Dog::makeSound()const {
	
	std::cout << this->_type << " says wawh wawh... " << std::endl;

	return;
}


