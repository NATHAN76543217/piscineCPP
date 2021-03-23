#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::readStdin(void)
{
	std::string tmp;
	while (std::getline(std::cin, tmp))
	{
		std::cout << tmp;
		if (!std::cin.eof())
			std::cout << std::endl;
	}
	return ;
}

void	Cat::read(void)
{
	std::string tmp;

	while (std::getline(this->getIfs(), tmp))
	{
		std::cout << tmp;
		if (!this->getIfs().eof())
			std::cout << std::endl;
	}
	return ;
}

int		Cat::openInFile(std::string filename)
{
	this->_ifs = new std::ifstream(filename);
	if (!this->_ifs)
		return -1;
	else if (!*this->_ifs)
	{
		std::cerr << "cat: " + filename + ": No such file or directory" << std::endl;
		delete this->_ifs;
	}
	else
		return 0;
	return -1;
}

void	Cat::file(std::string filename)
{
	if (filename == "-")
		return readStdin();
	if (this->openInFile(filename) != 0)
		return ;
	this->read();
	this->getIfs().close();

	delete this->_ifs;
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::ifstream	&Cat::getIfs(void)
{
	return *(this->_ifs);
}

std::ofstream	&Cat::getOfs(void)
{
	return *(this->_ofs);
}

/* ************************************************************************** */