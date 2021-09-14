#include "Character.hpp"

/*
** --------------------------------- STATICS ----------------------------------
*/


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name("default")
{
	this->_init_materias();
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const & name) : _name(name)
{
	this->_init_materias();
	std::cout << "Character named constructor called" << std::endl;
}

Character::Character( const Character & src ) : _name(src._name)
{
	std::cout << "Character copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (uint i = 0; i < Character::maxMaterias; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
	std::cout << "Character destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		for (uint i = 0; i < Character::maxMaterias; i++)
		{
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
			if ( rhs._materia[i] == NULL)
				this->_materia[i] = NULL;
			else
				this->_materia[i] = rhs._materia[i]->clone();
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & character )
{
	o << "Character " << character.getName() << " is equiped with" << std::endl;
	for (uint i = 0; i < Character::maxMaterias; i++)
	{
		if (character.getItem(i) != NULL)
			o << "- " << character.getItem(i)->getType() << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Character::equip( AMateria* m)
{
	if (this->_equiped >= Character::maxMaterias)
	{
		std::cout << this->_name << " cannot equip: inventory full" << std::endl; 
		return ;
	}
	for (uint i = 0; i < Character::maxMaterias; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			this->_equiped++;
			std::cout << this->_name << " is equiped with " << m->getType() << std::endl; 
			return ;
		}
	}
}

void		Character::unequip( int idx )
{
	if (idx >= 0 || (uint)idx <= Character::maxMaterias)
	{
		if (this->_materia[idx] != NULL)
		{
			std::cout << this->_name << " unequiped with " << this->_materia[idx]->getType() << std::endl; 
			// delete this->_materia[idx];
			this->_materia[idx] = NULL;
			this->_equiped--;
		}
		else
			std::cout << this->_name << " Cannot unequip: empty inventory on slot(" << idx << ")" << std::endl; 
	}
	else
		std::cout << this->_name << " Cannot unequip: inventory empty at this slot(" << idx << ")" << std::endl; 
	return ;
}

void		Character::use( int idx, ICharacter& target)
{
	if (idx >= 0 && (uint)idx < Character::maxMaterias)
	{
		if (this->_materia[idx] != NULL)
			this->_materia[idx]->use(target);
		else
			std::cout << "Cannot use materia: No materia equiped at this slot(" << idx << ")" << std::endl;
	}
	else {
		std::cout << "Cannot use materia: Index " << idx << " out of range [0-3]" << std::endl;
	}
}

void		Character::_init_materias( void )
{
	for ( uint i = 0; i < Character::maxMaterias; i++)
	{
		this->_materia[i] = NULL;
	}
	this->_equiped = 0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName( void ) const
{
	return this->_name;
}

AMateria const*		Character::getItem( uint idx ) const
{
	if (idx > Character::maxMaterias)
		return NULL;
	return this->_materia[idx];
}

/* ************************************************************************** */