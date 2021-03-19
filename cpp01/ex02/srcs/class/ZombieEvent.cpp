#include "ZombieEvent.hpp"


/*
** --------------------------------- GLOBALS ----------------------------------
*/

static const std::string nameList[] = {"coucou", "bonjours", "Ann", "Luck", "kikou", "eibmoz", "deadman"};

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ZombieEvent::ZombieEvent() : _type("default")
{
	std::cout << "a zombie event is create." << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ZombieEvent::~ZombieEvent()
{
	std::cout << "a zombie event is destroyed." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

Zombie * ZombieEvent::newZombie (std::string name)
{
	return new Zombie(this->_type, name);
}

void	ZombieEvent::setZombieType (std::string type)
{
	this->_type = type;
}

void	ZombieEvent::randomChump()
{
	Zombie z(this->_type, this->getRandomName());
	z.announce();
	return ;
}

std::string	ZombieEvent::getRandomName() const
{
	std::random_device seedGen; // obtain a random number (seed) from hardware
    std::mt19937 gen(seedGen()); // create generator from seed
    std::uniform_int_distribution<> distr(0, 6); // define the range

	return nameList[distr(gen)];
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */