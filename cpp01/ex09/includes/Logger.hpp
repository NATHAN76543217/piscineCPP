#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream> 
# include <string>
# include <time.h>

class Logger
{

	public:

		Logger();
		Logger(std::string filename);
		~Logger();
		
		typedef		void (Logger::*Actions)(std::string);

		Actions		actions[2];
		std::string	choices[2];
		
		void		log(std::string const & dest, std::string const & message);

	private:
		std::string		_filename;
		std::ofstream	_ofs;

		void		logToFile(std::string str);
		void		logToConsole(std::string str);
		std::string	makeLogEntry(std::string str);
};

#endif /* ********************************************************** LOGGER_H */