#include"ClapTrap.hpp"
# include <iostream>

ClapTrap:: ClapTrap(void): _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std:: cout << "ClapTrap Default constructor called"<< std:: endl;
	return ;
}

ClapTrap:: ~ClapTrap() {
	std:: cout <<"ClapTrap Destructor called " << this->_name << " has been destroyed"<< std:: endl;
}

ClapTrap :: ClapTrap(const std:: string& name_para): _name(name_para), _hitPoint(10), _energyPoint(10), _attackDamage(0){
    std::cout << "ClapTrap Parameterized constructor called" << std::endl;
	return;

}

ClapTrap :: ClapTrap(ClapTrap const & src) {
	std:: cout << "ClapTrap copy constructor called"<< std:: endl;
	*this = src._name;
	_hitPoint = src._hitPoint;
    _energyPoint = src._energyPoint;
    _attackDamage = src._attackDamage;
	return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
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

		std:: cout <<"Sorry! ClapTrap target name:- " <<this->_name 
		<<" cannot attack because you have no energyPoints or hitPoints "<<std:: endl;
	}
	else
	{
		std:: cout <<this->_name <<" target name:- "<< target<< ", causing "<<this->_attackDamage 
		<< " points of damage !"<<std::endl;
		this->_energyPoint -= 1;

	}
	std::cout <<std::endl;

	return;
}

void ClapTrap:: takeDamage(unsigned int amount) {
	if (this->_hitPoint <= 0)
	{
		std:: cout <<"Sorry! ClapTrap target name:- " <<this->_name 
		<<" cannot attack because you have no energyPoints or hitPoints "<<std:: endl;
		return ;
	}
	std:: cout << this->_name <<" take " <<amount << "hitPoints" << std:: endl;
	this->_hitPoint -= amount;
	std:: cout <<this->_name <<"'s available hitPoint after damage: " <<this->_hitPoint <<std::endl;

}

void ClapTrap:: beRepaired(unsigned int amount) {
	if(this->_hitPoint <= 0 || this->_energyPoint <= 0)
	{
		std:: cout <<"Sorry! cannot repaire or add amount of "<<amount 
		<<" because you have no energyPoints or hitPoints. "<<std:: endl;

	}
	else
	{
		std:: cout <<this->_name <<" repairs itself by adding "<<amount << " of points !"<<std::endl;

		this->_energyPoint -= 1;
		this->_hitPoint += amount;
		std:: cout<<this->_name <<"'s available hitPoint after repaired: " <<this->_hitPoint <<std::endl;
		std:: cout<<this->_name <<"'s available energyPoints after repaired: " <<this->_energyPoint <<std::endl;

	}
	std::cout <<std::endl;
	
}

void ClapTrap::ClapTrapStatus( void )
{
	std::cout << std::endl;
	std::cout << "name		        " << this->_name << std::endl;
	std::cout << "hitpoint		" << this->_hitPoint << std::endl;
	std::cout << "energypoint		" << this->_energyPoint << std::endl;
	std::cout << "attackDamage		" << this->_attackDamage << std::endl << std::endl;
	return ;
}