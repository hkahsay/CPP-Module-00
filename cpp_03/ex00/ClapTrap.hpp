#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include<iostream>
#include <iomanip>

class ClapTrap {

	private:

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
	std:: string getName()const;
	void setName(std:: string nom);


};

std::ostream& operator<< (std:: ostream & o, ClapTrap const & rhs);
// std::ostream& operator<< (std:: ostream & o, ClapTrap const & i);
	
#endif