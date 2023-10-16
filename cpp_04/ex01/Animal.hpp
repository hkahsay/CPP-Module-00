#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <string>
class Animal {

	protected:

	std:: string	_type;

	public:

	Animal(void);// Default constructor
	Animal(const std:: string & src);

	Animal(Animal const & src);
	virtual ~Animal(void);
	//virtual functions must have a virtual destructor.
	Animal & operator = (const Animal& rhs);
	const std:: string& getType() const;
	virtual void makeSound()const;
	


};


#endif
