#include"ClapTrap.hpp"
# include <iostream>

ClapTrap:: ClapTrap(void): _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std:: cout << "Default constructor called"<< std:: endl;
	return ;
}

ClapTrap:: ~ClapTrap() {
	std:: cout <<"'Destructor called' " << this->_name << " has been destroyed"<< std:: endl;
}

ClapTrap :: ClapTrap(const std:: string& name_para): _name(name_para), _hitPoint(10), _energyPoint(10), _attackDamage(0){
	std:: cout << this->_name << "'s available hitpoints: " << this->_hitPoint << std:: endl;
	std:: cout << this->_name << "'s available energypoints: " << this->_energyPoint << std:: endl;
	std:: cout << this->_name << "'s attackDamage: " << this->_attackDamage << std:: endl;
	std::cout <<std::endl;
	return;

}

ClapTrap :: ClapTrap(ClapTrap const & src) {
	std:: cout << "copy constructor called"<< std:: endl;
	*this = src._name;
	_hitPoint = src._hitPoint;
    _energyPoint = src._energyPoint;
    _attackDamage = src._attackDamage;
	return;
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


void ClapTrap::attack(const std::string& target) {

	if (this->_hitPoint <= 0 || this->_energyPoint <= 0) {

		std:: cout <<"Sorry!" <<target << " ClapTrap target name:- " <<this->_name <<" cannot attack because you have no energyPoints or hitPoints "<<std:: endl;
	}
	else
	{
		std:: cout<< "ClapTrap " <<this->_name <<" target name:- "<< target<< ", causing "<<this->_attackDamage << " points of damage !"<<std::endl;
		this->_energyPoint -= 1;

	}
	std::cout <<std::endl;

	return;
}

void ClapTrap:: takeDamage(unsigned int amount) {
	std:: cout << "ClapTrap "<< this->_name <<" took " <<amount << "hitPoints" << std:: endl;
	this->_hitPoint -= amount;
	std:: cout<< "ClapTrap " <<this->_name <<"'s available hitPoint: " <<this->_hitPoint <<std::endl;

}

void ClapTrap:: beRepaired(unsigned int amount) {
	if(this->_hitPoint <= 0 || this->_energyPoint <= 0)
	{
		std:: cout <<"Sorry!" <<" cannot repaire or add amount of "<<amount <<" because you have no energyPoints or hitPoints. "<<std:: endl;

	}
	else
	{
		std:: cout<< "ClapTrap " <<this->_name <<" repairs itself by adding "<<amount << " of points !"<<std::endl;

		this->_energyPoint -= 1;
		this->_hitPoint += amount;
		std:: cout<< "ClapTrap " <<this->_name <<"'s available hitPoint: " <<this->_hitPoint <<std::endl;
		std:: cout<< "ClapTrap " <<this->_name <<"'s available energyPoints: " <<this->_energyPoint <<std::endl;

	}
	std::cout <<std::endl;
	
}

