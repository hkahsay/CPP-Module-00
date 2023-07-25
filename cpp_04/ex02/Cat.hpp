#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <iomanip>
#include "AAnimal.hpp"
#include <string>
#include "Brain.hpp"





class Cat : public AAnimal{

	private:
	Brain* _brain;

	public:

	Cat(void);// Default constructor
	Cat(Cat const & src);
	~Cat(void);
	Cat &	operator=(Cat const & rhs);
	void makeSound(void)const; // Override the virtual function
	Brain* getBrain(void)const;


};

#endif
