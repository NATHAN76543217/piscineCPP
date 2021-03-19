#include "utils.hpp"

std::string	truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str; 
}

bool	youWantTo(std::string str)
{
	std::string type;

	do
	{
		std::cout << "Do you want to " << str << "? [y/n]" << std::endl;
		std::getline(std::cin, type);
	}
	while(type!="y" && type!="n");	
	if (type=="y")
		return true;
	return false;
}
