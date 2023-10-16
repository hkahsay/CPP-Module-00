#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <string>
class AAnimal {

	protected:

	std:: string	_type;

	public:

	AAnimal(void);// Default constructor
	AAnimal(const std:: string & src);

	AAnimal(AAnimal const & src);
	virtual ~AAnimal(void);
	//virtual functions must have a virtual destructor.
	AAnimal & operator = (const AAnimal& rhs);
	const std:: string& getType() const;
	virtual void makeSound()const = 0;
	


};


#endif

// An abstract class is a concept in object-oriented programming (OOP) that serves 
// as a blueprint or template for other classes. It cannot be instantiated on its own, 
// meaning you cannot create objects directly from an abstract class. Instead, 
// it is meant to be subclassed, and its subclasses (concrete classes) 
// provide specific implementations for the abstract class's methods and properties.


// Abstract Methods: Abstract classes can have one or more abstract methods, 
// which are declared without any implementation. These methods act as placeholders, 
// defining a method signature that must be implemented by the subclasses.
