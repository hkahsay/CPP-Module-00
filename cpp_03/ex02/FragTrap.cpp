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
	*this = src;
	return ;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void FragTrap:: highFivesGuys(void) {
    std::cout << "high fives!" << std::endl;
	return ;
}


void FragTrap::FragTrapStatus( void )
{
	std::cout << std::endl;
	std::cout << "name	            " << this->_name << std::endl;
	std::cout << "hitpoint		" << this->_hitPoint << std::endl;
	std::cout << "energypoint		" << this->_energyPoint << std::endl;
	std::cout << "attackDamage		" << this->_attackDamage << std::endl << std::endl;
	return ;
}


