#include "Dog.hpp"
#include "Cat.hpp"


#include <iostream>

Cat::Cat(){

	std::cout << "Cat Default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
	return;
 
}

Cat::Cat(const Cat& src)  : AAnimal() {
    std::cout << "Cat Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
	return ;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
	delete _brain;
	return ;
}


Cat &	Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < NUMBER_OF_IDEAS; i++)
			this->_brain->setIdeas( i, rhs._brain->getIdeas(i));
		this->_type = rhs.getType();
	}
	return *this;
}

 // Implementation of pure virtual functions from AAnimal

void Cat::makeSound()const {
	
	std::cout << this->_type << " says meaw meaw... " << std::endl;
	return;
}

Brain* Cat:: getBrain() const {
	return _brain;
}

