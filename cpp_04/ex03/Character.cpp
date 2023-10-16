#include "Character.hpp"

Character::Character() : _name(), _inventorySlot() {
	// this->_inventorySlot = new AMateria*[4];

    for (int i = 0; i < 4; i++) {
        _inventorySlot[i] = NULL;
    }
    std::cout << "Character Default Constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	std::cout << "char para"<<std:: endl;
	// this->_inventorySlot = new AMateria*[4];
    for (int i = 0; i < 4; i++) {
        _inventorySlot[i] = NULL;
    }
	std::cout << "char para2 "<< _name<<std:: endl;

}


Character:: ~Character() {
	std:: cout << " Character Default Destructor called"<<std:: endl;
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventorySlot[i])
		{
			delete this->_inventorySlot[i];
			this->_inventorySlot[i] = NULL;
		}
	}
	return ;
}

Character:: Character(Character const & src) {

	this->_name =  src.getName();
	for (int i = 0; i < 4; i++)
	{
		if(src._inventorySlot[i])
			this->_inventorySlot[i] = src._inventorySlot[i]->clone();
		else
			this->_inventorySlot[i] = NULL;
	}
	
}

Character & Character:: operator = (Character const & rhs) {


    // Check for self-assignment to avoid unnecessary work
	if(this != &rhs)
	{
		// Copy the name
		this->_name = rhs.getName();

		for (int i = 0; i < 4; i++)
		{
			if (this->_inventorySlot[i] != NULL) {

			//  Delete existing Materias in the inventory
				delete this->_inventorySlot[i];
				_inventorySlot[i] = NULL;

			}
			// it checks if the corresponding slot in the rhs object's inventory
			// is pointing to a Materia (not NULL). If it is, it uses the clone() 
			// function to create a new copy of the Materia and stores the 
			// pointer in the corresponding slot of the this object's inventory.
			if (rhs._inventorySlot[i])
				this->_inventorySlot[i] = rhs._inventorySlot[i]->clone();
		}
		 
	}
	 // Return *this to enable chained assignments
	return *this;
}


std::string const & Character:: getName() const {
	return this->_name;
}

AMateria* Character::getMateriaFromInventory(int idx)
{
	return _inventorySlot[idx];
}


void Character:: equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventorySlot[i] == NULL)
		{
			this->_inventorySlot[i] = m;
			std::cout << m->getType()<< "materia is added"<<std:: endl;
			break;
			// Since the character can only equip one AMateria in each slot, the 
			// loop stops as soon as it finds an empty slot and equips the AMateria there.
		}
		
	}	

}



void Character:: unequip(int idx) {
	if (idx < 0 || idx > 3)
		std:: cout <<"the index must be between 0 and 3"<<std::endl;
	else if (!_inventorySlot[idx])
		std:: cout <<this->_name << ": at the index "<< idx<<"doesn't exist"<<std::endl;
	else
	{
		AMateria* type = _inventorySlot[idx];
		std::cout <<this->_name<< "removed" <<type->getType() <<std:: endl;
			_inventorySlot[idx] = NULL;

	}	
}

void Character:: use(int idx, ICharacter& target) {

	if (idx < 0 || idx > 3 || this->_inventorySlot[idx] == NULL)
	{
		std::cout <<"invalid index or target doesnot exist " << idx << " " <<target.getName()<< std:: endl;
		std::cout << "this->_inventorySlot[idx]"<< this->_inventorySlot[idx] <<std:: endl;
		return;
	}
	else
	{

		std:: cout << _name<< ": ";
		this->_inventorySlot[idx]->use(target);
	}
		
}
