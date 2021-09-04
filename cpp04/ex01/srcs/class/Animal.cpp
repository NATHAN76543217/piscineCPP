#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("default")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal & src ) : _type(src._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
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

void			Animal::makeSound( void ) const
{
	std::cout << "**Animal sound**" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Animal::getType( void ) const
{
	return this->_type;
}

/* ************************************************************************** */