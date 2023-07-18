#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {

	std::cout << "ScavTrap Default constructor called" << std::endl;
    _hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name_para) : ClapTrap(name_para) {
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;

}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap:: guardGate() {
	std:: cout<< "ScavTrap is now in Gate keeper mode."<< std:: endl;

}
void ScavTrap:: attack(const std::string& target){
	std:: cout << "ScavTrap " << this->_name<< " attacks " << target<< std:: endl;
	ClapTrap::attack(target);
}

