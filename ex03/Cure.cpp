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
	
    // Copy assignment operator implementation

    // Check for self-assignment to avoid unnecessary work
    if (this != &rhs) {
        this->_type = rhs.getType();
    }
	std::cout << "Cure Copy assignment operator called" << std::endl;
    return *this;
}

AMateria* Cure:: clone() const {
	return new Cure();

}

void Cure:: use(ICharacter& target) {
	std:: cout << "* heals"<< target.getName() << "'s wounds *" << std:: endl;
}

