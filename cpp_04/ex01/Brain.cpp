#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


#include "Brain.hpp"

#include <iostream>

Brain::Brain(){

	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < NUMBER_OF_IDEAS; i++)
		_ideas[i] = "Brain creats an Ideas";
	
	return ;
 
}

Brain::Brain(const Brain& src)  : Animal() {
    std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
	return;
}

Brain &	Brain::operator=(Brain const & rhs)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < NUMBER_OF_IDEAS; i++)
		{
			_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

std:: string Brain:: getIdeas(int i) {

	return _ideas[i];
}

void Brain:: setIdeas(int i, std:: string ideas) {

	if(i < NUMBER_OF_IDEAS && !ideas.empty())
		_ideas[i]= ideas;
}
