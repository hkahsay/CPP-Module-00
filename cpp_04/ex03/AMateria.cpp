#include "AMateria.hpp"
#include "ICharacter.hpp"


//: _type("default")
AMateria:: AMateria(): _type(){
	// _type = "default";
	std:: cout << "AMateria Default Constructor called"<<std:: endl;
	return ;
}

AMateria:: ~AMateria() {
	std:: cout << " AMateria Default Destructor called"<<std:: endl;
	return ;
}

std::string const & AMateria:: getType() const {
	return _type;
}

AMateria:: AMateria(AMateria const & src) {
	this->_type =  src.getType();
	std:: cout << " copy Default Destructor called"<<std:: endl;

}

AMateria &AMateria::operator=(AMateria const &rhs) {
	// this->_type = rhs._type;
	 if(this != &rhs)
	 {
		this->_type = rhs.getType();
		std:: cout << " oper Default Destructor called"<< rhs.getType()<<std:: endl;

	 }
	
	return *this;
}

AMateria:: AMateria(std::string const &type) {
	this->_type = type;
}

void AMateria:: setType(const std::string type) {
	this->_type = type;
}


void AMateria:: use(ICharacter& target) {
	
	// std:: cout <<"All child classes use thier own identity not from parent"<< target.getName()<< std:: endl;
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;

}
