#include <iostream>
#include "ClapTrap.hpp"
#include"ScavTrap.hpp"

int main( void ) {

	ClapTrap a("ClapTrap");
	ScavTrap b("ScavTrap");

	a.ClapTrapStatus();
	a.attack("weapon_ClapTrap");
	a.takeDamage(5);
	a.beRepaired(20);

	b.ScavTrapStatus();
	b.attack("weapon_ScavTrap");
	b.guardGate();
	return (0);

}
