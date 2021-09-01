#include "FragTrap.hpp"

/*
** ------------------------------- STATIC --------------------------------
*/

	const unsigned int FragTrap::_init_hp = 100;
	const unsigned int FragTrap::_init_ep = 100;
	const unsigned int FragTrap::_init_attack = 30;
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: default constructor" << std::endl;
}

FragTrap::FragTrap( std::string name) : ClapTrap(name, FragTrap::_init_hp , FragTrap::_init_ep, FragTrap::_init_attack)
{
	std::cout << "FragTrap: name<" << this->getName() << ">:constructor" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << "FragTrap: copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap<" << this->getName() << ">: destructor" << std::endl;
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