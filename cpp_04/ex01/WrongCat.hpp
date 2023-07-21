#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include<string>
#include<iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

	public:

	WrongCat(void);
	~WrongCat(void);
	WrongCat(const std:: string& name);
	WrongCat(WrongCat const &src);
	WrongCat & operator = (WrongCat const &rhs);
	void makeSound()const;


};
#endif