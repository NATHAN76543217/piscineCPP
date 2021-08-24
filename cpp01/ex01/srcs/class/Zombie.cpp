#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie() : _name("default") 
{
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) 
{
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Zombie::announce( void ) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
** --------------------------------- ACCESSORS ----------------------------------
*/

void		Zombie::setName( std::string name )
{
	this->_name = name;
}

/* ************************************************************************** */