#include "MateriaSource.hpp"


MateriaSource:: MateriaSource(void): _numOfMateria(0){

    for (int i = 0; i < MAX_MATERIA; ++i)
    {
        _materias[i] = NULL; // Initialize all pointers to NULL initially
    }
	std:: cout << "MateriaSource Default constructor called"<< std:: endl;
	return ;
}

MateriaSource:: ~MateriaSource() 
{
    for (int i = 0; i < _numOfMateria; ++i)
    {
        delete _materias[i]; 
        _materias[i] = NULL;
    }
	std:: cout <<"MateriaSource Destructor called "<< std:: endl;
}


MateriaSource::MateriaSource(MateriaSource const& src) : _numOfMateria(src._numOfMateria) {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (src._materias[i]) {
            _materias[i] = src._materias[i]->clone();
        } else {
            _materias[i] = NULL;
        }
    }
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

// Copy Assignment Operator
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        // Delete existing Materias in the inventory
        for (int i = 0; i < MAX_MATERIA; ++i)
        {
            if (_materias[i])
            {
                delete _materias[i];
                _materias[i] = NULL;
            }
        }
        _numOfMateria = rhs._numOfMateria;
        for (int i = 0; i < MAX_MATERIA; ++i)
        {
            if (rhs._materias[i])
                _materias[i] = rhs._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource:: learnMateria(AMateria* m) {

    if (_numOfMateria < MAX_MATERIA && m != NULL)
    {
        _materias[_numOfMateria] = m->clone();
        _numOfMateria++;
    }
}

AMateria* MateriaSource:: createMateria(std::string const & type) {

    for (int i = 0; i < _numOfMateria; ++i)
    {
        if (_materias[i]->getType() == type) // Check if the type matches any learned Materia
        {
            return _materias[i]->clone(); // Return a copy of the matching Materia
        }
    }
    return NULL; // Return NULL if the type is unknown or not learned
}
