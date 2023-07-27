#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria {

	public :
		Cure();
		~Cure();
		Cure(Cure const  & src);
		Cure & operator = (Cure const & rhs);
		Cure(std::string & type);
		Cure(const std:: string & type);
		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif
