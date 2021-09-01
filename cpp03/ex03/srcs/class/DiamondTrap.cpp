#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() :
	ClapTrap("default_clap_name", FragTrap::_init_hp, ScavTrap::_init_ep, FragTrap::_init_attack ), 
	FragTrap(),
	ScavTrap(),
	_name("default")
{
	std::cout << "DiamondTrap: default constuctor" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap( std::string name) :
	ClapTrap(name + "_clap_name", FragTrap::_init_hp, ScavTrap::_init_ep, FragTrap::_init_attack ), 
	FragTrap(name), 
	ScavTrap(name),
	_name(name)
{
	std::cout << "DiamondTrap: name<" << this->_name << "> constructor" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name)
{
	std::cout << "DiamondTrap: copy constuctor" << std::endl << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << std::endl << "DiamTrap<" << this->getName() << ">: destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
		this->_name = rhs.getName();
	}
	return *this;
}


std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	o << "DiamondTrap " << std::endl;
	i.whoAmI();
	o << std::setw(10)	<< "hp: "		<< i.getHp() <<std::endl;
	o << std::setw(10)	<< "ep: "		<< i.getEp() <<std::endl;
	o << std::setw(10)	<< "attack: "	<< i.getAttack() <<std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		DiamondTrap::whoAmI( void ) const
{
	std::cout << std::setw(10) << "name: " << this->getName() << std::endl;
	std::cout << std::setw(10) << "CT_name: " << this->ClapTrap::getName() << std::endl;
}

void		DiamondTrap::attack( ClapTrap & target)
{
	this->ScavTrap::attack(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const&	DiamondTrap::getName( void ) const
{
	return this->_name;
}

void				DiamondTrap::setName( std::string name )
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
}
/* ************************************************************************** */