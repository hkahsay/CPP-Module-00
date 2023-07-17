#include <iostream>
#include "ClapTrap.hpp"
#include"ScavTrap.hpp"

int main( void ) {

	ClapTrap a("hanniel");
	ScavTrap b("hadriel");
	a.attack("hermon");
	b.attack("hermon");


	a.beRepaired(20);
	return (0);

}
