#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define NUMBER_OF_SLOTS 4
#include<iostream>
#include<string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character :public ICharacter {
	private:
		std:: string _name;
		AMateria* _inventorySlot[ NUMBER_OF_SLOTS];
	public:
		Character();
		virtual ~Character();
		Character(const std:: string& name);
		Character(Character const  & src);
		Character & operator = (Character const & rhs);
		std::string const & getName() const;
		AMateria* getMateriaFromInventory(int idx);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};



#endif
