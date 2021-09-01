#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() : _name("default"), _hp(10), _ep(10), _attack(0)
{
	std::cout << "ClapTrap: default constuctor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _attack(0)
{
	std::cout << "ClapTrap: str<" << name << "> constuctor" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) : _name(src._name), _hp(src._hp), _ep(src._ep), _attack(src._attack)
{
	std::cout << "ClapTrap: copy constuctor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_attack = rhs._attack;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	o << "ClapTrap " 	<< i.getName() <<std::endl;
	o << std::setw(10) << "hp: "		<< i.getHp() <<std::endl;
	o << std::setw(10) << "ep: "		<< i.getHp() <<std::endl;
	o << std::setw(10) << "attack: "	<< i.getAttack() <<std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		ClapTrap::attack(std::string & target)
{
	std::cout << "ClapTrap " << this->_name << " attack " 
		<< target << ", causing " << this->_attack << " points of damage!" << std::endl;
}
void		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take " 
		<< amount << " points of damage!" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " be repaired of " 
		<< amount << " points of damage!" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		ClapTrap::getName( void ) const
{
	return this->_name;
}

int		ClapTrap::getHp( void ) const
{
	return this->_hp;
}

int		ClapTrap::getEp( void ) const
{
	return this->_ep;
}

int		ClapTrap::getAttack( void ) const
{
	return this->_attack;
}

/* ************************************************************************** */