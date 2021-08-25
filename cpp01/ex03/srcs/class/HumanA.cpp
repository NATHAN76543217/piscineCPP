#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string name, Weapon & weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << this->_name << " created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attack with his " << this->_weapon.getType() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */