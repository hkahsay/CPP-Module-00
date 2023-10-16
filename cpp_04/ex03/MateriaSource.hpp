#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class AMateria;
class ICharacter;
class Character;

class MateriaSource: public IMateriaSource
{
	private:
		static const int _numOfMateria = 4;
		AMateria* _materias[_numOfMateria];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const & src);
		MateriaSource& operator = (const MateriaSource & rhs);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
