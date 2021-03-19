#include <iostream>
#include <iomanip>
#include "Annuaire.hpp"

std::string	truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str; 
}

Annuaire::Annuaire(void)
{
	this->open = true;
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
	return this->open;
}

std::string Annuaire::askInput(void) const
{
	std::string command;

	std::cout << "Please enter a command:" << std::endl;
	std::cin >> command;
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
	if (this->youWantTo("quit"))
	{
		this->open = false;
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
    		std::cin.clear();
    		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		if(this->youWantTo("have more details"))
		{
			index = this->askIndex();
			if (index != -1)
				this->contacts[index].printInfo();
		}
	}
	else
		std::cout << "You haven't any contact registered" << std::endl;
	return ;
}

int		Annuaire::askIndex(void) const
{
	int index = 0;

	do{
		std::cout << "Enter an index to see more details:" << std::endl;
		std::cin >> index;
		while ( !std::cin )
		{
			std::cin.clear ();
			std::cin.ignore ( std::numeric_limits<std::streamsize>::max() , '\n' );
			std::cout << "I said enter an index, thats mean a number. Try again:" << std::endl;
			std::cin >> index;
		}
		if (index < this->nbMax && this->contacts[index].filled == true)
			return index;
		std::cout << "This is an invalid index." << std::endl;
		
	} while(this->youWantTo("enter another index"));
	return -1;
}

bool	Annuaire::youWantTo(std::string str)
{
	char type;

	do
	{
		std::cout << "Do you want to " << str << "? [y/n]" << std::endl;
		std::cin >> type;
	}
	while( !std::cin.fail() && type!='y' && type!='n' );	
	if (type=='y')
		return true;
	return false;
}
