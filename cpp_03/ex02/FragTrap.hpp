#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include<iostream>
#include <iomanip>
#include <string>

class FragTrap : public ClapTrap{

	public:

	FragTrap(void);// Default constructor
	FragTrap (const std:: string& name_para);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap &	operator=(FragTrap const & rhs);
	
	void FragTrapStatus(void);
    void highFivesGuys(void);
};

#endif