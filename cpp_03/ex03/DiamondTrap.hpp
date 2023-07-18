#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include<iostream>
#include <iomanip>
#include"ClapTrap.hpp"
#include"FragTrap.hpp"
#include"ScavTrap.hpp"

//class DiamondTrap: virtual public ScavTrap, virtual public FragTrap 

class DiamondTrap: public ScavTrap, public FragTrap {

	private:

	std:: string	_name;
	// int _hitPoint;
	// int _energyPoint;
	// int _attackDamage;

	public:

	DiamondTrap(void);// Default constructor
	DiamondTrap (const std:: string& name_para);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap(void);
	DiamondTrap & operator = (const DiamondTrap& rhs);
	void attack(const std::string& target);
	void whoAmI();
	// void DiamondTrapStatus( void );


};

	
#endif