#include"Animal.hpp"
# include <iostream>

Animal:: Animal(void){
	std:: cout << "Animal Default constructor called"<< std:: endl;
	return ;
}

Animal:: ~Animal() {
	std:: cout <<"Animal Destructor called "<< std:: endl;
}

Animal:: Animal(const std:: string & name) {
	std:: cout << "Animal name constructor called"<< std:: endl;
	_type = name;

}

Animal :: Animal(Animal const & src) {
	std:: cout << "Animal copy constructor called"<< std:: endl;
	_type = src._type; // is the same as *this = src
	
	return;
}

Animal& Animal::operator=(const Animal& rhs) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
    // Copy assignment operator implementation
    if (this != &rhs) {
        this->_type = rhs.getType();
	

    }
    return *this;
}

const std:: string& Animal:: getType() const {

	return _type;

}




void Animal::makeSound()const {
	
	std::cout<<"Animal of type: "<< this->_type << " make a sound. " << std::endl;

	return;
}
