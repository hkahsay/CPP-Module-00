#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap a("ClapTrap");

	a.ClapTrapStatus();
	a.attack("weapon_ClapTrap");
	a.takeDamage(30);
	a.beRepaired(20);
	return (0);

}
