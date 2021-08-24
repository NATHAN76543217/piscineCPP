#include "Annuaire.hpp"

// Constructors
Annuaire::Annuaire(void) : _nbMax(8), _nbRegistered(0), _open(false)
{
	return ;
}

//destructors
Annuaire::~Annuaire(void)
{
	return ;
}

// Public members

void	Annuaire::open(void)
{
	this->_open = true;
	this->_displayCommands();
	while (this->_open)
		this->_command(this->_askInput());
}

void	Annuaire::close(void)
{
	if (youWantTo("quit"))
	{
		this->_open = false;
		std::cout << "GOODBYE, you lost your contacts." << std::endl;
	}
	return ;
}

bool	Annuaire::isOpen(void) const
{
	return this->_open;
}

// Private methods

void	Annuaire::_displayCommands(void) const
{
	std::cout << "WELCOME IN THE SUPER anNU(L)aire" << std::endl << std::endl;
	std::cout << "The commands are:" << std::endl;
	std::cout << "EXIT: Exit from the annuaire." << std::endl;
	std::cout << "ADD: Create a new contact." << std::endl;
	std::cout << "SEARCH: Display a list of contact and allow you to explore them." << std::endl << std::endl;
	return ;
}

int		Annuaire::_command(std::string cmd)
{
	if (cmd.compare("EXIT") == 0)
		this->close();
	else if (cmd.compare("ADD") == 0)
		this->_addContact();
	else if (cmd.compare("SEARCH") == 0)
		this->_search();
	else
		std::cout << "sorry, this command doesn't exist. Try again." << std::endl << std::endl;
	return 0;
}

void	Annuaire::_addContact(void)
{
	if (this->_nbRegistered == this->_nbMax)
	{
		std::cout << "Your annuaire is full." << std::endl << std::endl;
		return ;
	}
	for (int i = 0; i < this->_nbMax; i++)
	{
		if (this->_contacts[i].filled == false)
		{
			std::cout << "- Adding an user -" << std::endl;
			this->_contacts[i].fill();
			std::cout << "- Contact complete and added -" << std::endl;
			this->_nbRegistered++;
			return ;
		}
	}
}

void	Annuaire::_search(void) const
{
	int	index;
	std::cout << std::string(45, '-') << std::endl << "|"
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << "|" << std::endl
		<< std::string(45, '-') << std::endl;
	for (int i = 0; i < this->_nbMax; i++)
	{
		if (this->_contacts[i].filled == true)
		{
			std::cout << std::right
				<< "|" << std::setw(10) << i 
				<< "|" << std::setw(10) << this->truncate(this->_contacts[i].getFirstName(), 10)
				<< "|" << std::setw(10) << this->truncate(this->_contacts[i].getLastName(), 10)
				<< "|" << std::setw(10) << this->truncate(this->_contacts[i].getNickName(), 10)
				<< "|" << std::endl << std::string(45, '-') << std::endl;
		}
	}
	if (this->_nbRegistered != 0)
	{
		if (youWantTo("have more details"))
		{
			index = this->_askIndex();
			if (index != -1)
				this->_contacts[index].printInfo();
		}
	}
	else
		std::cout << "You haven't any contact registered" << std::endl << std::endl;
	return ;
}

int		Annuaire::_askIndex(void) const
{
	int index = -1;
	std::string buf;

	do{
		std::cout << "Enter an index to see more details:" << std::endl;
		std::getline(std::cin, buf);
		try{
			index = stoi(buf);
			if (index < this->_nbMax && index >= 0 && this->_contacts[index].filled == true)
				return index;
			std::cout << "This is an invalid index." << std::endl;
	    }
		catch (const std::exception& e) {
			std::cout << "I said enter an index, thats mean a number beetween 0 and the number of contact registered." << std::endl;
		}
	} while(youWantTo("enter another index"));
	return -1;
}

std::string Annuaire::_askInput(void) const
{
	std::string command;

	std::cout << "Please enter a command (ADD, SEARCH, EXIT):" << std::endl;
	std::getline(std::cin, command);
	return command;   
}

// non-member function

bool	Annuaire::youWantTo(std::string str)
{
	std::string type;

	do
	{
		std::cout << "Do you want to " << str << "? [y/n]" << std::endl;
		std::getline(std::cin, type);
	} while (type != "y" 
		&& type != "Y"
		&& type != "n" 
		&& type != "N");	
	if (type == "y" || type == "Y")
		return true;
	return false;
}

std::string	Annuaire::truncate(std::string str, size_t len)
{
	size_t strlen = str.length() - (Annuaire::countSpecial(str) / 2);
	size_t endIndex = Annuaire::sizeOfPrintable(str, len - 1);
	if (endIndex != 0)
		return str.substr(0, endIndex) + ".";
	return str.insert(0, len - strlen , ' ');
}

size_t Annuaire::countSpecial(std::string str)
{
	int i = 0;
	int special = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 0)
			special++;
		i++;
    }
	return special;
}
size_t	Annuaire::sizeOfPrintable(std::string str, size_t nb)
{
	size_t size = 0;
	size_t passed = 0;
	while ( passed < nb && str[size] != '\0')
	{
		if (str[size] < 0)
			size += 2;
		else
			size++;
		passed += 1;
	}
	if (passed != nb)
		return 0;
	return size;
}