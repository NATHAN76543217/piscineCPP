#include "ZombieHorde.hpp"

/*
** --------------------------------- GLOBALS ----------------------------------
*/

const std::string ZombieHorde::_nameList[] = { "Coucou", "Bonjours", "Ann", "Luck", "Kikou", "Eibmoz", "DeadMan" };


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ZombieHorde::ZombieHorde(int N)
{
	std::cout << "A zombie horde is created..." << std::endl;
	this->_nb_zombies = N;
	this->_zomlist = new Zombie[N];
	for ( int i=0; i<N; ++i )
		this->_zomlist[i].setName(this->_getRandomName());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ZombieHorde::~ZombieHorde()
{
	delete [] this->_zomlist;
	std::cout << "-- The zombie horde is disolved..." << std::endl;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	ZombieHorde::_getRandomName() const
{
	return this->_nameList[getRandomIndex(0, 6)];
}

void	ZombieHorde::announce()
{
	for ( int i=0; i<this->_nb_zombies; ++i )
		this->_zomlist[i].announce();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */