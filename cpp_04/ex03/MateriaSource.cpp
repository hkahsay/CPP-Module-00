#include "MateriaSource.hpp"

MateriaSource:: MateriaSource(void){

    for (int i = 0; i < _numOfMateria; i++)
    {
        this->_materias[i] = NULL; // Initialize all pointers to NULL initially
    }
	std:: cout << "MateriaSource Default constructor called"<< std:: endl;
	return ;
}

MateriaSource:: ~MateriaSource(void) 
{
    for (int i = 0; i < _numOfMateria; i++)
    {
        delete this->_materias[i]; 
    }
	std:: cout <<"MateriaSource Destructor called "<< std:: endl;
}


MateriaSource::MateriaSource(MateriaSource const& src) {

    for (int i = 0; i < _numOfMateria; i++) {
        if (src._materias[i]) {
            this->_materias[i] = src._materias[i]->clone();
        } else {
            this->_materias[i] = NULL;
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
        for (int i = 0; i < _numOfMateria; i++)
        {
            if (this->_materias[i])
            {
                delete this->_materias[i];
                this->_materias[i] = NULL;
            }
            if (rhs._materias[i])
                this->_materias[i] = rhs._materias[i]->clone();
        }

    }
    return *this;
}

void MateriaSource:: learnMateria(AMateria* m) {
    // if (this->_numOfMateria  == 4 || m == NULL)
    // {
    //     std::cout << "this->_numOfMateria1" <<std::endl;
	// 	return ;
    // }
    for (int i = 0; i < this->_numOfMateria; i++)
    {
        std:: cout << "for loop "<<std::endl;

        if (this->_materias[i] == NULL)
        {
            this->_materias[i] = m;
            std::cout << "learnmateria" <<this->_materias[i]->getType() <<std::endl;
            return;
        }
    }
    return;
  
}


AMateria* MateriaSource:: createMateria(std::string const & type) {
    std::cout << "type: " << type << std::endl;
    for (int i = 0; i < this->_numOfMateria; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type) // Check if the type matches any learned Materia
        {
            return this->_materias[i]->clone(); // Return a copy of the matching Materia
	        std:: cout << " ccc2 Default Destructor called"<<std:: endl;
        }

    }

	// std:: cout << " ccc3 Default Destructor called"<<std:: endl;
    return NULL; // Return NULL if the type is unknown or not learned
}
