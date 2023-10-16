#ifndef CRAPTRAP_HPP
#define CRAPTRAP_HPP

#include <iostream>
#include <iomanip>
#include <string>
class ClapTrap {

	protected:

	std:: string	_name;
	int _hitPoint;
	int _energyPoint;
	int _attackDamage;

	public:

	ClapTrap(void);// Default constructor
	ClapTrap (const std:: string& name_para);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap & operator = (const ClapTrap& rhs);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
 	void beRepaired(unsigned int amount);
	void ClapTrapStatus( void );
	


};


#endif
