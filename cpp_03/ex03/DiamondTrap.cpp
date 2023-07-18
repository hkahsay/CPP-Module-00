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

DiamondTrap::DiamondTrap(const std::string& name) 
: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) 
{
    std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
	_hitPoint = FragTrap::getHitpoints();
	_energyPoint = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
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
    std::cout << "DiamondTrap " << _name << " attacks " << target << std::endl;
}

// void DiamondTrap::DiamondTrapStatus( void )
// {
// 	std::cout << std::endl;
// 	std::cout << "DiamondTrap _name	" << _name << std::endl;
// 	std::cout << "hitpoint		    " << _hitPoint << std::endl;
// 	std::cout << "energypoint		" << _energyPoint << std::endl;
// 	std::cout << "attackDamage		" << _attackDamage << std::endl << std::endl;
// 	return ;
// }
// void DiamondTrap::DiamondTrapStatus( void )
// {
// 	std::cout << std::endl;
// 	std::cout << "DiamondTrap _name	" << getName() << std::endl;
// 	std::cout << "hitpoint		    " << getHitPoint() << std::endl;
// 	std::cout << "energypoint		" << getEnergyPoint() << std::endl;
// 	std::cout << "attackDamage		" << getAttackDamage() << std::endl << std::endl;
// 	return ;
// }
