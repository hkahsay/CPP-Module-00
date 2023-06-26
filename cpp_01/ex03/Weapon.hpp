#ifndef WEAPON_HPP
#define WEAPON_HPP
// #include"HumanA.hpp"
#include<iostream>
#include<string>

class Weapon {
	private:

		std:: string _type;

	public:
		Weapon();
		~Weapon();
		Weapon(std:: string type);

		const std:: string& getType(void)const;
		void setType(std:: string type);

};

#endif