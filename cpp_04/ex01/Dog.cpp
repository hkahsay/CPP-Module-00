#include "Dog.hpp"
#include "Animal.hpp"
// #include <iostream>

Dog::Dog(): _brain (new Brain()){

	std::cout << "Dog Default constructor called" << std::endl;
	_type = "Dog";
	// _brain = new Brain();
 
}

Dog::Dog(const Dog& src) : Animal(src), _brain (new Brain()) {
    std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
	delete _brain;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < NUMBER_OF_IDEAS; i++)
			this->_brain->setIdeas( i, rhs._brain->getIdeas(i));
		this->_type = rhs.getType();
	}
	return *this;
}

// void Dog:: setType(std::string type) {
// 	this->_type = type;
// }

void Dog::makeSound()const {
	
	std::cout << this->_type << " says wawh wawh... " << std::endl;

	return;
}

Brain* Dog:: getBrain() {
	return this->_brain;
}

