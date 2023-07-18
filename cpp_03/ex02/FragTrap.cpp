#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {

	std::cout << "FragTrap Default constructor called" << std::endl;
    _hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name_para) : ClapTrap(name_para) {
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;

}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap:: highFivesGuys(void) {
    std::cout << "high fives!" << std::endl;

}



