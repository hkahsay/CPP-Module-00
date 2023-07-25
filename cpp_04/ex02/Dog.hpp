#ifndef DOG_HPP
#define DOG_HPP

#include<iostream>
#include<string>
#include"AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {

	private:
	Brain* _brain;

	public:
	Dog(void);// Default constructor
	Dog(const std:: string & name);
	Dog(Dog const & src);
	~Dog(void);
	Dog & operator=( Dog const & rhs );
	void makeSound(void)const; // Override the virtual function
	Brain* getBrain(void);
	// void setType(std::string type);



};



#endif
