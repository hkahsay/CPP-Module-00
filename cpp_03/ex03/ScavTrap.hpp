#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
	ScavTrap(void);// Default constructor
	ScavTrap (const std:: string& name_para);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap &	operator=(ScavTrap const & rhs);
	void guardGate();
	void attack(const std::string& target);
	int getHitpoints()const;
	int getEnergyPoints()const;
	int getAttackDamage()const;
	void ScavTrapStatus(void);


};



#endif
