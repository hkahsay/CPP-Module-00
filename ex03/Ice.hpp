#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice : public AMateria {
	public :
		Ice();
		~Ice();
		Ice(Ice const  & src);
		Ice & operator = (Ice const & rhs);
		Ice(std::string & type);
		Ice(const std:: string & type);
		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif
