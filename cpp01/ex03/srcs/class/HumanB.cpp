#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanB " << this->_name << " created." << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attack with his " << this->_weapon->getType() << std::endl; 
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	HumanB::setWeapon(Weapon & weapon)
{
	this->_weapon = &weapon;
}

/* ************************************************************************** */