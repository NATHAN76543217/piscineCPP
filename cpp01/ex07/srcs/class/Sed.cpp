#include "Sed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Sed::Sed() : _suffix(".replace"), _inputFile("input.txt"), _outputFile("output.txt"), _ifs(new std::ifstream(_inputFile)), _iState(true)
{
	if (this->checkInValidity())
		this->_ofs = new std::ofstream(this->_outputFile);
	else
		this->_ofs = NULL;

}

Sed::Sed(std::string filename) : _suffix(".replace"), _inputFile(filename), _outputFile(filename + _suffix), _ifs(new std::ifstream(_inputFile)), _iState(true)
{
	if (this->checkInValidity())
		this->_ofs = new std::ofstream(this->_outputFile);
	else
		this->_ofs = NULL;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Sed::~Sed()
{
	if (this->checkOutValidity())
		this->_ofs->close();
	if (this->checkInValidity())
		this->_ifs->close();
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool		Sed::checkInValidity()
{
	if (!this->_iState)
		return false;
	else if (!this->_ifs->is_open())
	{
		std::cerr << "Error when opening '" << this->_inputFile << "' file." << std::endl;
		this->_iState = false;
	}
	else if (this->_ifs->fail() && !this->_ifs->eof())
	{
		std::cerr << "Error when reading from '" << this->_inputFile << "' file." << std::endl;
		this->_iState = false;
	}
	else
		return true;
	return false;
}

bool		Sed::checkOutValidity() const
{
	if (this->_ofs == NULL)
		return false ;
	else if (!this->_ofs->is_open())
		std::cerr << "Error when opening '" << this->_outputFile << "' file." << std::endl;
	else if (this->_ofs->fail())
		std::cerr << "Error when writing to '" << this->_outputFile << "' file." << std::endl;
	else
		return true;
	return false;
}

int			Sed::replace(std::string s1, std::string s2)
{
	std::string first;
	std::string dest;
	size_t		pos ;

	if (!(this->checkInValidity() && this->checkOutValidity()))
		return -1;
	while (std::getline(this->getIfs(), dest))
	{
		pos = dest.find(s1);
		if (pos != std::string::npos)
			dest.replace(pos, s1.length(), s2);
		*(this->_ofs) << dest << std::endl;
	}
	return 0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void			Sed::setInputile(std::string inputFile)
{
	this->_inputFile = inputFile;
	this->_outputFile = inputFile + this->_suffix;
	this->_ifs->close();
	this->_ifs->open(inputFile);

	return ;
}

void			Sed::setOutputile(std::string outputFile)
{
	this->_outputFile = outputFile;
	this->_ofs->close();
	this->_ofs->open(outputFile);
	return ;
}

void			Sed::setSuffix(std::string suffix)
{
	this->_suffix = suffix;
	return ;
}

std::string		Sed::getInputFile(void)
{
	return this->_inputFile;
}

std::string		Sed::getOutputFile(void)
{
	return this->_outputFile;
}

std::ifstream	&Sed::getIfs(void)
{
	return *(this->_ifs);
}

std::ofstream	&Sed::getOfs(void)
{
	return *(this->_ofs);
}

/* ************************************************************************** */