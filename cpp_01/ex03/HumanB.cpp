#include"HumanB.hpp"
#include"Weapon.hpp"
#include<iostream>

HumanB:: HumanB(): _weapon(NULL) {

}

HumanB:: ~HumanB() {
	
}

HumanB:: HumanB(const std:: string& HumanBPtr)
:_name(HumanBPtr), _weapon(NULL) {

}

void HumanB:: setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return ;
}

void HumanB:: attack(void) {

if (_weapon == nullptr)
{
	std:: cout << _name << " no attacks with their "<< std:: endl;

}
else{

	std:: cout << _name << " attacks with their "<< _weapon->getType()<< std:: endl;
}
}
