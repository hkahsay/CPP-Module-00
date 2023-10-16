#include "Dog.hpp"
//AAnimal("Dog"),
Dog::Dog():  _brain (new Brain()){

	std::cout << "Dog Default constructor called" << std::endl;
	_type = "Dog";
	// _brain = new Brain();
 
}

Dog:: Dog(const std:: string & name) {
	std:: cout << "Dog name constructor called"<< std:: endl;
	_type = name;
	_brain = new Brain();


}

Dog::Dog(const Dog& src) : AAnimal(src), _brain(new Brain()) {
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


 // Implementation of pure virtual functions from AAnimal
void Dog::makeSound()const {
	
	std::cout << this->_type << " says wawh wawh... " << std::endl;

	return;
}

Brain* Dog:: getBrain() {
	return this->_brain;
}

