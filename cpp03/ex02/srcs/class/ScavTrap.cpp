#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: default constructor" << std::endl << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap: name<" << name << "> constructor" << std::endl << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap: copy constructor" << std::endl << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap<" << this->getName() << ">: destructor" << std::endl << std::endl;
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