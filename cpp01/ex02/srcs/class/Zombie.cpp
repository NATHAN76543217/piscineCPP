#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie() : _name("default"), _type("default")
{
	std::cout << "Zombie is born." << std::endl;
}

// Zombie::Zombie( const Zombie & src )
// {
// }

Zombie::Zombie(std::string type, std::string name) : _name(name), _type(type)
{
	std::cout << "The zombie " << this->_name << " is born." << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie()
{
	std::cout << "The zombie " << this->_name << " died." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Zombie::getName(void) const
{
	return this->_name;
}

std::string Zombie::getType(void) const
{
	return this->_type;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << std::setw(5) << " (" << this->_type << ") Braiiiiiiiiiiinnnsss....." << std::endl;
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */