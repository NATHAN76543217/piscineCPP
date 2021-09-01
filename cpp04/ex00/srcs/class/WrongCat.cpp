#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat constructor() called" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src)
{
	std::cout << "WrongCat constructor(WrongCat) called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "WrongCat = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */