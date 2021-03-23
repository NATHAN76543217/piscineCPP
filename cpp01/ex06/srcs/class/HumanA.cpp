#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA()
{
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanA::attack()
{
	std::cout << this->_name << " attack with his " << this->_weapon.getType() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */