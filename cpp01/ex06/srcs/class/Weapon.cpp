#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(std::string type) : _type(type)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const &Weapon::getType(void)
{
	return this->_type;
}

/* ************************************************************************** */