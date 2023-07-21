#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include<string>
#include<iostream>

class WrongAnimal {
	protected:
	 std:: string _type;
	public:

	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal(const std:: string& name);
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal & operator = (const WrongAnimal &rhs);
	const std::string& getType() const;
	virtual void makeSound() const;


};
#endif