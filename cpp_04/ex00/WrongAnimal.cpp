#include "WrongAnimal.hpp"

WrongAnimal:: WrongAnimal() {
	std:: cout << "Default WrongAnimal constructor created"<<std:: endl;
	return ;

}

WrongAnimal:: ~WrongAnimal() {
	std:: cout << "Default WrongAnimal destructor created"<<std:: endl;
	return ;
}

WrongAnimal:: WrongAnimal(const std:: string& name) {
	std:: cout << "name constructor created"<<std:: endl;

	_type = name;
}

WrongAnimal:: WrongAnimal(WrongAnimal const & src) {
	std:: cout << "WrongAnimal copy constructor called"<< std:: endl;
	_type = src._type;

}

WrongAnimal&  WrongAnimal::operator = (const WrongAnimal  & rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

const std::string&  WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound()const {
	
	std::cout<<"WrongAnimal of type: "<< this->_type << " make a sound. " << std::endl;

	return;
}
		
