#include"HumanB.hpp"
#include"Weapon.hpp"
#include<iostream>

HumanB:: HumanB() {

}

HumanB:: ~HumanB() {
	
}

HumanB:: HumanB(const std:: string& HumanBRef)
:_name(HumanBRef) {

}

void HumanB:: setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return ;
}
void HumanB:: attack(void) {

if (this->_weapon == NULL)
{
	std:: cout << _name << "no attacks with their"<< std:: endl;

}
else{

	std:: cout << _name << "attacks with their"<< _weapon.getType()<< std:: endl;
}
}
