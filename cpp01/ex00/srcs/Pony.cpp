#include "Pony.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Pony::Pony() : age(0), name("random")
{
	std::cout << "A pony is born" << std::endl;	
	std::cout << "He have" << this->age << "years old." << std::endl;
}

Pony::Pony(const std::string name) : age(0), name(name)
{
	std::cout << "The pony " << name << " is born" << std::endl;
	std::cout << "He have " << this->age << " years old." << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Pony::~Pony()
{
	if (this->name.compare("random") == 0)
		std::cout << "A random pony died." << std::endl;
	else
		std::cout << "Pony " << this->name << " died." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Pony::jump(void)
{
	if (this->name.compare("random") == 0)
		std::cout << "A random pony jump." << std::endl;
	else
		std::cout << this->name << " jump." << std::endl;
	return ;
}

void	Pony::run(void)
{
	if (this->name.compare("random") == 0)
		std::cout << "A random pony run." << std::endl;
	else
		std::cout << this->name << " run. fast." << std::endl;
	return ;
}

void	Pony::look(void)
{
	if (this->name.compare("random") == 0)
		std::cout << "A random pony look around him." << std::endl;
	else
		std::cout << this->name << " look around him." << std::endl;
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */