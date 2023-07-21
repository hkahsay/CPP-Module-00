#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include <string>




class Cat : public Animal{

	public:

	Cat(void);// Default constructor
	Cat (const std:: string& name);
	Cat(Cat const & src);
	~Cat(void);
	Cat &	operator=(Cat const & rhs);
	void makeSound()const;// Override the virtual function

};

#endif