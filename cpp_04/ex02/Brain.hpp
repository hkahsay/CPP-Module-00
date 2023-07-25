#ifndef BRAIN_HPP
#define BRAIN_HPP

#define NUMBER_OF_IDEAS 100
#include<iostream>
#include<string>
#include <iomanip>
#include "AAnimal.hpp"

class Brain {

	private:
	 std:: string _ideas[NUMBER_OF_IDEAS];

	public:
	Brain(void);// Default constructor
	Brain(Brain const & src);
	~Brain(void);
	Brain &	operator=( Brain const & rhs );
	std::string getIdeas(int i);
	void setIdeas(int i, std::string ideas);

};



#endif
