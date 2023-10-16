#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define MAX_MATERIA 4
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _materias[MAX_MATERIA];
		int _numOfMateria;
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const & src);
		MateriaSource& operator = (const MateriaSource & rhs);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
