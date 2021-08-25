#include "Karen.hpp"

/*
** --------------------------------- STATICS ----------------------------------
*/
	const std::string Karen::levelNames[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int const Karen::nbr_levels = NBR_LEVELS;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Karen::Karen() 
{
	this->_level[0] = &Karen::debug;
	this->_level[1] = &Karen::info;
	this->_level[2] = &Karen::warning;
	this->_level[3] = &Karen::error;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Karen::~Karen()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void Karen::complain(std::string level) const
{
	for (int i = 0; i <= 3; i++)
	{
		if (level == this->levelNames[i])
			(this->*_level[i])();
	}
}

void Karen::debug( void ) const
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I just love it!" << std::endl;
}

void Karen::info( void ) const
{
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning( void ) const
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error( void ) const
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */