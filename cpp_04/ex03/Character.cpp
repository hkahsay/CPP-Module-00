#include "Character.hpp"


Character:: Character():_name("no name"), _inventorySlot{NULL} {
	_name = "no name";
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
	{
		_inventorySlot[i] = NULL;
	}
	std:: cout << "Character Default Constructor called"<<std:: endl;
	
	return ;
}

Character:: Character(const std::string& name): _name(name), _inventorySlot{NULL} {
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
	{
		_inventorySlot[i] = NULL;
	}
}

Character:: ~Character() {
	std:: cout << " Character Default Destructor called"<<std:: endl;
	return ;
}

Character:: Character(Character const & src) {
	this->_name =  src.getName();
}

Character & Character:: operator = (Character const & rhs) {
	if(this != &rhs)
		this->_name = rhs.getName();
	return *this;
}



std::string const & Character:: getName() const {
	return _name;
}

void Character:: equip(AMateria* m) {

}
// void unequip(int idx);
// void use(int idx, ICharacter& target)

