#include"DiamondTrap.hpp"
#include"ClapTrap.hpp"
#include"FragTrap.hpp"
#include"ScavTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap(), ScavTrap(), FragTrap(), _name("default") 
{
    std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
	_hitPoint = FragTrap::getHitpoints();
	_energyPoint = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
}

//a. ClapTrap(name + "_clap_name"): This initializes the ClapTrap 
//base class by calling its constructor with the name + "_clap_name" as a parameter.
// This means that the ClapTrap part of the DiamondTrap will have its name attribute 
//set to name + "_clap_name". This is done by using the ClapTrap constructor 
//that takes a const std::string& parameter.

DiamondTrap::DiamondTrap(const std::string& name) 
: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) 
{
	_hitPoint = FragTrap::getHitpoints();
	_energyPoint = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
    std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		_name= rhs._name;
	}
	return *this;
}


void DiamondTrap::attack(const std::string& target) {
    std::cout << _name << " Use ScavTrap's attack target name:" << target << std::endl;
	ScavTrap::attack(target);
}
void DiamondTrap:: whoAmI() 
{
	std::cout<< "hello I am " << _name << " and I am grand child of ClapTrap -> "
	<< ClapTrap::_name << ". " <<std:: endl;
}

void DiamondTrap::DiamondTrapStatus( void )
{
	std::cout << std::endl;
	std::cout << "name   		" << _name << std::endl;
	std::cout << "hitpoint(F)		" << _hitPoint << std::endl;
	std::cout << "energypoint(S)		" << _energyPoint << std::endl;
	std::cout << "attackDamage(F)		" << _attackDamage << std::endl << std::endl;
	return ;
}

