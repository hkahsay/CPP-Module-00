#ifndef HUMANB_HPP
#define HUMANB_HPP
#include"Weapon.hpp"
#include<iostream>
#include<string>
class HumanB {

	private:
	std:: string _name;
	Weapon* _weapon;
	
	public:
	HumanB();

	~HumanB();
	HumanB(const std:: string& HumanBPtr);
	void setWeapon(Weapon& setweapon);

	
	void attack(void);
};

#endif