#include"ClapTrap.hpp"
# include <iostream>

ClapTrap:: ClapTrap(void): _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std:: cout << "Default constructor called" << std:: endl;
	return ;
}

ClapTrap :: ClapTrap(const std:: string& name_para): _name(name_para), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std:: cout << "parameteric constructor called" << std:: endl;
	return;

}

ClapTrap :: ClapTrap(ClapTrap const & src) {
	std:: cout << "copy constructor called"<< std:: endl;
	*this = src;
	return;
}

ClapTrap:: ~ClapTrap() {
	std:: cout <<" Destructor called" << std:: endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    // Copy assignment operator implementation
    if (this != &rhs) {
        this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;

    }
    return *this;
}

std:: string ClapTrap:: getName() const
{
	return this->_name;
}

void ClapTrap:: setName(std:: string nom)
{
	this->_name = nom;
	return;
}


void attack(const std::string& target) {

	if (this->_hitPoint <= 0) {

		std:: cout <<"ClapTrack attacks"<<std:: endl;
	}
	

}

void takeDamage(unsigned int amount) {

}

void beRepaired(unsigned int amount) {
	
}