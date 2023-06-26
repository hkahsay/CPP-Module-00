
#include"Weapon.hpp"
#include"HumanA.hpp"
#include<iostream>

HumanA:: HumanA(const std:: string& HumanARef, Weapon& WeaponRef)
:_name(HumanARef), _weapon(WeaponRef) {

}

HumanA:: ~HumanA() {

}

void HumanA:: attack(void) {
	// Weapon weapon;
	std::cout <<_name <<"attacks with their "<<_weapon.getType()<<std:: endl;
	return ;
}

