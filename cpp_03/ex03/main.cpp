#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main( void ) {

	ClapTrap a("ClapTrap");
	ScavTrap b("ScavTrap");
	FragTrap c("FragTrap");
	DiamondTrap d("DiamondTrap");

	a.ClapTrapStatus();
	a.attack("weapon_ClapTrap");
	a.takeDamage(30);
	a.beRepaired(20);

	b.ScavTrapStatus();
	b.attack("weapon_ScavTrap");
	b.guardGate();

	c.FragTrapStatus();
	c.highFivesGuys();

	d.DiamondTrapStatus();
	d.attack("weapon_diamond");
	d.whoAmI();



	return (0);

}
