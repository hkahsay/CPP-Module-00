#include"AAnimal.hpp"
# include <iostream>

AAnimal:: AAnimal(void){
	std:: cout << "AAnimal Default constructor called"<< std:: endl;
	return ;
}

AAnimal:: ~AAnimal() {
	std:: cout <<"AAnimal Destructor called "<< std:: endl;
}

AAnimal:: AAnimal(const std:: string & name) {
	std:: cout << "AAnimal name constructor called"<< std:: endl;
	_type = name;

}

AAnimal :: AAnimal(AAnimal const & src) {
	std:: cout << "AAnimal copy constructor called"<< std:: endl;
	_type = src._type; // is the same as *this = src
	
	return;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
    // Copy assignment operator implementation
    if (this != &rhs) {
        this->_type = rhs.getType();
	

    }
    return *this;
}

const std:: string& AAnimal:: getType() const {

	return _type;

}




void AAnimal::makeSound()const {
	
	std::cout<<"hello i cannot make a sound (abstract class)"<< std::endl;

	return;
}
