#include "MateriaSource.hpp"

/*
** ------------------------------- STATICS --------------------------------
*/

const unsigned int MateriaSource::maxMaterias = 4;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	this->_init_materias();
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & src ) 
{
	this->operator=(src);
	std::cout << "MateriaSource copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (uint i = 0; i < MateriaSource::maxMaterias; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		for (uint i = 0; i < MateriaSource::maxMaterias; i++)
		{
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
			if (rhs._materia[i] == NULL)
				this->_materia[i] = NULL;
			else
				this->_materia[i] = rhs._materia[i]->clone();
		}
		this->_learned = rhs._learned;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, MateriaSource const & M )
{
	o << "MateriaSource[" << M.getNbLearned() << "]:" << std::endl;
	for (uint i = 0; i < MateriaSource::maxMaterias; i++)
	{
		o << "- " << M.getMateriaType(i) << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		MateriaSource::learnMateria(AMateria* materia)
{
	if (this->_learned >= 4)
		return ;

	this->_materia[this->_learned] = materia->clone();
	++this->_learned;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (uint i = 0; i < this->_learned; i++)
	{
		if (this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();	
	}
	return NULL;
}

void		MateriaSource::_init_materias( void )
{
	for (uint i = 0; i < MateriaSource::maxMaterias; i++)
	{
		this->_materia[i] = NULL;
	}
	this->_learned = 0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const		MateriaSource::getMateriaType(uint idx) const
{
	if ( idx < MateriaSource::maxMaterias)
		return this->_materia[idx]->getType();
	return "Invalid index";
}

uint					MateriaSource::getNbLearned( void ) const
{
	return this->_learned;
}

/* ************************************************************************** */