#include "Character.hpp"


Character:: Character():_name("no name") {

	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
	{
		_inventorySlot[i] = NULL;
	}
	std:: cout << "Character Default Constructor called"<<std:: endl;
	
	return ;
}

Character:: Character(const std::string& name): _name(name) {

	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
	{
		_inventorySlot[i] = NULL;
	}
}

Character:: ~Character() {
	std:: cout << " Character Default Destructor called"<<std:: endl;
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
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

	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
	{
		if(src._inventorySlot[i])
		this->_inventorySlot[i] = src._inventorySlot[i]->clone();
	}
	this->_name =  src.getName();
	
}

Character & Character:: operator = (Character const & rhs) {

    // Check for self-assignment to avoid unnecessary work
	if(this != &rhs)
	{
		// / Delete existing Materias in the inventory
		for (int i = 0; i < NUMBER_OF_SLOTS; i++)
		{
			delete _inventorySlot[i];
			_inventorySlot[i] = NULL;
		}
		 // Copy the contents of the rhs object to this object
		 for (int i = 0; i < NUMBER_OF_SLOTS; i++)
		 {
			// it checks if the corresponding slot in the rhs object's inventory
			// is pointing to a Materia (not NULL). If it is, it uses the clone() 
			// function to create a new copy of the Materia and stores the 
			// pointer in the corresponding slot of the this object's inventory.
			if (rhs._inventorySlot[i])
				this->_inventorySlot[i] = rhs._inventorySlot[i]->clone();
		 }
		 // Copy the name
		 _name = rhs.getName();
		 
	}
	 // Return *this to enable chained assignments
	return *this;
}


std::string const & Character:: getName() const {
	return _name;
}


AMateria	*Character::getMateriaFromInventory(int idx)
{
	return _inventorySlot[idx];
}


void Character:: equip(AMateria* m) {
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
	{
		if (!_inventorySlot[i])
		{
			_inventorySlot[i] = m;
			std::cout <<m->getType()<< "materia is added"<<std:: endl;
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
	if (idx < 0 || idx > 3 || !_inventorySlot[idx])
		std::cout <<"invalid index or target doesnot exist "<< std:: endl;
	_inventorySlot[idx]->use(target);

}


