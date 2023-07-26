#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

Cure:: Cure(void){
	std:: cout << "Cure Default constructor called"<< std:: endl;
	return ;
}

Cure:: ~Cure() {
	std:: cout <<"Cure Destructor called "<< std:: endl;
}

Cure:: Cure(const std:: string & type) {
	std:: cout << "Cure type constructor called"<< std:: endl;
	_type = type;

}

Cure :: Cure(Cure const & src) {
	std:: cout << "Cure copy constructor called"<< std:: endl;
	_type = src.getType(); // is the same as *this = src
	
	return;
}

Cure& Cure::operator=(const Cure& rhs) {
	std::cout << "Cure Copy assignment operator called" << std::endl;
    // Copy assignment operator implementation
    if (this != &rhs) {
        this->_type = rhs.getType();
    }
    return *this;
}

AMateria* Cure:: clone() const {
	return new Cure();

}

void Cure:: use(ICharacter& target) {
	std:: cout << "* heals"<< target.getName() << "'s wounds *" << std:: endl;
}

