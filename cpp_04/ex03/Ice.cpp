#include "Ice.hpp"
#include "Character.hpp"


Ice:: Ice(void){
	std:: cout << "Ice Default constructor called"<< std:: endl;
	return ;
}

Ice:: ~Ice() {
	std:: cout <<"Ice Destructor called "<< std:: endl;
}

Ice:: Ice(const std:: string & type) {
	std:: cout << "Ice type constructor called"<< std:: endl;
	_type = type;

}

Ice :: Ice(Ice const & src) {
	std:: cout << "Ice copy constructor called"<< std:: endl;
	_type = src.getType(); // is the same as *this = src
	
	return;
}

Ice& Ice::operator=(const Ice& rhs) {
	std::cout << "Ice Copy assignment operator called" << std::endl;
    // Copy assignment operator implementation
    if (this != &rhs) {
        this->_type = rhs.getType();
    }
    return *this;
}

AMateria* Ice:: clone() const {
	return new Ice();
}

void Ice:: use(ICharacter& target) {
	std:: cout << "*shoots an ice bolt at " << target.getName() << " *"<< std:: endl;
}
