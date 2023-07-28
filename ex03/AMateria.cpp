#include "AMateria.hpp"

AMateria:: AMateria() {
	std:: cout << "AMateria Default Constructor called"<<std:: endl;
	return ;
}

AMateria:: ~AMateria() {
	std:: cout << " AMateria Default Destructor called"<<std:: endl;
	return ;
}

AMateria:: AMateria(AMateria const & src) {
	this->_type =  src.getType();
}

AMateria & AMateria:: operator = (AMateria const & rhs) {
	if(this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

AMateria:: AMateria(std::string & type) {
	_type = type;
}
std::string const & AMateria:: getType() const {
	return _type;
}

void AMateria:: setType(std:: string type) {
	this->_type = type;
}


void AMateria:: use(ICharacter& target) {
	
	std:: cout <<"All child classes use thier own identity not from parent"<< target.getName()<< std:: endl;
	return ;

}
