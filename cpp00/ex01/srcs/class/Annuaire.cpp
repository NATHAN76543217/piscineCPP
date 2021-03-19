#include "Annuaire.hpp"

Annuaire::Annuaire(void)
{
	this->_open = true;
	this->nbRegistered = 0;
	this->nbMax = 8;
	return ;
}

Annuaire::~Annuaire(void)
{
	return ;
}

void	Annuaire::displayCommands(void) const
{
	std::cout << "WELCOME IN THE SUPER anNU(L)aire" << std::endl << std::endl;
	std::cout << "The commands are:" << std::endl;
	std::cout << "EXIT: Exit from the annuaire." << std::endl;
	std::cout << "ADD: Create a new contact." << std::endl;
	std::cout << "SEARCH: Display a list of contact and allow you to explore them." << std::endl << std::endl;
	return ;
}

bool	Annuaire::isOpen(void) const
{
	return this->_open;
}

std::string Annuaire::askInput(void) const
{
	std::string command;

	std::cout << "Please enter a command (ADD, SEARCH, EXIT):" << std::endl;
	std::getline(std::cin, command);
	return command;   
}

int		Annuaire::command(std::string cmd)
{
	if (cmd.compare("EXIT") == 0)
		this->close();
	else if (cmd.compare("ADD") == 0)
		this->addContact();
	else if (cmd.compare("SEARCH") == 0)
		this->search();
	else
		std::cout << "sorry, this command doesn't exist. Try again." << std::endl;
	return 0;
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

void	Annuaire::addContact(void)
{
	if (this->nbRegistered >= this->nbMax)
	{
		std::cout << "Your annuaire is full." << std::endl << std::endl;
		return ;
	}
	for (int i = 0; i < this->nbMax; i++)
	{
		if (this->contacts[i].filled == false)
		{
			std::cout << "- Adding an user -" << std::endl;
			this->contacts[i].fill();
			std::cout << "- Contact complete and added -" << std::endl;
			this->nbRegistered++;
			return ;
		}
	}
}

void	Annuaire::search(void) const
{
	int	index;
	std::cout << std::string(45, '-') << std::endl << "|"
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << "|" << std::endl
		<< std::string(45, '-') << std::endl;
	for (int i = 0; i < this->nbMax; i++)
	{
		if (this->contacts[i].filled == true)
		{
			std::cout << std::right
				<< "|" << std::setw(10) << i 
				<< "|" << std::setw(10) << truncate(this->contacts[i].getFirstName()) 
				<< "|" << std::setw(10) << truncate(this->contacts[i].getLastName())
				<< "|" << std::setw(10) << truncate(this->contacts[i].getNickName())
				<< "|" << std::endl << std::string(45, '-') << std::endl;
		}
	}
	if (this->nbRegistered != 0)
	{
		if (youWantTo("have more details"))
		{
			index = this->askIndex();
			if (index != -1)
				this->contacts[index].printInfo();
		}
	}
	else
		std::cout << "You haven't any contact registered" << std::endl << std::endl;
	return ;
}

int		Annuaire::askIndex(void) const
{
	int index = -1;
	std::string buf;

	do{
		std::cout << "Enter an index to see more details:" << std::endl;
		std::getline(std::cin, buf);
		try{
			index = stoi(buf);
			if (index < this->nbMax && index >= 0 && this->contacts[index].filled == true)
				return index;
			std::cout << "This is an invalid index." << std::endl;
	    }
		catch (const std::exception& e) {
			std::cout << "I said enter an index, thats mean a number beetween 0 and the number of contact registered." << std::endl;
		}
	} while(youWantTo("enter another index"));
	return -1;
}
