#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main( void ) {

	ClapTrap a("hanniel");
	FragTrap b("hadriel");
	DiamondTrap d("Diamond");
	//a.attack("hermon");
	a.attack("hermon");

	b.highFivesGuys();

	// d.DiamondTrapStatus();
	a.beRepaired(20);
	return (0);

}
