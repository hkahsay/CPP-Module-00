#ifndef HUMANA_HPP
#define HUMANA_HPP
#include"Weapon.hpp"
#include<iostream>
#include<string.h>

class HumanA {

	private:
	std:: string _name;
	Weapon& _weapon;

	public:
		HumanA(const std:: string& HumanARef, Weapon& WeaponRef);
		~HumanA();
	void attack(void);
};

#endif
