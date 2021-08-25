#include "Replace.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Replace::Replace(std::string filename) : _filename(filename), _outname(filename + ".replace")
{
	this->_ifs.open(filename);
	if (this->_ifs.is_open() == false)
	{
		std::cout << "Error while opening file: " << this->_filename << std::endl;
		return ;
	}
	this->_ofs.open(this->_outname);
	if (this->_ofs.is_open() == false)
	{
		std::cout << "Error while opening output file: " << this->_outname << std::endl;
		return ;
	}

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Replace::~Replace()
{
	if (this->_ifs.is_open() == true)
		this->_ifs.close();
	if (this->_ofs.is_open() == true)
		this->_ofs.close();
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Replace::replace(std::string s1, std::string s2)
{
	std::string readed;
	std::string output;

	if (s1.empty() || s2.empty())
	{
		std::cout << "s1 and s2 should not be empty" << std::endl;
		return ;
	}
	while (this->_ifs.eof() == false && this->_ifs.fail() == false)
	{
		getline(this->_ifs, readed);
		size_t pos = 0;
		while (pos != std::string::npos)
		{
			pos = readed.find(s1);
			if (pos != std::string::npos)
			{
				output += readed.substr(0, pos);
				output += s2;
				readed.erase(0, pos + s1.length());
			}
			else
				output += readed;
		}
		this->_ofs << output << std::endl;
		output = "";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */