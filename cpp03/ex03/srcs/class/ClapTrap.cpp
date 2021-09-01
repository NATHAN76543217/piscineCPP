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
	std::cout << "ClapTrap: name<" << name << "> constuctor" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int attack) : _name(name), _hp(hp), _ep(ep), _attack(attack)
{
	std::cout << "ClapTrap: name<" << name << "> hp<" << hp << "> ep<" << ep << "> attack<" << attack << "> constuctor" << std::endl;
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
	std::cout << "ClapTrap<" << this->_name << ">: destructor" << std::endl;
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
	o << "ClapTrap " 	<< i.getName()	<< std::endl;
	o << std::setw(10) 	<< "hp: "		<< i.getHp() <<std::endl;
	o << std::setw(10) 	<< "ep: "		<< i.getEp() <<std::endl;
	o << std::setw(10) 	<< "attack: "	<< i.getAttack() <<std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		ClapTrap::attack(ClapTrap & target) const
{
	std::cout << "ClapTrap <" << this->_name << ">: attack " 
		<< target._name << ", causing " << this->_attack << " points of damage!" << std::endl;
	target.takeDamage(this->_attack);
}
void		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take " 
		<< amount << " points of damage!" << std::endl;
	
	this->_hp -= amount;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " be repaired of " 
		<< amount << " points of damage!" << std::endl;
	this->_hp += amount;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const&ClapTrap::getName( void ) const
{
	return this->_name;
}

unsigned int	ClapTrap::getHp( void ) const
{
	return this->_hp;
}

unsigned int	ClapTrap::getEp( void ) const
{
	return this->_ep;
}

unsigned int	ClapTrap::getAttack( void ) const
{
	return this->_attack;
}

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
}

/* ************************************************************************** */