#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Waepon created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon()
{
	std::cout << "Waepon destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Weapon::getType( void ) const
{
	return this->_type;
}

void		Weapon::setType( std::string type )
{
	this->_type = type;
}

/* ************************************************************************** */