#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : _type("default")
{
	std::cout << "WrongAnimal constructor() called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) : _type(src._type)
{
	std::cout << "WrongAnimal constructor(WrongAnimal) called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			WrongAnimal::makeSound( void ) const
{
	std::cout << "GRAJKIEE!! This is the sound of a wrongAnimal" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		WrongAnimal::getType( void ) const
{
	return this->_type;
}

/* ************************************************************************** */