#ifndef AMateria_HPP
#define AMateria_HPP

#include<iostream>
#include<string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string  _type;
	public:
		AMateria();
		virtual~AMateria();
		AMateria(AMateria const  & src);
		AMateria & operator = (AMateria const & rhs);
		AMateria(std::string & type);
		std::string const & getType() const; //Returns the materia type
		void setType(std:: string type);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};



#endif
