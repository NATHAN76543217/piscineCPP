#include "Logger.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Logger::Logger(std::string filename) : _filename(filename)
{
	Actions funcs[2] = { &Logger::logToConsole, &Logger::logToFile };
	std::string choices[2] = { "cout" , "file" };
	for (int i = 0; i < 2; i++)
	{
		this->actions[i] = funcs[i];
		this->choices[i] = choices[i];
	}
	this->_ofs.open(filename, std::ofstream::out | std::ofstream::app);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Logger::~Logger()
{
	this->_ofs.close();
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Logger::log(std::string const & dest, std::string const & message)
{
	for (int i = 0; i < 2; i++)
	{
		if (this->choices[i] == dest)
			(this->*actions[i])(makeLogEntry(message));
	}
	return ;
}

std::string	Logger::makeLogEntry(std::string message)
{
	time_t rawtime;
	time (&rawtime);

	std::string formated = asctime(localtime(&rawtime));
	formated.erase(std::remove(formated.begin(), formated.end(), '\n'), formated.end());
	return formated + " (" + std::getenv("USER") + ") `" + message + "`" ;
}

void	Logger::logToFile(std::string str)
{
	this->_ofs << str << std::endl;
	return ;
}

void	Logger::logToConsole(std::string str)
{
	std::cout << str << std::endl;
	return ;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */