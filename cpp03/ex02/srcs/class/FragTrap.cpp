#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: default constructor" << std::endl << std::endl;
}

FragTrap::FragTrap( std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap<" << this->getName() << ">:constructor" << std::endl << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << "FragTrap<" << this->getName() << ">:copy constructor" << std::endl << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap<" << this->getName() << ">: destructor" << std::endl << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << "FragTrap " 	<< i.getName()	<< std::endl;
	o << std::setw(10)	<< "hp: "		<< i.getHp() <<std::endl;
	o << std::setw(10)	<< "ep: "		<< i.getEp() <<std::endl;
	o << std::setw(10)	<< "attack: "	<< i.getAttack() <<std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	FragTrap::highFivesGuys( void ) const
{
	std::cout << "FragTrap<" << this->getName() << ">: Hey guys!!! Let's HIGH FIVE!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */