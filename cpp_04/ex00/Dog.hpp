#ifndef DOG_HPP
#define DOG_HPP

#include<iostream>
#include<string>
#include <iomanip>
#include"Animal.hpp"

class Dog: public Animal {

	public:
	Dog(void);// Default constructor
	Dog(Dog const & src);
	~Dog(void);
	Dog &	operator=( Dog const & rhs );
	Dog(const std:: string & name);
	void makeSound()const; // Override the virtual function




};



#endif
