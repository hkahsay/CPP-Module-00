#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"
#include <string>




class FragTrap : virtual public ClapTrap{

	public:

	FragTrap(void);// Default constructor
	FragTrap (const std:: string& name_para);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap &	operator=(FragTrap const & rhs);
	void FragTrapStatus(void);
    void highFivesGuys(void);
	int getHitpoints()const;
	int getEnergyPoints()const;
	int getAttackDamage()const;
};

#endif