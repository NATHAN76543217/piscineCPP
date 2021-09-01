#include "ScavTrap.hpp"

/*
** ------------------------------- STATIC --------------------------------
*/

	const unsigned int ScavTrap::_init_hp = 100;
	const unsigned int ScavTrap::_init_ep = 50;
	const unsigned int ScavTrap::_init_attack = 20;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: default constructor" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, ScavTrap::_init_hp, ScavTrap::_init_ep, ScavTrap::_init_attack)
{
	std::cout << "ScavTrap: name<" << this->getName() << "> constructor" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap: copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap<" << this->getName() << ">: destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{
	o << "ScavTrap " 	<< i.getName() <<std::endl;
	o << std::setw(10)	<< "hp: "		<< i.getHp() <<std::endl;
	o << std::setw(10)	<< "ep: "		<< i.getEp() <<std::endl;
	o << std::setw(10)	<< "attack: "	<< i.getAttack() <<std::endl;
	return o;	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap<" << this->getName() << "> entered in Gate keeper mode." << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */