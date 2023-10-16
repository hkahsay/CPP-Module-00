#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap() {

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
	*this = src;
	return ;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

int ScavTrap::getHitpoints()const {
	return _hitPoint;
}

int ScavTrap::getEnergyPoints()const {
	return _energyPoint;
}

int ScavTrap::getAttackDamage()const
{
	return _attackDamage;

}

void ScavTrap:: attack(const std::string& target){
	if (this->_hitPoint <= 0 || this->_energyPoint <= 0) {

		std:: cout <<"Sorry! ScavTrap target name:- " <<this->_name
		<<" cannot attack because you have no energyPoints or hitPoints "<<std:: endl;
	}
	else
	{
		std:: cout<<this->_name <<" target name:- "<< target<< ", causing "
		<<this->_attackDamage << " points of damage !"<<std::endl;
		this->_energyPoint -= 1;

	}
	std::cout <<std::endl;
}

void ScavTrap:: guardGate() {
	if (this->_hitPoint <= 0){
		std:: cout <<"Sorry!" <<this->_name << "  is not in Gate keeper mode. " <<this->_name 
		<<" cannot attack because you have no energyPoints or hitPoints "<<std:: endl;
		return;
	}
	std:: cout<< "ScavTrap is now in Gate keeper mode."<< std:: endl;
	return;

}


void ScavTrap::ScavTrapStatus( void )
{
	std::cout << std::endl;
	std::cout << "name      	    " << this->_name << std::endl;
	std::cout << "hitpoint		" << this->_hitPoint << std::endl;
	std::cout << "energypoint		" << this->_energyPoint << std::endl;
	std::cout << "attackDamage		" << this->_attackDamage << std::endl << std::endl;
	return ;
}



