#include "WrongCat.hpp"
//: WrongAnimal("Wrong cat")
WrongCat::WrongCat() :WrongAnimal(){
	std:: cout << "WrongCat Default constructor called"<< std:: endl;
	_type = "Wrong cat";
	return ;
}

WrongCat::~WrongCat() {
	std:: cout << "WrongCat destructor called"<< std:: endl;
	return ;
}

WrongCat::WrongCat(const std:: string& name) {
	std:: cout << "WrongCat name constructor called"<< std:: endl;
	_type = name;
}

WrongCat::WrongCat(WrongCat const& src) {
	std:: cout << "WrongCat copy constructor called"<< std:: endl;
	_type = src._type;
	return;
}

WrongCat& WrongCat::operator = (WrongCat const& rhs)
{
	if(this != &rhs)
		this->_type = rhs._type;
	return *this;
}
void WrongCat::makeSound()const {
	
	std::cout<<"WrongCat of type: "<< this->_type << " make a sound meaw meaw. " << std::endl;

	return;
}